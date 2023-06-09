using namespace std;

template<typename T>
class Klelele : public Container<T> {
    private:
        element<T> *bottom = NULL;
    public:
        void push(T value);
        T front();
        T getBottom();
        // T pop();
};
template<typename T>
void Klelele<T>::push(T value){
    element<T> *temp = new element<T>(value);
    if(Container<T>::empty()){
        Container<T>::top = temp;
        bottom = temp;
    }
    else{
        bottom->next = temp;
        bottom = temp;
    }
    Container<T>::size++;
}
template<typename T>
T Klelele<T>::front(){
    if(Container<T>::empty()){
        throw Container<T>::exception_container_empty();
    }
    return Container<T>::top->data;
}
template<typename T>
T Klelele<T>::getBottom() {return bottom->data;}