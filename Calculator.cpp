//
// Created by 沈嘉瑞 on 2023.10.15.
//

#include "Calculator.h"
//构造函数
Calculator::Calculator() {
    InfixExpression = "";
    PostfixExpression = "";
}

//输入中缀表达式
void Calculator::setInfixExpression(string s) {
    InfixExpression = InfixExpressionTest(s);
    InfixToPostfix();
}
//复杂测试用例
//1-(((2+3-4)/5*6-3+6)*5/3/5+6-(7-6))=

//输入后缀表达式
void Calculator::setPostfixExpress(string s) {
    PostfixExpression = PostfixExpressTest(s);
    PostfixToInfix();
}
//复杂测试用例
//123+4-5/6*3-6+5*3/5/6+76---=

//中缀转后缀并储存
void Calculator::InfixToPostfix() {
    LinkStack<char> operatorStack;
    operatorStack.push('=');
    string postExpression = "";

    for(char c: InfixExpression){
        if (isdigit(c)){
            postExpression += c;
        } else{
            while (true) {
                int comp = isLarge(c, operatorStack.getTop());
                if (comp == 1) {
                    operatorStack.push(c);
                    break;
                } else if (comp == 0) {
                    postExpression += operatorStack.pop();
                } else if (comp == 2) {
                    if (operatorStack.getTop() == '(' && c == ')') {
                        operatorStack.pop();
                        break;
                    } else if (operatorStack.getTop() == '=') {
                        while (!operatorStack.empty()){
                            postExpression += operatorStack.pop();
                        }
                        break;
                    }
                }
            }
        }
    }
    PostfixExpression = PostfixExpressTest(postExpression);
}

//后缀转中缀并储存
void Calculator::PostfixToInfix() {
    struct enExpression{
        string exp;
        char op;
        enExpression(string s,char o){
            exp = s;
            op=o;
        }
        enExpression(char c,char o){
            exp = "";
            exp += c;
            op=o;
        }
        enExpression(){
            exp = "";
            op = '.';
        };
    };
    LinkStack<enExpression> stack;
    for(char c: PostfixExpression){
        if (isdigit(c)){
            stack.push(enExpression(c,'.'));
        } else if (c != '='){
            enExpression s2 = stack.pop();
            enExpression s1 = stack.pop();
            switch (c) {
                case '-':
                    switch (s2.op) {
                        case '+':
                        case '-':
                            s2.exp = '(' + s2.exp + ')';
                            break;
                        default:
                            break;
                    }
                    break;
                case '*':
                    switch (s1.op) {
                        case '+':
                        case '-':
                            s1.exp = '(' + s1.exp + ')';
                            break;
                        default:
                            break;
                    }
                    switch (s2.op) {
                        case '+':
                        case '-':
                            s2.exp = '(' + s2.exp + ')';
                            break;
                        default:
                            break;
                    }
                    break;
                case '/':
                    switch (s1.op) {
                        case '+':
                        case '-':
                            s1.exp = '(' + s1.exp + ')';
                            break;
                        default:
                            break;
                    }
                    switch (s2.op) {
                        case '.':
                            break;
                        default:
                            s2.exp = '(' + s2.exp + ')';
                            break;
                    }
                    break;
                default:
                    break;
            }
            stack.push(enExpression((s1.exp + c + s2.exp),c));
        } else{
            break;
        }
    }
    InfixExpression = InfixExpressionTest(stack.pop().exp + '=');
}

//获得中缀表达式
string Calculator::getInfixExpression(){
    if (InfixExpression == ""){
       throw ExpressEmptyException("中缀表达式为空，请先使用1号菜单输入表达式。");
    }
    return InfixExpression;
}

//获得后缀表达式
string Calculator::getPostfixExpression() {
    if (PostfixExpression == ""){
        throw ExpressEmptyException("后缀表达式为空，请先使用1号菜单输入表达式。");
    }
    return PostfixExpression;
}

/*
栈满异常测试表达式11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
*/

//计算中缀表达式（栈）
double Calculator::calculateInfixExpression_Stack() {
    SqStack<double> numStack;
    SqStack<char> operatorStack;
    operatorStack.push('=');
    double result = 0.0;

    for(char c: InfixExpression){
        if (isdigit(c)){
            numStack.push(c - '0');
        } else{
            while (true) {
                int comp = isLarge(c, operatorStack.getTop());
                if (comp == 1) {
                    operatorStack.push(c);
                    break;
                } else if (comp == 0) {
                    char c2 = operatorStack.pop();
                    double num2 = numStack.pop(), num1 = numStack.pop();
                    numStack.push(calculate(c2, num1, num2));
                } else if (comp == 2) {
                    if (operatorStack.getTop() == '(' && c == ')') {
                        operatorStack.pop();
                        break;
                    } else if (operatorStack.getTop() == '=') {
                        break;
                    }
                }
            }
        }
    }

    return numStack.pop();
}

//计算中缀表达式（链表）
double Calculator::calculateInfixExpression_List() {
    LinkStack<double> numStack;
    LinkStack<char> operatorStack;
    operatorStack.push('=');
    double result = 0.0;

    for(char c: InfixExpression){
        if (isdigit(c)){
            numStack.push(c - '0');
        } else{
            while (true) {
                int comp = isLarge(c, operatorStack.getTop());
                if (comp == 1) {
                    operatorStack.push(c);
                    break;
                } else if (comp == 0) {
                    char c2 = operatorStack.pop();
                    double num2 = numStack.pop(), num1 = numStack.pop();
                    numStack.push(calculate(c2, num1, num2));
                } else if (comp == 2) {
                    if (operatorStack.getTop() == '(' && c == ')') {
                        operatorStack.pop();
                        break;
                    } else if (operatorStack.getTop() == '=') {
                        break;
                    }
                }
            }
        }
    }

    return numStack.pop();
}

/*
栈满异常测试表达式11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
*/

//计算后缀表达式（栈）
double Calculator::calculatePostfixExpress_Stack() {
    SqStack<double> numStack;
    double result = 0.0;
    for (char c : PostfixExpression) {
        if (isdigit(c)){
            numStack.push(c - '0');
        } else if (isOperator(c)){
            double num2 = numStack.pop(),num1 = numStack.pop();
            numStack.push(calculate(c,num1,num2));
        }
    }
    return numStack.pop();
}

//计算后缀表达式（链表）
double Calculator::calculatePostfixExpress_List() {
    LinkStack<double> numStack;
    double result = 0.0;
    for (char c : PostfixExpression) {
        if (isdigit(c)){
            numStack.push(c - '0');
        } else if (isOperator(c)){
            double num2 = numStack.pop(),num1 = numStack.pop();
            numStack.push(calculate(c,num1,num2));
        }
    }
    return numStack.pop();
}

//中缀表达式检测
string Calculator::InfixExpressionTest(string s){
    LinkStack<char> operatorStack;
    int equalNum = 0;
    //至少两个字符
    if (s.length()<=1){
        throw inputException("表达式太短，输入错误。");
    }

    //=只能在最后且只有一个
    for (char i : s) {
        if (i == '='){
            equalNum++;
        }
    }
    if (s[s.length()-1]!='='){
        throw inputException("未以等号结尾，输入失败。");
    } else if (equalNum != 1) {
        throw inputException("等号数量错误，输入失败。");
    }

    //是否有非法字符
    for (char i : s) {
        if (!(isOperator(i) || isdigit(i) || i == '(' || i == ')' || i == '=')){
            throw inputException("表达式中含有非法字符(只能有+-*/=()以及数字)，输入失败。");
        }
    }

    //括号匹配
    for (char i : s) {
        if (i == '('){
            operatorStack.push(i);
        }
        if (i == ')'){
            if (operatorStack.empty()){
                throw inputException("表达式左括号不匹配，输入失败。");
            }
            operatorStack.pop();
        }
    }
    if (!operatorStack.empty()){
        throw inputException("表达式右括号数量不匹配，输入失败。");
    }

    //括号不能相邻
    for (int i = 0; i < s.length() - 1; ++i) {
        if (((s[i] == '(') && (s[i+1] == ')')) || ((s[i] == ')') && (s[i+1] == '('))){
            throw inputException("表达式括号相邻，输入失败。");
        }
    }

    //运算符前只能是数字或),运算符后只能是数字或(,不能是第一个或最后。负号-比较特殊，若-前面是(，则看作负数，后面是能是数字而不能是(.
    for (int i = 0; i < s.length(); ++i) {
//        //先进行负号判断（负数使用，已弃用）
//        if (s[i] == '-'){
//            if ((i==0 && isdigit(s[i+1])) || (i>0 && s[i-1] == '(' && i<=(s.length()-4) && isdigit(s[i+1]))){
//                i++;
//            }
//        }
        //运算符判断
        if (isOperator(s[i])){
            if (i==0 || i>=s.length()-2){
                throw inputException("运算符不能出现在开头或结尾，输入失败。");
            } else if (!((isdigit(s[i-1])||s[i-1]==')')&&(isdigit(s[i+1])||s[i+1]=='('))){
                throw inputException("运算符不能连续出现，输入失败。");
            }
        }
    }

    //个位数字判断
    for (int i = 0; i < s.length(); ++i) {
        if (i == 0 && isdigit(s[i])){
            if (isdigit(s[i+1])){
                throw inputException("建议不要输入大于9的多位整数，请重新输入。");
            }
        } else if (i >= s.length()-2 && isdigit(s[i])){
            if (isdigit(s[i-1])){
                throw inputException("建议不要输入大于9的多位整数，请重新输入。");
            }
        } else if (isdigit(s[i])){
            if (isdigit(s[i-1] || isdigit(s[i+1]))){
                throw inputException("建议不要输入大于9的多位整数,你可以使用乘法和加法来拆分这个数,请重新输入。");
            }
        }
    }
//    //小数点前后必须是数字，且一个数字未结束不能出现多个小数点（已弃用）
//    int dot = 0;
//    for (int i = 0; i < s.length(); ++i) {
//        if (s[i] == '.'){
//            if (i == 0 || i >= s.length()-2){
//                throw inputException("小数点不能出现在开头或结尾，输入失败。");
//            } else if (dot > 0){
//                throw inputException("一个数中不能同时出现多个小数点，输入失败。");
//            } else if (!(isdigit(s[i-1]) && isdigit(s[i+1]))){
//                throw inputException("小数点格式错误，输入失败。");
//            } else{
//                dot++;
//            }
//        } else if (isOperator(s[i]) || s[i]=='(' || s[i] == ')') {
//            dot=0;
//        }
//    }

    return s;
}

//后缀表达式检测
string Calculator::PostfixExpressTest(string s){
    LinkStack<char> numStack;
    int equalNum = 0;
    //至少两个字符
    if (s.length()<=1){
        throw inputException("表达式太短，输入错误。");
    }

    //=只能在最后且只有一个
    for (char i : s) {
        if (i == '='){
            equalNum++;
        }
    }
    if (s[s.length()-1]!='='){
        throw inputException("未以等号结尾，输入失败。");
    } else if (equalNum != 1) {
        throw inputException("等号数量错误，输入失败。");
    }

    //是否有非法字符
    for (char i : s) {
        if (!(isOperator(i) || isdigit(i) || i == '=')){
            throw inputException("表达式中含有非法字符(仅能有+-*/=和数字)，输入失败。");
        }
    }

    //栈分析
    for (char i : s) {
        if (isdigit(i)){
            numStack.push(i);
        } else if (isOperator(i)){
            if (numStack.size()<2){
                throw inputException("表达式运算符与数字数量不匹配，输入失败。");
            } else{
                numStack.pop();
            }
        }
    }
    if (numStack.size() != 1){
        throw inputException("表达式运算符与数字数量不匹配，输入失败。");
    }
    return s;
}