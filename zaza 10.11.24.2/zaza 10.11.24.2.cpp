#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    T* arr;
    int front;
    int rear;
    int capacity;
    int size;

    void resize() {
        int newCapacity = capacity * 2;
        T* newArr = new T[newCapacity];

        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[(front + i) % capacity];
        }

        delete[] arr;

        arr = newArr;
        front = 0;
        rear = size;
        capacity = newCapacity;
    }

public:
    Queue(int initCapacity = 10) {
        capacity = initCapacity;
        arr = new T[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(const T& value) {
        if (size == capacity) {
            resize();
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }

        T value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    bool isEmpty() const {
        return size == 0;
    }

    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return arr[front];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    return 0;
}
