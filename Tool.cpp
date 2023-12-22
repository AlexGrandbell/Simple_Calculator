//
// Created by 沈嘉瑞 on 2023.10.15.
//

#include "Tool.h"

double inputDouble(){
    string tmp;
    cin>>tmp;
    exitTest(tmp);
    return doubleNumberTest(tmp);
}

int inputInt(){
    string tmp;
    cin>>tmp;
    exitTest(tmp);
    return intNumberTest(tmp);
}

string inputString(){
    string tmp;
    cin>>tmp;
    exitTest(tmp);
    return tmp;
}

//double转换
double doubleNumberTest(string num){
    double tempDouble = 0;
    std::istringstream iss(num);
    if (iss >> tempDouble) {
        return tempDouble;
    } else {
        throw NumberException("在需要输入小数的地方输入的不是一个数字，操作失败！");
    }
};

int intNumberTest(string num){
    int tempDouble = 0;
    std::istringstream iss(num);
    if (iss >> tempDouble) {
        return tempDouble;
    } else {
        throw NumberException("在需要输入整数的地方输入的不是一个数字，操作失败！");
    }
}

void exitTest(string s){
    if (s == "q"){
        throw ExitException("已手动退出进程。");
    }
}

//是否是运算符
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

//运算符大小比较
int isLarge(char c1,char c2){
    switch (c1) {
        case '+':
        case '-':
            switch (c2) {
                case '(':
                case '=':
                    return 1;
                default:
                    return 0;
            }
        case '*':
        case '/':
            switch (c2) {
                case '*':
                case '/':
                case ')':
                    return 0;
                default:
                    return 1;
            }
        case '(':
            switch (c2) {
                case ')':
                    throw inputException("表达式左括号匹配错误，计算失败。");
                default:
                    return 1;
            }
        case ')':
            switch (c2) {
                case '(':
                    return 2;
                case '=':
                    throw inputException("表达式右括号匹配错误，计算失败。");
                default:
                    return 0;
            }
        case '=':
            switch (c2) {
                case '=':
                    return 2;
                case '(':
                    throw inputException("表达式等号匹配错误，计算失败。");
                default:
                    return 0;
            }
        default:
            throw inputException("运算符比较错误,操作失败。");
    }
}

//四则运算
double calculate(char c,double num1,double num2){
    double result = 0.0;
    switch (c) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            throw inputException("表达式操作符错误，计算失败。");
    }
    return result;
}