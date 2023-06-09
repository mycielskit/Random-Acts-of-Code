using namespace std;

template<typename T>
class Stos : public Container<T> {
    public:
        void push(T value);
        T getTop();
};
template<typename T>
void Stos<T>::push(T value){
    element<T> *temp = new element<T>(value);
    temp->next = Container<T>::top;
    Container<T>::top = temp;
    Container<T>::size++;
}
template<typename T>
T Stos<T>::getTop(){
    return Container<T>::top->data;
}