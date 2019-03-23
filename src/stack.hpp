#include <iostream>
#include "vector.hpp"

template <class T>
class Stack : public Vector<T>
{
    private:
        Vector<T> m_arr;
    public:
        void push(T item);
        void pop();
        T& top();
        bool s_is_empty();
};

template <class T>
void Stack<T>::push(T item)
{
    m_arr.push_back(item);
}

template <class T>
bool Stack<T>::s_is_empty()
{
    return m_arr.is_empty();
}

template <class T>
void Stack<T>::pop()
{
    if(s_is_empty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    m_arr.pop_back();
}

template <class T>
T& Stack<T>::top()
{
    if(s_is_empty()) {
        throw "Stack is empty";
    }
    return m_arr.back();
}
