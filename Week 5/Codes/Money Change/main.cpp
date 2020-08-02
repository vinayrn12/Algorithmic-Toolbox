#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int money, num_coins;
    cin>>money;
    vector<int> minCoins(money+1);
    minCoins.at(0) = 0;
    vector<int> coins {1, 3, 4};
    for(size_t i=1; i<minCoins.size(); i++){
        minCoins[i] = 99999;
        for(size_t j=0; j<coins.size(); j++){
            if(i >= coins[j]){
                num_coins = minCoins[i-coins.at(j)]+1;
                if(num_coins < minCoins[i])
                    minCoins[i]=num_coins;
            }
        }
    }
    int result = minCoins.at(money);
    cout<<result;
    return 0;
}
