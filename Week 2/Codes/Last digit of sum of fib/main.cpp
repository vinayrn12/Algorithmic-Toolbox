#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

long int fib(long long int n){
    if(n <= 1)
        return n;
    int a = 0;
    int b = 1;
    int c = 0;
    long int sum=1;
    for(long long int i=2; i<=n; i++){
        c=a+b;
        c%=10;
        a=b;
        b=c;
        sum+=c;
        sum%=10;
    }
    return sum;
}

int main()
{
    long long int n;
    cin>>n;
    n%=60;

    cout<<fib(n);
    return 0;
}
