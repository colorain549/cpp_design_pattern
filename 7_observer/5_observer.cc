// 13 时间观察者
// A 主题Subject
// B 观察者Observer
// C 具体主题ConcreteSubject
// D 具体观察者ConcreteObserver
// 1 搭建框架
// 2 完善观察者和主题
// 3 搭建 具体主题框架
// 4 搭建 具体观察者框架
// 5 完善 具体主题框架
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::string;
using std::vector;

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
private:
    vector<Observer *> _observers;
    int _hour;

public:
    Clock() : _hour(0) {}

    void registerObserver(Observer *observer) override
    {
        _observers.push_back(observer);
    }
    void removeObserver(Observer *observer) override
    {
        // 对于vector, 没有vector.find
        auto it = find(_observers.begin(), _observers.end(), observer);
        if (it != _observers.end())
        {
            _observers.erase(it);
        }
    }
    void notifyObserver() override
    {
        for (Observer *observer : _observers)
        {
            observer->update(_hour);
        }
    }

    // 添加获取观察者的函数
    const vector<Observer *> &getObservers() const
    {
        return _observers;
    }

    void tick()
    {
        _hour = (_hour + 1) % 24;
        notifyObserver();
    }
};

// 具体观察者
class Student : public Observer
{
private:
    string _name;

public:
    Student(const string &name) : _name(name) {}

    void update(int hour) override {}
};

int main()
{
    return 0;
}