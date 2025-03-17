// 11 公司组织架构
// A 组件接口(Component组件)
// B 叶子节点(Leaf叶子)
// C 组合节点：包含叶子节点的操作行为(Composite合成)
// D 客户端代码
// 1 实现框架
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// A 组件接口(Component组件)
class Component
{
};

// B 叶子节点(Leaf叶子)
class Department : public Component
{
};

// C 组合节点：包含叶子节点的操作行为(Composite合成)
class Employee : public Component
{
};

// D 客户端代码
class Company
{
};

int main()
{
    return 0;
}