#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        a.emplace_back(temp);
    }
    int m;
    cin>>m;
    vector<int> s;
    for(int i=0; i<m; i++)
    {
        int temp;
        cin>>temp;
        s.emplace_back(temp);
    }
    for(size_t i=0; i<s.size(); i++){
        int l=0, h=n-1;
        int mid;
        int key=s[i], found=0;
        while(l <= h){
            mid=((l+h)/2);
            if(key == a[mid]){
                s[i]=mid;
                found=1;
                break;
            }
            else if(key < a[mid])
                h=mid-1;
            else
                l=mid+1;
        }
        if(!found)
            s[i]=-1;
    }
    for(size_t i=0; i<s.size(); i++)
        cout<<s[i]<<" ";
    return 0;
}
