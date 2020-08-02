#include <iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;

long long pairwise_product(vector<int> &arr){
    int i1=-1, i2=-1;
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        if(i1 == -1 || (long long)(arr[i]) > arr[i1])
            i1=i;
    }
    for(int j=0; j<n; j++){
        if(j != i1 && (i2==-1 || arr[j] > arr[i2]))
            i2=j;
    }
    return (long long)(arr[i1]) * arr[i2];
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    long long result = pairwise_product(arr);
    cout<<result;
    return 0;
}
*/
