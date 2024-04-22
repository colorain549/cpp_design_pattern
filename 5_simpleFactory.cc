// 输入
// 3 Circle 1 Square 2 Circle 1
// 输出
// Circle Block
// Square Block
// Square Block
// Circle Block

#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

// 抽象积木
class Shape
{
public:
    virtual void produceShape() = 0;
};

// 具体积木
class Circle : public Shape
{
public:
    void produceShape() override
    {
        cout << "Circle Block" << endl;
    }
};
class Square : public Shape
{
public:
    void produceShape() override
    {
        cout << "Square Block" << endl;
    }
};

// 简单工厂(一个工厂创建所有具体产品)
class Factory
{
public:
    Shape *get(string type)
    {
        if ("Circle" == type)
        {
            Circle *pCircle = new Circle();
            return pCircle;
        }
        else if ("Square" == type)
        {
            Square *pSquare = new Square();
            return pSquare;
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    int times;
    cin >> times;
    string item;
    int quantity;
    while (times--)
    {
        cin >> item >> quantity;
        for (int i = 0; i < quantity; i++)
        {
            // if (item == "Circle")
            // {
            //     Factory *factory = new Factory();
            //     Shape *circleFactory = factory->get(item);
            //     circleFactory->produceShape();
            // }
            // else if (item == "Square")
            // {
            //     Factory *factory = new Factory();
            //     Shape *squareFactory = factory->get(item);
            //     squareFactory->produceShape();
            // }
            Factory *factory = new Factory();
            Shape *shapeFactory = factory->get(item);
            shapeFactory->produceShape();
        }
    }

    return 0;
}