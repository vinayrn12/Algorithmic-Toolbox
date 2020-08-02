#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int loot_possible(int w, int W){
    if(w < W)
        return 1;
    return 0;
}

void calculate_loot(vector<pair<double, int>> value_by_weight, vector<int> weights, int W){
    double loot=0.0;
    for(unsigned int i=0; i<value_by_weight.size(); i++){
        if(W == 0)
            break;
        if(loot_possible(weights[value_by_weight[i].second], W)){
            loot += ((double)(weights[value_by_weight[i].second])*value_by_weight[i].first);
            W -= weights[value_by_weight[i].second];
        }
        else{
            loot += ((double)(W)*value_by_weight[i].first);
            W -= W;
        }
    }
    cout<<fixed;
    cout<<setprecision(5)<<loot;
}

int main()
{
    int n, W;
    cin>>n>>W;
    vector<int> weights;
    vector<int> value;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        value.emplace_back(temp);
        cin>>temp;
        weights.emplace_back(temp);
    }
    vector<pair<double, int>> value_by_weight;
    for(unsigned int i=0; i<value.size(); i++)
        value_by_weight.emplace_back((double)(value[i])/weights[i], i);
    sort(begin(value_by_weight), end(value_by_weight));
    reverse(begin(value_by_weight), end(value_by_weight));
    calculate_loot(value_by_weight, weights, W);
    return 0;
}
