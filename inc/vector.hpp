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
       friend std::ostream& operator<< <>(std::ostream& out, const Vector& v);

       void insert(int i, T item);
       void remove(int i);

       void push_back(T item);
       void pop_back();
};

#include "vector.cpp"

#endif


