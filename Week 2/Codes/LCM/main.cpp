#include <iostream>

using namespace std;

long long GCD(int a, int b){
    if(b == 0)
        return a;
    GCD(b, a%b);
}

int main()
{
    long a, b;
    cin>>a>>b;
    long long gcd = GCD(a, b);
    long long int lcm = (long long int)(a) * b /gcd;
    cout<<lcm;
    //Method-1(Successful)
    /*if(b>a){
        int temp = a;
        a = b;
        b = temp;
    }
    long long int result;
    long long int range = (long long int)(a)*b;
    for(long long int i=a; i<=range; i+=a){
        if(i%a==0 && i%b==0){
            result=i;
            break;
        }
        else
            result=0;
    }
    cout<<result;*/
    return 0;
}
