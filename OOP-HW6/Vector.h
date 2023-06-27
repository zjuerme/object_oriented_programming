#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <class T>
class Vector {
    public:
        Vector();
        Vector(int size);
        Vector(const Vector& r);
        ~Vector();
        T& operator[](int index);
        T& at(int index);
        int size() const;
        void push_back(const T& x);
        void clear();
        bool empty() const;
    private:
        void inflate();
        T* m_pElements;
        int m_nSize;
        int m_nCapacity;
};

template <class T>
Vector<T>::Vector() : m_pElements(nullptr), m_nSize(0), m_nCapacity(0) {}

template <class T>
Vector<T>::Vector(int size) : m_pElements(new T[size]), m_nSize(0), m_nCapacity(size) {}

template <class T>
Vector<T>::Vector(const Vector<T>& r) : m_pElements(new T[r.m_nCapacity]), m_nSize(r.m_nSize), m_nCapacity(r.m_nCapacity) {
    for(int i = 0; i < m_nSize; i++) {
        m_pElements[i] = r.m_pElements[i];
    }
}

template <class T>
Vector<T>::~Vector() {
    delete[] m_pElements;
}

template <class T>
T& Vector<T>::operator[](int index) {
    return m_pElements[index];
}

template <class T>
T& Vector<T>::at(int index) {
    if(index < 0 || index >= m_nSize) {
        throw std::out_of_range("Index is out of range.");
    }
    return m_pElements[index];
}

template <class T>
int Vector<T>::size() const {
    return m_nSize;
}

template <class T>
void Vector<T>::push_back(const T& x) {
    if(m_nSize == m_nCapacity) {
        inflate();
    }
    m_pElements[m_nSize] = x;
    m_nSize++;
}

template <class T>
void Vector<T>::clear() {
    delete[] m_pElements;
    m_pElements = nullptr;
    m_nSize = 0;
    m_nCapacity = 0;
}

template <class T>
bool Vector<T>::empty() const {
    return m_nSize == 0;
}

template <class T>
void Vector<T>::inflate() {
    int newCapacity = (m_nCapacity > 0) ? 2 * m_nCapacity : 1;
    T* newArray = new T[newCapacity];
    for(int i = 0; i < m_nSize; i++) {
        newArray[i] = m_pElements[i];
    }
    delete[] m_pElements;
    m_pElements = newArray;
    m_nCapacity = newCapacity;
}
#endif