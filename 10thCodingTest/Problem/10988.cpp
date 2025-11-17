//10988번 문제

#include <iostream>
#include <string>
using namespace std;


//이건 그냥 s[i] == s[s.size()-1 -i] 이런식으로 하면 된다.
string s;
int main()
{
    cin>>s;

    for (int i=0; i<s.size()/2; i++)
    {
        if (s[i] != s[s.size()-1 -i])
        {
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<1<<endl;
    return 0;
    
}