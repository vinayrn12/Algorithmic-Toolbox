#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n1;
    cin>>n1;
    vector<int> d1;
    for(int i=0; i<n1; i++){
        int temp;
        cin>>temp;
        d1.emplace_back(temp);
    }
    int n2;
    cin>>n2;
    vector<int> d2;
    for(int i=0; i<n2; i++){
        int temp;
        cin>>temp;
        d2.emplace_back(temp);
    }
    int n3;
    cin>>n3;
    vector<int> d3;
    for(int i=0; i<n3; i++){
        int temp;
        cin>>temp;
        d3.emplace_back(temp);
    }
    vector<vector<vector<int>>> d(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1)));
    for(int i=1; i<=n1; i++)
        for(int j=1; j<=n2; j++)
            for(int k=1; k<=n3; k++){
                if((d1[i-1] == d2[j-1]) && (d2[j-1] == d3[k-1]))
                    d[i][j][k] = d[i-1][j-1][k-1]+1;
                else
                    d[i][j][k] = max(max(d[i-1][j][k], d[i][j-1][k]), d[i][j][k-1]);
        }
    int result = d[n1][n2][n3];
    cout<<result;
    return 0;
}
