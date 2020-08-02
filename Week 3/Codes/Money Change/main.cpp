#include <iostream>

using namespace std;

int main()
{
    int money;
    int tens=0, fivers=0, ones=0;
    cin>>money;
    while(money > 0){
        if(money/10){
            tens=money/10;
            money %= 10;
        }
        if(money/5){
            fivers=money/5;
            money %= 5;
        }
        else{
            ones=money;
            money=0;
        }
    }
    cout<<(tens+fivers+ones);
    return 0;
}
