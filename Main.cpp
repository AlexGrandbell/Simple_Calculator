#include "Menu.h"

int main() {
    Menu menu;
    cout << "\n欢迎进入整数四则运算表达式计算器" << endl;
    cout << "\n受限于表达式的格式，你的运算数只能是0-9的正整数，并且只能进行+-*/运算" << endl;
    cout<<"你可以随时输入'q'来退出当前操作。"<<endl;
    cout<<"----------任意输入以开始----------"<<endl;
    string tmp;
    cin>>tmp;
    cout<<"\n\n\n\n\n"<<endl;
    int nSelection = -1;//判断用户输入的数字选择对应的菜单
    string input;

    //不断循环，执行操作
    do {
        //界面与输入
        menu.outPutMenu();//界面
        fflush(stdin);//清除输入流缓存
        nSelection = -1;
        try {
            nSelection = inputInt();

            //根据输入选择行为
            switch (nSelection) {
                case 0: {
                    menu.ExitApp();
                    return 0;
                }//再见
                case 1: {
                    menu.Input();
                    break;
                }//输入
                case 2: {
                    menu.Watch();
                    break;
                }//查看
                case 3: {
                    menu.Calculate();
                    break;
                }//计算
                default: {
                    printf("您输入的菜单序号错误,");
                    break;
                }//错误
            }//完成
        } catch (const exception &e) {
            cerr << e.what() << endl;
        }
        if (nSelection != 0) {
            printf("继续操作请按1，关闭程序请按0:");
            fflush(stdin);//清除输入流缓存
            nSelection = -1;
            try {
                nSelection = inputInt();
                if (nSelection == 0) {
                    menu.ExitApp();
                }
            }catch  (const exception& e){
                cerr<<e.what()<<endl;
            }
        }
    } while (nSelection != 0);
    return 0;
}
