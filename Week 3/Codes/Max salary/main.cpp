#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check_max(int n, int m){
    string s1 = to_string(n);
    string s2 = to_string(m);
    if(s1+s2 > s2+s1)
        return true;
    return false;
}

void cal_salary(vector<int> numbers){
    string salary {""};
    while(numbers.size() != 0){
        size_t index = 0;
        int max_ele = 0;
        for(size_t i=0; i<numbers.size(); i++){
            int ele = numbers[i];
            if(check_max(ele, max_ele)){
                max_ele = ele;
                index=i;
            }
        }
        salary += to_string(max_ele);
        numbers.erase(numbers.begin() + index);
    }
    cout<<salary;
}

int main()
{
    int n;
    cin>>n;
    vector<int> numbers;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        numbers.emplace_back(temp);
    }
    cal_salary(numbers);
    return 0;
}
