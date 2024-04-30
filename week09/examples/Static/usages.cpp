#include <iostream>
#include <fstream>

// example of static member variable usage
class WithUniqueId
{
    static unsigned uniqueId;
    unsigned id;

protected:
    WithUniqueId() : id{uniqueId++}
    {
    }

    WithUniqueId(const WithUniqueId &u) : WithUniqueId()
    {
    }

public:
    int getId()
    {
        return id;
    }

    friend class Ticket;
};

unsigned WithUniqueId::uniqueId = 0;

class Ticket
{
    // having unique id as a member variable - composition
    WithUniqueId id;

public:
    Ticket() : id()
    {
    }

    int getId()
    {
        return id.id;
    }
};

// inheritance
class Student : public WithUniqueId
{
};

// number of instances
class WithNumberOfInstances
{
    static int numberOfInstances;

public:
    WithNumberOfInstances()
    {
        std::cout << 'a' << ++numberOfInstances << '\n';
    }

    WithNumberOfInstances(const WithNumberOfInstances &a) : WithNumberOfInstances()
    {
    }

    WithNumberOfInstances(const WithNumberOfInstances &&a) : WithNumberOfInstances()
    {
    }

    ~WithNumberOfInstances()
    {
        numberOfInstances--;
    }

    static int getNumberOfInstances()
    {
        return numberOfInstances;
    }
};

int WithNumberOfInstances::numberOfInstances = 0;

// Singleton pattern
class Database
{
    // static Database* db;

    const std::string pathName = "./db.sql";
    std::fstream fs;
    std::string content;

    Database()
    {
        fs.open(pathName);
    }

public:
    static Database *getInstance()
    {
        // lazy
        /*if (!db) {
            db = new Database();
        }*/
        static Database db;
        return &db;
    }

    Database(const Database &) = delete;
    Database(const Database &&) = delete;

    Database &operator=(const Database &) = delete;
    Database &operator=(const Database &&) = delete;

    void createTicket(/*... args*/)
    {
    }

    void deleteTicket(/*... args*/)
    {
    }
};

// Database* Database::db = nullptr;

class Application
{
public:
    static void run()
    {
        std::string input;
        while (true)
        {
            std::cin >> input;
            if (input == "exit")
            {
                break;
            }
            if (input == "craete ticket")
            {
                Database::getInstance()->createTicket();
            }
            if (input == "delete ticket")
            {
                Database::getInstance()->deleteTicket();
            }
            std::cout << input << '\n';
        }
    }
};

void f()
{
    // example for static variables inside a function
    static int a = 5;
    std::cout << a++;
}

int main()
{
    // WithNumberOfInstances a, a1, a2 = a1;
    // {
    //     WithNumberOfInstances a4;
    // }
    // std::cout << WithNumberOfInstances::getNumberOfInstances() << ' ' << a.getNumberOfInstances() << ' ' << a1.getNumberOfInstances() << ' ' << a2.getNumberOfInstances();

    // Ticket t, t1, t2;
    // std::cout << t.getId() << ' ' <<t1.getId() << ' ' << t2.getId() << ' ';

    // Student s, s1, s2;
    // std::cout << s.getId() << ' ' << s1.getId() << ' ' << s2.getId() << ' ';

    // Application::run();
    Database *d1 = Database::getInstance(), *d2 = Database::getInstance();
    std::cout << d1 << " " << d2 << '\n';

    // f();
    // f();
    // f();
    // f();
    // f();
}