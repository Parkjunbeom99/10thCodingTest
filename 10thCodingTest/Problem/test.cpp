#include <iostream>

using namespace std;

int t;
string s;

long long a,b,c;

long long ret =1 ;
long long mod(long long a, long long b)
{
    if (b == 1 )
    {
        return a % c;
    }
    ret = mod(a, b/2);
    ret = (ret * ret) % c;
    if (b % 2 == 1)
    {
        ret = (ret * a) % c;
    }
    return ret;
}

int main()
{
  
    /// (a*a)%c;
    

}