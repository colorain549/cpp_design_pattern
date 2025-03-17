// 13 时间观察者
// A 主题Subject
// B 观察者Observer
// C 具体主题ConcreteSubject
// D 具体观察者ConcreteObserver
// 1 搭建框架
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 观察者
class Observer
{
};

// 主题
class Subject
{
};

// 具体主题
class Clock : public Subject
{
};

// 具体观察者
class Student : public Observer
{
};

int main()
{
    return 0;
}