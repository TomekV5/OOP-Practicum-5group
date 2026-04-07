# Предефиниране на оператори. Friend функции и класове


## Видове оператори

### 1.Унарни
Унарни оператори са тези оператори, които приемат **един** аргумент.
В езика С++ има 9 унарни оператора
```c++
(++)var(++);    // Increment operator - добавя 1 към var
(--)var(--);    // Decrement operator - изважда 1 от var
+var;           // Unary plus operator - показва, че var е положително
-var;           // Unary minus operator - показва, че var е отрицателно
!var;           // Логическо не - връща отрицанието на var
~var;           // Побитово отрицание - обръща всички битове на var
&var;           // Амперсант - взима адреса на var
*var;           // Звездичка - дереферира var
sizeof(var)     // Взима размера на var като байтове
```

---

### 2.Бинарни
Бинарните оператори са тези оператори, които приемат **два** аргумента.

```c++
// Аритметични оператори
a + b;          // Събиране
a - b;          // Изваждане
a * b;          // Умножение
a / b;          // Целочислено деление
a % b;          // Деление с остатък
```

```c++
// Побитови оператори
a & b;          // Побитово И
a | b;          // Побитово ИЛИ
a ^ b;          // XOR
a << b;         // Отместване наляво
a >> b;         // Отместване надясно
```

```c++
// Логически оператори
a && b;         // Логическо И
a || b;         // Логическо ИЛИ
a == b;         // Равно
a != b;         // Различно
a > b;          // По-голямо
a < b;          // По-малко
a >= b;         // По-голямо или равно
a <= b;         // По-малко или равно
```

### 3.Тернарен
Тернарният оператор приема **три** аргумента. Има един единствен.
```c++
(condition) ? a : b;
// returns a id condition = true
// returns b id condition = false
```

### Кои оператори може да предефинираме в С++?
- Аритметични операции: **%**, **+**, **-**, **\***, **/**
- Унарни оператори: **++**, **--**, **!**
- Логически оператор: **==**, **!=**, **>=**, **<=**, **&&**, **||**
- Присвояващи оператори: **=**, **+=**, ***=**, **/=**, **-=**, **%=**
- Оператор скоби **[ ]**
- Побитови оператори **&**, **|**, **<<**, **>>**, **^**, **~**

### Кои оператори НЕ може да предефинираме в С++?
- Тернарния оператор: **?:**
- **sizeof**.
- Оператор за резолюция: **::**
- **.**
- **\.\***

---

## Friend classes
Приятелски клас е клас, който има достъп до private и protected функциите и член-данните в даден клас.

```c++
class A {
private:
    int privateVar;
protected:
    int protectedVar;
public:
    friend class Friend;
};

class Friend {
public:
    void display(A& a) {
        cout << "The value of Private Variable = "
             << a.privateVar << endl;
        cout << "The value of Protected Variable = "
             << a.protectedVar;
    }
};

int main() {
    A a;
    Friend fr;
    fr.display(a);
}
```

---

## Friend functions
Това са външни функкции, които имат достъп до private и protected член-данните и функциите в класа.
Приятелските функции могат да са:
- **Глобални**
```c++
class A {
private:
    int privateVar;
protected:
    int protectedVar;
public:
    // Friend function declaration
    friend void friendFunction(base& obj);
};


// friend function definition
void friendFunction(A& obj) {
    cout << "Private Variable: "
         << obj.privateVar << endl;
    cout << "Protected Variable: "
         << obj.protectedVar;
}

int main() {
    A object;
    friendFunction(object);
}
```

- **Като член функции в класа**
```c++
class A {
private:
    int private;
protected:
    int protected;
public:
    friend bool operator==(const A& lhs, const A& rhs);
	friend bool operator!=(const A& lhs, const A& rhs);
};

// Friend functions definition
bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return lhs.private == rhs.private && lhs.protected == rhs.protected;
}

bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return !(lhs == rhs);
}
```