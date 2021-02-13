# std::vector



## 1. 简介

vector底层是一个**动态数组**，包含三个迭代器，`start`和`finish`之间是已经被使用的空间范围，`start`与`end_of_storage`是整块连续空间，包括已经分配但是没有使用的空间。



## 2. 基本操作

```c++
vector<int> v;
vector<int>::iterator it;
int x;

it = v.begin();
it = v.end();

bool v.empty(); // 判断vector中是否没有元素
// 如果用vector<int> v(100)初始化，则默认vector中所有的元素都为0，vector.empty()为false

unsigned int v.size(); // 返回v中元素的个数，时间复杂度为O(1)
unsigned int v.capacity(); // 返回已经分配的内存最多可以容纳元素的个数，时间复杂度为O(1)

v.push_back(x); // 在vector的最后加入一个元素
v.pop_back(x); // 删除vector的最后一个元素

v.insert(it, x); // 在迭代器所在位置插入一个元素，原来在该位置的元素依次后移，时间复杂度为O(N)
v.erase(v.begin()+1, v.end()-3); // 删除指定区间的元素，时间复杂度为O(N)
v.erase(it); // 删除迭代器位置的元素，时间复杂度为O(N)

// 将vector的容量扩容至n，即把v.capacity()变为n。若n小于原来的容量，则容量保持不变
// 可以在一定程度上解决push_back()需要多次申请、释放空间和拷贝数据的问题
v.reserve(n); 

v.clear(); // 删除vector中所有的数据，但是不释放内存空间
v.shrink_to_fit()； // 请求容器降低其capacity和size匹配。
// 二者一起使用：清空内容且释放内存
```



## 3. 内存增长机制

vector的内存增长机制：vector初始只分配1个单位的空间，当分配的空间占满时，会自动在申请当前容量1.5倍或2倍的新的内存空间，然后把原来的数据拷贝至新的空间并释放原来的空间。这其中共经过了（1）申请新的内存空间（2）拷贝元素和（3）释放原来的空间 3个步骤。***为什么扩容倍数为1.5倍或2倍？***

注意，若某种操作操作引起了空间的重新配置，由于内存地址发生变化，指向原vector的所有迭代器会都失效。

```C++
// 查看vector内存分配情况
vector<int> v;
int cnt = 0;
for(int i = 0; i < 1024; i++) {
	v.push_back(1);
    if(pow(2, cnt) == i) {
        cnt++;
        cout << "size: " << v.size() << " ";
        cout << "capacity: " << v.capacity() << endl;
    }
}
```

```C++
// 输出结果
size: 2 capacity: 2
size: 3 capacity: 4
size: 5 capacity: 8
size: 9 capacity: 16
size: 17 capacity: 32
size: 33 capacity: 64
size: 65 capacity: 128
size: 129 capacity: 256
size: 257 capacity: 512
size: 513 capacity: 1024
```

已经分配了的内存空间，即使删除了vector内的大部分元素，内存空间也不会回收；

如果用`vector<int> v(1000);`的方式指定vector的容量，容量就是指定值，不再是2的N次幂。之后进行扩容时，依然把容量扩充为原来的2倍，如原来是1000，则扩容后容量为2000。



## 4. vector的拷贝

`=`只会拷贝`begin()`到`end`的部分，不会拷贝`finish`到`end_of_storage`的部分；

而`swap()`函数是原样拷贝，会把`finish`到`end_of_storage`也拷贝过来。



## 5. 二维及多维的vector

对于`vector<vector<int>> v2`，v2的第一维的每个元素都是`vector<int>`型的指针。二维vector的第二维也可以是`set`、`map`等其它类型的容器。

```c++
// 初始化二维vector，v2与v3等价
vector<int> v1 = {1,2,3,4,5};
vector<vector<int>> v2(3, v);
vector<vector<int>> v3(3, {1,2,3,4,5});

// 遍历二维vector
for(int i = 0; i < v2.size(); i++) {
    for(int j = 0; j < v2[i].size(); j++) {
        cout << v2[i][j];
    }
    cout << endl;
}
```



## 6. 使用技巧

1. vector初始化的多种方法：

   ```C++
   // 新建容量为maxSize，每个元素初始值为x的vector。也可以只指定容量，不指定初始值
   int maxSize = 10, x = 3;
   vector<int> v1(maxSize, x); 
   for(int i = 0; i < v1.size(); i++) {
       cout << v1[i] << " ";
   }
   cout << endl;
   
   vector<int> v2 = {0,1,2,3,4,5,6,7,8,9}; // 直接指定vector的初始值
   for(int i = 0; i < v2.size(); i++) {
       cout << v2[i] << " ";C++
   } 
   cout << endl;
   
   // 初始化为两个迭代器指定范围中元素的拷贝，也可以用于其他容器，特别适合获取一个序列的子序列
   vector<int> v3(v2.begin()+2, v2.end()-1); 
   for(int i = 0; i < v3.size(); i++) {
       cout << v3[i] << " ";
   }
   cout << endl;
   
   // 直接指定vector的容量，如果需要扩容，依然每次扩容为原容量的二倍
   // 如果用这样的方式初始化向量，当使用push_back()函数时，元素会加在最后面，也就是第11个元素的位置
   vector<int> v4(10);
   cout << v4.size() << endl;
   cout << v4.capacity() << endl;
   ```

   ```C++
   // 输出结果
   3 3 3 3 3 3 3 3 3 3 
   0 1 2 3 4 5 6 7 8 9 
   2 3 4 5 6 7 8 
   ```

2. 两个vector之间可以用直接用”==“判断是否完全一致；

3. vector头指针大小为24B（3个迭代器）；

4. ~~vector的底层实现要求连续的**对象排列**，**引用并非对象，没有实际地址，因此vector的元素类型不能是引用**。~~

5. 当插入一个元素到vector中，由于引起了内存重新分配，所以指向原内存的迭代器全部失效。

   当删除容器中一个元素后,该迭代器所指向的元素已经被删除，那么也造成迭代器失效。erase方法会返回下一个有效的迭代器，所以当我们要删除某个元素时，需要`it=vec.erase(it);`。

6. ~~vector 扩容为什么要以1.5倍或者2倍扩容?~~

   根据查阅的资料显示，考虑可能产生的堆空间浪费，成倍增长倍数不能太大，使用较为广泛的扩容方式有两种，以2倍的方式扩容，或者以1.5倍的方式扩容。

     **以2倍的方式扩容，导致下一次申请的内存必然大于之前分配内存的总和，导致之前分配的内存不能再被使用**，所以最好倍增长因子设置为(1,2)之间：

8. 在常见的迭代器中，只有`vector`和`string`允许使用`v.begin() + 3`这种迭代器+数字的写法。