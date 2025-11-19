// 1940번 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//해당 문제는 투포인터를 이용하면 쉽게 풀수 있는 문제이다

// 그리고 nC2 를 이용해서 풀수도 있다
// 2개 를 뽑는 문제라서 중첩 반복문을 사용해서 풀어도 된다
int n, m;
vector<int> v1;
int main()
{
    cin>>n;
    cin>>m;

    int a;
    for (int i=0; i<n;i++)
    {
        cin>>a;
        v1.push_back(a);
    }

    sort(v1.begin(), v1.end());
    
    int start =0;
    int end = n-1;

    int cnt =0;
    while (start < end)
    {
        int sum = v1[start] + v1 [end];

        if ( sum > m)
        {
            end--;
        }
        else if (sum < m)
        {
            start++; 
        }
        else
        {
            cnt ++;
            start ++;
            end --;
        }
    }
    
    cout<<cnt<<endl;
}