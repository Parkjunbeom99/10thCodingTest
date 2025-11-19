//1629번 문제

//이건 모듈러 연산에 대한 개념이 필요핟
///정수론에서 모듈러 연산(modular arithmetic) 이란,
///정수의 합과 곱을 어떤 주어진 수의 나머지에 대하여 정의하는 방법입니다.
///c++ 에서 mod는 %로 표현됩니다
//0. a = b % M 과 b = c % M 은 a = c % M 을 의미 합니다.
//1. ((a % M) + (b % M)) % M = (a+b) % M
//2. ((a % M) - (b % M)) % M = (a-b) % M
//3. ((a % M) * (b % M)) % M = (a*b) % M

#include <iostream>
using namespace std;

long long a, b, c;

long long ret = 1;

long long mod(long long a, long long b ,long long c)
{
    if (b == 1)
    {
        return (a%c) ;
    }
    ret = mod(a, b/2, c);
    ret = ret *ret %c;
    if (b %2 )
    {
        ret = (ret * a )%c;
    }
    return ret;
   
    
}
int main()
{
    cin>>a>>b>>c;
    
    cout<<mod(a, b, c);
}