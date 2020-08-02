#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long int n;
    int m;
    cin>>n>>m;
    vector<long long int> f(m*m);
    f.at(0)=0;
    f.at(1)=1;
    int c=1;
    for(long int i=2; i<m*m; i++){
        f.at(i)=f.at(i-1)+f.at(i-2);
        f.at(i) %= m;
        if(f[i]==1 && f[i-1]==0)
            break;
        else
            c++;
    }
    int mod_factor=n%c;
    long int result=f.at(mod_factor);
    cout<<result;
    return 0;
}
