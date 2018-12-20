#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <cstdio>
#include <string/String.h>

void get_failure(const String &p, int *f)
{
    f[0] = -1;
    int j = 0, k = -1;
    while (j < p.GetLength() - 1)
        if (k == -1 || p[k] == p[j])
            f[++j] = ++k;
        else
            k = f[k];
}

int kmp_find(const String &s, const String &p, unsigned int begin = 0)
{
    if (p.IsEmpty() || s.IsEmpty() || s.GetLength() < p.GetLength() ||
        begin > s.GetLength() - p.GetLength())
        return -1;
    std::unique_ptr<int[]> f(new int[p.GetLength()]);
    get_failure(p, f.get());
    int sindex = begin, pindex = 0;
    while (sindex < s.GetLength() && pindex < p.GetLength() &&
           p.GetLength() - pindex <= s.GetLength() - sindex)
    {
        if (pindex == -1 || p[pindex] == s[sindex])
        {
            sindex++;
            pindex++;
        }
        else
        {
            pindex = f[pindex];
        }
    }
    return pindex < p.GetLength() ? -1 : sindex - pindex;
}

void repeat(char c = '|', int times = 1)
{
    if (times <= 0)
        return;
    while (times--)
        std::putchar(c);
}

void repeat(std::initializer_list<std::pair<char, int>> list)
{
    for (const auto &p : list)
        repeat(p.first, p.second);
}

int kmp_find_step(const String &s, const String &p, unsigned int begin = 0)
{
    if (p.IsEmpty() || s.IsEmpty() || s.GetLength() < p.GetLength() ||
        begin > s.GetLength() - p.GetLength())
        return -1;
    std::unique_ptr<int[]> f(new int[p.GetLength()]);
    get_failure(p, f.get());
    int sindex = begin, pindex = 0;
    int times = 0;
    while (sindex < s.GetLength() && pindex < p.GetLength() &&
           p.GetLength() - pindex <= s.GetLength() - sindex)
    {
        int i, j;
        bool success = false;
        if (pindex == -1 || p[pindex] == s[sindex])
        {
            success = true;
            i = sindex;
            j = pindex;
            sindex++;
            pindex++;
        }
        else
        {
            i = sindex;
            j = pindex;
            pindex = f[pindex];
        }
        std::cout << ++times << (success ? " :success" : " :fail") << ", i = " << i << " , j = " << j << std::endl;
        for (int n = 0; n < s.GetLength(); n++)
            std::cout << n % 10;
        putchar('\n');
        std::cout << s.CStr() << std::endl;
        repeat({{' ', i - j}, {'|', success ? j + 1 : j}, {'*', success ? 0 : 1}, {'\n', 1}, {' ', i - j}});
        std::cout << p.CStr() << std::endl;
        repeat(' ', i - j);
        for (int n = 0; n < p.GetLength(); n++)
            std::cout << n % 10;
        repeat({{'\n', 1}, {'_', 20}, {'\n', 2}});
    }
    return pindex < p.GetLength() ? -1 : sindex - pindex;
}

int main()
{
    {
        String p = "abcabaa";
        String t = "abcaabbabcabaacbacba";
        std::cout << kmp_find_step(t, p);
    }
    system("pause");
    return 0;
}