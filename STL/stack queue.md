## stack



```c++
stack<int> s; // 新建一个栈，栈中元素可以是其他类型
int num;

s.empty()  // 判断栈是否为空
s.size() // 返回栈中元素个数

s.push(num)  // 元素入栈
s.top()  // 返回栈顶元素
s.pop()  // 栈顶元素出栈
```



可以用<vector\>或者<string\>模拟栈，因为可以通过类似`v.back() += 1`的操作直接对栈顶元素进行修改。

## queue

```c++
queue<int> q;  // 新建一个队列

q.empty()
q.size()
    
q.front()
q.back()

q.push()
q.pop()
```

