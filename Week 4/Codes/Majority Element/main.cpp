#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        a.emplace_back(temp);
    }
    int result;
    sort(begin(a), end(a));
    int key = n/2;
    int c=0;
    for(int i=0; i<n; i++)
        if(a[i]==a[key])
            c++;
    if(c>n/2)
        result=1;
    else
        result=0;
    cout<<result;
    return 0;
}
