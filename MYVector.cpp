#include "MYVector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
Vector<T>::Vector(int cap)
    : capacity_{ cap }
    , size_{ 0 }
    , data{ new T[capacity] }
{
    vec.begin();
    // empty body
}

template <class T>
Vector<T>::Vector(T* aData, int sz)
    : capacity_{ sz }
    , size_{ sz }
    , data{ new T[capacity_] }
{
    for (int i{ 0 }; i < sz; ++i)
        data[i] = aData[i];
}

template <class T>
Vector<T>::Vector(const Vector& other)
    : capacity_{ other.capacity() }
    , size_{ other.size() }
    , data{ new T[capacity_] }
{
    for (int i{ 0 }; i < size_; ++i)
        data[i] = other.data[i];
}

template <class T>
Vector<T>::~Vector()
{
    delete[] data;
}

template <class T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        size_ = other.size();
        capacity = other.capacity();
        delete[] data;
        data = new T[capacity_];

        for (int i{ 0 }; i < size_; ++i)
            data[i] = other.data[i];
    }

    return *this;
}

template <class T>
const Vector<T>& Vector<T>::operator=(const Vector<T>&& other)
{
    if (this != &other)
    {
        size_ = other.size();
        other.size_ = 0;

        capacity = other.capacity();
        other.capacity_ = 0;

        delete[] data;
        data = other.data;
        other.data = nullptr;
    }

    return *this;
}

template <class T>
T& Vector<T>::operator[](int index)
{
    if (index < 0 || index > (size_ - 1))
        throw out_of_range("index out of range");

    return data[index];
}

template <class T>
const T& Vector<T>::operator[](int index) const
{
    if (index < 0 || index > (size_ - 1))
        throw out_of_range("index out of range");

    return data[index];
}

template <class T>
int Vector<T>::push_back(T element)
{
    if (size() == capacity())
        resize();

    data[size()] = element;
    ++size_;

    return size();
}

template <class T>
T Vector<T>::pop_back()
{
    --size_;
    return data[size_];
}



// erase



// erase


template <class T>
void Vector<T>::clear()
{
    delete[] data;
    size_ = 0;
}

// insert


template <class T>
bool Vector<T>::operator==(const Vector<T>& other) const
{
    if (size() != other.size())
        return false;

    for (int i{ 0 }; i < size(); ++i)
        if (data[i] != other.data[i])
            return false;

    return true;
}

template <class T>
bool Vector<T>::operator<(const Vector<T>& other) const
{
    if (size() != other.size())
        return size() < other.size();

    for (int i{ 0 }; i < size(); ++i)
        if (data[i] != other.data[i])
            return data[i] < other.data[i];

    return false;
}

template <class T>
int Vector<T>::size() const { return size_ }

template <class T>
int Vector<T>::capacity() const { return capacity_ }

template <class T>
bool Vector<T>::empty() const { return (size_ == 0); }

template <class T>
int Vector<T>::resize()
{
    capacity_ = static_cast<int>(capacity() * 1.5);
    
    T* newData = new T[capacity()];
    
    for (int i{ 0 }; i < size(); ++i)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    newData = nullptr;

    return capacity();
}
