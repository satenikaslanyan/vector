#include <iostream>
#include "vector.hpp"

template <class T>
class Stack : public Vector<T>
{
    public:
        void push(T item);
        void pop();
        T& top();
};

template <class T>
void Stack<T>::push(T item)
{
    Vector<T>::push_back(item);
}

template <class T>
void Stack<T>::pop()
{
    if(Vector<T>::is_empty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    Vector<T>::pop_back();
}

template <class T>
T& Stack<T>::top()
{
    if(Vector<T>::is_empty()) {
        throw "Stack is empty";
    }
    return Vector<T>::back();
}
