# Теоретични въпроси

---
### 1. Какво ще изведе следният код?

```c++
class Product {
  char name[20]{};
  double price = 0;
};

int main() {
  Product product;
  std::cout<<product.price;
  return 0;
}
```
---

### 2. Кои от следните извиквания на функции са възможни?

```c++
class A {
public:
    void f() {}
    void f() const {}
    void g() const {
        f();
    }
    void t() {}
};

void testFunc1(const A* ptr) {
    if (!ptr) {
        return;
    }
    ptr->f();
}

void testFunc2(const A& ref){
    ref.t();
}

int main(){
    A obj;
    obj.f();
    testFunc1(&obj);
    obj.g();
    testFunc2(obj);
    return 0;
}
```

---

### 3. Какво ще се изведе на стандартния изход след изпълнение на следния код?

```c++
class X {
	char ch = 'a';

public:
	X() {
		std::cout << "X()" << std::endl;
	}

	X(char ch) : ch(ch) {
		std::cout << "X(char)" << std::endl;
	}

	~X() {
		std::cout << "~X()" << std::endl;
	}
};

class Y{
public:

	Y() {
		std::cout << "Y()" << std::endl;
	}

	~Y() {
		std::cout << "~Y()" << std::endl;
	}
};

int main() {
	Y* ptr = new Y[2]{};
	X obj = 'a';
	Y arr[3]{};

	delete[] ptr;
	return 0;
}
```

---

### 4. Какво ще се изведе на стандартния изход след изпълнение на следния код?

```c++
class C {
	double d;
public:

	C() {
		d = 3.14;
		std::cout << "C()" << std::endl;
	}

	C(double d) {
		this->d = d;
		std::cout << "C(double d)" << std::endl;
	}

	~C() {
		std::cout << "~C()" << std::endl;
	}
};

void f(C obj) {
	std::cout << "f(C obj)" << std::endl;
}

int main() {
	C obj;
	f(5.12);

	return 0;
}
```

---

### 5. Какво ще се отпечата?

```c++
struct C {
	double d;

	C(double d) {
    		this->d = d;
    		std::cout << "C(double d)" << std::endl;
	}

	~C() {
    		std::cout << "~C()" << std::endl;
	}
};


int main() {
	C arr[2];
	C* ptr = new C[1];

	delete[] ptr;
}
```

---

### 6. Какво ще се изведе на стандартния изход след изпълнение на следния код?

```c++
class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}

	~A() {
		std::cout << "~A()" << std::endl;
	}
};

class B {
	A a;
public:
	B() {
		std::cout << "B()" << std::endl;
	}
	~B() {
		std::cout << "~B()" << std::endl;
	}
};

class C {
	A a;
	B b;
public:
	C() : b(), a() {
		std::cout << "C()" << std::endl;
	}
	~C() {
		std::cout << "~C()" << std::endl;
	}
};

int main() {
	C arr1[2];
	C* ptr = new C();
	return 0;
}
```

---

### 7. Какво ще се изведе на стандартния изход?

```c++
class Base {
public:
	Base() {
		std::cout << "Base()" << std::endl;
	}

	~Base() {
		std::cout << "~Base()" << std::endl;
	}
};

class Derived {
	Base b;
public:
	Derived() {
		std::cout << "Derived()" << std::endl;
	}

	~Derived() {
		std::cout << "~Derived()" << std::endl;
	}
};

int main() {
	{
		Derived d;
	}
	return 0;
}
```

---

### 8. Как передават стойности методите и какво ще се отпечата?

```c++
class Counter {
	int count = 0;
public:
	Counter() {
		std::cout << "Counter()" << std::endl;
	}

	Counter(int c) : count(c) {
		std::cout << "Counter(int)" << std::endl;
	}

	~Counter() {
		std::cout << "~Counter()" << std::endl;
	}
};

void test(Counter c) {
	std::cout << "test()" << std::endl;
}

int main() {
	Counter c1;
	test(c1);
	test(5);
	return 0;
}
```

---

### 9. Какво ще се случи при компилиране на следния код?

```c++
class Data {
	int value;
public:
	Data() : value(0) {}

	void setValue(int v) {
		value = v;
	}

	void display() const {
		std::cout << value << std::endl;
		setValue(10);
	}
};

int main() {
	Data d;
	d.display();
	return 0;
}
```

---

### 10. Какво ще се отпечата?

```c++
class Engine {
public:
	Engine() {
		std::cout << "Engine created" << std::endl;
	}
	~Engine() {
		std::cout << "Engine destroyed" << std::endl;
	}
};

class Wheels {
public:
	Wheels() {
		std::cout << "Wheels created" << std::endl;
	}
	~Wheels() {
		std::cout << "Wheels destroyed" << std::endl;
	}
};

class Car {
	Engine e;
	Wheels w;
public:
	Car() {
		std::cout << "Car created" << std::endl;
	}
	~Car() {
		std::cout << "Car destroyed" << std::endl;
	}
};

int main() {
	Car car;
	return 0;
}
```

---

### 11. Какво е неправилното в следния код?

```c++
class Point {
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}

	Point getCopy() const {
		return *this;
	}

	void modify() const {
		x = 10;
		y = 20;
	}
};

int main() {
	Point p(5, 5);
	p.modify();
	return 0;
}
```

---

### 12. Какво ще се отпечата?

```c++
class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}

	~A() {
		std::cout << "~A()" << std::endl;
	}
};

void test(A a) {
	std::cout << "in test" << std::endl;
}

int main() {
	A obj;
	test(obj);
	return 0;
}
```

---

### 13. Какво ще се изведе на стандартния изход?

```c++
class Number {
	int value;
public:
	Number() : value(0) {
		std::cout << "Default" << std::endl;
	}

	Number(int v) : value(v) {
		std::cout << "Param: " << v << std::endl;
	}

	Number(double v) : value((int)v) {
		std::cout << "Double: " << v << std::endl;
	}
};

int main() {
	Number n1;
	Number n2(5);
	Number n3(5.5);
	Number n4 = 7;
	return 0;
}
```

---

### 14. Какво е проблемът при компилиране?

```c++
class Container {
	int* data;
public:
	Container() : data(new int[10]) {}

	~Container() {
		delete[] data;
	}
};

int main() {
	Container c1;
	Container c2 = c1;
	return 0;
}
```

---

### 15. Какво ще се отпечата?

```c++
class Print {
public:
	Print() {
		std::cout << "Print()" << std::endl;
	}

	~Print() {
		std::cout << "~Print()" << std::endl;
	}
};

Print create() {
	Print p;
	return p;
}

int main() {
	Print p = create();
	return 0;
}
```

---

### 16. Какво ще се случи при следния код?

```c++
class Value {
	int v;
public:
	Value() : v(0) {
		std::cout << "Value()" << std::endl;
	}

	Value(int x) : v(x) {
		std::cout << "Value(int)" << std::endl;
	}

	~Value() {
		std::cout << "~Value()" << std::endl;
	}
};

int main() {
	Value arr[3] = {Value(1), Value(2), Value(3)};
	return 0;
}
```

---

### 17. Какво ще се отпечата и защо?

```c++
class A {
	int value;
public:
	A(int v = 5) : value(v) {
		std::cout << "A(" << v << ")" << std::endl;
	}
	~A() {
		std::cout << "~A(" << value << ")" << std::endl;
	}
};

int main() {
	A obj;
	A* ptr = new A(10);
	delete ptr;
	return 0;
}
```

---

### 18. Обяснeте проблемът:

```c++
class Container {
	int* arr;
	int size;
public:
	Container(int s) : size(s) {
		arr = new int[size];
	}

	void printSize() const {
		std::cout << "Size: " << size << std::endl;
		size = 0;
	}
};

int main() {
	Container c(10);
	c.printSize();
	return 0;
}
```

---

### 19. Какво ще се изведе на стандартния изход?

```c++
struct Engine {
    int capacity;
    int horsepower;

    Engine() {
        std::cout << "Engine()" << '\n';
    }

    ~Engine() {
        std::cout << "~Engine()" << '\n';
    }
}

struct Tyre {
    char* manufacturer;
    int size;

    Tyre() {
        std::cout << "Tyre()" << '\n';
    }

    Tyre(int size) {
        std::cout << "Tyre(" <<size << ")" << '\n';
    }

    ~Tyre() {
        std::cout << "~Tyre()" << '\n';
    }
}

class Car{
    Engine engine;
    Tyres[4] tyres;

    Car() : tyres(new Tyre(16)), engine()
}
---

### 20. Кои функции ще бъдат викани и в какъв ред?

```c++
struct A {
    int num;

    A() {
        std::cout << "A()" << '\n';
    }

    ~A() {
        std::cout << "~A()" << '\n';
    }
}

struct B {
    char ch;

    B() {
        std::cout << "B()" << '\n';
    }

    ~B() {
        std::cout << "~B()" << '\n';
    }
}

struct C {
    A a;

    C() {
        std::cout << "C()" << '\n';
    }

    ~C() {
        std::cout << "~C()" << '\n';
    }
}

struct D {
    B b;
    C c;
    A a;

    D() {
        std::cout << "D()" << '\n';
    }

    ~D() {
        std::cout << "~D()" << '\n';
    }
}

int main() {
    D d;
}
```