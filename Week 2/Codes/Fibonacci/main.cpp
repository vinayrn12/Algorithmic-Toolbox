#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

long long fib(int n, vector<long long> & f){
    if(n <= 1)
        return n;
    f.at(0) = 0;
    f.at(1) = 1;
    for(int i=2; i<=n; i++)
        f.at(i) = f.at(i-1) + f.at(i-2);
    return f.at(n);
}

int main()
{
    int n;
    cin>>n;
    vector<long long int> f(n+1);

    cout<<fib(n, f);
    return 0;
}
