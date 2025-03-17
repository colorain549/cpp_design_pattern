// 11 公司组织架构
// A 组件接口(Component组件)
// B 叶子节点(Leaf叶子)
// C 组合节点: 包含叶子节点的操作行为(Composite合成)
// D 客户端代码
// 1 实现框架
// 2 实现 A 组件接口(Component组件)
// 3 实现 B 叶子节点(Leaf叶子)
// 4 实现 C 组合节点: 包含叶子节点的操作行为(Composite合成)
// 5 实现 客户端代码
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// A 组件接口(Component组件)
class Component
{
public:
    virtual void display(int depth) = 0;
};

// B 叶子节点(Leaf叶子)
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

// C 组合节点：包含叶子节点的操作行为(Composite合成)
class Employee : public Component
{
private:
    string _name;

public:
    Employee(const string &name) : _name(name) {}

    void display(int depth) override
    {
        string indent(depth * 2, ' ');
        cout << indent << _name << endl;
    }
};

// D 客户端代码
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
    return 0;
}