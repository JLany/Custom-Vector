#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iterator>
#include <iostream>

#define iterator T*

template <class T>
class Vector {
    // friends
    friend std::ostream& operator << (std::ostream& out, XYvector<T>);

public:
    // Constructors and Big 4
    Vector(int); // Initialize by specific capacity
    // No content is added, size = 0
    // Assign a default size value

    Vector(T*, int n); // Initialize by n items from array
    Vector(const Vector&); // Initialize with a copy
    ~Vector(); // Delete allocated memory

    const Vector<T>& operator=(const Vector<T>&); // Copy assignment
    const Vector<T>& operator=(const Vector<T>&&); // Move assignment

    // Access operations
    T& operator[](int); // Access item by reference
    const T& operator[](int) const;
    // Throw an exception if out of range

    // Modifying operations
    int push_back(T); // Add item to end of vec & return # of items
    // Increase capacity of needed

    T pop_back(); // Remove and return last element in vec

    void erase(iterator); // Remove item at iterator
    // Throw exception if invalid iter
    void erase(iterator, iterator); // Remove items between
    // iterator 1 <= iterator 2 otherwise do nothing
    // Throw exception if any iterator outside range

    void clear(); // Delete all vector content
    void insert(iterator, T); // Insert item at iterator
    // Throw exception if invalid

    // Iterators // Supports *, + and ++ operations at least
    // Can use: typedef T* iterator
    // Or u can use std::iterator so you can
    // apply STL algorithms on Vector
    iterator begin(); // Return an iterator (T*)
    iterator end(); // Return an iterator (T*)

    // Comparison operations
    bool operator==(const Vector<T>&) const; // Return true if ==
    bool operator<(const Vector<T>&) const; // Compares item by item
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