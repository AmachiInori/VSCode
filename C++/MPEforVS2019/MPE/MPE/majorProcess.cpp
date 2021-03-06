#include "linearAnalysis.hpp"
#include "smooth.hpp"
#include "expr.hpp"

int console() {
    cout << "欢迎使用MPExAutoDataAnaly实验数据处理工具，目前版本为0.13，更新日期20200908。\n";
    cout << "本工具作者@AmachiInori，本工具由GPL3.0开源，但建议你不要看它的源代码\n因为它实在是太下饭了，连我自己都不想看\n";
    vector<int(*)()> entrance({0, expr2, expr3, expr7, expr8, expr1 ,exprC1});
    auto getList = [](){
        cout << "\n-----------------------------------------------\n";
        cout << "目前支持的实验处理有\n";
        cout << "1 材料物理实验：利用紫外测定聚N-异丙基丙烯酰胺的最低溶液温度\n";
        cout << "2 材料物理实验：热塑性塑料熔体流动速率的测定\n";
        cout << "3 材料物理实验：光电信号转换测试\n";
        cout << "4 材料物理实验：X射线光电子能谱演示实验\n";
        cout << "5 材料物理实验：聚合物拉伸强度和断裂伸长率的测定\n";
        cout << "-----------------------------------------------\n";
        cout << "其余的在上课过程中同步开发\n";
        cout << "不是我不想写，是真的因为看不懂实验报告要我干什么\n\n";
    };
    auto help = [](){
        cout << "\n-----------------------------------------------\n";
        cout << "指令:\n";
        cout << "help  显示帮助\n";
        cout << "list  显示支持的实验列表\n";
        cout << "start [expr number]  开始指定序号的实验处理\n";
        cout << "docu  打开官方文档(amachi.com.cn)\n";
        cout << "exit  退出程序\n";
        cout << "-----------------------------------------------\n";
    };
    help();
    getList();
    while (1) {
        string com;
        cin >> com;
        if (com == "help") {
            cin.sync();
            help();
        } else if (com == "list") {
            cin.sync();
            getList();
        } else if (com == "start") {
            string tempS;
            cin >> tempS;
            int temp;
            try {
                temp = stoi(tempS);
            } catch (std::invalid_argument) {
                cin.sync();
                cout << tempS << "不是有效的参数\n";
            }
            if (temp > 0 && temp < entrance.size()) {
                cin.sync();
                if(entrance[temp]() == 0) cout << "进程expr" << temp << "运行完成\n";
                help();
            } else {                cout << tempS << "不是有效的参数\n";
            }
        } else if (com == "exit") break;
        else if (com == "docu") {
            cin.sync();
            system("start https://amachi.com.cn/_posts/2020-09-06-MPEDP%E5%AE%98%E6%96%B9%E6%96%87%E6%A1%A3/");
        } else {
            cout << '"' << com << "\"不是有效的命令\n";
        }
    }
    return 0;
}

double tempF(double x) {
    long double res = x * (0.2656 * x + (1 - x));
    res /= (0.2656 * x * x + 2 * x * (1 - x) + 1.4503 * (1 - x) * (1 - x));
    return res;
}

int main() {
    funcDraw fz(tempF);
    fz.drawFunction(0.00000000001, 1);
    //    return console();
}   