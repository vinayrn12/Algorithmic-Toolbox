#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long int n;
    cin>>n;
    vector<long int> prizes;
    long int k=1;
    while(n != 0){
        if(2*k < n){
            prizes.emplace_back(k);
            n-=k;
        }
        else{
            prizes.emplace_back(n);
            n-=n;
        }
        k++;
    }
    cout<<prizes.size()<<endl;
    for(size_t i=0; i<prizes.size(); i++)
        cout<<prizes[i]<<" ";
    return 0;
}
