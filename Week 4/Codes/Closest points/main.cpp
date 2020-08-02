#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math>

using namespace std;

struct point{
    int x, y;
};

double calculate_distance(point p1, point p2){
    double res = sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
    return res;
}

int mindist(vector<point> &points, int l, int mid, int h){
    if(points.size() == 1)
        return 0;

}

void mergesort(vector<point> &points, int l, int h){
    if(l >= r)
        return;
    int mid = (l+h)/2;
    mergesort(points, l, mid);
    mergesort(points, mid+1, h);
    int result = mindist(points, l, mid, h);
}

int main()
{
    int n;
    cin>>n;
    vector<point> points;
    for(int i=0; i<n; i++){
        point temp;
        cin>>temp.x>>temp.y;
        points.emplace_back(temp);
    }
    sort(begin(points), end(points), (point t1, point t2)[] {return (t1.x < t2.x);});
    mergesort(points, 0, n-1);
    return 0;
}
