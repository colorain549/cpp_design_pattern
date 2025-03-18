// 13 时间观察者
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// 观察者接口(观察者)
class Observer
{
public:
    virtual void update(int hour) = 0;
    virtual ~Observer() {}
};

// 主题接口(目标)
class Subject
{
public:
    virtual void registerObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

// 具体主题实现(具体目标)
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
        auto it = std::find(_observers.begin(), _observers.end(), observer);
        if (it != _observers.end())
        {
            _observers.erase(it);
        }
    }

    void notifyObservers() override
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
        notifyObservers();
    }
};

// 具体观察者实现(具体观察者)
class Student : public Observer
{
private:
    string _name;

public:
    Student(const string &name) : _name(name) {}

    void update(int hour) override
    {
        cout << _name << " " << hour << endl;
    }
};

int main()
{
    // 读取学生数量
    int N;
    cin >> N;

    // 创建时钟
    Clock clock;

    // 注册学生观察者
    for (int i = 0; i < N; i++)
    {
        string studentName;
        cin >> studentName;
        clock.registerObserver(new Student(studentName));
    }

    // 读取时钟更新次数
    int updates;
    cin >> updates;

    // 模拟时钟每隔一个小时, 更新一次
    for (int i = 0; i < updates; i++)
    {
        clock.tick();
    }

    // 释放动态分配的观察者对象
    for (Observer *observer : clock.getObservers())
    {
        delete observer;
    }

    return 0;
}