# Polymorphism 
Polymorphism is a Greek word that means "many-shaped" and it has two distinct aspects: At run time, objects of a derived class may be treated as objects of a base class in places such as method parameters and collections or arrays.

# Виртуални функции
Виртуалната функция е член-функция на даден клас, която е дефинирана като виртуална в базов клас и е предефинирана (overridden) в клас наследник. Когато използваме динамично свързване и реферираме към обект от класа наследник използвайки указател или референция към базовия клас, можем да извикаме виртуалната функция за този обект и ще се изпълни предефинираната версия от класа наследник.

- Виртуалните функции подсигуряват това, че се извиква правилната версия на даден метод за обект, независимо от типа на референцията (или укарателя), използван за извикване.
- Използват се за да постигнем полиморфизъм по време на изпълнение на програмата. (**Runtime polymorphism**)
- Фунцкиите се декларират с ключовата думичка `virtual`
- Изпълнението им се определя по време на изпъленение на програмата.

Правила за виртуалните функции:
- Не могат да са статични - очеивдно, там няма наследяване
- Могат да са приятелски за друг клас и/или фунцкия
- За да се постигне желаният **Runtime polymorphism** трябва да се извикват през указател или референция към базовия клас.
- Прототипът на виртуалната функция трябва да е един и същ в базовия и класа наследник.
- Винаги се декларират в базовия клас и се предефинират в наследника, като наследниците НЕ са задължени да ги предифинират. В този случай поведението е същото като в базовия клас.      
- Деструкторът може да е вируален, но НЕ и конструкторът.

## Примери:
```c++
#include<iostream>
  
class base {
public:
    virtual void print()
    {
        std::cout << "print base class\n";
    }
  
    void show()
    {
        std::cout << "show base class\n";
    }
};
  
class derived : public base {
public:
    void print()
    {
        std::cout << "print derived class\n";
    }
  
    void show()
    {
        std::cout << "show derived class\n";
    }
};
  
int main()
{
    base *bptr;
    derived d;
    bptr = &d;
  
    // Virtual function, binded at runtime
    bptr->print();
  
    // Non-virtual function, binded at compile time
    bptr->show();
}
```
```
Output:  

print derived class
show base class
```

# Абстрактни класове и чисто виртуални функции

Понякога не можем да напишем имплементациите на всички виртуални функции в даден базов клас просто защото не знам очакваното поведение. Такъв клас се нарича абстрактен клас. Абстрактен клас наричаме такъв клас, който има поне 1 чисто виртуална функция. Чисто виртуалните функции са виртуални фунцкии, които приравняваме на 0 в декларацията.

```c++
class Shape {
public:
    virtual void draw() = 0;
};
```

Сега всичките наследени класове са длъжни да предефинират тази чисто виртуална функция, т.е. да дадат собствено поведение. 

Не можем да инстанциираме абстрактни класове. Трябва класовете наследници да имат предифинирани чисто виртуалните функции. Иначе те също ще станат абстрактни.

# Interface vs Abstract class
В езикa c++ няма синтактично разделение между интерфейс и абстрактен клас. Теоретичната разлика е, че в абстрактния клас имаме и полета. Докато в интерфейсите само задаваме поведение, т.е. имаме единствено чисто виртуални методи. За да направим семантично разделение често използваме префикса `I`. Въпреки това следвайте вашия shyle guide. 

Например:
```c++
class ISerializable {
public:
    virtual void serialize(std::ostream&) = 0;
    virtual void deserialize(std::istream&) = 0;
};

```
# Задачи
## Задача 1.

Съществуват различни видове броячи - някои могат само да увеличават
бройката, която пазят, други могат и да я намалят, а трети имат
ограничение до колко могат да отброяват.

### Клас Counter
Най-простият брояч - само нагоре, без ограничение.
- Конструктор без параметри: началната стойност е 0 и стъпката на брояча
е 1
- Конструктор с 1 параметър int initial: началната стойност е initial,
а стъпката е 1
- Конструктор с 2 параметъра int initial, unsigned step: началната
стойност е initial, а стъпката e step
- increment(): увеличава текущата стойност със стъпката на брояча
- getTotal(): връща int - текущата отброена стойност
- getStep(): връща unsigned - стъпката на брояча (не трябва да може да
бъде променяна)

### Клас TwowayCounter
Брояч, който може и да намалява отброяваната стойност.
Освен всичко изброено в Counter, съдържа и:
- decrement(): намалява текущата стойност със стъпката на брояча
### Клас LimitedCounter
Брояч, който отброява само до дадена максимална стойност.
- Конструктор с 1 параметър int max: максималната стойност е max,
началната е 0, а стъпката е 1
- Конструктор с 2 параметъра int max, int initial: максималната
стойност е max, началната е initial, а стъпката е 1
- Конструктор с 3 параметъра int max, int initial, unsigned step:
максималната стойност е max, началната е initial, а стъпката е step
- increment(): увеличава текущата стойност със стъпката на брояча само
ако няма да надмине максималната
- getMax(): връща int - максималната стойност на брояча
- getTotal(): същия като този на Counter
- getStep(): същия като този на Counter

### Клас LimitedTwowayCounter
Той е и LimitedCounter и TwowayCounter едновременно: може да отброява
нагоре до определена максимална стойност и надолу до определена
минимална стойност.
- Конструктор с 2 параметъра int min, int max: минималната стойност е
min, максималната стойност е max, началната е 0, а стъпката е 1
- Конструктор с 3 параметъра int min, int max, int initial:
минималната стойност е min, максималната стойност е max, началната е
initial, а стъпката е 1
- Конструктор с 4 параметъра int min, int max, int initial,
unsigned step: минималната стойност е min, максималната стойност е
max, началната е initial, а стъпката е step
- increment(): същия като на LimitedCounter
- decrement(): намаля текущата стойност със стъпката на брояча само
ако няма да стане по-ниска от минималната
- getMin(): връща минималната стойност на брояча
- getMax(): същия като този на LimitedCounter
- getTotal(): същия като този на Counter
- getStep(): същия като този на Counter

### Клас Semaphore
Най-простия бинарен семафор - това е LimitedTwowayCounter, който има
минимална стойност 0, максимална стойност 1 и стъпка 1. Използва се от
процесите в операционнитe системи за синхронизационни цели.
- Конструктор без параметри - началната стойност на брояча е 0.
- Конструктор с един параметър bool - при true началната стойност на
брояча е 1, а при false е 0.
- isAvailable(): връща bool, показващ дали стойността на брояча е над
0
- wait() - прави същото като decrement() на LimitedTwowayCounter
- signal() - прави същото като increment() на LimitedTwowayCounter

## Задача 2.

Направете система, която да дава възможност за комуникация чрез заявки
между разработчици и техния ръководител на екип. Имплементирайте
функционалности за изпращане на заявка за напускане и заявка за
повишаване на заплатата.

### Клас Developer
Разработчик.
- Име (символен низ);
- Заплата (double);
- Ръководител на екип (указател към обект от клас TeamLead);
- Конструктор с 1 параметър const string& name: името е name,
заплатата е 0, указателят сочи към nullptr;
- getName(): връща string - текущата стойност на името;
- getSalary(): връща double - текущата стойност на заплатата;
- getTeamLead(): връща TeamLead * - текущата стойност на указателя към
ръководителя;
- setInitialSalary(double amount): присвоява за заплатата подадената
сума amount, само ако нейната текуща стойност е 0; (Ако не е да не
присвоява стойност)
- void sendLeavingRequest();: подава към ръководителя
LeavingRequest с името на разработчика;
- void sendPromotionRequest(double amount);: подава към
ръководителя PromotionRequest с името на разработчика и
количеството на заплатата, подадено в аргумента на функцията;

### Клас TeamLead
Ръководител на екип.
Освен всичко изброено в Developer, съхранява и:
- вектор с указатели към обекти от клас Developer; (ръководителят не е
част от екипа)
- заявки за напускане (LeavingRequest);
- заявки за повишаване на заплатата (PromotionRequest);
- Конструктор с 2 параметъра const string& name, double salary:
името е name, заплатата е salary, a указателят към ръководителят на
екипа сочи към текущият обект;
- getTeam(): връща `Vector<Developer*>` - текущият вектор, който
представлява екипа;
- void addDeveloperToTeam(Developer * developer, double salary);:
добавя разработчик към екипа и задава заплатата му да бъде със
стойност salary. Трябва за разработчикът да се промени, че вече има
ръководител на екипа; (Възможно е да има разработчици в екипа с
еднакви имена. Съобразете дали developer не сочи към nullptr.)
- void removeDeveloperFromTeam(const string& name);: премахва
разработчик от екипа по подадено име name. (Ако не се намери търсения
разработчик, не последва действие. Ако намери разработчици с еднакво
име премахва последния.)
- void increaseTeamSalariesBy(double amount);: повишава заплатите
на разработчиците в екипа със стойност amount;
- void decreaseTeamSalariesBy(double amount);: понижава заплатите
на разработчиците в екипа със стойност amount;
- void addLeavingRequest(const LeavingRequest& leavingRequest);:
добавя на съхранение заявка за напускане;
- void addPromotionRequest(const PromotionRequest&
promotionRequest);: добавя на съхранение заявка за повишаване на
заплатата;
- void fulfillLeavingRequests();: изпълнява всички съхранени заявки
за напускане, като премахва от екипа изпратилите заявките, променя
техният ръководител (TeamLead * да сочи към nullptr) и изчиства
всички изпълнени заявки;
- void fulfillPromotionRequests();: изпълнява всички съхранени
заявки за повишаване на заплатата, повишава заплатата на изпратилите
заявките и изчиства всички изпълнени заявки;

### Клас Request
Заявка.
- Съобщение (символен низ)
- Изпращач (символен низ) (името на този, който я изпраща)
- Брояч (цяло число) - започва от 0 и се увеличава с всеки създаден обект
от тип Request или негови наследници;
- ID (цяло число) - уникален идентификатор, който има стойността на
брояча в момента на създаването му (ако сме създали два обекта от тип
Request или негови наследници, първият ще има ID със стойност 1, а
вторият ID със стойност 2);
- Конструктор с 2 параметъра const string& message, const string&
sender: съобщението е message, изпращачът е sender, броячът се
увеличава с 1, ID приема стойността на брояча;
- getMessage() : връща string - текущата стойност на съобщението;
- getSender(): връща string - текущата стойност на изпращача;
- getCount(): връща int - текущата стойност на брояча;
- getID(): връща int - текущата стойност на ID;

### Клас LeavingRequest
Заявка за напускане.
Освен всичко изброено в Request:
- Конструктор с 1 параметъра const string& sender: съобщението е "I
want to leave!", изпращачът е sender, броячът се увеличава с 1, ID
приема стойността на брояча;

### Клас PromotionRequest
Заявка за повишаване на заплатата.
Освен всичко изброено в Request:
- Kоличество (double) - количество, с което да се увеличи заплатата;
- Конструктор с 2 параметъра const string& sender, double amount:
съобщението е "I want a raise!", изпращачът е sender, количеството
е amount , броячът се увеличава с 1, ID приема стойността на брояча;
- getAmount(): връща double - текущата стойност на количеството;
При решението на задачата и работатата с указатели НЕ трябва да се създават копия