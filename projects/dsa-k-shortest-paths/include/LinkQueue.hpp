#pragma once

#include <iostream>
#include "LinkStack.hpp"

template <class T>
class LinkQueue {
private:
    DNode<T>* front;
    DNode<T>* back;
    int length;

public:
    LinkQueue() {
        front = new DNode<T>;
        front->next = nullptr;
        back = front;
        length = 0;
    }

    ~LinkQueue() {
        while (front != nullptr) {
            back = front;
            front = front->next;
            delete back;
        }
    }

    int getLength() const {
        return length;
    }

    bool isEmpty() const {
        return length == 0;
    }

    void enQueue(T x) {
        DNode<T>* tmpN = new DNode<T>;
        tmpN->data = x;
        tmpN->next = nullptr;
        back->next = tmpN;
        back = tmpN;
        length++;
    }

    T deQueue() {
        if (length == 0) throw "Queue Empty!";
        DNode<T>* tmpN = front->next;
        front->next = tmpN->next;
        T tmpD = tmpN->data;
        delete tmpN;
        length--;
        if (length == 0) back = front;
        return tmpD;
    }

    T peekQueue() const {
        if (length == 0) throw "Queue Empty!";
        return front->next->data;
    }

    void printQueue() const {
        std::cout << "Front of queue: ";
        DNode<T>* tmp = front->next;
        while (tmp != nullptr) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << ": back of queue" << std::endl;
    }
};
