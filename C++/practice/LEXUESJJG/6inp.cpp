#include <iostream>
using namespace std;

class Client
{
    char *m_name;
    int m_age;
public:
    Client();
    void input(char *name, int age);
    void display();
    ~Client();
};

Client::Client()
{
    m_name = new char[40]();  //此处不可char *m_name 重复声明导致初始化不到类中
}

void Client::input(char *name, int age)
{
    for (int i = 0; name[i] != 0; i++)
    {
        m_name[i] = name[i];
    }
    m_age = age;
}

void Client::display()
{
    cout << "Name:" << m_name << endl << "Age:" << m_age << endl;
}

Client::~Client()
{
}

int main()
{
    char name[40];
    int age;
    cin >> name >> age;
    Client theClient = Client();
    theClient.input(name, age);
    theClient.display();
    getchar();
    getchar();
    theClient.~Client();
    return 0;
}