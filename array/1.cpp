// partition an array around a pivot
#include <bits/stdc++.h>
using namespace std;

void partition(vector<int> &a, int p) {
	int i=0;
	int j=0;

	while(i<a.size()) {
		if (a[i] > p) {
			i++;
		} else {
			swap(a[i], a[j]);
			i++;
			j++;
		}
	}
}

int main()
{
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0; i<n; i++) {
    	cin>>a[i];
    }
    partition(a, 0);

    for (auto x: a){
    	cout << x << " ";
    }
    cout<<endl;
}