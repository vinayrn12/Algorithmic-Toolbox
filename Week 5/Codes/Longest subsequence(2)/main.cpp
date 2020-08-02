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
    vector<vector<int>> d(n1+1, vector<int>(n2+1));
    for(int i=0; i<=n1; i++)
        d[i][0]=0;
    for(int j=0; j<=n2; j++)
        d[0][j]=0;
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(d1[i-1] == d2[j-1])
                d[i][j] = d[i-1][j-1]+1;
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }
    int result = d[n1][n2];
    cout<<result<<endl;
    //Getting the sequence
    /* Optional
    vector<int> sequence;
    int i=n1, j=n2;
    while(result != 0){
        if(d1[i-1] == d2[j-1]){
            result-=1;
            sequence.emplace_back(d1[i-1]);
            i-=1;j-=1;
        }
        else{
            if(d[i-1][j] >= d[i][j-1])
                i-=1;
            else
                j-=1;
        }
    }
    reverse(begin(sequence), end(sequence));
    for(size_t i=0; i<sequence.size(); i++)
        cout<<sequence[i]<<" ";
        */
    return 0;
}
