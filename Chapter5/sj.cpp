#include <string/LinkList.h>

//1
typedef LinkList<char> String;
typedef Node<char> CNode;

bool find_char(const String &str, unsigned int len, char c)
{
    CNode *head = str.GetHead();
    head = head->next;
    int length = len;
    while (head != nullptr && (length--))
    {
        if (head->data == c)
            return true;
        head = head->next;
    }
    return false;
}

int find(const String &s, const String &t)
{
    CNode *shead = s.GetHead();
    shead = shead->next;
    for (int i = 0; shead != nullptr; shead = shead->next, i++)
    {
        if (find_char(s, i, shead->data))
            continue;
        if (!find_char(t, t.GetLength(), shead->data))
            return i;
    }
    return -1;
}

//2
void delete_string(char* str, unsigned int s, unsigned int m, unsigned int t)
{
    std::strncpy(str + s, str, m);
    std::strncpy(str + m + t, str + s + m, s - m - t);
}


int main()
{
#define STR(arr) String(arr, sizeof(arr) / sizeof(char))
    //return -1
    assert(find(STR(""), STR("")) == -1);
    assert(find(STR("abcdef"), STR("abcdef")) == -1);
    assert(find(STR(""), STR("aaaaaa")) == -1);
    assert(find(STR("aaabbbccc"), STR("abc")) == -1);

    assert(find(STR("aaaaa"), STR("")) == 0);
    assert(find(STR("abcdef"), STR("ab")) == 2);
    assert(find(STR("abcdef"), STR("abcd")) == 4);
    assert(find(STR("abcdef"), STR("abcde")) == 5);
    assert(find(STR("aaaabc"), STR("ab")) == 5);

    system("pause");
    return 0;
}