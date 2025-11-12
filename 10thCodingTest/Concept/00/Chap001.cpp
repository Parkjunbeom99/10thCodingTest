#include <iostream>
#include <vector>

using namespace std;


vector<int> v;
int k;
int n;
void PrintV(vector<int>& V)
{
    for (int i=0; i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

// 순열을 재귀로 만드는 법 
void MakePermutation(int n, int r, int depth)
{
    cout<<n<<" : " <<r << " : "<<depth<< '\n';
    if (r == depth)
    {
        PrintV(v);
        return;              
    }
    for (int i=depth; i<n; i++)
    {
        swap(v[i], v[depth]);
        MakePermutation(n, r, depth+1);
        swap(v[i], v[depth]);
    }
    return;
}

//조합을 재귀 함수 -> 4개 이상 뽑을 떄 
//외우는 게 좋다 
void Combi(int start, vector<int> b) 
{
    if (b.size() == k)
    {
        PrintV(b);
        return;
    }
    for (int i=start+1; i<n; i++)
    {
        b.push_back(v[i]);
        Combi(i, b);
        b.pop_back();
    }
}

//중첩 for문 -> 3개이하를 뽑을때 사용하자  뽑을 떄 
int main()
{
    vector<int>b;
  
    for (int i=0; i<n;i++)
    {
        for (int j =i+1; j<n;j++)
        {
            for (int k= j+1; k<n;k++)
            {
                cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<'\n';
            }
        }
    }
}