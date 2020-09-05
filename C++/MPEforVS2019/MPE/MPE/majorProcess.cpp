#include "linearAnalysis.h"
#include "smooth.h"
#include "expr.h"

int console() {
    cout << "��ӭʹ��MPExAutoDataAnalyʵ�����ݴ����ߣ�Ŀǰ�汾Ϊ0.10beta����������20200905��\n";
    cout << "����������@AmachiInori����������ȫ��Դ�������㲻Ҫ������Դ����\n��Ϊ��ʵ����̫�·��ˣ������Լ������뿴\n";
    vector<int(*)()> entrance({0, expr2, expr3, exprC1});
    auto getList = [](){
        cout << "\n-----------------------------------------------\n";
        cout << "Ŀǰ֧�ֵ�ʵ�鴦����\n";
        cout << "1 ��������ʵ�飺��������ⶨ��N-�������ϩ�����������Һ�¶�\n";
        cout << "2 ��������ʵ�飺���������������������ʵĲⶨ\n";
        cout << "-----------------------------------------------\n";
        cout << "��������Ͽι�����ͬ������\n";
        cout << "�����Ҳ���д���������Ϊ������ʵ�鱨��Ҫ�Ҹ�ʲô\n\n";
    };
    auto help = [](){
        cout << "\n-----------------------------------------------\n";
        cout << "ָ��:\n";
        cout << "help  ��ʾ����\n";
        cout << "list  ��ʾ֧�ֵ�ʵ���б�\n";
        cout << "start [expr number]  ��ʼָ����ŵ�ʵ�鴦��\n";
        cout << "exit  �˳�����\n";
        cout << "-----------------------------------------------\n";
    };
    help();
    getList();
    while (1) {
        string com;
        cin >> com;
        if (com == "help") {
            cin.clear();
            help();
        } else if (com == "list") {
            cin.clear();
            getList();
        } else if (com == "start") {
            int temp;
            cin >> temp;
            if (temp > 0 && temp < entrance.size()) {
                cin.clear();
                if(entrance[temp]() == 0) cout << "����expr" << temp << "�������\n";
            } else {
                cout << temp << "������Ч�Ĳ���\n";
            }
        } else if (com == "exit") break;
        else {
            cout << '"' << com << "\"������Ч������\n";
        }
    }
    return 0;
}

int main() {
    return console();
}