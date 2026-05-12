
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
		std::cout << "C.C A()" << std::endl;
	}

    A(A&& other) {
        std::cout << "M.C A()" << std::endl;
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
```


### 1. Какво ще се отпечата на конзолата

```c++
A f()
{
	return A();
}

int main() 
{
	A a = f();

	return 0;
}
```

### 2. Какво ще се отпечата на конзолата
```c++
A f()
{
	return A();
}

int main() 
{
	A a;
    a = f();

	return 0;
}
```

### 3. Какво ще се отпечата на конзолата
```c++
const A f()
{
	return A();
}

int main() 
{
	A a;
    a = f();

	return 0;
}
```

### 4. Какво ще се отпечата на конзолата
```c++
class B {
	A a;

public:
	void f() {
		std::cout << "f()" << std::endl;
		g();
	}

	void f() const {
		std::cout << "f() const" << std::endl;
	}

	void g() const {
		std::cout << "g()" << std::endl;
		f();
	}
};

int main() 
{
	B b;
	b.g();
	b.f();

	return 0;
}
```

### 5. Какво ще се отпечата на конзолата
```c++
int main()
{
	std::vector<A> v(3);
	v[2] = A();

	return 0;
}
```

### 6. Какво ще се отпечата на конзолата
```c++
struct C
{
	int a;
	char b;

	auto operator<=>(const C& other) const = default;
};

int main()
{
	C c1(10, 'a');
	C c2(5, 'a');
	C c3(10, 'b');

	std::cout << (c1 > c2) << ' ' << (c2 < c3) << ' ' << (c1 == c3);
}
```

### 7. Какво ще се отпечата на конзолата
```c++
class D {
	static int d;

public:
	D() {
		std::cout << "D()" << std::endl;
	}

	~D() {
		std::cout << "~D()" << std::endl;
	}

	void add(int num) {
		d += num;
	}

	static void print() {
		std::cout << d << std::endl;
	}
};

int D::d = 1;

int main() {
	D d1;
	{
		D d2;
		d2.add(4);
		D::print();
	}
	d1.add(3);
	D::print();
}
```

### 8. Какво ще се отпечата на конзолата
```c++
class B {
	int num = 0;

public:
	B() {
		std::cout << "B()" << std::endl;
	}

	B(int num) {
		std::cout << "B(num)" << std::endl;
		this->num = num;
	}

	B(const B& other) {
		std::cout << "C.C B()" << std::endl;
	}

	B(B&& other) noexcept {
		std::cout << "M.C B()" << std::endl;
	}

	B& operator=(const B& other) {
		std::cout << "OP= B()" << std::endl;
		return *this;
	}

	B& operator=(B&& other) noexcept {
		std::cout << "MOP= B()" << std::endl;
		return *this;
	}

	~B() {
		std::cout << "~B()" << std::endl;
	}
};

int main() {
	B b[4]{ B(7) };
	b[2] = 4;
}
```

### 9. Какво ще се отпечата на конзолата
```c++
struct C {
	A a;
	B& b;

	C(A a, B b) : b(b)
	{
		this->a = a;
		std::cout << "C()" << std::endl;
	}

	~C() {
		std::cout << "~C()" << std::endl;
	}
};

int main() {
	A a;
	B b = 3;

	C c(a, b);
}
```

### 10. Какво ще се отпечата на конзолата
```c++
struct C {
	A* a;
	B& b;

	C(A& a, B& b) : b(b)
	{
		this->a = new A(a);
		std::cout << "C()" << std::endl;
	}

	~C() {
		std::cout << "~C()" << std::endl;
	}
};

int main() {
	A a;
	B b = 3;

	C c(a, b);
}
```
### 11. Какво ще се отпечата на конзолата
```c++
struct C {
	A a;
	B b;

	C(A a, B b) : b(b), a(a)
	{
		std::cout << "C()" << std::endl;
	}

	~C() {
		std::cout << "~C()" << std::endl;
	}
};

int main() {
	A a;
	B b = 3;

	C c(a, b);
}
```

### 12. Какво ще се отпечата на конзолата
```c++
class D 
{
    int num;

public:
    D() {
        std::cout << "D()" << std::endl;
        num = 2;
    }
    
    D(int num) {
        std::cout << "D(num)" << std::endl;
        this->num = num;
    }

    D& operator*=(int coef) {
        num *= coef;
        return *this;
    }

    int getNum() const {
        return num;
    }

    ~D() {
        std::cout << "~D()" << std::endl;
    }
};

D operator*(D& obj, int coef) {
    D temp = obj;
    temp *= coef;
    return temp;
}

int DPowerOfTwo()
{
    static D result(3);
    result *= 2;
    return result.getNum();
}

int main()
{
    std::cout << DPowerOfTwo() << std::endl;
    std::cout << DPowerOfTwo() << std::endl;
    std::cout << DPowerOfTwo() << std::endl;
}
```

### 13. Какво ще се отпечата на конзолата
```c++
int main() {
    std::string s = "hello";
    std::string t = std::move(s);
    std::cout << s << " " << t << std::endl;
}
```

### 14. Какво ще се отпечата на конзолата
```c++
int main() {
    std::unique_ptr<A> p1 = std::make_unique<A>();
    std::unique_ptr<A> p2 = std::move(p1);

    if (!p1) std::cout << "empty\n";
}
```

### 15. Какво ще се отпечата на конзолата
```c++
struct E {
	std::unique_ptr<A> p;

	E() : p(std::make_unique<A>()) {}

	E(E&& other) noexcept : p(std::move(other.p)) 
	{
		std::cout << "M.C E()" << std::endl;
	}
};

int main() {
	E e1;
	E e2 = e1;
	E e3 = std::move(e1);
}
```
### 16. Какво ще се отпечата на конзолата
```c++
int main() {
    std::shared_ptr<A> p1 = std::make_shared<A>();
    {
        std::shared_ptr<A> p2 = p1;
        std::cout << p1.use_count() << std::endl;
    }
    std::cout << p1.use_count() << std::endl;
}

```
