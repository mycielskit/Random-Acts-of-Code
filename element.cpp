template<typename T>
struct element
{
    T data;
    element<T> *next = NULL;
    element(T value)
    {
        data = value;
    }
};