#include <iostream>
#include <cassert>
#include "InterpolationPair.h"
#include "TagPair.h"
#include "ComplexPair.h"
#include "KNYAML.h"
#include "KNYAML_resizeable_set.h"
#include "ResizableSet.h"

void testSimplePair()
{
    try
    {
        SimplePair sp("Key", "Value");
        assert(("Key cannot start contain capital letters", false));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        SimplePair sp("asd_basd", "Value");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        assert(false);
    }
}

void testInterpolationPair()
{
    try
    {
        InterpolationPair ip("asd_basd", "My name is %{username}");
        ip.printValue();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        assert(false);
    }

    try
    {
        InterpolationPair ip("asd_basd", "My name is ");
        assert(("Value must contain interpolation string", false));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        InterpolationPair ip("asd_basd", "My name is %{first} %{second}");
        ip.printValue();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        assert(("Can contain more than one interpolation strings", false));
    }

    try
    {
        InterpolationPair ip("asd_basd", "My name is %{name} %{name}");
        assert(("Interpolations must be unique", false));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        InterpolationPair ip("asd_basd", "My name is %{}");
        assert(("Value must contain interpolation string", false));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        InterpolationPair ip("asd_basd", "My name is %{USERNAME}");
        assert(("Interpolation string must be lower cased", false));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testTagPair()
{
    try
    {
        TagPair tp("greeting_html", "\"How are <b>you?</b> <br/> <hr/>\"");
        tp.printValue();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        assert(("Tag Pair is valid", false));
    }

    try
    {
        TagPair tp("ml", "\"How are <b>you?</b> <br/> <hr/>\"");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        TagPair tp("greeting_html", "How are <b>you?</b> <br/> <hr/>\"");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testComplexPair()
{
    try
    {
        ComplexPair cp("sth_html", "\"How are <b>you?</b>, %{name} <br/> <hr/>\"");
        cp.printValue();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        assert(false);
    }

    try
    {
        ComplexPair cp("sth_html", "\"How are <b>you?</b>, %{name1} <br/> <hr/>\"");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testKNYAML()
{
    try
    {
        KNYAML knyaml({new TagPair("greeting_html", "\"How <b>you</b> doin' <br/><br/> <hr/>\"")});
        knyaml["greeting_html"];
    }
    catch (const std::exception &e)
    {
        assert(false);
    }
}

void testResizeableSet()
{
    ResizableSet<int> rs;
    rs.add(1);
    rs.add(2);
    rs.add(3);
    rs.add(4);
    assert(rs[2]);
    assert(!rs[6]);
    assert(rs.remove(2));
    assert(!rs[2]);
    assert(!rs.remove(2));
    try
    {
        rs.add(1);
        assert(("Cannot add item that already exists", false));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    struct Tst
    {
        int i;
        double d;
        bool operator==(const Tst &t)
        {
            return i == t.i && abs(d - t.d) < 0.001;
        }
    };

    ResizableSet<Tst> rs1;
    Tst t1 = {1, 3.14}, t2 = {2, 5.67};
    rs1.add(t1);
    rs1.add(t2);
    try
    {
        rs1.add(t1);
        assert(("Cannot add item that already exists", false));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    assert(rs1.remove(t2));
    assert(!rs1[t2]);
    assert(!rs1.remove(t2));

    ResizableSet<int *> rsIntPtr(comparePtr<int>);
    rsIntPtr.add(new int(5));
    try
    {
        rsIntPtr.add(new int(5));
        assert(("Cannot add item that already exists", false));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    for (size_t i = 0; i < rsIntPtr.getSize(); i++)
    {
        delete rsIntPtr.getData()[i];
    }
}

void testKNYAMLResizeableSet()
{
    try
    {
        KNYAMLSpec knyaml({new TagPair("greeting_html", "\"How <b>you</b> doin' <br/><br/> <hr/>\""), new ComplexPair("fact_html", "\"Do you think <b>%{fact}</b> is important?\"")});
        knyaml["fact_html"];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        assert(false);
    }

    try
    {
        KNYAMLSpec knyaml({new TagPair("fact_html", "\"How <b>you</b> doin' <br/><br/> <hr/>\""), new ComplexPair("fact_html", "\"Do you think <b>%{fact}</b> is important?\"")});
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void runAllTests()
{
    testSimplePair();
    testInterpolationPair();
    testTagPair();
    testComplexPair();
    testKNYAML();
    testResizeableSet();
    testKNYAMLResizeableSet();
}