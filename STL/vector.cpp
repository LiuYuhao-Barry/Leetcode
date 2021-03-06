/*
vector可理解为变长数组，是一个能够存放任何数据类型的变长数组
*/

#include <iostream>
#include <vector>

using namespace std;

// traverse the vector through index
void show_vector_with_idx(vector<int> vector_to_show) 
{
    for(unsigned int i = 0; i < vector_to_show.size(); i++)
    {
        cout << vector_to_show[i] << " " ;
    }
    cout << endl;
}

// traverse the vector through iterator
void show_vector_with_iterater(vector<int> vector_to_show)
{
    for(vector<int>::iterator it = vector_to_show.begin(); it != vector_to_show.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

vector<int> my_clear(vector<int> &a)
{
    if(!a.empty())
    {
        a.clear();
    }

    return a;
}


int main()
{
    vector<int> vec; // initialize a vector
    vector<vector<int>> two_dim_vector; // define a two dim vector

    cout << vec.empty() << endl;

    vec.push_back(1); // add an element into the tail of the vector
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(6);
    cout << vec.size() << endl;
    show_vector_with_idx(vec);
    
    vec.pop_back();
    show_vector_with_idx(vec);
    
    vec.insert(vec.begin()+1, 10); // insert an element after the loc of the second element
    show_vector_with_idx(vec);

    vec.erase(vec.begin()+2); // erase the third element of the vector
    show_vector_with_idx(vec);
    vec.erase(vec.begin()+1, vec.end()-2);
    show_vector_with_idx(vec);

    // traverse the vector through index and iterator respectively
    show_vector_with_idx(vec);
    show_vector_with_iterater(vec);

    vec = my_clear(vec);
    show_vector_with_idx(vec);
    cout << vec.size();

    return 0;
}
