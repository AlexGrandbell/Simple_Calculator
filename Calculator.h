//
// Created by 沈嘉瑞 on 2023.10.15.
//

#ifndef SIMPLE_CALCULATOR_CALCULATOR_H
#define SIMPLE_CALCULATOR_CALCULATOR_H
#include "SqStack.h"
#include "LinkStack.h"

class Calculator {
private:
    string InfixExpression;//中缀表达式
    string PostfixExpression;//后缀表达式
public:
    Calculator();
    void setInfixExpression(string);
    void setPostfixExpress(string);
    void InfixToPostfix();
    void PostfixToInfix();
    string getInfixExpression();
    string getPostfixExpression();
    double calculateInfixExpression_Stack();
    double calculateInfixExpression_List();
    double calculatePostfixExpress_Stack();
    double calculatePostfixExpress_List();
    string InfixExpressionTest(string);
    string PostfixExpressTest(string);
};

#endif //SIMPLE_CALCULATOR_CALCULATOR_H
