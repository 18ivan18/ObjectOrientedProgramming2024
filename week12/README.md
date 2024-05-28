The SOLID principles were introduced by Robert C. Martin in his 2000 paper “Design Principles and Design Patterns.” These concepts were later built upon by Michael Feathers, who introduced us to the SOLID acronym. And in the last 20 years, these five principles have revolutionized the world of object-oriented programming, changing the way that we write software.

So, what is SOLID and how does it help us write better code? Simply put, Martin and Feathers' design principles encourage us to create more maintainable, understandable, and flexible software. Consequently, as our applications grow in size, we can reduce their complexity and save ourselves a lot of headaches further down the road!

The following five concepts make up our SOLID principles:
1. Single Responsibility
2. Open/Closed
3. Liskov Substitution
4. Interface Segregation
5. Dependency Inversion

## Single Responsibility
Един клас трябва да отговаря за едно нещо. Той трябва да има само една причина да бъде променян.

Как това ни помага да поддържаме кода по-чист и разбираем? 
- тестване - клас, който отговаря само за едно нещо (т.е. има една единствена цел) ще има по-малко тестови сценарии
- по-малко функционалности означават по-малко зависимости
- по-малък клас означава по-четим и по-добре организиран клас.

Пример: 
```c++
class Book {
private:
    string name;
    string author;
    string text;

public:
    //constructor, getters and setters

    // methods that directly relate to the book properties
    string replaceWordInText(string word){
        return text.replace(word, text);
    }

    bool isWordInText(string word){
        return text.contains(word) != string::npos;
    }
};
```
Имаме един добре работещ клас `Book`. Сега можем да имаме много книги в нашето приложение. Но все още не можем да ги четем и пишем на конзолата. Затова решаваме да направим метод за принтиране.
```c++
class Book {
    //...

    void printTextToConsole(){
        // our code for formatting and printing the text
    }
}
```

Това обаче нарошава `single responsibility` принципа. За да се поправим можем да имплементираме отделен клас, който принтира текст.

```c++
 class BookPrinter {

    // methods for outputting text
    void printTextToConsole(string text){
        //our code for formatting and printing the text
    }

    void printTextToAnotherMedium(string text){
        // code for writing to any other location..
    }
};
```

## Open for Extension, Closed for Modification
O в SOLID е познато още като `open-closed principle`. Кодът трябва да може да се надгражда, но не и да се променя. По този начин се спираме от това да счупим вече работеща функционалност.

```c++
class Guitar {
private:
    string make;
    string model;
    int volume;

    //Constructors, getters & setters
};
```
Ето нашия клас Китара. Той работи перфектно, приложението печели пари. След няколко месеца обаче решаваме, че искаме по-интересни китари. Решаваме да добавим картинки по тях. Може да се изкушим да променим класа Китара като добавим още полета за новостите, но open-closed принципа ни спира. Вместо това създаваме нов клас, който наследява китарата.
```c++
class SuperCoolGuitarWithFlames: public Guitar {
private:
    string flameColor;

    //constructor, getters + setters
};
```
По този начин сме сигурни, че не вкарваме нови бъгове във вече работещото приложението.

## Liskov Substitution
Това е потенциално най-трудния от петте принципа. Най-просто казана клас наследник трябва да може да бъде използван вместо родителския си клас навсякъде без да се промени поведението на програмата.
```c++
class Car {
public:
    virtual void turnOnEngine() = 0;
    virtual void accelerate() = 0;
};
```
Ето го интерфейса за нашата кола.
```c++
class MotorCar: public Car {

private:
    Engine engine;

    //Constructors, getters + setters
public:
    void turnOnEngine() {
        //turn on the engine!
        engine.on();
    }

    void accelerate() {
        //move forward!
        engine.powerOn(1000);
    }
};
```
Примерна имплементация на обикновена кола. Сега ще се опитаме да имплементираме електрическа кола.

```c++
class ElectricCar: public Car {
public:
    void turnOnEngine() {
        throw AssertionError("I don't have an engine!");
    }

    void accelerate() {
        //this acceleration is crazy!
    }
};
```
Забелязваме, че електрическите коли нямат двигател. Това може да промени поведението на програмата и решенето на този проблем може да бъде много по-сложно от това на някои други нарошения на SOLID принципите. Едно примерно решение е да преработим началния интерфейс като вземем предвид състоянието на кола без двигател.

## Interface Segregation
Големите интерфейси трябва да се разделят на няколко по-малки. По този начин един клас трябва да се грижи само за методите, които го интересуват.
```c++
class BearKeeper {
    virtual void washTheBear() = 0;
    virtual void feedTheBear() = 0;
    virtual void petTheBear() = 0;
};
```
Ние обичаме да полагаме грижи за мечките в зоологическата градина, но да ги галим си е чиста лудост. Така зададеният интерфейс обаче ни задължава да имплементираме код за това. Нека го разделим на няколко по-малки интерфейса.
```c++
class BearCleaner {
    virtual void washTheBear() = 0;
};

class BearFeeder {
    virtual void feedTheBear() = 0;
};

class BearPetter {
    virtual void petTheBear() = 0;
};
```
Сега, когато имаме по-добро разделение, можем да имплементираме само методите, които ни интересуват.

```c++
class BearCarer: public BearCleaner, public: BearFeeder {
public:
    void washTheBear() {
        //I think we missed a spot...
    }

    void feedTheBear() {
        //Tuna Tuesdays...
    }
};
```

Ии да оставим опасните неща настрани.
```c++
class CrazyPerson: public BearPetter {
public:
    void petTheBear() {
        //Good luck with that!
    }
}
```

Сега след като вече знаем този принцип може да разделим `BookPrinter` класа от миналия пример на интерфейса `Printer` и да оставим различни класове да предефинират методите му като например `ConsoleBookPrinter` и `OtherMediaBookPrinter`.

## Dependency Inversion
Тук се има предвид разделение на модулите. По този начин вместо модулите от високо ниво на разчитат на модули от ниско ниво, те разчитат на абстракции.

Нека разгледаме примера. Имаме клас, описващ стар компютър. Естествено на него му трябват мишка и клавиатура.
```c++
class Windows98Machine {
private:
    StandardKeyboard keyboard;
    Monitor monitor;

public:
    Windows98Machine() {
        monitor = new Monitor();
        keyboard = new StandardKeyboard();
    }
}
```
Този код ще работи перфектно, но така обвързваме нашия компютър с конкретно класовете StandardKeyboard и Monitor. По този начин не само затрудняваме тестването, но и правим невъзмножна смяната на мишка и клавиатура. Нека добавим малко абстракция.

```c++
// interface
class Keyboard { };

class Windows98Machine {
private:
    Keyboard keyboard;
    Monitor monitor;

public:
    Windows98Machine(Keyboard keyboard, Monitor monitor) {
        this->keyboard = keyboard;
        this->monitor = monitor;
    }
};

// ...

class StandardKeyboard: public Keyboard { };
```
Сега класовете ни зависят на абстракции и можем бързо и лесно да ги използваме по желания от нас начин.