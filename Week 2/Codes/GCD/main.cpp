#include <iostream>

using namespace std;

long long GCD(int a, int b){
    if(b == 0)
        return a;
    GCD(b, a%b);
}

int main()
{
    long long a, b;
    cin>>a>>b;
    long long result = GCD(a, b);
    cout<<result;
    return 0;
}
