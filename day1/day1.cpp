#include <iostream>
#include <vector>
#include <string>
/*
功能要求（Day 1 只做最基础框架）
    可以输入学生姓名和学号
    可以输出学生信息列表
    数据用 数组或 vector 存储
*/
class Student
{
public:
    void setStudent()
    {
        std::cout << "请输入姓名：";
        std::cin >> name_;
        std::cout << "请输入年龄：";
        std::cin >> age_;
    }

    void print() const
    {
        std::cout << "姓名：" << name_ << "  年龄：" << age_ << std::endl;
    }

private:
    std::string name_;
    int age_;
};

int main()
{
    std::vector<Student> students;

    while (true)
    {
        std::cout << "\n=== 学生管理系统 ===\n";
        std::cout << "1. 添加学生\n";
        std::cout << "2. 打印所有学生\n";
        std::cout << "3. 退出\n";
        std::cout << "请选择：";

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            Student stu;
            stu.setStudent();
            students.emplace_back(stu);
        }
        else if (choice == 2)
        {
            std::cout << "\n当前学生信息：\n";
            for (const auto& stu : students)
            {
                stu.print();
            }
        }
        else if (choice == 3)
        {
            break;  // 正常退出
        }
        else
        {
            std::cout << "无效输入，请重试。\n";
        }
    }

    return 0;
}