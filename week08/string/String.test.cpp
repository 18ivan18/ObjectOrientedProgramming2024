#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../../utils/doctest.h"
#include "String.cpp"

TEST_SUITE("String Tests")
{
    TEST_CASE("init empty string")
    {
        String s;
        CHECK_EQ(s.size(), 0);
        CHECK_EQ(strcmp(s, ""), 0);
    }

    TEST_CASE("init string with const char*")
    {
        String s("Ivan");
        CHECK_EQ(s.size(), 4);
        CHECK_EQ(strcmp(s, "Ivan"), 0);

        const char ivan[] = "Ivan";
        String s1(ivan);
        CHECK_EQ(s1.size(), 4);
        CHECK_EQ(strcmp(s1, "Ivan"), 0);

        char *georgi = new char[strlen("Georgi") + 1];
        strcpy(georgi, "Georgi");
        String s2(georgi);
        delete[] georgi;
        CHECK_EQ(s2.size(), 6);
        CHECK_EQ(strcmp(s2, "Georgi"), 0);
    }

    TEST_CASE("copy constructor and operator=")
    {
        String s, s1("Ivan"), s2 = s1, s3(s2);
        s = s2;
        CHECK_EQ(s1.size(), 4);
        CHECK_EQ(strcmp(s1, "Ivan"), 0);
        CHECK_EQ(s2.size(), 4);
        CHECK_EQ(strcmp(s2, "Ivan"), 0);
        CHECK_EQ(s3.size(), 4);
        CHECK_EQ(strcmp(s3, "Ivan"), 0);
        CHECK_EQ(s.size(), 4);
        CHECK_EQ(strcmp(s, "Ivan"), 0);
    }

    TEST_CASE("at")
    {
        const char test[] = "Test string";
        String str(test);
        for (unsigned i = 0; i < str.length(); i++)
        {
            CHECK_EQ(test[i], str.at(i));
        }
        CHECK_THROWS(str.at(100));
    }

    TEST_CASE("back")
    {
        String str("hello world.");
        str.back() = '!';
        CHECK_EQ(strcmp(str, "hello world!"), 0);

        const char &back = str.back();
        // back = '?';
    }

    TEST_CASE("front")
    {
        String str("hello world.");
        str.front() = 'H';
        CHECK_EQ(strcmp(str, "Hello world."), 0);
    }

    TEST_CASE("push_back")
    {
        String str("hello world");
        str.pushBack('!');
        CHECK_EQ(strcmp(str, "hello world!"), 0);
    }

    TEST_CASE("operator +=")
    {
        String name("John");
        String family("Smith");
        name += " K. "; // c-string
        name += family; // string
        name += '\n';   // character

        CHECK_EQ(strcmp(name, "John K. Smith\n"), 0);
    }

    // TEST_CASE("append")
    // {
    //     String str;
    //     String str2 = "Writing ";
    //     String str3 = "print 10 and then 5 more";

    //     // used in the same order as described above:
    //     str.append(str2);               // "Writing "
    //     str.append(str3, 6, 3);         // "10 "
    //     str.append("dots are cool", 5); // "dots "
    //     str.append("here: ");           // "here: "
    //     str.append(10u, '.');           // ".........."

    //     std::cout << str << '\n';

    //     CHECK_EQ(strcmp(str, "Writing 10 dots here: .........."), 0);
    // }
}