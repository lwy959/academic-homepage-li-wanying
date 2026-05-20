#pragma once

#include <iostream>

template <class T>
struct DNode {
    T data;
    DNode<T>* next;
};

template <class T>
class LinkStack {
private:
    DNode<T>* top;
    int length;

public:
    LinkStack() {
        top = nullptr;
        length = 0;
    }

    ~LinkStack() {
        while (top != nullptr) {
            DNode<T>* tmp = top;
            top = top->next;
            delete tmp;
        }
    }

    int getLength() const {
        return length;
    }

    bool isEmpty() const {
        return length == 0;
    }

    void clear() {
        while (!isEmpty()) pop();
    }

    void push(T x) {
        DNode<T>* tmp = new DNode<T>;
        tmp->data = x;
        tmp->next = top;
        top = tmp;
        length++;
    }

    T pop() {
        if (length == 0) throw "Stack Empty!";
        DNode<T>* tmp = top;
        top = top->next;
        T tmpData = tmp->data;
        delete tmp;
        length--;
        return tmpData;
    }

    T getTop() const {
        if (length == 0) throw "Stack Empty!";
        return top->data;
    }

    void printStack() const {
        std::cout << "Stack top: ";
        DNode<T>* tmp = top;
        while (tmp != nullptr) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << ":stack bottom" << std::endl;
    }
};
