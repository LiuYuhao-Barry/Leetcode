# <set\>



## 1. 简介

\<set\>即集合，是一种内部元素自动按增序排列且不含重复元素的容器，底层用**红黑树**实现。set内的元素可以是任意基本类型，如`int`、`char`、结构体等，也可以是STL容器，如`<vector>`、`<set>`、`<string>`。

\<set\>不支持随机访问，只能通过迭代器遍历。



## 2. <set\>常见操作

```c++
set<int> s; // 新建set

it = s.begin();
it = s.end();

bool s.empty(); // 判断集合是否为空
unsigned int s.size(); // 获取集合内元素个数

s.insert(1); // 插入元素，时间复杂度为O(lgN)
s.erase(x); // 查找并删除元素，时间复杂度为O(lgN)
s.erase(it); // 删除迭代器位置的元素，时间复杂度为O(lgN)
s.erase(first, last); // 删除区间内元素，区间为左闭右开

s.clear(); // 清空集合
```



## 3. <multiset\>

<set\>自动保证了元素的唯一性，如果需要处理元素不唯一的情况，可以使用<multiset\>。<multiset\>底层同样通过红黑树实现。