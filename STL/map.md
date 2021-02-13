# std::map

map即映射，主要有四种，分别为\<map\>，\<multimap\>，\<unordered_map\>，\<unordered_multimap\> 



## 1. 实现方式

|       类型       | 实现方式 |
| :--------------: | :------: |
|      <map\>      |  红黑树  |
|   <multimap\>    |  红黑树  |
| <unordered_map\> |  哈希表  |
|      <set\>      |  红黑树  |
|   <multiset\>    |  红黑树  |
| <unordered_set\> |  哈希表  |



## 2. <map\>

\<map\> 、\<set\>、\<multiset\>、\<multimap\>的底层实现都是==红黑树==，epoll模型的底层数据结构也是红黑树，linux系统中CFS进程调度算法，也用到了红黑树。

\<map\>将`key`和`value`组成的`pair`作为元素，根据`key`的排序准则自动将元素排序，并且可以从任何类型或STL容器映射到任何类型或STL容器。

<map\>中的键值是唯一的，如果需要一个键对应多个值，则需要使用<multimap\>。



### 2.1 常见操作

```C++
map<string, int> mp;
map<string, int>::iterator it;

it = mp.begin(); // 第1个元素的迭代器
it = mp.end(); // 最后一个元素的后一位置的迭代器

bool mp.empty(); // 判断映射是否为空
int mp.size(); // 映射表中当前存在的key的个数
int mp.capacity(); // 如果不重新分配内存,当前已经分配内存可以容纳的元素的个数
int mp.max_size() // 映射表可能存在最大的key的个数

mp.insert({key, value}); // 插入键值对，时间复杂度为O(logN)
mp.erase(key); // 查找并删除指定key，时间复杂度为O(logN)
mp.erase(it); // 删除迭代器对应的键值对，时间复杂度为O(logN)
mp.erase(first, last); // 删除区间内键值对，区间为左闭右开

mp.count(key); // 返回key出现的次数，对于<map>一个key最多出现一次，所以该key存在返回1，不存在则返回0
it = mp.find(key); // 返回对应key的键值对的迭代器，时间复杂度为O(logN)

cout << it->first; //迭代器对应键值对的key
cout << it->second; //迭代器对应键值对的value
```



### 2.2 判断键值是否存在于哈希表

```
// 第一种方法
if (mp.count(key) == 1) {}
//第二种方法
if (mp.find(key) != mp.end()) {}
// 第三种方法
if (!mp[key]) {}
```



## 3. <unordered_map\>

<unordered_map>底层通过一个防冗余的哈希表实现，可以把查找的时间复杂度降为O(1)（**最好情况为O(1)，最坏情况为O(N)**），代价则是消耗较多的内存。

哈希表通过一个较大的数组存储元素，一般使用**除留取余法**作为散列函数，并用**拉链法**解决冲突。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pbWFnZXMyMDE4LmNuYmxvZ3MuY29tL2Jsb2cvMTI3Mjk3OC8yMDE4MDYvMTI3Mjk3OC0yMDE4MDYxMDE5Mjk1MzEwOS01NzQwNTg2MS5wbmc?x-oss-process=image/format,png)

<unordered_map>查找速度会比<map\>快，而且查找速度基本和数据量大小无关，属于常数级别；而<map\>的查找速度是O(lgN)级别。常数其实不一定比lgN小，hash还有hash函数的耗时；如果考虑效率，**特别是在元素达到一定数量级时，考虑unordered_map** 。但若对内存使用特别严格，希望程序尽可能少消耗内存，那么一定要小心，unordered_map 可能会让你陷入尴尬，特别是当你的unordered_map 对象特别多时，你就更无法控制了，而且unordered_map 的构造速度较慢（最坏可达O(N^2^))。



## 4. 使用技巧

1. 当给定哈希表的大小时（比如仅有小写字母），可以考虑自己开数组作为哈希表，代价更小；
2. 当map中不存在某个键值时，如果用`mp[key]`访问该键值，会返回`0`；



## 5. 面试问题

- 为何map和set的插入删除效率比其他序列容器高，而且每次insert之后，以前保存的iterator不会失效？
  - 红黑树存储的是结点，**不需要内存拷贝和内存移动**。每次插入操作只是将指针进行调整，结点的内存地址没有发生变化，而迭代器是指向结点所在内存地址的指针，结点的内存地址没有变，指向结点的指针就不会变。
- 

