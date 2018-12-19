#include <queue>
#include <iostream>

int main()
{
    int n, prev;
    std::cin >> n;
    std::queue<int> que;
    que.push(1);
    for (int i = 1; i <= n; i++)
    {
        que.push(1);
        for (int j = 0; j < i; j++)
        {
            if (j)
                que.push(que.front() + prev);
            prev = que.front();
            que.pop();
            std::cout << prev << ' ';
        }
        que.push(1);
        std::cout << std::endl;
    }
    return 0;
}