#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Timings{
    long int arrive, depart;
};

bool sort_time(Timings t1, Timings t2){
    if(t1.depart < t2.depart)
        return true;
    return false;
}

void visit_count(vector<Timings> &timings){
    set<long int> points;
    int timing=timings[0].depart;
    points.insert(timing);
    for(size_t i=1; i<timings.size(); i++){
        if(timing<timings[i].arrive || timing>timings[i].depart){
            timing=timings[i].depart;
            points.insert(timing);
        }
    }
    cout<<points.size()<<endl;
    for(auto x: points)
        cout<<x<<" ";
}


int main()
{
    long int n;
    cin>>n;
    vector<Timings> timings(n);
    for(long int i=0; i<n; i++)
        cin>>timings[i].arrive>>timings[i].depart;
    sort(begin(timings), end(timings), sort_time);/*
    for(int i=0; i<n; i++)
        cout<<timings[i].arrive<<" "<<timings[i].depart<<endl;*/
    visit_count(timings);
    return 0;
}
