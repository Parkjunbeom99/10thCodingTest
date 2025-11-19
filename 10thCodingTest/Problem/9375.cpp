//9375번 문제

///해당 문제는 경우의 수를 구하는 문제라서 조합이라고 처음에 생각했는데
///문제에서 모두 장착 안했을 경우만 제외를 하고 각 부분 별 1개 씩만 장착이 가능하니
/// 생각을 해보니 각 종류별로 1개씩 선택하는 경우의 수 + 아무것도 안하는 경우를 곱하면 된다.
/// ex -> hear 에 3개 가 있으면  3 + 1 를 곱하면 된다
/// 그래서 마지막에 모두 장착을 안하는 경우의 수를 하나 빼주면 되는 문제이다


#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int t, n;
string kind , name;

int cal(map<string, vector<string>> m1)
{
    int sum =1;
    for (auto i : m1)
    {
        sum *= i.second.size() + 1;
        
    }
    return sum-1;
}
int main()
{
    cin>>t;
    while (t--)
    {
        cin>> n;
        map<string, vector<string>> m1 ;
        for (int i=0;i <n; i++)
        {
            cin>>name>>kind;
            m1[kind].push_back(name);
        }
        cout<< cal(m1)<<'\n';
    }
}