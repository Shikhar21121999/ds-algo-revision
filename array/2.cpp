// partition an array around a pivot
#include <bits/stdc++.h>
using namespace std;

void partitionOddEven(vector<int> &a) {
	int i=0;
	int j=0;

	while(i<a.size()) {
		if (a[i]%2 == 0) {
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
    partitionOddEven(a);

    for (auto x: a){
    	cout << x << " ";
    }
    cout<<endl;
}