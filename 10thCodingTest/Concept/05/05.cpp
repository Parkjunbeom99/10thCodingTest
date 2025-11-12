#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


bool comp(pair<int,int>a, pair<int,int>b)
{
    return a.first > b.first;
}
int main()
{
    vector<pair<int,int>> v ={{10000,5},{1000,3},{500,1},{100,5},{50,5},{10,5},{1,5}};
    sort(v.begin(), v.end(), comp); // 우선 가장 큰 금액부터

    int n = 12100;

    int cnt =0;
    for (int i=0; i<v.size();i++)
    {
        cnt += n / v[i].first; // 큰 금액의 지폐부터
        n %= v[i].first;
        if (n==0) break;

    }
    cout << cnt << '\n';

}

bool comp2(pair<int,int>a, pair<int,int>b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    int n ;
    cin >> n;

    vector<pair<int,int>> v(n);
    for (int i=0;i<n;i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), comp2);

    int end = v[0].second;
    int cnt =1;
    for (int i=1;i<v.size();i++)
    {
        if (v[i].first >= end)
        {

            end = v[i].second;
            cnt++;
        }

    }
    cout<<cnt<<'\n';

}




typedef long long ll;

ll n, k, ret, temp1, temp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    vector<pair<ll,ll>> v(n);
    vector<ll> vv(k);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 0; i < k; i++)
    {
        cin >> vv[i];
    }

    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());

    priority_queue<ll> pq;
    int j = 0;

    for(int i = 0; i < k; i++)
    {
        while(j < n && v[j].first <= vv[i])
        {
            pq.push(v[j++].second);
        }

        if(pq.size())
        {
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret << "\n";

    return 0;
}



 //라인 스위핑
int main()
{
    

    int n;
    cin>>n;

    vector<pair<int,int>> v(n);
    for (int i=0;i <n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(), v.end());
    int s = v[0].first;
    int e = v[0].second;

    int sum =0;
    for (int i=1 ;i<n;i++)
    {
        if (v[i].first > e)
        {
            sum +=e - s;
            s = v[i].first;
            e = v[i].second;
        }
        else
        {
            e = max(e, v[i].second);
        }
    }
    sum += e-s;
    cout<<sum<<'\n';
    
}

//투 포인터  양 끝	start=0, end=n-1	정렬이 보통 필요	두 요소의 조합에서 사용 
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int x;
    cin>>x;
    sort(v.begin(), v.end());

    int start =0;
    int end = n-1;

    int cnt = 0;
    while (start < end)
    {
        int sum = v[start] + v[end];
        if ( sum > x)
        {
            end --;
        }
        else if ( sum < x)
        {
            start ++; 
        }
        else if ( sum == x )
        {
            end--;
            cnt++;
        }
    }
    
}


// start=0, end=0	정렬 불필요	연속된 구간 구하는 용도 
int main()
{
    int n, x;
    cin >> n >> x;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    int start = 0;
    int end = 0;
    int sum = 0;
    int minLen = INT_MAX;
    
    while (end < n)
    {
        sum += v[end];
        
        // 합이 x 이상이면 start를 이동하며 최소 길이 찾기
        while (sum >= x)
        {
            minLen = min(minLen, end - start + 1);
            sum -= v[start];
            start++;
        }
        
        end++;
    }
    
    if (minLen == INT_MAX)
        cout << 0 << '\n';
    else
        cout << minLen << '\n';
}