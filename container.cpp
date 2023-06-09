using namespace std;

template<typename T>
class Container{
    protected:
        string exception_container_empty(){
            return "Container is empty.";
        }
        unsigned int size = 0;
        element<T> *top = NULL;
    public:
        bool empty(){
            return size == 0;
        }
        unsigned int getSize(){
            return size;
        }
        T pop();
        ~Container(){
            element<T> *temp;
            while(Container<T>::size--){
                temp = Container<T>::top->next;
                delete Container<T>::top;
                Container<T>::top = temp;
            }
        }
};
template<typename T>
T Container<T>::pop(){
    if(this->empty()){
        throw this->exception_container_empty();
    }
    T data = top->data;
    element<T> *temp = top->next;
    delete top;
    top = temp;
    size--;
    return data;
}