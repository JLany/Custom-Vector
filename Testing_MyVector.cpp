#include<iostream>
#include "MYVector.h"
using namespace std;

void test_case1()
{
    MYVector<int>vec(4);
    cout<<"Push back: "<<endl;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
        cout<<vec<<endl;
        cout<<vec.capacity()<<endl;
    }
    cout<<"----------------------------------"<<endl;
    cout<<"Pop back: "<<endl;
    for (int i = 0; i < 10; i++)
    {
        vec.pop_back();
        cout<<vec<<endl;
        cout<<vec.capacity()<<endl;
    }
}

void test_case2()
{
    int a[] = {1 , 2 , 3 , 4 , 5};
    MYVector<int>vec(a,5);
    cout<<"vector: "<<vec<<endl;
    vec.erase(vec.end()-1);
    cout<<"vector after erase: "<<vec<<endl;
    vec.insert(vec.end(),5);
    cout<<"insert item: "<<vec<<endl;
    vec.erase(vec.begin()+1,vec.begin()+3);
    cout<<"delete items from 2 -> 4 : "<<vec<<endl;

}

void test_case3()
{ 
    int a[] = {1 , 2 , 3 , 4 , 5};
    int b[] = {1 , 2 , 5 , 3 , 4};  
    MYVector<int>vec1(a,5);
    MYVector<int>vec2(b,5);
    MYVector<int>vec3(a,5);
    cout<<"first vector: "<<vec1<<endl;
    cout<<"second vector: "<<vec2<<endl;
    if (vec1 < vec2)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    if (vec1 == vec3)
    {
        cout<<"Equal"<<endl;
    }
}

void test_case4()
{
    int a[] = {1,2,3,4,5};
    MYVector<int>vec(a,5);
    cout<<"vector: "<<vec<<endl;
    cout<<"Size: "<<vec.size()<<endl;
    vec.clear();
    cout<<"after clear: "<<vec<<endl;
    cout<<"Size: "<<vec.size()<<endl;
    if (vec.empty())
    {
        cout<<"Vector is empty."<<endl;
    }
}

int main()
{
    test_case4();


    return 0;
}