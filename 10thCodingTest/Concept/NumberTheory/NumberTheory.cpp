#include <iostream>
#include <vector>
using namespace std;


// 최대 공약수

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int gcd(int a , int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
// 최소 공배수
int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}
// 모듈러 연산
///0. a ≡ b mod n과 b ≡ c mod n 은 a ≡ c mod n 을 의미
///1. [(a mod n)+(b mod n)] mod n = (a+b) mod n
///2. [(a mod n)-(b mod n)] mod n = (a-b) mod n
///3. [(a mod n)*(b mod n)] mod n = (a*b) mod n

//에라토스테네스의 체
//소수가 아닌 값들에 대한 불리언 배열을 만들어 소수만을 걸러낼 수 있는 방법입니다
const int max_n = 40;
bool che[max_n + 1];
// 예를 들어 40을 넣었을 때 che[40]이 참조가 되므로 max_n + 1을 넣어야 함.
//  max_n까지의 소수를 만드는 함수.
 vector<int> era(int mx_n)
 {
     vector<int> v;
     for(int i = 2; i <= mx_n; i++)
     {
         if(che[i]) continue;
         for(int j = 2*i; j <= mx_n; j += i)
         {
             che[j] = 1;
         }
     }
     for(int i = 2; i <= mx_n; i++)
         if(che[i] == 0)
             v.push_back(i);

     return v;
 }
// 등차 수열 공식은  n = 공차 * (초항 + 마지막 항) /2 이다
 //등비 수열  a는 초항 , r는 공비 , n은 더하는 것의 계수 ->a * ((int)pow(r, n) - 1) / (r - 1);

//승수는 pow를 이용
//제곱근은 sqrt를 이용