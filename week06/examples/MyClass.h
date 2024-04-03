#pragma once
#include <string>
class MyClass
{
private:
    int i;
    std::string s;
    int *ptr;

public:
    MyClass() : i(0), s({}), ptr(new int(42)) {}

    //...Copy assignment operator
    // (takes an lvalue)
    MyClass &operator=(const MyClass &rhs)
    {
        if (this != &rhs)
        {
            i = rhs.i;
            ptr = new int;
            *ptr = *rhs.ptr;
            s = rhs.s;
        }
        return *this;
    }

    // Move contructor
    // tasks:
    // 1. tranfer the contents of mc into this
    // 2. leave mc in valid but undefinied state
    MyClass(MyClass &&mc) noexcept : i(std::move(mc.i)), s(std::move(mc.s)), ptr(std::move(mc.ptr))
    {
        mc.ptr = nullptr;
    }

    //...Move assignment operator
    // (takes a rvalue)
    // tasks:
    // 1. clear resources
    // 2. tranfer the contents of mc into this
    // 3. leave mc in valid but undefinied state
    MyClass &operator=(MyClass &&mc) noexcept
    {
        delete ptr;
        i = std::move(mc.i);
        s = std::move(mc.s);
        ptr = std::move(mc.ptr);
        mc.ptr = nullptr;
        return *this;
    }

    static MyClass createMyClass()
    {
        return MyClass();
    }
};