#include<iostream>
using namespace std;
 
// A recursive function that removes 'n' characters from 'str'
// to store the smallest possible number in 'res'
void buildLowestNumberRec(string str, int n, string &res)
{
    
    
    if (n == 0)
    {
        res.append(str);
        return;
    }
 
    int len = str.length();
 
    if (len <= n)
        return;
 
    int minIndex = 0;
    for (int i = 1; i<=n ; i++)
        if (str[i] < str[minIndex])
            minIndex = i;
 
    // Append the smallest character to result
    res.push_back(str[minIndex]);
 
  
    string new_str = str.substr(minIndex+1, len-minIndex);
 
  
    buildLowestNumberRec(new_str, n-minIndex, res);
}
 

string buildLowestNumber(string str, int n)
{
    string res = "";
 
    
    buildLowestNumberRec(str, n, res);
 
    return res;
}
 

int main()
{
    string str = "121198";
    int n = 2;
    cout << buildLowestNumber(str, n);
    return 0;
}

