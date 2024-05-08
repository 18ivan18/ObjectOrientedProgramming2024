template <typename T>
concept Addable = requires(T x)
{
    x + x;
}; // requires-expression

template <typename T>
requires Addable<T> // requires-clause, not requires-expression
    T add(T a, T b)
{
    return a + b;
}

// template <typename T>
// requires requires(T x) { x + x; } // ad-hoc constraint, note keyword used twice
// T add(T a, T b) { return a + b; }

#include <iostream>
#include <vector>
#include <string>
struct Test
{
    int a, b;
    // Test operator+(const Test &t)
    // {
    //     return Test{a + t.a, b + t.b};
    // }
    friend std::ostream &operator<<(std::ostream &os, const Test &t)
    {
        return os << t.a << " " << t.b;
    }
};

struct Animal
{
    Animal(const std::string &name) : name{name} {}
    std::string name;
    void walk()
    {
        std::cout << name << " is walking\n";
    }
};

struct Cat : public Animal
{
    Cat() : Animal("Cat") {}
    void meow() {}
};

struct Fish : private Animal
{
    Fish() : Animal("Fishy") {}
    void swim() {}
    using Animal::name;
};

template <typename T>
concept Meowable = requires(T x)
{
    x.meow();
};

template <typename T>
concept Walkable = requires(T x)
{
    x.walk();
};

template <typename T>
requires Walkable<T>
void walkTheHerd(std::vector<T *> v)
{
    for (auto &&i : v)
    {
        i->walk();
    }
}

// concept
template <class T, class U>
concept Derived = std::is_base_of<U, T>::value;

template <Derived<Animal> T>
void f(T x)
{
    x.walk();
} // T is constrained by Derived<T, Base>

struct Human
{
    void walk()
    {
        std::cout << "A human is walking\n";
    }
};

int main()
{
    // std::cout << add(5, 10) << '\n';
    // std::cout << add(3.14, 42.0) << '\n';
    // std::cout << add(true, false) << '\n';
    // std::cout << add('5', '7') << '\n';
    // std::cout << add(Test{10, 20}, Test{20, 30}) << '\n';

    std::vector<Animal *> v;
    v.push_back(new Animal("Cow"));
    v.push_back(new Animal("Dog"));
    v.push_back(new Cat());
    // v.push_back(new Fish());
    walkTheHerd(v);

    f(Animal("Pig"));
    f(Cat());
    // f(Human());
}