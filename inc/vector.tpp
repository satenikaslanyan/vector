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
    for (int j = i; j < m_size - 1; ++j) {
        m_vector[j] = m_vector[j + 1];
    }
    --m_size;
}

template <class T>
void Vector<T>::push_back(T item)
{
    if(m_size > m_capacity) {
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

template <class T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v) 
{ 
    for (int i = 0; i < v.m_size; ++i) {
        out << v[i] << "  ";
    }
    std::cout << std::endl; 
    return out; 
} 
