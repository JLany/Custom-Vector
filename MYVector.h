#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

#define Iterator T*

template <class T>
class MYVector {
    // friends
    friend std::ostream& operator<<(std::ostream& os, const MYVector<T>& vec)
    {
        for (int i{ 0 }; i < vec.size(); ++i)
            os << vec.data[i] << " ";

        return os;
    }

public:
    // Constructors and Big 4
    MYVector(int); // Initialize by specific capacity
    // No content is added, size = 0
    // Assign a default size value

    MYVector(T*, int n); // Initialize by n items from array
    MYVector(const MYVector&); // Initialize with a copy
    ~MYVector(); // Delete allocated memory

    const MYVector<T>& operator=(const MYVector<T>&); // Copy assignment
    const MYVector<T>& operator=(MYVector<T>&&) noexcept; // Move assignment

    // Access operations
    T& operator[](int); // Access item by reference
    const T& operator[](int) const;
    // Throw an exception if out of range

    // Modifying operations
    int push_back(T); // Add item to end of vec & return # of items
    // Increase capacity of needed

    T pop_back(); // Remove and return last element in vec

    void erase(Iterator); // Remove item at Iterator
    // Throw exception if invalid iter
    void erase(Iterator, Iterator); // Remove items between
    // Iterator 1 <= Iterator 2 otherwise do nothing
    // Throw exception if any Iterator outside range

    void clear(); // Delete all vector content
    void insert(Iterator, T); // Insert item at Iterator
    // Throw exception if invalid

    // Iterators // Supports *, + and ++ operations at least
    // Can use: typedef T* Iterator
    // Or u can use std::Iterator so you can
    // apply STL algorithms on MYVector
    Iterator begin() const; // Return an Iterator (T*)
    Iterator end() const; // Return an Iterator (T*)

    // Comparison operations
    bool operator==(const MYVector<T>&) const; // Return true if ==
    bool operator<(const MYVector<T>&) const; // Compares item by item
    // Return true if first different item in this is < in other

    // Capacity operations
    int size() const; // Return current size of vec
    int capacity() const; // Return size of current allocated array
    bool empty() const; // Return true if size is 0
    int resize(); // Relocate to bigger space

private:
    T* data;
    int size_;
    int capacity_;
};

#endif // MYVECTOR_H