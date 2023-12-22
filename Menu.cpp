//
// Created by 沈嘉瑞 on 2023.10.15.
//

#include "Menu.h"

//显示菜单
void Menu::outPutMenu(){
    cout<<"\n ----------菜单----------"<<endl;
    cout<<" |1.输入表达式          |"<<endl;
    cout<<" |2.查看表达式          |"<<endl;
    cout<<" |3.计算表达式          |"<<endl;
    cout<<" |0.退出程序            |"<<endl;
    cout<<" ------------------------"<<endl;
    //输出提示选择编号
    cout<<"请选择菜单项编号(0-3):";
}

//输入表达式
void Menu::Input(){
    cout << "--------输入表达式--------" << endl;
    try {
        int choice = 1;
        cout<<"请选择输入的表达式类型(1-中缀表达式,2-后缀表达式):";
        choice = inputInt();
        switch (choice) {
            case 1:
                cout<<"请输入中缀表达式(不用以空格区分，以\"=\"结束):";
                calculator.setInfixExpression(inputString());
                break;
            case 2:
                cout<<"请输入后缀表达式(以空格区分，以\"=\"结束):";
                calculator.setPostfixExpress(inputString());
                break;
            default:
                throw NumberException("无效选择。");
        }
        cout<<"输入成功!且另一种表达式转换成功!"<<endl;
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "--------------------------" << endl;
}

//查看表达式
void Menu::Watch(){
    cout << "--------查看表达式--------" << endl;
    try {
        int choice = 1;
        cout<<"请选择查看的表达式类型(1-中缀表达式,2-后缀表达式,3-都查看):";
        choice = inputInt();
        string exp = "";
        switch (choice) {
            case 1:
                exp = calculator.getInfixExpression();
                cout<<"中缀表达式为:"<<exp<<endl;
                break;
            case 2:
                exp = calculator.getPostfixExpression();
                cout<<"后缀表达式为:"<<exp<<endl;
                break;
            case 3:
                exp = calculator.getInfixExpression();
                cout<<"中缀表达式为:"<<exp<<endl;
                exp = calculator.getPostfixExpression();
                cout<<"后缀表达式为:"<<exp<<endl;
                break;
            default:
                throw NumberException("无效选择。");
        }
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "--------------------------" << endl;
}

//计算表达式
void Menu::Calculate(){
    cout << "--------计算表达式--------" << endl;
    try {
        int choice = 1;
        cout<<"请选择使用哪种计算方式类型(1-中缀表达式(顺序栈),2-中缀表达式(链式栈),3-后缀表达式(顺序栈),4-后缀表达式(链式栈),5-都算一遍):";
        choice = inputInt();
        string exp = "";
        double res = 0.0;
        switch (choice) {
            case 1:
                exp = calculator.getInfixExpression();
                res = calculator.calculateInfixExpression_Stack();
                cout<<"计算结果为:"<<exp<<"   "<<fixed<< setprecision(3)<<res<<endl;
                break;
            case 2:
                exp = calculator.getInfixExpression();
                res = calculator.calculateInfixExpression_List();
                cout<<"计算结果为:"<<exp<<"   "<<fixed<< setprecision(3)<<res<<endl;
                break;
            case 3:
                exp = calculator.getPostfixExpression();
                res = calculator.calculatePostfixExpress_Stack();
                cout<<"计算结果为:"<<exp<<"   "<<fixed<< setprecision(3)<<res<<endl;
                break;
            case 4:
                exp = calculator.getPostfixExpression();
                res = calculator.calculatePostfixExpress_List();
                cout<<"计算结果为:"<<exp<<"   "<<fixed<< setprecision(3)<<res<<endl;
                break;
            case 5:
                exp = calculator.getInfixExpression();
                res = calculator.calculateInfixExpression_Stack();
                cout<<"方法1计算结果为:"<<exp<<"   "<<fixed<< setprecision(3)<<res<<endl;
                res = calculator.calculateInfixExpression_List();
                cout<<"方法2计算结果为:"<<exp<<"   "<<fixed<< setprecision(3)<<res<<endl;
                exp = calculator.getPostfixExpression();
                res = calculator.calculatePostfixExpress_Stack();
                cout<<"方法3计算结果为:"<<exp<<"   "<<fixed<< setprecision(3)<<res<<endl;
                res = calculator.calculatePostfixExpress_List();
                cout<<"方法4计算结果为:"<<exp<<"   "<<fixed<< setprecision(3)<<res<<endl;
                break;
            default:
                throw NumberException("无效选择。");
        }

    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "--------------------------" << endl;
}

//退出程序
void Menu::ExitApp(){
    cout<<"\n欢迎再次使用，再见。"<<endl;
}