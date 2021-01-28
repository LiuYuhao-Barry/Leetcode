/*
set 是一个内部自动有序且不含重复元素的容器，自动实现去重与按升序排序
*/

#include <iostream>
#include <set>

using namespace std;

//traverse <set> with iterator(<set> cannot be traversed through index)
void show_set(set<int> s)
{
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// set.empty()
void my_empty(set<int> s)
{
    if(s.empty())
    {
        cout << "the set is empty" << endl;
    }
    else
    {
        cout << "the set isn't empty" << endl;
    }
}

int main()
{
    set<int> data;
    my_empty(data);

    //set.insert()
    data.insert(2);
    data.insert(3);
    data.insert(3);
    data.insert(3);
    data.insert(1);
    data.insert(4);

    show_set(data);
    cout << data.count(3) << endl;
    my_empty(data);

    // set.find()
    set<int>::iterator it = data.find(4); // find the iterator of certain element
    cout << *it << endl;

    int elem = 999;
    if(data.find(elem) == data.end())
    {
        cout << "element " << elem << " not found" << endl;
    }
    else
    {
        cout << *(data.find(elem));
    }

    //set.erase()
    data.erase(3);
    show_set(data);

    return 0;
}
