# Move semantics
## rvalue vs lvalue
Every C++ expression has a type, and belongs to a value category. The value categories are the basis for rules that compilers must follow when creating, copying, and moving temporary objects during expression evaluation.

The C++17 standard defines expression value categories as follows:

- A glvalue is an expression whose evaluation determines the identity of an object, bit-field, or function.
- A prvalue is an expression whose evaluation initializes an object or a bit-field, or computes the value of the operand of an operator, as specified by the context in which it appears.
- An xvalue is a glvalue that denotes an object or bit-field whose resources can be reused (usually because it is near the end of its lifetime). Example: Certain kinds of expressions involving rvalue references (8.3.2) yield xvalues, such as a call to a function whose return type is an rvalue reference or a cast to an rvalue reference type.
- An lvalue is a glvalue that is not an xvalue.
- An rvalue is a prvalue or an xvalue.
The following diagram illustrates the relationships between the categories:
![](https://docs.microsoft.com/en-us/cpp/cpp/media/value_categories.png?view=msvc-170)

An lvalue has an address that your program can access. Examples of lvalue expressions include variable names, including `const` variables, array elements, function calls that return an lvalue reference, bit-fields, unions, and class members.

A prvalue expression has no address that is accessible by your program. Examples of prvalue expressions include literals, function calls that return a non-reference type, and temporary objects that are created during expression evaluation but accessible only by the compiler.

An xvalue expression has an address that no longer accessible by your program but can be used to initialize an rvalue reference, which provides access to the expression. Examples include function calls that return an rvalue reference, and the array subscript, member and pointer to member expressions where the array or object is an rvalue reference.

```c++
int main()
{
    int i, j, *p;

    // Correct usage: the variable i is an lvalue and the literal 7 is a prvalue.
    i = 7;

    // Incorrect usage: The left operand must be an lvalue (C2106).`j * 4` is a prvalue.
    7 = i;     // C2106
    j * 4 = 7; // C2106

    // Correct usage: the dereferenced pointer is an lvalue.
    *p = i;

    // Correct usage: the conditional operator returns an lvalue.
    ((i < 3) ? i : j) = 7;

    // Incorrect usage: the constant ci is a non-modifiable lvalue (C3892).
    const int ci = 7;
    ci = 9; // C3892
}
```
### References
```c++
#include <iostream>

struct Person
{
    char *Name;
    short Age;
};

int main()
{
    // Declare a Person object.
    Person myFriend;

    // Declare a reference to the Person object.
    Person &rFriend = myFriend;

    // Set the fields of the Person object.
    // Updating either variable changes the same object.
    myFriend.Name = "Bill";
    rFriend.Age = 40;

    // Print the fields of the Person object to the console.
    std::cout << rFriend.Name << " is " << myFriend.Age << std::endl;
}
```

# Задачи

## Задача 1

Нека се имплементира програма за управление на автомат за напитки.

Напитката се характеризира по следния начин:

-  Име (низ, с динамичен размер)
-  Количество, в литри (подсказка: може да имаме и бутилка от 500мл)
-  Калории (per 100ml)
-  Цена (лв/литър)

Автомата за напитки трябва да поддържа следните функционалности:
-  Добавяне на напитка
   -  Ако напитката не съществува (не съществува напитка със същото
име), методът да връща true и да добавя напитката
   -  Ако напитката съществува, метода да връща false и да не добавя
напитката

-  Доливане на напитка
   -  Ако напитката не съществува, методът да връща false
   -  Ако напитката съществува, методът да обновява нейното количество с подаденото

- Закупуване на напитка
   - Потребителя подава на машината дадена сума пари, име на
напитка и количество (в литри)
      -  Ако напитката съществува и сумата е достатъчна,
напитката се премахва от машината и парите се добавят
към машината. Методът връща стойността на рестото, което трябва да бъде върато.
     -  Ако напитката съществува, но количеството не е достатъчно се купува останалото количество. Цената се съобразява спрямо продаденото количество.
Напитката се премахва от машината и парите се добавят
към машината. Методът връща стойността на рестото, което трябва да бъде върато.
     - Ако парите не са достатъчни, но напитката съществува -
 напитката не се премахва, но парите се добавят към
машината. (Приемаме, че ако искаме да закупим напитката,
трябва да дадем достатъчен брой пари - получаването на
напитка се случва само след подадена достатъчна сума)
Методът връща стойност -1.
     - Ако напитката не съществува - парите не се добавят към
машината. Методът връща стойност -2.

-  Проверка на получените пари от продажби.
-  Сортиране на напитките по калорийна стойност.


```c++
class VendingMachine {
public:
    bool addDrink(const Drink& toBeAdded);
    bool fillUpDring(const Drink& toBeFilledUp);
    int buyDrink(const char* drink_name, const double money, const double quantity);
    double getIncome() const;
};
```

Използвайте предефиниране на оператори в класа `Drink`.

## Задача 2
Асистентите по ООП са решили да тестват автоматично задачите на
студентите тази година
и се нуждаят от вашата помощ да напишат системата си. Предоставили са ви
основни
изисквания към системата, и основния интерфейс, който искат да ползват, като
имплементацията
е ваше задължение.


Следват основните инструкции към задачата, като подробности може да
намерите в кода.

Тестов пакет (`TestSuite`)

Всяка задача по ООП ще си има собствен набор от тестове наричан Тестов
Пакет.


Тестовият пакет трябва да има:
- Име (може да се променя)
- Множество тестови сценарии
- Възможност за добавяне на нов сценарии към множеството
- Възможност за филтриране на преминаващи/непреминаващи сценарии
- Възможност за филтриране на сценариите по тип грешка
- Възможност за премахване на всички тестови сценарии с даден тип
грешка

Тестов сценарий (`TestCase`)

Тестов сценарии представлява отделен тест за точно една функционалност.

Всеки сценарий трябва да има:
- Име
- Възможност да се провери дали теста е бил успешен
- Възможност да се провери дали има грешка
- Възможност да се провери типа на грешката
- Възможност да се провери съобщението на грешката

Грешка (`Error`)

Всеки тест може да е успешен, а може и да не е. Когато един тест не е минал успешно е
необходимо да имаме допълнителна информация какво се е счупило. За тази
цел тестовите сценарии могат да имат грешка, която трябва да има:
-  Тип (Празна/Никаква грешка, Грешка при компилация, Предупреждение,
Неуспех при сравнение)
- Съобщение
- Възможност да се проверява типа на грешката
- Възможност да се проверява дали грешката има съобщение
- Възможност да се проверява съобщението на грешката ако има такова
- Възможност да се създава нова грешка от всеки един тип