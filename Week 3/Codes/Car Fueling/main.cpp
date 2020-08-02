#include <iostream>
#include <vector>

using namespace std;

int car_fuel(int distance, int mileage, int num_stops, vector<int> stops){
    int currpos=0, lastpos;
    int refills=0;
    int n = stops.size()-2;
    while(currpos <= n){
        lastpos=currpos;
        while(currpos<=n && stops[currpos+1]-stops[lastpos]<=mileage)
            currpos+=1;
        if(currpos == lastpos){
            return -1;
        }
        if(currpos <= n)
            refills++;
    }
    return refills;
}

int main()
{
    int distance, mileage, num_stops;
    cin>>distance>>mileage>>num_stops;
    vector<int> stops;
    stops.emplace_back(0);
    for(int i=0; i<num_stops; i++){
        int temp;
        cin>>temp;
        stops.emplace_back(temp);
    }
    stops.emplace_back(distance);
    cout<<car_fuel(distance, mileage, num_stops, stops);
    return 0;
}
