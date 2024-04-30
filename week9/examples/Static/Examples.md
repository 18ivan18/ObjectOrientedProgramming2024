```c++
class X { static int n; }; // declaration (uses 'static')
int X::n = 1;              // definition (does not use 'static')
```

```c++
struct Foo;
struct S
{
   static int a[]; // declaration, incomplete type
   static Foo x;   // declaration, incomplete type
   static S s;     // declaration, incomplete type (inside its own definition)
};

int S::a[10]; // definition, complete type
struct Foo {};
Foo S::x;     // definition, complete type
S S::s;       // definition, complete type
```

```c++
struct X
{
    static void f(); // declaration
    static int n;    // declaration
};

X g() { return X(); } // some function returning X

void f()
{
    X::f();  // X::f is a qualified name of static member function
    g().f(); // g().f is member access expression referring to a static member function
}

int X::n = 7; // definition

void X::f() // definition
{
    n = 1; // X::n is accessible as just n in this scope
}
```
