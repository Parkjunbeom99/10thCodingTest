// 3986번 문제

//해당 문제는 stack 자료 구조의 특성을 이용해서 top과 들어갈 문자를 비교해보면된다
//이런 문제를 보면 문자를 뒤집어 보고 회전 시켜보면서 생각해보자

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
int main()
{
    cin>>n;

    string s;
    int cnt =0;
    while (n--)
    {
        cin>>s;
        stack<char> st;
        for (int i=0;i<s.size(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if (st.top()== s[i])
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
                
            }
        }
        if (st.empty())
        {
            cnt++;
        }
    }

    cout<<cnt;
}