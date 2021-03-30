#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct element
{
    T data;
    element<T> *next = NULL;
    element(T dat)
    {
        data = dat;
    }
};

template<typename T>
class Klelele
{
    private:
        element<T> *przod = NULL, *tyl = NULL;
        unsigned int siz = 0;
    public:
        void push(T dat);
        bool empty()
        {
            return siz;
        }
        unsigned int size()
        {
            return siz;
        }
        T pop();
        T front();
        T back();
        ~Klelele()
        {
            element<T> *temp;
            while(siz--)
            {
                temp = przod->next;
                delete przod;
                przod = temp;
            }
        }
};

template<typename T>
void Klelele<T>::push(T dat)
{
    element<T> *temp = new element<T>(dat);
    if(!siz)
    {
        przod = temp;
        tyl = temp;
    }
    else
    {
        tyl->next = temp;
        tyl = temp;
    }
    siz++;
}

template<typename T>
T Klelele<T>::pop()
{
    if(!this->siz)
        throw out_of_range("Empty queue");
    T data = przod->data;
    element<T> *deleted = przod;
    przod = przod->next;
    delete deleted;
    siz--;
    return data;
}

template<typename T>
T Klelele<T>::front()
{
    if(!this->siz)
        throw out_of_range("Empty queue");
    return przod->data;
}

template<typename T>
T Klelele<T>::back()
{
    return tyl->data;
}

template<typename T>
class Stos
{
    private:
        element<T> *gora = NULL;
        unsigned int siz = 0;
    public:
        void push(T dat);
        bool empty()
        {
            return siz;
        }
        unsigned int size()
        {
            return siz;
        }
        T pop();
        T top();
        ~Stos()
        {
            element<T> *temp;
            while(siz--)
            {
                temp = gora->next;
                delete gora;
                gora = temp;
            }
        }
};


template<typename T>
T Stos<T>::pop()
{
    if(!this->siz)
        throw out_of_range("Empty stack");
    T dat = gora->data;
    element<T> *temp = gora->next;
    delete gora;
    gora = temp;
    siz--;
    return dat;
}

template<typename T>
T Stos<T>::top()
{
    if(!this->siz)
        throw out_of_range("Empty stack");
    return gora->data;
}

template<typename T>
void Stos<T>::push(T dat)
{
    element<T> *a = new element<T>(dat);
    a->next = gora;
    gora = a;
    siz++;
}

int main()
{
    bool in;
    Stos<char> b;
    string inp;
    getline(cin, inp);
    in = 0;
    for(char i : inp)
    {
        switch(i)
        {
            case '(':
                b.push(i);
                break;
            case '[':
                b.push(i);
                break;
            case '{':
                b.push(i);
                break;
            case '<':
                b.push(i);
                break;
            case ')':
                if(b.top() == '(')
                    b.pop();
                else
                    in = 1;
                break;
            case '>':
                if(b.top() == '<')
                    b.pop();
                else
                    in = 1;
                break;
            case ']':
                if(b.top() == '[')
                    b.pop();
                else
                    in = 1;
                break;
            case '}':
                if(b.top() == '{')
                    b.pop();
                else
                    in = 1;
                break;
        }
        if(in)
        {
            cout << "Nawiasy są zapisanie niepoprawnie.\n";
            break;
        }
    }
    if(!in)
    {
        if(b.size())
            cout << "Nawiasy są zapisanie niepoprawnie.\n";
        else
            cout << "Nawiasy są zapisane poprawnie.\n";
    }
}
