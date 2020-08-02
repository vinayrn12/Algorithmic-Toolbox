#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<long int> ads;
    vector<long int> money;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        ads.emplace_back(temp);
    }
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        money.emplace_back(temp);
    }
    long int max_revenue=0;
    sort(begin(ads), end(ads));
    reverse(begin(ads), end(ads));
    sort(begin(money), end(money));
    reverse(begin(money), end(money));
    for(int i=0; i<n; i++)
        max_revenue += (ads[i]*money[i]);
    cout<<max_revenue;
    return 0;
}
