// 积木工厂
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Block
{
public:
    // 纯虚函数
    virtual void display() = 0;
};

class Circle : public Block
{
public:
    // 重载, 重写, 覆盖
    // 重载(同名, 如函数重载/操作符重载)
    // 重写(同名+virtual)(这里是重写)
    // 覆盖(同名)
    void display() override
    {
        cout << "Circle Block" << endl;
    }
};

class Square : public Block
{
public:
    void display() override
    {
        cout << "Square Block" << endl;
    }
};

int main()
{
    // 栈内存
    // Circle circle;
    // circle.display();
    // Square square;
    // square.display();
    
    // 0. 堆内存
    Circle *pCir = new Circle();
    pCir->display();
    delete pCir;
    Square *pSqu = new Square();
    pSqu->display();
    delete pSqu;

    return 0;
}