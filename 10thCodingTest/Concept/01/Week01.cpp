#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int Q1(int a, int b)
{
    vector<int> prefixSum;

    prefixSum.push_back(v[0]);

    for (int i=1; i< a; i++)
    {
        prefixSum.push_back(v[i] + prefixSum[i-1]); 
    }

    int sum = 0;
    for (int i = 0; i < b; i++) {
        int m, n;
        cin >> m >> n;
    
        if (m == 0)
            sum += prefixSum[n];
        else
            sum += prefixSum[n] - prefixSum[m-1];
    }
    return sum; 
    
}

