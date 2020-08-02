#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long int calculate_sum(long long int n){
    n%=60;
    if(n <= 1)
        return n;
    long long int a = 0;
    long long int b = 1;
    long long int c = 0;
    long long int sum=1;
    for(int i=2; i<=n; i++){
        c=(a+b)%100;
        a=b;
        b=c;
        sum+=c;
    }
    return sum;
}

int main()
{
    long long int n, m;
    cin>>m>>n;
    if(m==0)
        m++;
    cout<<((calculate_sum(n)-calculate_sum(m-1))%10 + 10)%10;
    return 0;
}



