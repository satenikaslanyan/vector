#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <assert.h>

template <class T> class Vector;

template <class T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v);



template <class T>
class Vector
{
    protected:
       int m_size;
       int m_capacity;
       T* m_vector;
       void resize();
    public:
       Vector();
       Vector(const Vector& v);
       ~Vector();
       Vector& operator=(const Vector& v);

       // This function returns last element of the vector
       T& back();

       // This function returns sized of the vector
       int get_size();

       // This function checks if the list is empty or not
       bool is_empty();

       // The overload function of operator[]
       T& operator[](int i);

       // The overload function of operator[] (for constant vector)
       const T& operator[](int i) const { return m_vector[i]; }

       // The overload function of operator<<
       friend std::ostream& operator<< <>(std::ostream& out, const Vector& v);

       //This function is for inserting an element in range of [0, m_size]
       void insert(int i, T item);

       //This function is for deleting an element in range of [0, m_size-1]
       void remove(int i);

       //This function adds an element in the end of the vector
       void push_back(T item);

       //This function deletes the last element of the vector
       void pop_back();
};

#endif

template <class T> 
Vector<T>::Vector() 
    : m_size(0)
    , m_capacity(10)
    , m_vector(NULL)
{
    m_vector = new T [m_capacity];
    assert(m_vector);
}

template <class T>
Vector<T>::Vector(const Vector<T>& v)
    : m_vector(NULL)
    , m_size(0)
    , m_capacity(10)
{
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_vector = new T [m_capacity];
    assert(m_vector);
    for (int i = 0; i < m_capacity; ++i) {
        m_vector[i] = v.m_vector[i];
    }
}

template <class T>
Vector<T>::~Vector()
{
    delete [] m_vector;
    m_vector = NULL;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
    if (this == &v) {
        return *this;
    } else {
        delete [] m_vector;
        m_capacity = v.m_capacity;
        m_size = v.m_size;
        m_vector = new T [m_capacity];
        assert(m_vector);
        for (int i = 0; i < m_capacity; ++i) {
            m_vector[i] = v.m_vector[i];
        }
        return *this;
    }
}

template <class T>
int Vector<T>::get_size()
{
    return m_size;
}

template <class T>
bool Vector<T>::is_empty()
{
    return (0 == m_size);
}

template <class T>
T& Vector<T>::back()
{
    return m_vector[m_size - 1];
}

template <class T>
T& Vector<T>::operator[](int i)
{
    if (i < 0 || i >= m_size) {
        std::cout << "Index is out of range" << std::endl;
    }
    assert(i >= 0 && i < m_size); 
    return m_vector[i];
}

template <class T>
void Vector<T>::insert(int i, T item)
{
    if (i > m_size) {
        std::cout << "Out of range" << std::endl;
        return;
    } else {	    
	++m_size;
	if (m_size > m_capacity) {
	    resize();
	}
	for (int j = m_size - 1; j > i; --j) {
	    m_vector[j] = m_vector[j - 1];
	}
	m_vector[i] = item;
    }
}

template <class T>
void Vector<T>::remove(int i)
{
    if (i > m_size - 1) {
        std::cout << "Out of range" << std::endl;
        return;
    }
    for (int j = i; j < m_size - 1; ++j) {
        m_vector[j] = m_vector[j + 1];
    }
    --m_size;
}

template <class T>
void Vector<T>::push_back(T item)
{
    if (m_size > m_capacity) {
        resize();
    }
    insert(m_size, item);
}

template <class T>
void Vector<T>::pop_back()
{
    --m_size;
}

template <class T>
void Vector<T>::resize()
{
    m_capacity *= 2;
    T* new_ptr = new T [m_capacity];
    assert(new_ptr);
    for (int i = 0; i < m_capacity/2; ++i) {
        new_ptr[i] = m_vector[i];
    }
    delete [] m_vector;
    m_vector = new_ptr;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v) 
{ 
    for (int i = 0; i < v.m_size; ++i) {
        out << v[i] << "  ";
    }
    std::cout << std::endl; 
    return out; 
}
