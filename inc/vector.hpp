#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <assert.h>

template <typename T> class Vector;

template<typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v);

template <typename T>
class Vector
{
    private:
       int m_size;
       int m_capacity;
       T* m_vector;
       void resize();
    public:
       Vector();
       Vector(const Vector& v);
       ~Vector();
       Vector& operator=(const Vector& v);

       int get_size();

       T& operator[](int i);
       const T& operator[](int i) const { return m_vector[i]; }

       void insert(int i, T item);
       void remove(int i);

       void push_back(T item);
       void pop_back();

       friend std::ostream& operator<< <>(std::ostream& out, const Vector& v);
};

#endif

template <typename T> 
Vector<T>::Vector() 
    : m_size(0)
    , m_capacity(10)
    , m_vector(NULL)
{
    m_vector = new T [m_capacity];
    assert(m_vector);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& v)
    : m_vector(NULL)
    , m_size(0)
    , m_capacity(10)
{
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_vector = new T [m_capacity];
    for (int i = 0; i < m_capacity; ++i) {
        m_vector[i] = v.m_vector[i];
    }
}

template <typename T>
Vector<T>::~Vector()
{
    delete [] m_vector;
    m_vector = NULL;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
    if (this == &v) {
        return *this;
    } else {
        delete [] m_vector;
        m_capacity = v.m_capacity;
        m_size = v.m_size;
        m_vector = new T [m_capacity];
        for (int i = 0; i < m_capacity; ++i) {
            m_vector[i] = v.m_vector[i];
        }
        return *this;
    }
}

template <typename T>
int Vector<T>::get_size()
{
    return m_size;
}

template <typename T>
T& Vector<T>::operator[](int i)
{
    if (i < 0 || i >= m_size) {
        std::cout << "Index is out of range" << std::endl;
    }
    return m_vector[i];
}

template <typename T>
void Vector<T>::insert(int i, T item)
{
    ++m_size;
    if (m_size > m_capacity) {
        resize();
    }
    for (int j = m_size - 1; j > i; --j) {
        m_vector[j] = m_vector[j - 1];
    }
    m_vector[i] = item;
}

template <typename T>
void Vector<T>::remove(int i)
{
    for (int j = i; j < m_size - 1; ++j) {
        m_vector[j] = m_vector[j + 1];
    }
    --m_size;
}

template <typename T>
void Vector<T>::push_back(T item)
{
    if(m_size > m_capacity) {
        resize();
    }
    insert(m_size, item);
}

template <typename T>
void Vector<T>::pop_back()
{
    remove(m_size - 1);
}

template <typename T>
void Vector<T>::resize()
{
    T* old = new T [m_capacity];
    for (int i = 0; i < m_capacity; ++i) {
        old[i] = m_vector[i];
    }
    m_capacity *= 2;
    m_vector = new T [m_capacity];
    for (int i = 0; i < m_capacity/2; ++i) {
        m_vector[i] = old[i];
    }
    delete [] old;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v) 
{ 
    for (int i = 0; i < v.m_size; ++i) {
        out << v[i] << "  ";
    }
    std::cout << std::endl; 
    return out; 
} 
