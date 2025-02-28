// * 输出包含小明购物车中的所有商品及其购买数量
// * 使用STL的vector
// * 懒汉模式: 第一次使用时才创建
// 1. 私有的构造函数
// 2. 私有的静态实例变量
// 3. 公有的静态方法
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

class ShoppingCartManager
{
private:
    // 1. 私有的构造函数
    ShoppingCartManager() {}

public:
    // 构造函数
    // ShoppingCartManager() {}

    // 3. 公有的静态方法
    static ShoppingCartManager *getInstance()
    {
        if (_pInstance == nullptr)
        {
            _pInstance = new ShoppingCartManager();
        }
        return _pInstance;
    }

    // 初始化变量
    void addItem(const string &item, int quantity)
    {
        // 检查商品是否已经存在
        for (auto &it : _cart)
        {
            if (it.first == item)
            {
                it.second += quantity;
                // 商品已存在, 直接返回
                return;
            }
        }
        // 如果商品不存在，插入新商品
        _cart.push_back(pair<string, int>(item, quantity));
    }

    // 输出包含小明购物车中的所有商品及其购买数量
    void display() const
    {
        // 范围for
        for (const auto &it : _cart)
        {
            cout << it.first << " " << it.second << endl;
        }
        // 迭代器
        // for (auto it = _cart.begin(); it != _cart.end(); ++it)
        // {
        //     cout << it->first << " " << it->second << endl;
        // }
    }

    // 释放单例实例
    static void destroyInstance()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

private:
    vector<pair<string, int>> _cart;
    // 2. 私有的静态实例变量
    static ShoppingCartManager *_pInstance;
};
// 初始化, 私有的静态实例变量
ShoppingCartManager *ShoppingCartManager::_pInstance = nullptr;

int main()
{
    string item;
    int quantity;
    // 栈内存
    // ShoppingCartManager cart;
    // while (cin >> item >> quantity)
    // {
    //     cart.addItem(item, quantity);
    // }
    // cart.display();
    // 堆内存
    // ShoppingCartManager *cart = new ShoppingCartManager();
    ShoppingCartManager *cart = ShoppingCartManager::getInstance();
    while (cin >> item >> quantity)
    {
        cart->addItem(item, quantity);
    }
    cart->display();
    // delete cart;
    ShoppingCartManager::destroyInstance();

    return 0;
}