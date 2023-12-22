//
// Created by 沈嘉瑞 on 2023.10.15.
//

#ifndef SIMPLE_CALCULATOR_SQSTACK_H
#define SIMPLE_CALCULATOR_SQSTACK_H
#include "Tool.h"
const int Stack_Maxsize = 100;//栈容量100

//类定义
template<class T>
class SqStack {
private:
    T *data;
    int top;//栈顶元素数组下标
public:
    SqStack();
    ~SqStack();
    bool empty();
    bool full();
    void push(T);
    T pop();
    T getTop();
    int size();
    //void clear();无需实现的清空函数
    //T peek();无需实现的查看函数
};

//构造函数
template<class T>
SqStack<T>::SqStack() {
    data = new T[Stack_Maxsize];
    top = -1;
}

//析构函数
template<class T>
SqStack<T>::~SqStack(){
    delete [] data;
}

//栈是否空
template<class T>
bool SqStack<T>::empty() {
    return top == -1;
}

//栈是否满
template<class T>
bool SqStack<T>::full() {
    return top == Stack_Maxsize-1;
}

//压入栈
template<class T>
void SqStack<T>::push(T e) {
    if (full()){
        throw StackFullException("栈已满，操作失败。");
    } else{
        data[++top] = e;
    }
}

//弹出栈
template<class T>
T SqStack<T>::pop() {
    if (empty()) {
        throw StackEmptyException("栈是空的，操作失败。");
    } else{
        return data[top--];
    }
}

//获得栈顶
template<class T>
T SqStack<T>::getTop() {
    return data[top];
}

//数量
template<class T>
int SqStack<T>::size() {
    return top+1;
}

#endif //SIMPLE_CALCULATOR_SQSTACK_H
