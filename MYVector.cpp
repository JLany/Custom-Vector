#include "MYVector.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

template <class T>
MYVector<T>::MYVector(int cap)
    : capacity_{ cap }
    , size_{ 0 }
    , data{ new T[cap]{} }
{
    // empty body
}

template <class T>
MYVector<T>::MYVector(T* aData, int sz)
    : capacity_{ sz }
    , size_{ sz }
    , data{ new T[sz]{} }
{
    for (int i{ 0 }; i < sz; ++i)
        data[i] = aData[i];
}

template <class T>
MYVector<T>::MYVector(const MYVector& other)
    : capacity_{ other.capacity() }
    , size_{ other.size() }
    , data{ new T[other.capacity()]{} }
{
    for (int i{ 0 }; i < size_; ++i)
        data[i] = other.data[i];
}

template <class T>
MYVector<T>::~MYVector()
{
    if (data)
        delete data;

    data = nullptr;
}

template <class T>
const MYVector<T>& MYVector<T>::operator=(const MYVector<T>& other)
{
    if (this != &other)
    {
        size_ = other.size();
        capacity_ = other.capacity();
        delete[] data;
        data = new T[capacity_]{};

        for (int i{ 0 }; i < size_; ++i)
            data[i] = other.data[i];
    }

    return *this;
}

template <class T>
const MYVector<T>& MYVector<T>::operator=(MYVector<T>&& other) noexcept
{
    if (this != &other)
    {
        size_ = other.size();
        other.size_ = 0;

        capacity_ = other.capacity();
        other.capacity_ = 0;

        delete[] data;
        data = other.data;
        other.data = nullptr;
    }

    return *this;
}

template <class T>
T& MYVector<T>::operator[](int index)
{
    if (index < 0 || index >(size_ - 1))
        throw out_of_range("index out of range");

    return data[index];
}

template <class T>
const T& MYVector<T>::operator[](int index) const
{
    if (index < 0 || index >(size_ - 1))
        throw out_of_range("index out of range");

    return data[index];
}

template <class T>
int MYVector<T>::push_back(T element)
{
    if (size() == capacity())
        resize();

    data[size_] = element;
    ++size_;

    return size();
}

template <class T>
T MYVector<T>::pop_back()
{
    --size_;
    return data[size_];
}


template <class T>
void MYVector<T>::erase(Iterator itr)
{
    if (itr < begin() || itr >= end())
        throw out_of_range("Iterator out of range");

    int pos = itr - begin();

    --size_;
    for (int i{ pos }; i < size(); ++i)
        data[i] = data[i + 1];

}

template <class T>
void MYVector<T>::erase(Iterator first, Iterator last)
{
    if (first < begin() || first >= end())
        throw out_of_range("Iterator out of range");

    if (last < begin() || last >= end())
        throw out_of_range("Iterator out of range");

    if (first <= last)
    {
        int pos = first - begin();
        int diff = last - first + 1;

        size_ -= diff;
        for (int i{ pos }; i < size(); ++i)
        {
            data[i] = data[i + diff];
        }
    }
}


template <class T>
void MYVector<T>::clear()
{
    delete[] data;
    size_ = 0;
}

template <class T>
void MYVector<T>::insert(Iterator itr, T value)
{
    if (itr < begin() || itr > end())
        throw out_of_range("Iterator out of range");

    Iterator old_begin = begin();

    if (size() == capacity())
        resize();

    int pos = itr - old_begin;

    for (int i{ size() }; i > pos; --i)
        data[i] = data[i - 1];

    data[pos] = value;
    ++size_;
}

template <class T>
Iterator MYVector<T>::begin() const
{
    return data;
}

template <class T>
Iterator MYVector<T>::end() const
{
    return data + size();
}


template <class T>
bool MYVector<T>::operator==(const MYVector<T>& other) const 
{
    if (size() != other.size())
        return false;

    for (int i{ 0 }; i < size(); ++i)
        if (data[i] != other.data[i])
            return false;

    return true;
}

template <class T>
bool MYVector<T>::operator<(const MYVector<T>& other) const
{
    if (size() != other.size())
        return size() < other.size();

    for (int i{ 0 }; i < size(); ++i)
        if (data[i] != other.data[i])
            return data[i] < other.data[i];

    return false;
}

template <class T>
int MYVector<T>::size() const { return size_; }

template <class T>
int MYVector<T>::capacity() const { return capacity_; }

template <class T>
bool MYVector<T>::empty() const { return (size_ == 0); }

template <class T>
int MYVector<T>::resize()
{
    capacity_ = static_cast<int>(ceil(capacity() * 1.5));

    T* newData = new T[capacity()]{};

    for (int i{ 0 }; i < size(); ++i)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    newData = nullptr;

    return capacity();
}


template class MYVector<string>;
template class MYVector<double>;
template class MYVector<int>;
template class MYVector<long long>;
template class MYVector<char>;
template class MYVector<string*>;
template class MYVector<double*>;
template class MYVector<int*>;
template class MYVector<long long*>;
template class MYVector<char*>;
