//1(3)
template <typename T>
void SeqList<T>::Unique()
{
    T *end = std::unique(elems, elems + length);
    for (T *p = end; p != elems + length; p++)
        p->~T();
    length = end - elems;
}

//2(3)
/*由于LinkList与SeqList均含有GetLength、GetElem与InsertElem三个成员函数，
所以把Combine做成模板函数
本题直接使用Combine<SeqList<T>>
上机题中合并链表可直接使用Combine<LinkList<T>>*/
template <typename T>
T Combine(const T &s1, const T &s2)
{
    T res;
    int i = 0, j = 0;
    while (i <= s1.GetLength() && j <= s2.GetLength())
    {
        if (s1.GetElem(i) > s2.GetElem(j))
        {
            res.InsertElem(s2.GetElem(j));
            j++;
        }
        else
        {
            res.InsertElem(s1.GetElem(i));
            i++;
        }
    }
    while (i <= s1.GetLength())
    {
        res.InsertElem(s1.GetElem(i));
        i++;
    }
    while (j <= s2.GetLength())
    {
        res.InsertElem(s2.GetElem(j));
        j++;
    }
    return res;
}

//2(4)
template <typename T>
void SeqList<T>::Erase(const T &s, const T &t)
{
    if (s <= t)
        throw std::invalid_argument("t should be greater than s.");
    T *begin = std::find(elems, elems + length,
                         std::bind(std::greater<T>(), std::placeholders::_1, s));
    T *end = std::find(begin, elems + length,
                       std::bind(std::greater<T>(), std::placeholders::_1, t));
    for (int i = 0; end + i < elems + length; i++)
        *(begin + i) = *(end + i);
    length = length - end + begin;
}

//5
template <typename T>
Status LinkList<T>::InsertElem(int i, const T &e)
{
    if (i < 1 || i > length + 1)
        return RANGE_ERROR;
    else
    {
        if (i == 1)
        {
            head = new Node<T>(e, head);
            length++;
        }
        else
        {
            Node<T> *p = head;
            for (int j = 2; j < i; j++)
                p = p->next;
            //p->next为新元素位置
            p->next = new Node<T>(e, p->next);
            length++;
        }
    }
    return SUCCESS;
}

template <typename T>
Status LinkList<T>::DeleteElem(int i, T &e)
{
    if (i < 1 || i > length)
        return RANGE_ERROR;
    else
    {
        if (i == 1)
        {
            Node<T> *p = head->next;
            delete head;
            head = p;
            length--;
        }
        else
        {
            Node<T> *p = head;
            for (int j = 2; j < i; j++)
                p = p->next;
            //p->next为要删除的元素
            Node<T> *new_next = p->next->next;
            delete p->next;
            p->next = new_next;
            length--;
        }
    }
    return SUCCESS;
}