//2979번 문제

#include <iostream>
#include <vector>
using namespace std;

/// 1.abc입력 받음
/// 각 줄 마다 도착 떠나는 시간
/// 그래서 각 시간 별 차량 갯수를 배열에 넣어주고 갯수별 가격 넣어주면 된다

int a, b, c;
int arr[101]; 

int main()
{
    cin>>a>>b>>c;
    int s,e;
    for (int i=0; i<3; i++)
    {
        cin>>s>>e;
        for (int j=s; j<e; j++)
        {
            arr[j]++;
        }
        
    }
    int sum =0;
    for (int i=0; i<101; i++)
    {
        if (arr[i] == 1)
        {
            sum += arr[i] * a;
        }
        else if (arr[i] == 2)
        {
            sum += arr[i] * b;
        }
        else if (arr[i] == 3)
        {
            sum += arr[i] * c;
        }
    }
    cout<<sum<<'\n';
    return 0;
}