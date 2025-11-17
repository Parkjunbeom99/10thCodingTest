//2559번 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n,k;

//이건 누적합을 이용해서 풀었다
//k가 연속된 일수이기에 i+k 가 n을 넘어가지 않는한 prefixSum[i+k] - prefixSum[i]를 하면 된다.

int main()
{
    cin>>n>>k;
    vector<int> v(n+1,0);
    vector<int> prefixSum(n+1,0);
    for (int i=1;i<= n;i++)
    {
        cin>>v[i];
        prefixSum[i] = prefixSum[i-1] + v[i];
        
    }
    int ans = -1e9;
    for (int i=0; i<n; i++)
    {
        if (i+k >n) break;
        ans = max(ans , prefixSum[i+k] - prefixSum[i]);
    }
    cout<<ans;
}