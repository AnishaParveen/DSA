#include<iostream>
using namespace std;
template<class T>
class stack
{
    int tos,size;
    T *arr;
    public:
    stack();
    stack(int size);
    ~stack();
    stack(const stack &ob);
    bool isfull();
    bool isempty();
    void push(T data);
    T peek();
    T pop();
};
template<class T>
stack<T>::stack()
    {
        tos=-1;
        size=5;
        arr=new T[size];
    }
template<class T>
stack<T>::~stack()
{
    delete[] arr;
}
template<class T>
stack<T>::stack(int size)
    {
        tos=-1;
        this->size=size;
        arr=new T[size];
    }
template<class T>
stack<T>::stack(const stack &ob)
    {
        this->tos=ob.tos;
        this->size=ob.size;
        this->arr=new int[this->size];
        for(int i=0; i<=this->tos;++i)
        this->arr[i]=ob.arr[i];
    }
template<class T>
bool stack<T>:: isfull()
    {
        if(tos == size -1)
            return true;
        return false;
    }   
template<class T>
bool stack<T>::isempty()
    {
        if(tos==-1)
            return true;
        return false;
    }
template<class T>
void stack<T>::push(T data)
    {
        if(isfull())
        return;
        else{
            arr[++tos]=data;
            }
    }
template<class T>
T stack<T>::pop()
    {   int tmp;
        if(isempty())
        return 1;
        else{
            tmp=arr[tos--];
            return tmp;
        }
    }
template<class T>
T stack<T>::peek()
{
    int tmp;
        if(isempty())
        return 1;
        else{
            tmp=arr[tos];
            return tos;
        }
}
int main(){
    stack<int> s1(10);
    stack<char> s2(10);
    s1.push(5);
    s1.push(15);
    s2.push('a');
    s2.push('b');
    cout<<s1.pop()<<endl;
    cout<<s2.pop()<<endl;
    return 0;
}
