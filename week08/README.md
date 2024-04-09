# Упражнение

Да се напише клас String за работа със символни низове.
Очаквани методи:

- За капацитет:
  - size - Return length of string (public member function )
  - at - Get character in string (public member function )
  - back - Access last character (public member function )
  - front - Access first character (public member function )
- За модифициране
  - operator+= - Append to string (public member function )
  - append - Append to string (public member function )
  - push_back - Append character to string (public member function )
  - insert - Insert into string (public member function )
  - erase - Erase characters from string (public member function )
  - replace - Replace portion of string (public member function )
  - swap - Swap string values (public member function )
  - pop_back - Delete last character (public member function )
- Операции:
  - c_str - Get C string equivalent (public member function )
  - substr - Generate substring (public member function )
  - operator+ - Concatenate strings (function )
  - all relational operators - Relational operators for string (function )
  - operator>> - Extract string from stream (function )
  - operator<< - Insert string into stream (function )

**Забележка:** помислете как може класът да се реализира максимално оптимално.

# Наследяване

Наследяването е начин за създаване на нови класове чрез
използване на компоненти и поведение на съществуващи
класове.

При създаване на нов клас, който има общи компоненти и
поведение с вече дефиниран клас, вместо да дефинира повторно
тези компоненти и поведение, програмистът може да определи
новия клас като клас наследник на вече дефинирания.

- Базов и производен клас:
  - Дефинираният клас се нарича базов или основен.
  - Новосъздаденият клас се нарича производен.

Нека разгледаме следните класове:
// single source of truth

```c++
class Motorcycle
{
private:
    char* make;
    char* model;
    int horsepower;
    int capacityLuggage;
public:
    const char* getMake() const;
    const char* getModel() const;
    const int getHorsepower() const;
    const int getCapacity() const;
};
```

```c++
class Car
{
private:
    char* make;
    char* model;
    int horsepower;
    int seats;
public:
    const char* getMake() const;
    const char* getModel() const;
    const int getHorsepower() const;
    const int getCapacity() const;
};
```

Забелязваме, че и двата класа имат член-данните `make`, `model` и `horsepower` и съответните методи,
но `Car` има `seats`, а `Motorcycle` има `capacityLuggage`.

Тук изниква въпроса - възможно ли е да
отделим общите части на двата класа и да ги използваме, без да се налага да ги пишем всеки път наново?

Един вариант е да се използва композиция - да се създаде клас `Vehicle` и инстанция на този клас да
бъде поле на `Car` и `Motorcycle`.
Другият вариант е `Car` и `Motorcycle` да наследяват `Vehicle`. Така те ще получат полетата и
методите на `Vehicle` като свои, без да се налага да пишем два пъти.

## Композиция vs Наследяване?

Кога е да използваме наследяване и кога да използваме композиция?

Тук въпросът е, каква връзка искаме да създадем между отделните класове. Ако искаме връзката да е
"is-a" (т.е. `Car` is a `Vehicle`) - използваме наследяване. Ако искаме връзката да е "has-a", (`Car` has a
`Vehicle` няма особенна логика, но `Car` has a `SteeringWheel` има) - използваме композиция.
Също така, използваме наследяването, когато новият клас, който ще наследява нещо, да добавя нови
елементи (полета или методи) или пък да променя действието на някои методи.

## Как се дефинират производните класове?

Нека отделим общите полета и методи на `Car` и `Motorcycle` в нов клас, `Vehicle`:

```c++
class Vehicle
{
private:
    char* make;
    char* model;
    int horsepower;
public:
    Vehicle();
    Vehicle(const Vehicle& objectToCopyFrom);
    Vehicle& operator=(const Vehicle& objectToCopyFrom);
    const char* getMake() const;
    const char* getModel() const;
    const int getHorsepower() const;
    ~Vehicle();
};
```

Класовете Car и Motorcycle ще изглеждат по този начин:

```c++
class Car : public Vehicle
{
private:
    int seats;
public:
    Car(): seats{1} {}
    const int getSeats() const;
};

class Motorcycle : public Vehicle
{
private:
    int capacityLuggage;
public:
    Motorcycle(): capacityLuggage{0} {}
    const int getCapacity() const;
};
```

Така вече и двата класа `Car` и `Motorcycle` имат полетата и методите на `Vehicle`

Възникват няколко въпроса:

## Защо Car и Motorcycle нямат голяма четворка ?

Самите класове `Car` и `Motorcycle` нямат динамична памет. При извикване на `copy-constructor` или
`operator=`, компилатора извиква съответните `copy-constructor` или `operator=` на `Vehicle`. Същото се
случва и при деструкторите. Не е нужен и конструктор по подразбиране, макар че е добра практика да
има такъв, защото при инициализация на `Car`, се извиква и конструктора по подразбиране на `Vehicle`.

## Може ли даден клас да наследява два или повече класа?

Да

```c++
class A {/*...*/};
class B {/*...*/};

class C : public A, public B
{
/*...*/
};
```

## Области на видимост и достъп

Забелязваме, че `Car` и `Motorcycle` наследяват `Vehicle` като `public`. Също както полетата и
методите, наследните класове могат да бъдат `public`, `protected` и `private`

| Тип на наследяване\Област на видимост на компонента в основния клас | public    | protected | private |
| ------------------------------------------------------------------- | --------- | --------- | ------- |
| public                                                              | public    | protected | private |
| protected                                                           | protected | protected | private |
| private                                                             | private   | private   | private |

Забелязваме следните няколко неща:

- Всички полета и методи, които са `private` в основният клас, винаги се наследяват като
  `private` (и ние нямаме директен достъп до тях).
- Aко наследним някой клас като `private` (което се случва ако изричнo не напишем `protected` или
  `public` пред класа, който ще наследяване), всички полета на родителския клас ще бъдат
  наследени като `private`

- `protected` ни позволява тези полета да са видим за производните класове, но не и извън тях

## Достъп до член-данни и методи на наследен клас

Ако имаме достъп до дадени член-данни или методи (т.е. да са `public` или `protected` спрямо горната
таблица), можем да ги използваме чрез `име_на_клас::поле` или `име_на_клас::метод()`

# Задача 1

Към класът Vehicle ще добавим метод `print()`, който извежда на конзолата марката, модела и конските
сили на превозното средство. Да се добави метод `print()` и в `Car`, `Vehicle`, които да принтират цялата
налична информация за превозните средства.

## Overloading (static polymorphism) vs Overriding

### Overloading: Same method name but different parameters in the same class

На български език нямаме отделни термини за `Overloading` и `Overriding`. И на двете казваме предефиниране на функции. `Overloading` наричаме още статичен полиморфизъм, защото свързването се случва на ниво компилация. При него имаме едно и също име на методи, които се извикват с различни параметри.

```c++

class Processor {

	void process(int i, int j) {
		std::cout << "Processing two integers:" <<  i << " " << j;
	}

	void process(std::vector<int> ints) {
		std::cout << "Adding integer array:" << to_string(ints));
	}

	void process(std::vector<Object> objs) {
		std::cout << "Adding integer array:" <<  to_string(objs));
	}
};
```

### Overriding: Same method signature in both superclass and child class

Тук имаме същата сигратура в базовия клас и класа наследник. Коя от двете функции се извиква зависи от типа на обекта.
Използваме ключова дума override за да покажем на компилатора, че искаме същата сигнатура като в базовия клас. Ако има несъотвествие имаме компилационна грешка.

```c++
class MathProcessor: public Processor {

	void process(int i, int j) override {
		std::cout << "Sum of integers is " << (i + j);
	}


	void process(std::vector<int> ints) override {
		int sum = 0;
		for (int i : ints) {
			sum += i;
		}
		std::cout << "Sum of integer array elements is " << sum;
	}

}

//...
int main() {
    MathProcessor mp;
    Processor p;
    mp.process(5, 6); // Sum of integers is 11 -> mp is of type MathProcessor
    p.process(5, 6); // Processing two integers: 5 6 -> p is of type Processor
}
```

# Задача 2

Да се напише клас `Scooter`, който да наследява `Motorcycle`, но има само 30 конски сили. Да добавя нови
член-данни - `maxCapacityOfDriver` и `color`. Да се напишат подходящи методи.

Когато имаме наследяване на класове, голямата четворка не се наследява. Ще разгледаме всеки
случай по отделно:

## Наследяване на конструктори

Когато наследим клас, без да кажем кой конструктор на наследения клас да се изивика, винаги се
извиква този по подразбиране. Ако искаме да извикаме конкретен конструктор, това става по следният
начин:

```c++
Car::Car() : Vehicle(), seats{0}
{ /* ... */ }
```

Нека създадем конструктор с параметри на `Vehicle`, `Car` и `Motorcycle`:

```c++
Vehicle::Vehicle(const char* make, const char* model, const int horsepower)
{
    make = new char[strlen(make) + 1];
    strcpy(this->make, make);
    model = new char[strlen(model) + 1];
    strcpy(this->model, model);
    horsepower = horsepower;
}
```

Съответните конструктори с параметри на Car и Motorcycle ще изглеждат по следният начин:

```c++
Car::Car(const char* make, const char* model, const int horsepower, const int
seats) : Vehicle(make, model, horsepower), seats{seats}
{ /* ... */ }
```

Ще разгледаме следните под-случаи:
Основен клас\Производен клас | Има конструктор | Няма конструктор
-|-|-|
Няма default-ен конструктор, има такъв с параметри | Трябва задължително да се извика конструктора с параметри |Грешка
Има няколко конструктора, включително и default-ен | Вика се default-ния, ако изрично не е посочен друг | Компилатора създава default-ен конструктор

Редът, по който се извикват конструкторите в основния и наследеният клас е следният - първо
конструкторите на основните класове, после на производните.

## Наследяване на copy конструктор

Правилата за обикновенните конструктори, също важат и за copy.
Ако искаме да извикаме copy конструктор на основен клас, това се случва по следният начин:

```c++
Car::Car(const Car &objectToCopyFrom): Vehicle(objectToCopyFrom), seats{objectToCopyFrom.seats}
{  }
```

Отново имаме следните случаи:

| Основен клас\Производен клас | Има copy конструктор                                      | Няма copy конструктор                  |
| ---------------------------- | --------------------------------------------------------- | -------------------------------------- |
| Няма copy конструктор        | Използва се default-ен                                    | Използват се default-ни от компилатора |
| Има copy конструктор         | Трябва задължително да се извика конструктора с параметри | Компилатора създава default-ен         |

## Наследяване на оператор=

Извикването на оператор= при наследеният клас става по следният начин:

```c++
Car& Car::operator=(const Car &objectToCopyFrom) {
    seats = objectToCopyFrom.seats;
    Vehicle::operator=(objectToCopyFrom);
}
```

## Наследяване на деструктори

Реда на изпълняване на деструкторите е обратен на този при конструкторите

# Задача 3:

Да се добави поле fuelType, отговаряща за типа гориво на колата (petrol, diesel, etc) в класа
`Car`

# Задача 4:

Да се направи реализация на `String`, който наследява `Vector<char>`

# Задача 5:

Напишете клас `Person`, който има следните свойства:

- Име
- Фамилия
- Възраст
- Адрес (град, улица)

Напишете клас Teacher, който наследява `Person` и добавя следните свойства:

- Стаж (години)
- Заплата
- Брой курсове, които води

Напишете клас `Course`, който има следните свойства:

- име на курс
- Преподавател (Teacher)
- Оценка

Напишете клас `Student`, който наследява `Person` и добавя следните свойства:

- Факултетен номер
- Списък с курсове, в които е записан
- Среден успех
