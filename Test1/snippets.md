# Снипети от Контролно 1

### Задача 1

```c++
class Person {
public:
    std::string name;
    Person(std::string n) : name(std::move(n)) {}
    void print() const {
        std::cout << name << std::endl;
    }
};

int main() {
    std::string n = "Alice";

    Person p1(n);
    Person p2(std::move(n));

    std::cout << "n: " << n << std::endl;
    std::cout << "p1: "; p1.print();
    std::cout << "p2: "; p2.print();
}
```

Отговор:
```
n:
p1: Alice
p2: Alice
```

---

### Задача 2

```c++
class Log {
    std::string name;

public:
    Log(std::string n) : name(std::move(n)) {
        std::cout << "open" << "\n";
    }

    ~Log() { std::cout << "close " << "\n"; }

    void info(const std::string &m) {
        std::cout << name << ": " << m << "\n";
    }
};

int main() {
    {
        Log l("app");
        l.info("hi");
    }
    std::cout << "end\n";
}
```

Отговор:
```
open
app: hi
close
end
```

---

### Задача 3

```c++
class MyClass {
public:
    MyClass() = default;
    MyClass(const MyClass&) = delete;
    MyClass& operator=(const MyClass&) = delete;
};

int main() {
    MyClass a;
    std::cout << "before\n";
    MyClass b = a;
    std::cout << "done\n";
}
```

Отговор:
```c++
Compilation error when envokig copy constructor // MyClass b = a;
```

---

### Задача 4

```c++
class Student {
public:
    std::string name;
    Student(std::string n) : name(std::move(n)) {
        std::cout << "ctor " << name << "\n";
    }

    Student(const Student& o) : name(o.name) {
        std::cout << "copy " << name << "\n";
    }
};

int main() {
    std::vector<Student> v;
    v.emplace_back("Ivan");
    v.push_back(v[0]);
}
```

Отговор:
```c++
ctor Ivan
copy Ivan
copy Ivan
```

---

### Задача 5

```c++
class Engine {
public:
    Engine() { cout << "Engine\n"; }
};

class Car {
    Engine e;
public:
    Car() { cout << "Car\n"; }
};

int main() {
    Car c;
}
```

Отговор:
```c++
Engine
Car
```

---

### Задача 6

```c++
struct Cmp {
    int v;
    auto operator<=>(const Cmp& o) const = default;
};

int main() {
    Cmp a{1}, b{1};
    std::cout << (a == b) << " " << (a < b) << "\n";
}
```

Отговор:
```c++
1 0
```

---

### Задача 7

```c++
class A {
public:
    A() { std::cout << "A()\n"; }
    A(const A&) { std::cout << "A(copy)\n"; }
};

void foo(A a) { std::cout << "in foo\n"; }

int main() {
    A a;
    foo(a);
}
```

Отговор:
```c++
A()
A(copy)
in foo
```

---

### Задача 8

```c++
class A {
    int number = 5;
public:
    A(int i) : number(i) {}
};

int main() {
    A* arr = new A[3];
    for (int i = 0; i < 3; i++) {
        std::cout << arr[i].number;
    }
    delete[] arr;
}
```

Отговор:
```c++
Compilation error // no default constructor A()
```

---

### Задача 9

```c++
class MyString {
public:
    MyString() { cout << "default\n"; }
    MyString(const MyString&) { cout << "copy\n"; }
    MyString(MyString&&) { cout << "move\n"; }
};

int main() {
    MyString a;
    MyString b = a;
    MyString c = std::move(b);
}
```

Отговор:
```
default
copy
move
```

---

### Задача 10

```c++
class T {
public:
    T() { cout << "ctor\n"; }
    T(const T&) { cout << "copy\n"; }
    T(T&&) { cout << "move\n"; }
};

T foo() {
    T t;
    return t;
}

int main() {
    T x = foo();
}
```

Отговор:
```
ctor
```

---

### Задача 11

```c++
class Resource {
    int* data;
public:
    Resource() {
        data = new int(10);
        cout << "Constructor\n";
    }

    Resource(const Resource& other) {
        data = new int(*other.data);
        cout << "Copy constructor\n";
    }

    Resource(Resource&& other) {
        data = other.data;
        other.data = nullptr;
        cout << "Move constructor\n";
    }

    ~Resource() {
        cout << "Destructor\n";
        delete data;
    }
};

int main() {
    Resource a;
    Resource b = a;
}
```

Отговор:
```
Constructor
Copy constructor
Destructor
Destructor
```

---

### Задача 12

```c++
class Item {
    int id;
public:
    Item(int id = -1) : id(id) {
        cout << "ctor " << id << "\n";
    }

    ~Item() { cout << "dtor " << id << "\n"; }
};

int main() {
    Item arr[3] = { Item(0), Item(1), Item(2) };
    cout << "Inside main\n";
}
```

Отговор:
```
ctor 0
ctor 1
ctor 2
Inside main
dtor 2
dtor 1
dtor 0
```