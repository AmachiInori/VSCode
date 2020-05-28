#include <iostream>
using namespace std;

class counter
{
    int m_number;
public:
    counter();
    void countWord(char *sent);
    int show();
    ~counter();
};

counter::counter()
{
    m_number = 0;
}

void counter::countWord(char *sent)
{
    int temp = 0;
    int isStart = 0;
    for (int i = 0; sent[i] != 0; i++)
    {
        if (sent[i] == ' ')
        {
            if (isStart == 1)
            {
                isStart = 0;
            }
        }
        else 
        {
            if (isStart == 0)
            {
                temp++;
                isStart = 1;
            }
        }
    }
    
    m_number = temp;
}

int counter::show()
{
    return m_number;
}

counter::~counter()
{
}

int main()
{
    char sents[60] = { 0 };
    cin.get(sents,20);
    counter theCounter = counter();
    theCounter.countWord(sents);
    cout << "Words=" << theCounter.show() << endl;
    cin.get();
    cin.get();
    return 0;
}