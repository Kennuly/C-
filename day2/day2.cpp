#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

class Student
{
public:
    bool operator<(const Student &std) const
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
            while(true)
            {
                std::cin >> choice;
                if(std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cout << "请输入合法数字！" << std::endl;
                    continue;
                }
                if(choice >= 1 && choice <= 5)
                {
                    break;
                }
                std::cout << "请输入合法选项！" << std::endl;
            }
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
                int id;
                while (true)
                {
                    std::cout << "请输入学号：";
                    std::cin >> id;
                    if (std::cin.fail() || id < 0)
                    {
                        std::cin.clear();
                        std::cin.ignore(1024, '\n');
                        std::cout << "输入非法，请输入数字！" << std::endl;
                        continue;
                    }
                    break;
                }
                Student *std = idTogetStudent(id);
                if (!std)
                {
                    std::cout << "不存在此学生" << std::endl;
                }
                else
                {
                    std->print();
                }
            }
            break;
            case 4:
            {
                int id;
                while (true)
                {
                    std::cout << "请输入学号：";
                    std::cin >> id;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(1024, '\n');
                        std::cout << "输入非法，请输入数字！" << std::endl;
                        continue;
                    }
                    break;
                }
                bool ret = removeStudent(id);
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
        int id;
        while (true)
        {
            std::cout << "请输入学号：";
            std::cin >> id;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1024, '\n');
                std::cout << "输入非法，请输入数字！" << std::endl;
                continue;
            }
            break;
        }
        for (const auto &student : std_)
        {
            if (id == student.getid())
            {
                std::cout << "本学生已存在" << std::endl;
                return false;
            }
        }
        std::cout << "请输入姓名：";
        // std::numeric_limits<std::streamsize>::max() 返回 streamsize 类型的最大值，用于 ignore 丢弃缓冲区中所有剩余字符
        //从输入缓冲区中丢弃剩余的所有字符,丢弃到 遇到换行符 \n 为止，保证下一次输入不会被残留字符污染
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, name);
        int age;
        while (true)
        {
            std::cout << "请输入年龄：";
            std::cin >> age;
            if (std::cin.fail() || age < 0 || age > 150)
            {
                std::cin.clear();
                std::cin.ignore(1024, '\n');
                std::cout << "输入非法，请输入 0~150 的整数！" << std::endl;
                continue;
            }
            break;
        }
        std_.emplace_back(Student(id, name, age));
        return true;
    }
    // 打印学生
    void Print()
    {
        auto vec = std_;
        std::sort(vec.begin(), vec.end());
        for (const auto &s : vec)
            s.print();
    }
    // id查找
    Student *idTogetStudent(int id)
    {
        for (auto &student : std_)
        {
            if (id == student.getid())
            {
                return &student;
            }
        }
        return nullptr;
    }
    // id删除
    bool removeStudent(int id)
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