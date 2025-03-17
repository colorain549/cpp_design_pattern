// 13 时间观察者
// A 主题Subject
// B 观察者Observer
// C 具体主题ConcreteSubject
// D 具体观察者ConcreteObserver
// 1 搭建框架
// 2 完善观察者和主题
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 观察者
class Observer
{
public:
    virtual void update(int hour) = 0;
    virtual ~Observer() {}
};

// 主题
class Subject
{
public:
    virtual void registerObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObserver() = 0;
    virtual ~Subject() {}
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