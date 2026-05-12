# Шаблони

Функция/клас, която работи не с променливи от някакъв дефиниран тип, а с абстрактни променливи, се нарича шаблонна функция/клас

#### Защо да използваме шаблони
 - Писане на по-малко код, позволявайки една написана функция да работи с много различни типове
 - Може да бъде специализирана за определен тип данни
 - Всички STL контейневи и алгоритми като std::vectort, std::sort, и др. се основават на този принцип.

---

```c++
template <class T>
T sum(const T& a, const T& b)
{
    return a + b;
}

int main()
{
    int a = 4;
    int b = 9;
    cout << sum<int>(a, b) << endl;

    double c = 3.14;
    double d = 4.5;
    cout << sum<double>(c,d) << endl;

    return 0;
}
```

Компилаторът генерира т. нар. шаблонна функция, като замества параметрите на шаблона с типовете на съответните фактически параметри.

---

## Видове шаблони

#### 1.Шаблонни функции

```c++
template <typename T> T myMax(T x, T y){
    return (x > y) ? x : y;
}

int main(){

    cout << myMax<int>(3, 7) << endl;
    cout << myMax<double>(3.0, 7.0) << endl;
    cout << myMax<char>('g', 'e');
    return 0;
}
```

---

#### 2. Шаблонни класове

```c++
template <typename T> class Geek{
  public:
    T x;
    T y;

    Geek(T val1, T val2) : x(val1), y(val2){
    }

    void printValues(){
        cout << x << " " << y;
    }
};

int main(){
    Geek<int> intGeek(10, 20);
    Geek<double> doubleGeek(3.14, 6.28);
    intGeek.printValues();
    cout << endl;
    doubleGeek.printValues();
    return 0;
}
```

---

При реализация на шаблонен клас е важно да се помисли дали има необходими функции, без които този клас няма да може да бъде компилиран.

```c++
class A{
    char* name;
    int a;
}

template <typename T> class B{
    T a;
    T b;

    int compare() {
        if (a == b)
            return 0;
        return a > b ? 1 : -1;
    }
}

int main() {
    B<A> var;
    var.compare(); // Нямаме предефиниран оператор> в класа А
}
```

---

#### Специализация при шаблони
Специализацията ни позволява различна имплементация на шаблон за кокретен тип или форма на тип.

---

### Variadic templates
Това е механизъм, който ни позволява да примаме неограничен брой параметри

```c++
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
    cout << var1 << endl;

    print(var2...);
}
```

---

### std::tuple
Контейнер, който може да съдържа даден брой параметри и те могат да бъдат различен тип
```c++
    tuple<char, int, float> geek;
    geek = make_tuple('a', 10, 15.5);

    cout << get<0>(geek) << " " << get<1>(geek);
    cout << " " << get<2>(geek) << endl;

    get<0>(geek) = 'b';
    get<2>(geek) = 20.5;

    cout << get<0>(geek) << " " << get<1>(geek);
    cout << " " << get<2>(geek) << endl;
```