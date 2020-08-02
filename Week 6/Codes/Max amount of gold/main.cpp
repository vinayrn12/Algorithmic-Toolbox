#include <iostream>
#include <vector>

using namespace std;

void max_gold(vector<int> &weights, int &W, int &n){
    vector<vector<int>> result(n+1, vector<int>(W+1));
    int val;
    for(int i=0; i<=n; i++)
        result[i][0]=0;
    for(int i=0; i<=W; i++)
        result[0][i]=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            result[i][j] = result[i-1][j];
            if(weights.at(i) <= j){
                val = result[i-1][j-weights.at(i)]+weights.at(i);
                if(val > result[i][j])
                    result[i][j]=val;
            }
        }
    }
    cout<<result[n][W];
}

int main()
{
    int W, n;
    cin>>W>>n;
    vector<int> weights;
    weights.push_back(0);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        weights.emplace_back(temp);
    }
    max_gold(weights, W, n);
    return 0;
}
