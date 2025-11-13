#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n ,t,m;

    cin>>t;
    while (t--)
    {
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        sort(v.begin(), v.end());

        cin>>m;

        for (int i=0; i < m; i++)
        {
            int x;
            cin>>x;
            int ret = binary_search(v.begin(), v.end(), x);
            if (ret)
            {
                cout << 1 << '\n';  
            }
            else
            {
                cout << 0 << '\n'; 
            }
        }
        
    }
    
}

int main()
{
    int n ;
    cin>>n;
    vector<int> v(n);
    vector<int> cnt(n);
    int ret;
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    for (int i=0; i<n; i++)
    {
        int maxValue = 0;
        for (int j = 0; j<i;j++)
        {
            if (v[j] < v[i] && maxValue < cnt[j]) maxValue = cnt[j];
        }
        cnt[i] = maxValue +1;
        ret = max(ret,cnt[i]);
        
    }
    
     
    
}
