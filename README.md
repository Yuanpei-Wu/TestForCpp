# It includes test files for c++

## compare_between_size_t_and_int
小于0的int值不能和size_t类型进行比较  

## function parameter
### 成员函数形参默认值不能设置为成员变量
> error: call to 'void ParaTest::ParaTestFunc(int)' uses the default argument for parameter 1, which is not yet defined  

解决：函数重载

### 函数形参默认值不能设置为另一个形参的默认值
解决：函数重载  

## move test
###  在有拷贝赋值操作符和移动赋值操作符的情况下，编译器优先考虑move assignment operator

