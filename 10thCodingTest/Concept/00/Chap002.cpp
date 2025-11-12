#include <iostream>
#include <vector>

using namespace std;
// Split만드는 함수
//그냥 문자열을 구분해서 벡터에 담는다라고 생각해라 
//ex string s = "123,456,789";
// vector [123, 456, 789]
//del = ', '
//Substr( 0, 5) -> 인덱스 0 부터 5개
vector<string> Split(const string& s, string del)
{
    vector<string> result;

    auto start = 0;
    auto end = s.find(del);
    while (end != s.string::npos)
    {
        result.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    
    result.push_back(s.substr(start)); //마지막 문자열을 넣어준다. 
    return result;
    
}
