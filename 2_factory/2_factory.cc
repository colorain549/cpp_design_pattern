// 积木工厂
// 1. 获取实例
// 2. 抽象出工厂类(公有的静态方法)
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

// step 1 获取实例
// Circle *getCircle()
// {
//     Circle *pCircle = new Circle();
//     return pCircle;
// }

// Square *getSquare()
// {
//     Square *pSquare = new Square();
//     return pSquare;
// }

// 2. 抽象出工厂类
class Factory
{
public:
    // 公有的静态方法
    static Circle *getCircle()
    {
        Circle *pCir = new Circle();
        return pCir;
    }

    static Square *getSquare()
    {
        Square *pSqu = new Square();
        return pSqu;
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
    // Circle *pCir = new Circle();
    // pCir->display();
    // delete pCir;
    // Square *pSqu = new Square();
    // pSqu->display();
    // delete pSqu;

    // 1. 堆内存
    // Circle *pCir = getCircle();
    // Square *pSqu = getSquare();
    // pCir->display();
    // pSqu->display();
    // delete pCir;
    // delete pSqu;

    // 2. 堆内存
    Circle *pCir = Factory::getCircle();
    Square *pSqu = Factory::getSquare();
    pCir->display();
    pSqu->display();
    delete pCir;
    delete pSqu;

    return 0;
}