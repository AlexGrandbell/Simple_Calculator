//
// Created by 沈嘉瑞 on 2023.10.15.
//

#ifndef SIMPLE_CALCULATOR_EXCEPTION_H
#define SIMPLE_CALCULATOR_EXCEPTION_H
#include <stdexcept> // 包含stdexcept头文件以使用标准异常类
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

//异常父类
class MyException:public exception{
public:
    explicit MyException(const char* message):errorMessage(message){}
    const char * what() const noexcept override{
        return errorMessage.c_str();
    }
private:
    string errorMessage;
};

//输入公式符号异常
class inputException:public MyException{
public:
    explicit inputException(const char* message): MyException(message){}
};

//手动退出
class ExitException:public MyException{
public:
    ExitException(const char* message): MyException(message){}
};

//数字输入字符异常
class NumberException:public MyException{
public:
    NumberException(const char* message): MyException(message){}
};

//栈满异常
class StackFullException:public MyException{
public:
    StackFullException(const char* message): MyException(message){}
};

//栈空异常
class StackEmptyException:public MyException{
public:
    StackEmptyException(const char* message): MyException(message){}
};

//链表栈空异常
class ListStackEmptyException: public MyException{
public:
    ListStackEmptyException(const char* message): MyException(message){}
};

//表达式未初始化异常
class ExpressEmptyException: public MyException{
public:
    ExpressEmptyException(const char* message): MyException(message){}
};

#endif //SIMPLE_CALCULATOR_EXCEPTION_H