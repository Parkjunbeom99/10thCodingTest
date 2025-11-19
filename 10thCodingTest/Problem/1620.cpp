//1620번 문제

// 여기서는 counting 할때 string은 map int는 배열 or map을 사용해서 두 자료 구조를 사용하면된다
// 그럼 10만의 mlongn의 시간 복잡도로 탐색이 가능하기에 가능 ~  

#include <iostream>
#include <map>
#include <string>

using namespace std;

int n , m ;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;

    map<string, int >m1;
    map<int,string> m2;
    string s;
    for (int i=1; i<=n; i++)
    {
        cin>>s;
        m1[s] = i;
        m2[i] = s;
    }
    for (int i=0; i<m; i++)
    {
        cin>>s;

        if (atoi(s.c_str()))
        {
            cout<<m2[atoi(s.c_str())]<<'\n';
        }
        else
        {
            cout<<m1[s]<<'\n';
        }
        
    }
    
}