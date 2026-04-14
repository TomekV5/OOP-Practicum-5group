#include <iostream>
#include "Vector.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

void testQueue() {
    std::cout << "=== QUEUE TEST (FIFO) ===\n";

    Queue<int> q;

    std::cout << "Empty: " << q.empty() << std::endl;

    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Size: " << q.Size() << std::endl;

    std::cout << "Front: " << q.front() << std::endl; // 10
    std::cout << "Back: " << q.back() << std::endl;   // 30

    q.pop(); // ???? 10

    std::cout << "After pop:\n";
    std::cout << "Front: " << q.front() << std::endl; // 20
    std::cout << "Size: " << q.Size() << std::endl;

    q.pop();
    q.pop();

    std::cout << "Empty after removing all: " << q.empty() << std::endl;
}

void testStack() {
    std::cout << "\n=== STACK TEST (LIFO) ===\n";

    Stack<int> s;

    std::cout << "Empty: " << s.empty() << std::endl;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Size: " << s.Size() << std::endl;

    std::cout << "Top: " << s.top() << std::endl; // 30

    s.pop(); // ???? 30

    std::cout << "After pop:\n";
    std::cout << "Top: " << s.top() << std::endl; // 20
    std::cout << "Size: " << s.Size() << std::endl;

    s.pop();
    s.pop();

    std::cout << "Empty after removing all: " << s.empty() << std::endl;
}
int main()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.insert(2, 66);
    std::cout << "Hello World!\n";;
    for (size_t i = 0; i < v.Size(); i++) {
        std::cout << v[i]<<std::endl;
    }
    std::cout << "Hello World!\n";;
    v.erase(2);
    for (size_t i = 0; i < v.Size(); i++) {
        std::cout << v[i] << std::endl;
    }
    std::cout << v.begin() << std::endl;
    std::cout << v.end() << std::endl;

    testQueue();
    testStack();

}