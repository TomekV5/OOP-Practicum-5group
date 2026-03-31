# Теоретични въпроси

За следващите задачи ще използваме
```c++
class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	A(const A& other)
	{
		std::cout << "K.K A()" << std::endl;
	}

    A(A&& other) {
        std::cout << "M.K A()" << std::endl;
    }

	A& operator=(const A& other)
	{
		std::cout << "OP= A()" << std::endl;
		return *this;
	}

    A& operator=(A&& other) {
        std::cout << "MOP= A()" << std::endl;
        return *this;
    }

	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

class B
{
public:
	B()
	{
		std::cout << "B()" << std::endl;
	}

	B(const B& other)
	{
		std::cout << "K.K B()" << std::endl;
	}

    B(B&& other) {
        std::cout << "M.K B()" << std::endl;
    }

	B& operator=(const B& other)
	{
		std::cout << "OP= B()" << std::endl;
		return *this;
	}

    B& operator=(B&& other) {
        std::cout << "MOP= B()" << std::endl;
        return *this;
    }

	~B()
	{
		std::cout << "~B()" << std::endl;
	}
};
```

---

### Задача 1: Какво ще се отпечата на конзолата?

```c++
class X
{
private:
	A obj1;
	B& obj2;

public:
	X(const A& a, B& b) : obj2(b)
	{
		obj1 = a;
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		std::cout << "~X()" << std::endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	X obj(obj1, obj2);

	return 0;
}
```

---

### Задача 2: Какво ще се изведе на конзолата?

```c++
class X
{
private:
	A* obj1;
	B& obj2;

public:
	X(const A& a, B& b) : obj2(b)
	{
		obj1 = new A();
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		delete obj1;
		std::cout << "~X()" << std::endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	X obj(obj1, obj2);

	return 0;
}
```

---

### Задача 3: Какво ще се изведе на конзолата?

```c++
class X
{
private:
	A* obj1;
	B obj2;

public:
	X(const A& a, B& b) : obj2(b)
	{
		obj1 = new A(a);
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		delete obj1;
		std::cout << "~X()" << std::endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	X obj(obj1, obj2);

	return 0;
}
```

### Задача 4: Какво ще се изведе на конзолата?

```c++
class X
{
private:
	A* obj1;
	B& obj2;

public:
	X(const A& a, B* b) : obj1(new A(a)), obj2(*b)
	{
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		delete obj1;
		std::cout << "~X()" << std::endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	X obj(obj1, &obj2);

	return 0;
}
```

### Задача 5: Какво ще се изведе на конзолата?

```c++
class Wrapper {
public:
    A a;

    Wrapper(A param) : a(param) {}
};

int main() {
    A a1;
    Wrapper w(a1);
}
```

---

### 6. Какво ще се изведе на стандартния изход?

```c++
A make() {
    A temp;
    return temp;
}

int main() {
    A a1 = make();
    A a2 = std::move(a1);
}
```

---

### 7. Какво ще се изведе на конзолата?

```c++
int main() {
    A a1;
    A a2;
    A a3;

    a3 = a2 = A();
}
```

---

### 8. Какво ще се изведе на конзолата?

```c++
A func(A a) {
    return a;
}

int main() {
    A a1;
    A a2 = func(a1);
}
```

---

### 9. Какво ще се изведе на конзолата?

```c++
class C {
public:
    A a;
    friend class D;
};

class D {
public:
    C process(C c) {
        return c;
    }
};

int main() {
    C c1;
    D d;

    C c2 = d.process(c1);
}
```

---

### 10. Какво ще се изведе на конзолата?

```c++
class C {
public:
    A a;
    friend class D;
};

class D {
public:
    C process(C c) {
        return c;
    }
};

int main() {
    C c1;
    D d;

    C c2 = d.process(c1);
}
```

---

### 11. Какво ще се изведе на конзолата?

```c++
class C {
public:
    A a;

    C operator+(const C& other) {
        return C();
    }
};

int main() {
    C c1, c2, c3;

    c3 = c1 + c2;
}
```

---

### 12. Какво ще се изведе на конзолата?

```c++
A&& func() {
    return A();
}

int main() {
    A a = func();
}
```

---

### 13. Какво ще се изведе на конзолата?

```c++
A&& func(A&& a) {
    return std::move(a);
}

A create() {
    A temp;
    return temp;
}

int main() {
    A a = func(create());
}
```

---

### 14. Какво ще се изведе на конзолата?

```c++
A makeA() {
    return A();
}

int main() {
    A a1;
    A a2;

    a1 = makeA();
    a2 = a1 = makeA();
}
```

---

### 15. Какво ще се изведе на конзолата?

```c++
class X {
private:
    A a;
    B b;
public:
    X() {
        std::cout << "X()\n";
    }

    X(const X&) = delete;

    X(X&&) {
        std::cout << "M.K X()\n";
    }

    X& operator=(X&&) {
        std::cout << "MOP= X()\n";
        return *this;
    }

    ~X() {
        std::cout << "~X()\n";
    }
};

void takeByValue(X x) {
    std::cout << "inside takeByValue\n";
}

X create() {
    X x;
    return x;
}

int main() {
    X x1;
    X x2 = std::move(x1);
    takeByValue(x2);
    X x3 = create();
}
```

---

### 16. Какво ще се изведе на конзолата?

```c++
class X {
public:
    X() {
        std::cout << "X()\n";
    }

    X(const X&) = delete;

    X(X&&) {
        std::cout << "M.K X()\n";
    }

    X& operator=(X&&) {
        std::cout << "MOP= X()\n";
        return *this;
    }

    ~X() {
        std::cout << "~X()\n";
    }
};

X make() {
    X x;
    return x;
}

void take(X x) {
    X temp;
    temp = std::move(x);
}

int main() {
    X a1;

    X a2 = make();

    take(std::move(a2));

    X a3;
    a3 = std::move(a1);
}
```

---

### 17. Какви бихте подобрили в този клас? Има ли нещо невярно?

```c++
class X{
private:
    int* a;
    int size;
    int capacity;
public:
    X(int cap) : size(0), capacity(cap) {
        a = new int[capacity];
    }

    X(const X& other) : size(other.size), capacity(other.capacity), a(other.a) { }

    X(X&& other) : size(other.size), capacity(other.capacity), a(other.a) { }

    X& operator=(X&& other) {
        if (this != &other) {
            size = other.size;
            capacity = other.capacity;
            a = other.a;
        }
        return *this;
    }

    X& operator=(const X& other) {
        if (this != &other) {
            size = other.size;
            capacity = other.capacity;
            a = new int[capacity];
            for (int i = 0; i < size; ++i) {
                a[i] = other.a[i];
            }
        }
        return *this;
    }

    ~X() {
        delete[] a;
    }
}
```

---

### 18. Какво ще се отпечата и извика?

```c++
class Wrapper {
    int a;
public:
    Wrapper(int a) : a(a) {}

    Wrapper operator+(const Wrapper& other) {
        std::cout << "Wrapper + Wrapper called" << std::endl;
        return Wrapper(this->a + other.a);
    }

    Wrapper operator+(int num) {
        std::cout << "Wrapper + int called" << std::endl;
        return Wrapper(this->a + num);
    }

    int getValue() const {
        return a;
    }
};

int main() {
    int num = 5;
    Wrapper w1(10);
    Wrapper w2(20);

    Wrapper w3 = w1 + w2;
    Wrapper w4 = w1 + num;
    Wrapper w5 = num + w1.getValue();
    Wrapper w6 = w1.getValue() + num;;
    return 0;
}
```

---

### 19. Има ли проблем в този клас?

```c++
class X {
private:
    int* a;
    int size;

public:
    X(int n) : size(n) {
        a = new int[n];
    }

    X& operator=(X&& other) {
        if (this != &other) {
            a = other.a;
            size = other.size;
        }
        return *this;
    }

    ~X() {
        delete[] a;
    }
};
```

---

### 20. Има ли проблем в този клас?

```c++
class X {
private:
    int* a;
    int size;
    int capacity;

public:
    X(int cap = 0) : a(cap ? new int[cap] : nullptr), size(0), capacity(cap) { }

    ~X() {
        delete[] a;
    }

    X(const X& other) : a(other.capacity ? new int[other.capacity] : nullptr), size(other.size), capacity(other.capacity) {
        for (int i = 0; i < size; ++i)
            a[i] = other.a[i];
    }

    X& operator=(const X& other) {
        if (this == &other)
            return *this;

        int* newData = other.capacity ? new int[other.capacity] : nullptr;

        for (int i = 0; i < other.size; ++i)
            newData[i] = other.a[i];

        delete[] a;

        a = newData;
        size = other.size;
        capacity = other.capacity;

        return *this;
    }

    X(X&& other) : a(other.a)size(other.size), capacity(other.capacity)
    {
        other.a = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    X& operator=(X&& other) {
        if (this == &other)
            return *this;

        delete[] a;

        a = other.a;
        size = other.size;
        capacity = other.capacity;

        other.a = nullptr;
        other.size = 0;
        other.capacity = 0;

        return *this;
    }

    void print() const {
        for (int i = 0; i < size; ++i)
            std::cout << a[i] << " ";
        std::cout << "\n";
    }
};
```