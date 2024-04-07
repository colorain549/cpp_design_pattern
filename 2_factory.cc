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

// 抽象工厂
class Factory
{
public:
    virtual Shape *factory() = 0;
};

// 具体工厂
class CircleFactory : public Factory
{
public:
    Shape *factory()
    {
        Shape *pCircleFactory = new Circle();
        return pCircleFactory;
    }
};
class SquareFactory : public Factory
{
    Shape *factory()
    {
        Shape *pSquareFactory = new Square();
        return pSquareFactory;
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
            if (item == "Circle")
            {
                // // 返回指向CircleFactory对象的指针
                // Factory *pCircleFactory = new CircleFactory();
                // // 返回指向Shape对象的指针
                // Shape *pCircle = pCircleFactory->factory();
                // pCircle->produceShape()
                unique_ptr<Factory> pCircleFactory(new CircleFactory());
                unique_ptr<Shape> pCircle(pCircleFactory->factory());
                pCircle->produceShape();
            }
            else if (item == "Square")
            {
                // Factory *pSquareFactory = new SquareFactory();
                // Shape *pSquare = pSquareFactory->factory();
                // pSquare->produceShape();
                unique_ptr<Factory> pSquareFactory(new SquareFactory());
                unique_ptr<Shape> pShape(pSquareFactory->factory());
                pShape->produceShape();
            }
        }
    }

    return 0;
}