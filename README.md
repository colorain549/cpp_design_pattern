# 设计模式

## 最简单、最常用的模式(来源:《设计模式》)
1. 单例/单件
* 1 (懒汉模式)(_1_小明的购物车)(_ _ _已解决_ _ _)
* 2 (饿汉模式)(_1_小明的购物车)(_ _ _已解决_ _ _)
2. 工厂方法
* 1 工厂方法(_2_积木工厂)(_ _ _已解决_ _ _)
* 2 简单工厂(_2_积木工厂)(_ _ _已解决_ _ _)
3. 抽象工厂(_3_家具工厂)(_ _ _已解决_ _ _)
4. 适配器(_6_拓展坞)(_ _ _已解决_ _ _)
5. 组合(_11_公司组织架构)
6. 装饰(_8_咖啡加糖)
7. 观察者(_13_时间观察者)
8. 策略(_14_超市打折)
9. 模板方法(_18_咖啡馆)(_ _ _已解决_ _ _)

补充:
1. 🌟懒汉模式:第一次使用才创建(多线程可使用互斥锁)
2. 🌟饿汉模式:实例在类加载时就被创建(多线程不影响)(提供接口时直接返回;定义时new一个对象;无需再destory)

## 补充 参考资料
* [卡码网](https://kamacoder.com/designpattern.php)
* [工厂设计模式](https://mp.weixin.qq.com/s/NDIFu6V76_cIo1kWvTM1YQ)

## 补充 面向对象
1. 栈分配 自动管理内存 性能快(不涉及动态内存管理)
```
ShopCar shopcar(item, quantity);
ShoppingCartManager cart;
```
2. 堆分配 手动管理内存 灵活性(指针可在不同作用域之间传递和共享)
```
ShoppingCartManager *cart = ShoppingCartManager::getInstance();
```

## 补充 智能指针
```
// 返回指向CircleFactory对象的指针
// Factory *pCircleFactory = new CircleFactory();
unique_ptr<Factory> pCircleFactory(new CircleFactory());

// 返回指向Shape对象的指针
// Shape *pCircle = pCircleFactory->factory();
unique_ptr<Shape> pCircle(pCircleFactory->factory());
```

## 单例模式(懒汉模式)(小明的购物车)
1. 构造函数私有化/保护型
2. 🌟提供接口(自定义)
```
// 懒汉式
static ShoppingCartManager *getInstance(){
    if(_pInstance==nullptr){
        _pInstance = new ShoppingCartManager();
    }
    return _pInstance;
}
// 饿汉式
static ShoppingCartManager *getInstance(){
    return _pInstance;
}
```
3. 声明用来保存实例私有静态变量(私有的静态实例变量)
```
static ShopCar *_pInstance;
```
4. 初始化私有静态变量
```
// 懒汉式
ShoppingCartManager *ShoppingCartManager::_pInstance = nullptr;
// 饿汉式
ShoppingCartManager *ShoppingCartManager::_pInstance = new ShoppingCartManager ();
```
5. 显化默认构造函数
```
ShopCar(){}
```
6. 初始化数据
```
void addItem(const string &item, int quantity)
{
    _cart[item] += quantity;
}
```
7. 删除私有静态变量
```
static void destroyInstance(){...}
```

## 工厂方法模式(积木工厂)
* 记忆: 先物品, 后工厂
1. 抽象物品
```
class Shape {
    public:
    virtual void produceShape() = 0;
};
```
2. 具体物品
```
class Circle: public Shape {
    public:
    void produceShape() override {}
}
```
3. 抽象工厂
```
class Factory {
    public:
    virtual Shape* factory() = 0;
}
```
4. 具体工厂
```
class CircleFactory: public Factory {
    public:
    Shape* factory() override {
        Shape *pCircleFactory = new Circle();
        return pCircleFactory;
    }
}
```

## 抽象工厂模式(家具工厂)
* 记忆: 先物品, 后工厂
1. 抽象沙发
```
class Sofa {
    public:
    virtual void produceSofa() = 0;
}
```
2. 具体沙发
```
class ModernSofa: public Sofa {
    public:
    void produceSofa() override {}
}
```
3. 抽象椅子
```
class Chair {
    public:
    virtual void produceChair() = 0;
};
```
4. 具体椅子
```
class ModernChair: public Chair {
    public:
    void produceChair() override {}
}
```
5. 抽象工厂
```
class Factory {
    public:
    virtual Sofa *sofaFactory() = 0; 
    virtual Chair *chairFactory() = 0;
}
```
6. 具体工厂
```
class ModernFactory: public Factory {
    public:
    Sofa *sofaFactory() override {
        Sofa *pModernSofa = new ModernSofa();
        return pModernSofa;
    }
    Chair *chairFactory() override {
        Chair *pModernChair = new ModernChair();
        return pModernChair;
    }
}
```

## 单例模式(饿汉模式)(小明的购物车)
1. 构造函数私有化
2. 🌟提供接口(直接返回实例)
```
static ShoppingCartManager *getInstance(){
    return _pInstance;
}
```
3. 声明用来保存实例私有静态变量
4. 🌟初始化用来保存实例私有静态变量
```
ShopCar *ShopCar::_pInstance = new ShopCar();
```
5. 显化构造函数
6. 初始化数据
7. 删除私有静态变量

## 简单工厂模式(积木工厂)
1. 抽象积木
2. 具体积木
3. 🌟一个工厂创建所有具体产品(if...else)