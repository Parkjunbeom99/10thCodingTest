//1213번 문제
///해당 문제는 팰린드롬 문제이다.
///1. 각 문자의 수를 세어 배열에 넣는다
///2. 홀수 인 문자가 2개 이상인 경우 바로 false
///3. 일단 앞뒤로 붙인다
///4. 홀수인 문자가 있다면 중간에 넣는다.
///
///항상 반례를 생각하자 !!!!!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr [27];
int main()
{
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    {
        arr[s[i]-'A']++;
    }
    int cnt =0;
    for (int i=0; i<26; i++)
    {
        if (arr[i] % 2 == 1)
        {
            cnt++;
            if (cnt>1)
            {
                cout<<"I'm Sorry Hansoo"<<'\n';
                return 0;
            }
        }
    }

    string ret;
    for (int i =25; i>=0; i--)
    {
        for (int j=0; j<arr[i]/2; j++)
        {
            ret += (char)(i + 'A');
            ret = (char)(i + 'A') + ret;
        }
        if (arr[i] %2 == 1)
        {
            ret.insert(ret.size()/2, 1, (char)(i + 'A'));
        }
    }
    cout<<ret<<endl;
}