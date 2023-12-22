//
// Created by 沈嘉瑞 on 2023.10.15.
//

#ifndef SIMPLE_CALCULATOR_MENU_H
#define SIMPLE_CALCULATOR_MENU_H
#include "Calculator.h"

class Menu{
private:
    Calculator calculator;
public:
    void outPutMenu();

    void Input();
    void Watch();
    void Calculate();
    void ExitApp();
};

#endif //SIMPLE_CALCULATOR_MENU_H