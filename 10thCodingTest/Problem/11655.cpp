//11655번 문제

#include <iostream>
#include <string>
using namespace std;

//ROT13은 알파벳을 13자리씩 밀어주는 것이다.
// 그리고 만약 입력을 받는데 공백을 받을 경우 getline을 사용한다.
// 아스키 코드는 a는 97, A는 65, z는 122, Z는 90이다.

int main()
{
    string s;

    while (getline(cin, s))
    {
        for (int i=0; i<s.size();i++)
        {
            if (s[i]>= 'a' && s[i] <= 'z') // 소문자인 경우 
            {
                s[i] = (s[i] - 'a' + 13) % 26 + 'a';   //-> 차이 + 13을 한 후 26으로 나눈 나머지에다가 다시 a를 더해준다.
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') // 대문자인 경우 
            {
                s[i] = (s[i] - 'A' + 13) % 26 +'A';
            }

        }
        cout<<s<<" ";
    }
}