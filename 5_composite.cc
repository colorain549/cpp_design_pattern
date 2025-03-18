// 11 公司组织架构
// A 组件
// B 叶子
// C 合成
#include <iostream>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ws;

// 组件
class Component
{
public:
    virtual void display(int depth) = 0;
};

// 组合
class Department : public Component
{
private:
    string _name;
    vector<Component *> _children;

public:
    Department(const string &name) : _name(name) {}

    void add(Component *component)
    {
        _children.push_back(component);
    }

    void display(int depth) override
    {
        string indent(depth * 2, ' ');
        cout << indent << _name << endl;
        for (Component *component : _children)
        {
            component->display(depth + 1);
        }
    }
};

// 叶子
class Employee : public Component
{
private:
    string _name;

public:
    Employee(const string &name) : _name(name) {}

    void display(int depth) override
    {
        string indent((depth + 1) * 2, ' ');
        cout << indent << _name << endl;
    }
};

// 客户端
class Company
{
private:
    string _name;
    Department *_root;

public:
    Company(const string &name) : _name(name), _root(new Department(name)) {}

    void add(Component *component)
    {
        _root->add(component);
    }

    // 注意这里的display, 没有override
    void display()
    {
        cout << "Company Structure:" << endl;
        _root->display(0);
    }
};

int main()
{
    string companyName;
    getline(cin, companyName);

    Company company(companyName);

    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        string type, name;
        cin >> type;
        getline(cin >> ws, name);

        if (type == "D")
        {
            Department *department = new Department(name);
            company.add(department);
        }
        else if (type == "E")
        {
            Employee *employee = new Employee(name);
            company.add(employee);
        }
    }

    company.display();

    return 0;
}