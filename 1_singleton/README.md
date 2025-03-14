## 单例模式(懒汉式/惰性初始化)

### 单例模式是什么
1. 创建型设计模式
2. 核心思想(一个类只有一个实例对象, 并提供一个全局访问点来访问这个实例)
3. 全局访问点, 是为了让其他类能获取到这个唯一的实例

### 单例模式的优点
1. 全局控制: 只有一个实例, 可严格控制客户, 怎样访问它, 何时访问它
2. 节省资源: 只有一个实例, 避免多次创建相同的对象, 节省了系统资源, 多个模块可通过单例实例共享数据
3. 懒加载: 只在需要时实例化, 提高程序的性能

## 单例模式的使用场景
1. 资源共享: 多个模块共享某个资源的时候
* 应用程序需要一个全局的配置管理器来存储和管理配置信息
* 亦或是使用单例模式管理数据库连接池
2. 只有一个实例: 当系统中某个类只需要一个实例来协调行为的时候
* 管理应用程序中的缓存，确保只有一个缓存实例，避免重复的缓存创建和管理
* 创建和管理线程池
3. 懒加载: 对象创建本身比较消耗资源，且可能在程序中, 不一定会使用
* 流行的工具和库, 如Java的Runtime类, 表示程序的运行时环境
* Spring框架的应用上下文(ApplicationContext), 以提供对应用程序中所有 bean 的集中式访问点

### 单例模式的实现(小明的购物车)
1. 私有的构造函数: 防止外部代码直接创建类的实例
2. 私有的静态实例变量: 保存该类的唯一实例
3. 公有的静态方法: 通过公有的静态方法来获取类的实例
```
// 1. 私有的构造函数
private:
    ShoppingCartManager(){}

// 2. 私有的静态实例变量
private:
    static ShoppingCartManager *_pInstance;

// 3. 公有的静态方法
public:
    static ShoppingCartManager *getInstance(){
        ...
    }
```
 
### 面向对象
* 0_map.cc
* 0_vector.cc
```
// 使用map
class ShoppingCartManager{
public:
    // 添加商品(使用const string&, 避免不必要的复制)
    void addItem(const string& item, int quantity){
        _cart[item] += _cart;
    }

    // 输出(const不会修改类的成员变量)
    void display() const {
        ...
    }

private:
    map<pair<string, int>> _cart;
}
```
```
// 使用vector
class ShoppingCartManager{
public:
    // 添加商品(使用const string&, 避免不必要的复制)
    void addItem(const string& item, int quantity){
        // 检查商品是否已存在
        for(const auto &it: _cart){
            if(it.first == item){
                it.second += quantity;
                // 商品已存在, 则直接返回
                return;
            }
        }
        // 检查商品是不存在, 则创建
        _cart.push_back(pair<string, int>(item, quantity));
    }

    // 输出(const不会修改类的成员变量)
    void display() const {
        ...
    }

private:
    vector<pair<string, int>> _cart;
}
```

### 懒汉模式(重点)
* 1_mapSingleton.cc
* 1_vectorSingleton.cc
```
class ShoppingCartManager{
public:
    // 公有的静态方法
    static ShoppingCartManager *getInstance(){
        // 第一次调用时创建实例
        // 实例不存在, 则创建新实例, 否则直接返回
        if(_pInstance == nullptr){
            _pInstance = new ShoppingCartManager();
        }
        return _pInstance;
    }
private:
    // 私有的静态实例变量
    static ShoppingCartManager *_pInstance
}
// 初始化, 私有的静态实例变量
ShoppingCartManager *ShoppingCartManager::_pInstance = nullptr;
```

### 饿汉模式
1. 
* 2_mapSingleton.cc
* 2_vectorSingleton.cc
```
class ShoppingCartManager{
public:
    // 公有的静态方法
    static ShoppingCartManager *getInstance(){
        // 直接返回(类初始化的时候创建实例)
        return _pInstance;
    }
private:
    // 私有的静态实例变量
    static ShoppingCartManager *_pInstance;
};
// 初始化, 私有的静态实例变量
ShoppingCartManager *ShoppingCartManager::_pInstance = new ShoppingCartManager();
```

### 补充
1. 懒加载和懒汉模式的区别
* 懒加载, 适用于多种场景(图片, 数据(库), 对象), 延迟加载资源或对象(如网页中的图片在用户滚动到可见区域时才加载)
* 懒汉模式, 专用于单例模式, 延迟单例对象的创建