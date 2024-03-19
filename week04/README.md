## Конструктори и деструктор.

**Жизнен цикъл на обект**:
 - Създаване на обект в дадена област (scope) – заделя се памет и полетата се инициализират.
 - Достига се до края на скоупа (област).
 - Обектът и паметта, която е асоциирана с него се разрушава.

**Конструктор**:
 - Извиква се веднъж - при създаването на обекта.
 - Не се оказва експлицитно тип на връщане (връща констатна референция).
 - Има същото име като класа.
 
 **Деструктор**:
 - Извиква се веднъж - при изтриването на обекта.
 - Не се оказва експлицитно тип на връщане.
 - Има същото име като класа със симовла '~' в началото.

 ```c++
#include <iostream>

struct MyClass 
{
    MyClass()
    {
        std::cout << "Object is created" << '\n';
    }
    
    ~MyClass()
    {
        std::cout << "Object is destroyed" << '\n';
    }
    int a;
    int b;
};

int main()
{
	while ()
	{
		MyClass t; // Object is created 
		if ()
		{
			MyClass t2; // Object is created 

		} // Object is destroyed (t2)

	} // Object is destroyed (t)

    MyClass* t3 = new MyClass(); // Object is created 
    delete t3; // Object is destroyed (t3)


    MyClass* t4;

    if(true) {
        // ...
        t4 = new MyClass(); // Object is created 
    }
    while () {
        // ... do something with t4
    }
    delete t4; // Object is destroyed (t4)

}
```
## Забележки

### Default constructor vs param constructors
Когато нямаме дефиниран нито един конструктор, компилатора сам създава конструктор по подразбиране. Когато имаме дефиниран поне един конструкотр (независимо с параметри или не) компилаторът спира да създава конструктор по подразбиране сам и трябва да използваме вече дефинираните от нас.

### Инициализиращ списък (Initializer list)
Или още инициализиращ списък е специална синтактична форма за инициализиране на не-дефолтните променливи на класа. Синтактично представлява двуеточие (`:`), последвано от списък разделен със запетайки (`,`) от изброени `member-initializers`.
Всеки `member-initializer` има един от следните сичнтаксиси:

---
class-or-identifier ( expression-list(optional) )	(1)	
---
class-or-identifier braced-init-list	(2)	(since C++11)
---

1) Initializes the base or member named by class-or-identifier using direct initialization or, if expression-list is empty, value-initialization
2) Initializes the base or member named by class-or-identifier using list-initialization (which becomes value-initialization if the list is empty and aggregate-initialization when initializing an aggregate)

```c++
struct S
{
    int n;
    S(int);       // constructor declaration
    S() : n(7) {} // constructor definition:
                      // ": n(7)" is the initializer list
                      // ": n(7) {}" is the function body
};
 
S::S(int x) : n{x} {} // constructor definition: ": n{x}" is the initializer list
 
int main()
{
    S s;      // calls S::S()
    S s2(10); // calls S::S(int)
}
```
If a non-static data member has a default member initializer and also appears in a member initializer list, then the member initializer is used and the default member initializer is ignored:
```c++
struct S
{
    int n = 42;   // default member initializer
    S() : n(7) {} // will set n to 7, not 42
};
```
Reference members cannot be bound to temporaries in a member initializer list:

```c++
struct A
{
    A() : v(42) {} // Error
    const int& v;
};
```

**Delegating constructor**

If the name of the class itself appears as class-or-identifier in the member initializer list, then the list must consist of that one member initializer only; such a constructor is known as the delegating constructor, and the constructor selected by the only member of the initializer list is the target constructor

In this case, the target constructor is selected by overload resolution and executed first, then the control returns to the delegating constructor and its body is executed.

Delegating constructors cannot be recursive.
```c++

class Foo
{
public: 
    Foo(char x, int y) {}
    Foo(int y) : Foo('a', y) {} // Foo(int) delegates to Foo(char, int)
};
```

Променливите се инициализират в реда на тяхната декларация, независимо от реда им на изброяване в инициализиращия спиък.
```c++

class Foo
{
private:
    int i;
    double d;
    float f;

public: 
    Foo(): f{4.2}, d{3,14}, i{69} {} // i will be initialized first, after that d and lastly f
};
```


## Задача 1

Напишете клас `UserInfo`, който съдържа потребителско име и парола. Напишете следните конструктори:

- Конструктор по подразбиране
- Конструктор за копиране
- Конструктор, който приема потребителско име
- Конструктор, който приема потребителско име и парола

Напишете подходящи методи.

## Задача 2

Напишете клас `BrowserTab`, който съдържа URL и HTML съдържание. Напишете следните конструктори:

- Конструктор по подразбиране
- Конструктор за копиране
- Конструктор, който приема URL и HTML съдържание.

Напишете подходящи методи.

## Задача 3

Даден е клас `Point`, описващ точка в двумерното пространство. Напишете конструктор по подразбиране и конструктор с параметри. Напишете методи, за връщане на координатите на точката. Напишете метод, който връща разстоянието между две точки.

Даден е клас `Line`, описан от две точки. Напишете конструктор по подразбиране (създава се линия с дължина 1) и конструктор с параметри. Напишете метод за намиране на дължината на линията. 

## Задача 4

Даден е клас `LicenceKey`, който пази в себе си "ключ" (цяло, 8 цифрено число) и брой допустими копия. `LicenceKey` има метод `activate()`, който връща "ключа", стига той да не е копиран повече от допустимия брой пъти. Ако допустимия брой пъти е достигнат, да се връща `-1`. 