//1159번 문제

///해당 문제는 문자의 갯수를 관리해야해서 map의 자료 구조를 이용해서 counting을 하면된다 
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int n;

map<char,int> maps;
int main()
{
    string s;
    cin >>n;
    for (int i=0; i<n;i++)
    {
        cin>>s;
        maps[s[0]]++;
    }

    string s2; 
    for (auto it : maps)
    {
        if (it.second >= 5)
        {
            s2+=it.first;
        }
    }
    if (s2.size() == 0)
    {
        cout<<"PREDAJA"<<endl;
    }
    else
    {
        sort(s2.begin(), s2.end());
        cout<<s2<<endl;
    }
    return 0;
    
}

