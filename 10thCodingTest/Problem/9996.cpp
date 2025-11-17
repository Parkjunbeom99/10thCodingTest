//9996번 문제


#include <iostream>

using namespace std;

int n;

int main()
{

    cin>>n;
    string s;
    string s2;
    cin>>s;

    int ret = s.find('*');
    string prefix = s.substr(0, ret);  // * 앞부분
    string suffix = s.substr(ret + 1);  // * 뒷부분

    for (int i=0; i<n; i++)
    {
        cin>>s2;
    
        // 이걸 꼭 알아야함 !! 길이 체크 prefix + suffix보다 길이가 작으면 무조건 불통 
        if (s2.size() < prefix.size() + suffix.size())
        {
            cout<<"NE"<<endl;
            continue;
        }
    
      
        if (s2.substr(0, prefix.size()) == prefix && 
            s2.substr(s2.size() - suffix.size()) == suffix)
        {
            cout<<"DA"<<endl;
        }
        else
        {
            cout<<"NE"<<endl;
        }
    }
    
    
    
    
    
}
