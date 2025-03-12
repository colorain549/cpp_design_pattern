## 抽象工厂
1. 抽象产品(Chair, Sofa)
2. 具体产品1, 具体产品2 ... (ModernChair, ClassicalChair, ModernSofa, ClassicalChair)
3. 抽象工厂(Factory)
4. 具体工厂1, 具体工厂2 ... (ModernFactory, ClassicalFactory)
5. 使用方法(先获取指向具体工厂的指针, 再获取指向具体产品的指针, 最好生产具体产品)
```
Factory *modernFactory = new ModernFactory();
Sofa *modernSofa = modernFactory->sofaFactory();
modernSofa->produceSofa()
```

### 抽象工厂(《设计模式》3.1)
1. 提供接口, 创建一系列, 相关或相互依赖的对象
```
// 接口
virtual void chairFactory() const = 0;
virtual void sofaFactory() const = 0;
// 对象
modernChair
modernSofa
classicalChair
classicalSofa
// 
```
2. 一个系统
3. 一个系统
4. 强调
5. 提供一个产品类库