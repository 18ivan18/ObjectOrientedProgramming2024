# Методи и this

## Методи и външни функции

### Външни функции
```c++
struct Point2D {
    double x;
    double y;
};

void print(const Point2& p) {
    std::cout << p.x << " " << p.y;
}
```

### Методи
```c++
struct Point2D {
    double x;
    double y;
    // метод с имплементация в структурата, става прекалено голяма ако имаме много методи
    void print() {
        std::cout << x << " " << y; 
    }
};
```


### Разделна компилация
```c++
// Point2D.h
struct Point2D {
    double x;
    double y;
    void print();
};

// Point2D.cpp
#include "Point2D.h"
void Point2D::print() {
    std::cout << x << " " << y;
}
```

### Константни методи. Константните обектни не могат да извикват не-константни методи.
```c++
// Point2D.h
struct Point2D {
    double x;
    double y;
    void print() const;
    void setX(int x);
};

// Point2D.cpp
#include "Point2D.h"
void Point2D::print() const {
    std::cout << x << " " << y;
}

void Point2D::setX(int x) {
    this->x = x;
}

// main.cpp
int main() {
    const Point2D p1;
    p1.print();
    // не можем, защото setX не е константна фунцкия 
    p1.setX(5);


    Point2D p2;
    p2.print();
    // можем
    p2.setX(5);    
}
```

Добрият стил за писане на код изисква аргументите на функция, която не променя обектите да са
константни.

Когато обаче методите са вътре в класът, текущият обект с когото работим, се подава неявно. Как да
напишем const тогава - като добавим `const` след декларацията на функцията

### this
Указателят `this` е указател към текущения обект, с който работим. Той е неявен параметър на всички методи на класа.

Компилаторът транслира всички извиквания на методи по следния начин.

`p1.print(); → print(&p1);`


## Забележки

### Обекти на класът не могат да бъдат в член-данните на класът

```c++
// Не
class Person
{
    Person name;
    int age;
};
```

```c++
// Да
class Person
{
    Person* name;
    int age;
};
```

Това е поради фактът, че при първият пример, размерът на `Person` ще бъде размерът на `Person` +
размерът на `int`. (Което довежда до невъзможност за изчисляване на размерът)
Във вторият пример, name е тип указател, което е с фиксиран размер `(4b/8b)`, което ни дава фиксиран
размер на `Person`.


# Класове
В обектно ориентираното програмиране класът е шаблон за създаване на обекти (структури от данни), който дава начални стойности за състоянието на обекта (член променливи или още полета) и имплементация на поведението на обекта (член функции или още методи).

```c++
class Rational
{
private:
    int numerator;
    int denominator;

public:
    void setNumerator(int n)
    {
        numerator = n;
    }
    int getNumerator()
    {
        return numerator;
    }
    void setDenominator(int n)
    {
        numerator = n;
    }
    int getDenominator()
    {
        return denominator;
    }
    Rational add(Rational &b)
    {
        Rational c;
        if (this->denominator == b.denominator)
        {
            c.numerator = this->numerator + b.denominator;
            c.denominator = this->denominator;
        }
        else
        {
            c.numerator = this->numerator * b.denominator + b.numerator * this->denominator;
            c.denominator = this->denominator * b.denominator;
        }
        return c;
    }
};

int main()
{
    Rational a, b, c;
    a.setNumerator(5);
    a.setDenominator(7);
    b.setNumerator(3);
    b.setDenominator(4);
    c = a.add(b);
}
```

## Модификатори за достъп

Едно от основните свойства на обектно ориентираното програмиране е скриването на данни (data hiding). 

Можем да ограничим достъпа до полетата на един клас, за да предотвратим достъпа на други функции или класове до тях. По този начин ги предпазваме от (не)умишлени промени, когато такива не искаме да има.

Също е важно да дадем достъп до основните методи на класа, които да манипулират данните имплицитно.

Модификаторите за достъп ни позволяват да определим кои членове на класа да са достъпни за други класове и функции и кои не са.

### public Access Modifier
- The public keyword is used to create public members (data and functions).
- The public members are accessible from any part of the program.


```c++
#include <iostream>

// define a class
class Person {

    // public elements
   public:
    int age;

    void displayAge() {
        std::cout << "Age = " << age << std::endl;
    }
};

int main() {
    // declare a class object
    Person obj1;

    std::cout << "Enter your age: ";

    // store input in age of the obj1 object
    std::cin >> obj1.age;

    // call class function
    obj1.displayAge();

    // this is generally a bad approach since we don't want to modify age directly
}
```

### private Access Modifier
- The private keyword is used to create private members (data and functions).
- The private members can only be accessed from within the class.
- However, friend classes and friend functions can access private members.



```c++
#include <iostream>

// define a class
class Person {
   private:
    int age = 0;

   public:
    void displayAge() {
        std::cout << "Age = " << age << std::endl;
    }

    void birthday() {
        age++;
    }
};

int main() {
    // declare a class object
    Person obj1;
    // error
    // std::cin >> obj1.age;

    obj1.birthday();

    // call class function
    obj1.displayAge();
}
```


### Before we learn about the protected access specifier, make sure you know about inheritance in C++.
- The protected keyword is used to create protected members (data and function).
- The protected members can be accessed within the class and from the derived class.


| Specifiers|	Same Class |	Derived Class |	Outside Class|
-|-|-|-
`public`|	Yes|	Yes|	Yes
`private`	|Yes|	No|	No
`protected`	|Yes|	Yes|	No

**Забележка**: По подразбиране полетата в класовете са `private`, освен ако не е оказано друго, докато по подразбиране полетата в структурите са `public`.

# Задачи

## Задача 1
Реализирайте клас, представящ времева марка (**Timestamp**) с полета за часове, минути и секунди. Напишете функции за създаване на времева марка по подадени секунди, извеждане във формат HH:MM:SS, събиране на две времеви марки, преобразуване на времева марка обратно в секунди.

## Задача 2
Съставете клас, който представя комплексно число. Напишете функции за събиране и умножение на две комплексни числа, както и такава за извеждане на комплексно число на конзолата по коректен начин.

## Задача 3
Напишете клас, който предсатвя софтуер за контрол на диспенсър за вода. Класът трябва да пази колко литра вода има в момента в диспенсъра, колко литра е максимума, методи за пълнене на чаша/бутилка (подава се размера на чашата в милилитри - ако няма достатъчно вода, да се връща съобщение за грешка) и метод за пълнене на диспенсъра (приема литрите, които ще бъдат наляти в диспенсъра).

## Задача 4
Реализирайте клас, който представя квадратно уравнение. Изпозлвайте класа за комплексно число от `Задача 2` за решенията.

## Задача 5
Разширете структурата `Vectоr` от миналото упражнение, като я превърнете в клас. Енкапсулирайте полетата. Нека той имплементира следните методи:
- `void getCapacity();` – връща капациета на вектора
- `int getSize();` – връща размера на вектора
- `bool isEmpty();` – връща `true` ако векторът няма елементи и `false` иначе
- `int getAt(int position);` –
- `int getFirst();` – връща първия елемент
- `int getLast();` – връща последния елемент
- `void assign(int n, int x);` – инициализира вектора с n елемента x
- `void pushBack();` – слага елемент в края
- `void popBack();` – премахва елемент от края
- `void removeAt(int position);` – премахва елемент на дадена позиция