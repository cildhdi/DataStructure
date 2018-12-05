//T3
template <class ElemType>
void SeqList<ElemType>::Reverse()
{
    std::reverse(elems, elems + length);
}

//T7
//in LinkList.h
template <class ElemType>
template <typename T>
void LinkList<ElemType>::Traverse(T visit) const
// 操作结果：依次对单链表的每个元素使用可调用对象(visit)访问
{
    Node<ElemType> *p = head->next;
    while (p != NULL)
    {
        visit(p->data);
        p = p->next;
    }
}

//in Polynomial.h
struct Counter
{
    double &_result;
    double &_x;
    Counter(double &result, double x) : _result(result), _x(x) {}
    void operator()(const PolyItem &item)
    {
        _result += std::pow(_x, item.expn) * item.coef;
    }
};

double Cal(double x)
{
    double result = 0;
    Counter counter(result, x);
    polyList.Traverse(counter);
    return result;
}

//T10
template <typename T>
T CombineAndReverse(const T &s1, const T &s2)
{
    T res = Combine<T>(s1, s2);
    res.Reverse();
    return res;
}