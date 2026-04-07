# Работа с файлове

Поток (stream) - последователност от байтове данни влизащи в и излизащи от програмата.

![](/FileHandling/resources/streams.png)

Стъпки за работа с поток:
* Създаване на поток
* Свързване с източник/получател на данни (IO устройство)
* Проверка дали потока е отворен
* Работа с потока
* Затваряне и освобождаване на потока

Видове потоци
* входни потоци - istream
* изходни потоци - ostream

![](/FileHandling/resources/hierarchy.png)

Тези потоци се намират във `fstream`

### Основи на потоците
* `istream` има get указател: сочи позиция в потока -> показва откъде ще започне **четенето** при следващата **входна** операция
* `ostream` има put указател: отново, сочи позиция в потока -> показва откъде ще започне **писането** при следващата **изходна** операция
* `istream` има фунцкия `get`, която чете текущия символ и мести get указателя на следващата позиция (абсолютно аналогично за `ostream` и `put` функцията)

#### Позициониране във файл
* **tellg()** - Връща позицията на текущия символ в потока за четене (т.е. връща get)
* **tellp()** - Връща позицията на текущия символ в потока за писане (т.е. връща put)
* **seekg(offset, direction)** - Премества get указателя с **offset** стъпки от **direction** в потока за четене
* **seekg(idx)** - Премества get указателя на позиция idx в потока за четене
* **seekp(offset, direction)** - Премества put указателя с **offset** стъпки от **direction** в потока за писане
* **seekp(idx)** - Премества put указателя на позиция idx в потока за писане
* ignore(n = 1, delim = eof) - Премества get указателя, като прескача следващите n (по подразбиране n = 1) на брой символа или до първото срещане на разделителя **delim** (по подразбиране - краят на файла)
* peek() - Връща следващия символ **без да мести get-указателя**

Възможните стойности за **direction** са:
* std::ios::beg -> сочи началото на файла
* std::ios::curr -> сочи текущата позиция във файла
* std::ios::end -> сочи края на файла

### Примери
Четене от файл
```c++
#include <iostream>
#include <fstream>

int main()
{
   std::ifstream file("preview.txt");

   if (!file.is_open()) { //задължително проверяваме дали файла е отворен
   	return -1;
   }
   
   int a, b;
   file >> a >> b;

   file.close(); // задължително затваряме поток, който сме отворили ние, когато сме приключили работа
}
```

Писане във файл
```c++
#include <iostream>
#include <fstream>

int main()
{
   std::оfstream file("preview.txt");

   if (!file.is_open()) { //задължително проверяваме дали файла е отворен
   	return -1;
   }
   
   int a = 1, b = 2;
   file << a << b;

   file.close(); // задължително затваряме поток, който сме отворили ние, когато сме приключили работа
}
```

Работа със структури
```c++
struct Car {
    char owner[100];
    int price;
};
```
* сериализиране (т.е. да запишем структура във файл)
```c++
std::оfstream file("preview.txt");

   if (!file.is_open()) {
   	return -1;
   }
   
   Car car = {"Pesho", 100};
   file << car.owner << std::endl << car.price;

   file.close();
```

* десериализиране (т.е. да извлечем структура от файл)
```c++
std::ifstream file("preview.txt");

   if (!file.is_open()) {
   	return -1;
   }
   
   Car car;
   file.getline(car.owner, 100);
   file >> car.price;

   file.close();
```

## Двойчни (бинарни) файлове

**Файл** - последователност от байтове (числа от 0 до 255)

До момента разгледахме работа с текстови файлове. Те са много удобни за хората, понеже са разбираеми (всеки може да порчете тескта), също така има newline и други разделители. Това обаче не е най-оптималният запис на данни за процесора - за него най-оптимално е да работи с поток от данни, записан като 0 и 1 (бинарни данни). Затова и понякога се налага да използваме бинарни потоци, за да оптимизираме работата на програмата. 

### Инициализация
* `std::ifstream(<име-на-файл>, std::ios::binary)`
* `std::ofstream(<име-на-файл>, std::ios::binary)`

Единствената разлика с текстовите файлове е, че тук трябва да означим чрез std::ios::binary, че дадения поток ще работи с двойчни данни

### Основни операции
* `read(char* memoryBlock, size_t size)` за `ifstream`
* `write(const char* memoryBlock, size_t size)` за `ostream`

Както можете да видите, двойчните файлове работят с char*. Това се дължи на факта, че `char` в C++ до някаква степен играе ролята на байт (`sizeof(char)` = 1B). Съответно, щом искаме да запазим последователснот от байтове е логично да представим данните си като такива, или в случая - последнователност от `char`-ове.

Съответно, ако искаме да запазим какъвто и да било друг тип, трябва експлицитно да го cast-нем към char* (примери има по-надолу)

`size_t size` ни покава размера/броя байтове, който ще четем/пишем (за разлика от текстовите файлове, където имаме space, newline, тук всичко е представено като последователност от байтове, съответно само по дъжлината можем да разберем къде започва и свършва дадена дума)

## Примери

### Писане
```c++
#include <iostream>
#include <fstream>

int main()
{
   // трявба ни файл, поддържащ бинарни данни, затова разширението е .bin
   std::ofstream ofs("file.bin", std::ios::binary);

   if(!ofs.is_open()) {
       return -1;
   }

   int a = 16;

   //пример за cast-ване към char*
   /* тъй като само пишем съдържанието на a във файл, без да променяме 'a', можем да го считаме за константа, затова и cast-ването е const char*.
   Най-вероятно IDE-то ви ще даде грешка, ако забравите const.
   */
   ofs.write((const char*)&a, sizeof(int));

   ofs.close();
   return 0;
} 
```

### Четене
```c++
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream ifs("file.bin", std::ios::binary);
	
	if(!ifs.is_open()) {
	    return -1;
	}
	
	int a;
        //отново, cast-ваме към char*. Този път обаче, понеже четем от файл и запазваме съдържанието в 'a', то ние променяме съдържанието му, затова няма const
	ifs.read((char*)&a, sizeof(int));

	ifs.close();
	
	return 0;
}
```

### Масиви

#### Четене
```c++
int arr[constants::MAX_SIZE] = { 1,2,3,4,5 };
size_t size = 5;

std::ofstream ofs("file.bin", std::ios::binary);

if (!ofs.is_open()) {
    return -1;
}

//имаме size (в случая 5) на брой числа в масива, всяко с размер sizeof(int), следователно целия масив е с размер size * sizeof(int)
ofs.write((const char*)arr, size * sizeof(int));

ofs.close();
```
#### Писане
```c++
std::ifstream ifs("file.bin", std::ios::binary);

if (!ifs.is_open())
{
    return -1;
}

//getFileLen намира дължината на файла, може да го намерите в getFileLen.cpp
/* Идеята е, че в случая имаме запазен единствено масива в този файл, съовтетно броя на елементите е 
 * размера на файла (сумата от битове на всички елементи в масива) разделено на размера на един елемент от този масив (в случая int) */
size_t size = getFileLen(ifs) / sizeof(int);
int* arr = new int[size] {};

ifs.read((char*)arr, size * sizeof(int));

ifs.close();

//...вършите нужните действия с масива...

delete[] arr; //накрая не забравяте да изтриете заделената памет
```

### Структури

#### Без динамична памет
```c++
#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable: 4996)

struct Student 
{
	char name[25];
	int fn;
	int age;
};

int main()
{
    //писане
	{
		Student st;
		strcpy(st.name, "Ivan");
		st.fn = 1234;
		st.age = 33;

		std::ofstream ofs("student.bin", std::ios::binary);

		if (!ofs.is_open()) {
			return -1;
		}
        
	    //програмата може да се ориентира как са групирани данните в struct, понеже имаме фиксиран размер (нищо, че имаме масив, размера му е статичен)
		ofs.write((const char*)&st, sizeof(st));
	}

    //четене
	{
		Student st;
		std::ifstream ifs("student.bin", std::ios::binary);

		if (!ifs.is_open()) {
			return -1;
		}

		ifs.read((char*)&st, sizeof(st));
	}
}
```

#### С динамична памет
* Тук вече програмата не може да се ориентира какъв е размера на цялата структура, тъй като имаме член-данна с динамичен (променлив) размер
* Затова, при структури с динамична памет четем/пишем всяка член-данна **една по една**, като първо **записваме размера на динамичната памет**

```c++
struct Student 
{
	char* name;
	int gradesCount;
	double averageGrade;
};
    
void saveStudentToFile(std::ofstream& ofs, const Student& st) {
    size_t nameLen = strlen(st.name);
    
    //първо записваме размера, след това и самия масив/стринг/char*
    ofs.write((const char*)&nameLen, sizeof(nameLen));
    ofs.write(st.name, nameLen);

    ofs.write((const char*)&st.gradesCount, sizeof(st.gradesCount));
    ofs.write((const char*)&st.averageGrade, sizeof(st.averageGrade));

}

Student readStudentFromFile(std::ifstream& ifs) {
    Student res;

    size_t nameLen;

    //първо четем размера на динамичния char* и заделяме памет за него
    ifs.read((char*)&nameLen, sizeof(nameLen));
    res.name = new char[nameLen + 1]; // + 1 заради терминиращата нула '\0'
    
    ifs.read(res.name, nameLen);
    res.name[nameLen] = '\0';

    //оттам нататък четем примитивните член-данни нормално, но отново - една по една!  
    ifs.read((char*)&res.gradesCount, sizeof(res.gradesCount));
    ifs.read((char*)&res.averageGrade, sizeof(res.averageGrade));

    return res;
}
```

Както виждате сме отделили логиката за (де)сериализация в отделни методи. Това е особено удобно, когато имаме масив, записан във файл, от такива структури като Student, тъй като не трябва да смесваме логиката по четене/писане на масива и на Student