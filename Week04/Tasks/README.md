# Теоретични въпроси

1. Какво ще се изпринтира на стандартния изход?
```c++
int foo()
{
    static int x = 0;
    return ++x;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << foo() << " ";
    }
}
```

---

2. Какво ще се изпринтира на стандартния изход?
```c++
// Test.cpp
static int foo() { return 42; }
int bar() { return 42; }
```
```c++
// main.cpp
int main()
{
    std::cout << foo() << '\n';
    std::cout << bar() << '\n';
}
```

---

3. Какво ще се изпринтира на стандартния изход?
```c++
class Test
{
public:
    static int x;
};

class AnotherTest
{
    int x;
public:
    static int y;

    static void print()
    {
        std::cout << this->x << std::endl;
        std::cout << x << std::endl;
        std::cout << y << AnotherTest::y << Test::x << std::endl;
    }
}

int Test::x = 42;
int Test::y = 0;

int main()
{
    std::cout << Test::x << std::endl;
    AnotherTest::print();
    AnotherTest::y = 42;
    AnotherTest::print();
}
```
---

4. До кои променливи има достъп f(), a g()?

```c++
class Y
{
private:
        static int x;
        int y;
        int z;

public:
        void f();
        static void g();
}
```

---

5. Какво ще се изпринтира на стандартния изход?
```c++
#define MULT(a,b) a * b

int main() {
    int x = 2;
    int y = 3;
    int result = MULT(x + 1, y + 2);

    std::cout << result << '\n';
    return 0;
}
```

## Задачи
Представете си, че разработваме система за магазин за дрехи и обувки.

1. Създайте клас **Product**, който да представлява продукт в нашия магазин.

2. Създайте клас **Cart**, който представлява количка в нашия магазин.

3. Създайте клас **Client**, който представлява клиента в нашия магазин.

