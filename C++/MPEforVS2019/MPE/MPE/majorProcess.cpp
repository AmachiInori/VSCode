#include "linearAnalysis.h"
#include "smooth.h"
#include "expr.h"

int console() {
    cout << "��ӭʹ��MPExAutoDataAnalyʵ�����ݴ����ߣ�Ŀǰ�汾Ϊ0.10beta����������20200906��\n";
    cout << "����������@AmachiInori����������GPL3.0��Դ���������㲻Ҫ������Դ����\n��Ϊ��ʵ����̫�·��ˣ������Լ������뿴\n";
    vector<int(*)()> entrance({0, expr2, expr3, expr7, exprC1});
    auto getList = [](){
        cout << "\n-----------------------------------------------\n";
        cout << "Ŀǰ֧�ֵ�ʵ�鴦����\n";
        cout << "1 ��������ʵ�飺��������ⶨ��N-�������ϩ�����������Һ�¶�\n";
        cout << "2 ��������ʵ�飺���������������������ʵĲⶨ\n";
        cout << "3 ��������ʵ�飺����ź�ת������\n";
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
        cout << "docu  �򿪹ٷ��ĵ�(amachi.com.cn)\n";
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
            string tempS;
            cin >> tempS;
            int temp;
            try {
                temp = stoi(tempS);
            } catch (std::invalid_argument) {
                cin.clear();
                cout << tempS << "������Ч�Ĳ���\n";
            }
            if (temp > 0 && temp < entrance.size()) {
                cin.clear();
                if(entrance[temp]() == 0) cout << "����expr" << temp << "�������\n";
                help();
            } else {
                cout << tempS << "������Ч�Ĳ���\n";
            }
        } else if (com == "exit") break;
        else if (com == "docu") {
            cin.clear();
            system("start https://amachi.com.cn/_posts/2020-09-06-MPEDP%E5%AE%98%E6%96%B9%E6%96%87%E6%A1%A3/");
        } else {
            cout << '"' << com << "\"������Ч������\n";
        }
    }
    return 0;
}

int main() {
    return expr7();
//    return console();
}