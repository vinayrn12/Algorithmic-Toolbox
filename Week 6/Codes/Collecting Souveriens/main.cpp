#include <iostream>
#include <vector>

using namespace std;

int calc(long long int n, long long int sum, vector<long long int> items){
    vector<vector<int>> res(n+1, vector<int>(sum+1));
    for(int i=0; i<=n; i++)
        res[i][0]=1;
    for(int i=0; i<=sum; i++)
        res[0][i]=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(res[i-1][j]==1)
                res[i][j]=1;
            else{
                if(items.at(i-1)>j)
                    res[i][j]=0;
                else
                    res[i][j]=res[i-1][j-items.at(i-1)];
            }
        }
    }
    return res[n][sum];
}

int main()
{
    long long int n;
    cin>>n;
    vector<long long int> items;
    for(long long int i=0; i<n; i++){
        long long int temp;
        cin>>temp;
        items.emplace_back(temp);
    }
    long long int sum=0;
    int result;
    for(size_t i=0; i<items.size(); i++)
        sum += items.at(i);
    if(sum%3!=0)
        result=0;
    else
        result=calc(n, sum/3, items);
    cout<<result;
    return 0;
}
