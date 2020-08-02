#include <iostream>
#include <vector>

using namespace std;
int inversions = 0;

int count_inversions(vector<int> &a, int l, int r, int mid){
    vector<int> b;
    vector<int> c;
    int inverts=0;
    for(int i=l; i<=mid; i++)
        b.emplace_back(a[i]);
    for(int i=mid+1; i<=r; i++)
        c.emplace_back(a[i]);
    size_t i=0, j=0, k=l;
    while(i < b.size() && j < c.size()){
        if(b[i]<=c[j])
            a[k++]=b[i++];
        else{
            a[k++]=c[j++];
            inverts+=(b.size()-i);
        }
    }
    if(i!=b.size()){
        while(i<b.size()){
            a[k++]=b[i++];
        }
    }
    if(j!=c.size()){
        while(j<c.size())
            a[k++]=c[j++];
    }
    return inverts;
}


void mergesort(vector<int> &a, int l, int r){
    if(l >= r)
        return;
    int mid = (l + ((r-l)/2));
    mergesort(a, l, mid);
    mergesort(a, mid+1, r);
    int c = count_inversions(a, l, r, mid);
    inversions += c;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        a.emplace_back(temp);
    }
    mergesort(a, 0, a.size()-1);
    cout<<inversions;
    return 0;
}
