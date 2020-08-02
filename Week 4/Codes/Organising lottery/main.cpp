#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct line{
    long int l, r;
};

struct order{
    long int pos;
    char type;
    long int index;
};

bool operator==(line &t1, line &t2){
    if(t1.l == t2.l && t1.r == t2.r)
        return true;
    return false;
}

void range_check(vector<order> &a, long int n){
    long int c=0;
    vector<int> result(n);
    for(size_t i=0; i<a.size(); i++){
        if(a[i].type == 'l')
            c++;
        else if(a[i].type == 'r')
            c--;
        else
            result[a[i].index]=c;
    }
    for(size_t i=0; i<result.size(); i++)
        cout<<result[i]<<" ";
}

int main()
{
    long int numlines, numpoints;
    cin>>numlines>>numpoints;
    vector<line> lines(numlines);
    vector<long int> points(numpoints);
    for(long int i=0; i<numlines; i++)
        cin>>lines[i].l>>lines[i].r;
    for(long int i=0; i<numpoints; i++)
        cin>>points[i];
    vector<order> a;
    for(size_t i=0; i<lines.size(); i++){
        order temp1, temp2;
        temp1.pos = lines[i].l;
        temp1.type = 'l';
        temp1.index=i;
        temp2.pos = lines[i].r;
        temp2.type = 'r';
        temp2.index=i;
        a.emplace_back(temp1);
        a.emplace_back(temp2);
    }
    for(size_t i=0; i<points.size(); i++){
        order temp;
        temp.pos = points[i];
        temp.type = 'p';
        temp.index = i;
        a.emplace_back(temp);
    }
    sort(begin(a), end(a),
         [](order t1, order t2)
         {if(t1.pos==t2.pos)
            return t1.type<t2.type;
          else
            return t1.pos<t2.pos;
        });
    range_check(a, numpoints);
    return 0;
}
