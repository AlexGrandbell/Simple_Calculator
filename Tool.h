//
// Created by 沈嘉瑞 on 2023.10.15.
//

#ifndef SIMPLE_CALCULATOR_TOOL_H
#define SIMPLE_CALCULATOR_TOOL_H
#include "Exception.h"

double inputDouble();
int inputInt();
string inputString();
double doubleNumberTest(string);
int intNumberTest(string);
void exitTest(string);
bool isOperator(char);
int isLarge(char,char );
double calculate(char,double,double);

#endif //SIMPLE_CALCULATOR_TOOL_H
