#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getmin(vector<int> &numbers, int n){
    if(n%3==0 && n%2==0)
        return min(min(numbers.at(n/3)+1, numbers.at(n/2)+1), numbers.at(n-1)+1);
    if(n%3 == 0)
        return min(numbers.at(n/3)+1, numbers.at(n-1)+1);
    else if(n%2 == 0)
        return min(numbers.at(n/2)+1, numbers.at(n-1)+1);
    else
        return numbers.at(n-1)+1;
}



int main()
{
    int n;
    cin>>n;
    vector<int> numbers(n+1);
    numbers.at(0)=0;
    numbers.at(1)=0;
    for(size_t i=2; i<numbers.size(); i++){
        numbers.at(i) = getmin(numbers, i);
    }
    int result = numbers.at(n);
    cout<<result<<endl;
    //Display functions
    vector<int> path;
    path.emplace_back(n);
    while(n != 1){
        if(n%3==0 && n%2==0){
            if(numbers.at(n/3) < numbers.at(n/2)){
                if(numbers.at(n/3) < numbers.at(n-1))
                    n /= 3;
                else
                    n -= 1;
            }
            else{
                if(numbers.at(n/2) < numbers.at(n-1))
                    n /= 2;
                else
                    n -= 1;
            }
            path.emplace_back(n);
        }
        else{
            if(n%3 == 0){
                if(numbers.at(n/3) < numbers.at(n-1))
                    n /= 3;
                else
                    n -= 1;
                path.emplace_back(n);
            }
            else if(n%2 == 0){
                if(numbers.at(n/2) < numbers.at(n-1))
                    n /= 2;
                else
                    n -= 1;
                path.emplace_back(n);
            }
            else{
                n -= 1;
                path.emplace_back(n);
            }
        }
    }
    reverse(begin(path), end(path));
    for(size_t i=0; i<path.size(); i++)
        cout<<path.at(i)<<" ";
    return 0;
}
