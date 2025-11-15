#include <iostream>
#include <string>

//写一个程序：输入一个人的名字和年龄，输出“Hello, XXX, you are XX years old!”
int main()
{
    std::string name;
    int age;
    std::cout << "请输入年龄：";
    std::cin >> age;
    std::cout << "请输入姓名：";
    std::cin >> name;
    std::cout << "Hello, " << name << ", " << "you are " << age << "years old!" << std::endl;


    return 0;
}