# Какво е ООП?
## Строга дефинция:
"Object-oriented programming (OOP) is a programming paradigm based on the concept of "objects", which
may contain data, in the form of fields, often known as attributes; and code, in the form of procedures, often
known as methods. A feature of objects is that an object's procedures can access and often modify the data
fields of the object with which they are associated (objects have a notion of "this" or "self"). In OOP, computer
programs are designed by making them out of objects that interact with one another. There is significant
diversity of OOP languages, but the most popular ones are class-based, meaning that objects are instances of
classes, which typically also determine their type."

# Структури

## Какво е структура?
Тип данни дефиниран от потребителя. Позволява да се комбинират данни с различни типове. Хетерогенна структура от данни.

Елементите се наричат членове (member variables), мога да бъдат с различен тип и дължина.

## Примери

```c++
struct Point {
    float x, y;
};
```

### Деклариране на обекти
```c++
Point a; // defaults values

Point b {0, 0}; // x = 0, y = 0

Point c;
// we access member variables with the . operator
c.x = 0; 
c.y = 0;
```

### Подаване на обекти във функции

Ако няма да променяме обекта го подаваме по **константна референция**.
```c++
float euclideanDistance(const Point& q, const Point& p) {
    return sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
}
```

Ако искаме да можем да правим промени по обекта го подаваме като **референция**.

```c++
void readPoint(Point& p)
{
   cin >> p.x >> p.y;
}
```

Последно можем и да подаваме обекта като **копие**.
```c++
Point reflectX(Point p) {
    p.x *= -1;
    return p;
}
```

### Работа с динамични обекти
```c++
#include <iostream>

struct Point {
    float x, y;
};

float euclideanDistance(const Point& q, const Point& p) {
    return sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
}

int main()
{
   Point* p = new Point();
   Point* q = new Point();

   (*p).x = 0;
   (*p).y = 0;
   q->x = 2;
   q->y = 2;
   
   std::cout << euclideanDistance(*p, *q) << std::endl;
   
   delete p;
   delete q;
}
```

### Влагане на обекти
```c++
struct Point {
    float x, y;
};

struct Triangle {
    char name[1024];
    Point A;
    Point B;
    Point C;
};

int main() {
    Triangle t = {"Pythagorean triangle", {0, 0}, {3, 0}, {3, 4}};

    std::cout << t.name << '\n';
}

```

### Масиви от обекти
```c++
struct Point {
    float x = 3.14, y = 5; // default values, if not set they default to the variable default value
};

int main() {
    Point arr[10]; // 10 Points
    Point* arr1 = new Point[20]; // 20 Points in dynamic memory
    
    std::cout << arr[0].x << " " << arr1[3].y << std::endl;

    delete[] arr1; 
}
```

### Размери на обекти. Подравняване
```c++
// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

// structure A
struct structA
{
    char b;
    int c;
};


// structure B
struct structB
{
    short int s;
    char c;
    int i;
};

// structure C
struct structC
{
    char c;
    double d;
    int s;
};

// structure D
struct structD
{
    double d;
    int s;
    char c;
};

int main()
{
    std::cout << "Size of structA " << sizeof(structA) << std::endl; // Size of structA 8 (not 5 because of padding)
    std::cout << "Size of structB " << sizeof(structB) << std::endl;
    std::cout << "Size of structC " << sizeof(structC) << std::endl;
    std::cout << "Size of structD " << sizeof(structD) << std::endl;
}
``` 
![](https://camo.githubusercontent.com/87e5260554b5aff56f0fae251081a4f945adc0a13fb275d68313421c1dc2bba7/68747470733a2f2f692e6962622e636f2f6e73434b594c4e2f7374727563742e706e67)

### Обединения
Обединенията са част от паметта, която се поделя при съхранение на две или повече променливи. Променливите, поделящи паметта могат да са от различни типове. Във всеки един момент обаче може да се ползва само една променлива от състава на обединението.

Стар механизъм, наследен от езика С.

Обикновено не се използват.
```c++
// запазват памет колкото за най-големия елемент
union TestUnion
{
   int i;
   char c;
   double d;
};

// запазват памет за всичките елементи
struct TestStruct
{
   int i;
   char c;
   double d;
};


int main() {
    // [][][][]
    // ---i---
    // -c-
    // --s--
    TestUnion tu;
    tu.d = 5.5;
    tu.c = 'a';

    // [12][34][56][78]

    tu.i = 0x12345678;
    std::cout << tu.c;
    tu.c = 0x55;
    // [55][34][56][78]  
}
```

### Пример за използване на union
```c++
union ipaddr_t {
    uint32_t addr;
    uint8_t octet[4];
};

int main () {
    ipadder_t a;
    
    a.octet[0] = 127;
    a.octet[1] = 0;
    a.octet[2] = 0;
    a.octet[3] = 1;


}
```

```c++
struct Variant {
   enum {INT, CHAR, DOUBLE} type;
   union {
    int i;
    char c;
    double d;
   }
}

void process(Variant& v) {
    switch(v.type):
    {
        case Variant::INT:
        // ...
            break;
        case Variant::CHAR:
        // ...
            break;
        case Variant::DOUBLE:
        // ...
            break;
    }
}

int main () {
    Variant v;
    v.type = Variant::INT;
    v.i = 42;
    process(v);
}
```

## Задачи
За всяка от следните задачи пишете и малка `main` функция, която илюстрира работата на вашата задача.

### Задача 1
Да се създаде структура която представя комплексно число. Създайте функция,
която събира две комплексни числа. Създайте подходяща функция за извеждане
принтиране на комплексни числа.

### Задача 2
Създайте структура описваща студент. Всеки студент се определя чрез факултетен номер, курс и средна оценка за курса. Всеки студент е в първи, втори, трети или четвърти курс. Факултетните номера винаги са петцифрени цели числа. Създайте подходящо параметризирана функция `initStudent(...);`, която въвежда коректни данни за студент. Да се напише функция, която принтира студент. Може да използвате помощни функции.

**Забележка**: Винаги трябва да се грижим за динамичната памет.

### Задача 3
Една група се състои от краен брой студенти. Броят на студентите се задава от вас. Създайте структура, която описва група. Структурата също така трябва да пази средния успех на групата. Направете функция, която създава група, взимайки информация от стандартния вход. Средния успех трябва да се сметне след въвеждане на информацията. Напишете функция, която приема група и минимален успех за стипендия, и връща колко студента ще получават стипендия.

### Задача 4
Създайте функция, която приема група и минимален успех за стипендия и извежда
сортирани всички студенти, които ще получават стипендия идния семестър.

### Задача 5
Въвежда се цяло число N и после N тригъгълника в равнината, определени от 3 точки (6 координати). Отпечатайте тригълниците сортирани по лицата им.

### Задача 6
Реализирайте структура, която моделира квадратно уравнение. Квадратното уравнение се дефинира с 3 коефициента a, b, c, които са произвилни числа. Напишете методи за изчисление на решенията ако има реални такива.