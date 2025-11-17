#include <iostream>
#include <string>
using namespace std;

//10808번 문제
///문자열 s를 입력받는다
///배열을 소문자 a부터 z까지 넣을 껄 만든다
///s의 문자열을 하나씩 확인하면서 아스키 코드를 이용해 넣는다

string s;

int arr[26];

int main()
{
    cin>>s;
    for (int i=0; i<s.size();i++)
    {
        arr[s[i] - 'a'] ++;
    }
    for (int i=0; i<26; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}