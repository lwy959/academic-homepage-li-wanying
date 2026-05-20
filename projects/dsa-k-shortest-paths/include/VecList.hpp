#pragma once

#include <iostream>

template <class T>
class VecList {
private:
    int capacity;
    int length;
    T* arr;

    void doubleListSize() {
        T* oldArr = arr;
        arr = new T[2 * capacity];
        capacity = 2 * capacity;
        for (int i = 0; i < length; i++) {
            arr[i] = oldArr[i];
        }
        delete[] oldArr;
    }

public:
    VecList() {
        length = 0;
        capacity = 100;
        arr = new T[capacity];
    }

    VecList(T* a, int n) {
        length = n;
        capacity = 100 + 2 * n;
        arr = new T[capacity];
        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
        }
    }

    VecList(const VecList<T>& other) : capacity(other.capacity), length(other.length), arr(new T[other.capacity]) {
        for (int i = 0; i < other.length; i++) {
            arr[i] = other.arr[i];
        }
    }

    VecList<T>& operator=(const VecList<T>& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            length = other.length;
            arr = new T[capacity];
            for (int i = 0; i < length; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    bool operator==(const VecList<T>& other) const {
        if (length != other.length) return false;
        for (int i = 0; i < length; i++) {
            if (arr[i] != other.arr[i]) return false;
        }
        return true;
    }

    ~VecList() {
        delete[] arr;
    }

    bool contains(const T& element) const {
        for (int i = 0; i < length; i++) {
            if (arr[i] == element) return true;
        }
        return false;
    }

    int getLength() const {
        return length;
    }

    bool isEmpty() const {
        return length == 0;
    }

    void clear() {
        length = 0;
    }

    void insertEleAtPos(int i, T x) {
        if (length == capacity) doubleListSize();
        if (i > length || i < 0) throw "Illegal position";
        for (int j = length; j > i; j--) {
            arr[j] = arr[j - 1];
        }
        arr[i] = x;
        length++;
    }

    T deleteEleAtPos(int i) {
        if (i >= length || i < 0) throw "Illegal position";
        T tmp = arr[i];
        for (int j = i; j < length - 1; j++) {
            arr[j] = arr[j + 1];
        }
        length--;
        return tmp;
    }

    void setEleAtPos(int i, T x) {
        if (i >= length || i < 0) throw "Illegal position";
        arr[i] = x;
    }

    T getEleAtPos(int i) const {
        if (i >= length || i < 0) throw "Illegal position";
        return arr[i];
    }

    int locateEle(T x) const {
        for (int i = 0; i < length; i++) {
            if (arr[i] == x) return i;
        }
        return -1;
    }

    void insertLast(T x) {
        insertEleAtPos(length, x);
    }

    void printList() const {
        for (int i = 0; i < length; i++) {
            std::cout << arr[i] << " ";
        }
    }
};
