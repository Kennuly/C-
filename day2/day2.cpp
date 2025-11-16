#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Student
{
public:
    bool operator<(Student std)
    {
        return id_ < std.getid();
    }
    Student(int id = -1, std::string name = "nullptr", int age = -1) : id_(id), name_(name), age_(age) {}
    ~Student() = default;

    int getid() const
    {
        return id_;
    }
    std::string getname() const
    {
        return name_;
    }
    int getage() const
    {
        return age_;
    }
    void print() const
    {
        std::cout << "id：" << id_ << "\t姓名：" << name_ << "\t年龄：" << age_ << std::endl;
    }

private:
    int id_;
    std::string name_;
    int age_;
};
class Management
{
public:
    void start()
    {
        while (true)
        {
            std::cout << "\n=== 学生管理系统 ===\n";
            std::cout << "1. 添加学生\n";
            std::cout << "2. 打印所有学生\n";
            std::cout << "3. 查找学生\n";
            std::cout << "4. 删除学生\n";
            std::cout << "5. 退出\n";
            std::cout << "请选择：";
            int choice;
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                AddStudent();
                break;
            case 2:
                Print();
                break;
            case 3:
            {
                int id = -1;
                std::cout << "请输入学生id：";
                std::cin >> id;
                const Student std = idTogetStudent(id);
                if (std.getid() == -1)
                {
                    std::cout << "不存在此学生" << std::endl;
                }
                else
                {
                    std.print();
                }
            }
            break;
            case 4:
            {
                int id = -1;
                std::cout << "请输入学生id：";
                std::cin >> id;
                bool ret = removeStudnet(id);
                if (ret)
                {
                    std::cout << "删除成功" << std::endl;
                }
                else
                {
                    std::cout << "删除失败" << std::endl;
                }
            }
            break;
            case 5:
                return;
            }
        }
    }
    // 添加学生
    bool AddStudent()
    {
        std::string name;
        int age, id;
        std::cout << "请输入学号：";
        std::cin >> id;
        for (const auto &student : std_)
        {
            if (id == student.getid())
            {
                std::cout << "本学生已存在" << std::endl;
                return false;
            }
        }
        std::cout << "请输入姓名：";
        std::cin >> name;
        std::cout << "请输入年龄：";
        std::cin >> age;
        std_.emplace_back(Student(id, name, age));
        return true;
    }
    // 打印学生
    void Print()
    {
        std::sort(std_.begin(), std_.end());
        for (const auto &std : std_)
        {
            std.print();
        }
    }
    // id查找
    const Student idTogetStudent(int id)
    {
        for (const auto &student : std_)
        {
            if (id == student.getid())
            {
                return student;
            }
        }
        std::cout << "不存在该学生！" << std::endl;
        return Student();
    }
    // id删除
    bool removeStudnet(int id)
    {
        for (std::vector<Student>::iterator it = std_.begin(); it != std_.end(); it++)
        {
            if (it->getid() == id)
            {
                std_.erase(it);
                return true;
            }
        }
        return false;
    }

private:
    std::vector<Student> std_;
};

int main()
{
    Management manage;
    manage.start();
    return 0;
}