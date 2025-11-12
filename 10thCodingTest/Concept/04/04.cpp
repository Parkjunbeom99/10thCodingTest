#include <iostream>

using namespace std;

//비스마스킹을 이용한 경우의 수


string a[4] = {"사과", "딸기", "포도", "배"};


// 조합들의 모든 경우의 수를 구할때 유용 
void Func1()
{
    for (int i =0 ; i <(1<<4); i++) // 모든 경우의 수 16 가지 2 ^4
    {
        string ret = "";
        for (int j =0; j<4;  j++) 
        {
            if (i & (1 << j))  // 각 자리별 비트가 켜져 있는지 체크 
            {
                ret += a[j] + " ";
            }
            
        }
        cout<<ret<<endl;
        
    }
}
//비트마스킹을 이용한 매개변수 전달
void Func2(int num)
{
    string ret = "";
    for (int i =0; i<4; i++)
    {
        if(num & (1 << i)) ret += a[i] + " ";
    }
    cout<<ret<<endl;
    return;
}
///이런식으로 호출 

//     for (int j =0; j<n; j++)
//     {
//        Func2(1 | (1 << j)) 
//     }
//     cout<<endl;
