#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>> d(n1+1, vector<int>(n2+1));
    for(int i=0; i<=n1; i++)
        d[i][0]=i;
    for(int j=0; j<=n2; j++)
        d[0][j]=j;
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(str1[i-1] == str2[j-1])
                d[i][j] = min(min(d[i-1][j]+1, d[i][j-1]+1), d[i-1][j-1]);
            else
                d[i][j] = min(min(d[i-1][j]+1, d[i][j-1]+1), d[i-1][j-1]+1);
        }
    }
    int result = d[n1][n2];
    cout<<result;
    return 0;
}
