﻿#include <iostream>
using namespace std;

class DynamicArrayStack
{
private:
    int* ar;
    int capacity;
    int top;

public:

    DynamicArrayStack(int size)
    {
        capacity = size;
        ar = new int[capacity];
        top = -1;
    }

    ~DynamicArrayStack()
    {
        delete[] ar;
    }

    bool IsEmpty() const
    {
        return top == 0;
    }

    bool IsFull() const
    {
        return top == capacity - 1;
    }

    void Push(int value)
    {
        if (IsFull())
        {
            cout << "Stack is full. Imposible to add element\n";
            return;
        }
        ar[++top] = value;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty. Imposible to delete\n";
            return;
        }
        --top;
    }

    int Peek()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        else
            return ar[top];
    }

    bool Contains(int value)
    {
        for (int i = 0; i <= top; ++i)
        {
            if (ar[i] == value)
            {
                return true;
            }
        }
        return false;
    }

    void Print() {
        if (IsEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            cout << ar[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    srand(time(0));
    DynamicArrayStack stack(5);

    while (!stack.IsFull())
        stack.Push(rand() % 90 + 10);

    stack.Print();

    cout << "Top stack: " << stack.Peek() << endl;
    stack.Pop();
    cout << "Top stack after removing an element: " << stack.Peek() << endl;

    int search_value = 44;
    if (stack.Contains(search_value)) {
        cout << "Element " << search_value << " found\n";
    }
    else {
        cout << "Element " << search_value << " not found\n";
    }

    stack.Print();
}