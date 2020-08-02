#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <climits>

using namespace std;

long long int eval_exp(long long int a, long long int b, char o){
    if(o == '+')
        return a+b;
    else if(o == '-')
        return a-b;
    else if(o == '*')
        return a*b;
    else if(o == '/')
        return a/b;
    else
        return 0;
}

void max_exp(string exp){
    long long int n = (exp.size()+1)/2;
    vector<vector<long long int>> m(n, vector<long long int>(n));
    vector<vector<long long int>> M(n, vector<long long int>(n));
    for(long long int i=0; i<n; i++){
        m[i][i]=stoll(exp.substr(2*i, 1));
        M[i][i]=stoll(exp.substr(2*i, 1));
    }
    for(long long int s=0; s<n-1; s++){
        for(long long int i=0; i<n-s-1; i++){
            long long int j=i+s+1;
            long long int minimum = LLONG_MAX;
            long long int maximum = LLONG_MIN;
            for(long long int k=i; k<j; k++){
                long long int a = eval_exp(m[i][k], m[k+1][j], exp.at(2*k+1));
                long long int b = eval_exp(m[i][k], M[k+1][j], exp.at(2*k+1));
                long long int c = eval_exp(M[i][k], m[k+1][j], exp.at(2*k+1));
                long long int d = eval_exp(M[i][k], M[k+1][j], exp.at(2*k+1));
                minimum = min(minimum, min(min(a, b), min(c, d)));
                maximum = max(maximum, max(max(a, b), max(c, d)));
            }
            m[i][j]=minimum;
            M[i][j]=maximum;
        }
    }
    cout<<M[0][n-1];
}

int main()
{
    string exp;
    getline(cin, exp);
    max_exp(exp);
    return 0;
}
