#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct period{
    int m1, m2;
};

period partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  period j;
  j.m1 = l+1;
  j.m2 = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j.m2++;
      swap(a[i], a[j.m2]);
      if(a[j.m2] < x){
        swap(a[j.m2], a[j.m1]);
        j.m1++;
      }
    }
  }
  swap(a[j.m1-1], a[l]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  period m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.m1-2);
  randomized_quick_sort(a, m.m2+1, r);
}

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; ++i) {
        int temp;
        cin>>temp;
        a.emplace_back(temp);
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
}
