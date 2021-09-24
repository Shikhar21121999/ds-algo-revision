// qucik sort recursive
#include <bits/stdc++.h>
using namespace std;

#define vi vector <int>

void partition(vector<int> &a, int lo, int hi, int piv) {
	int i=lo;
	int j=lo;

	while(i <= hi) {
		if (a[i] > piv) {
			i++;
		} else {
			swap(a[i], a[j]);
			i++;
			j++;
		}
	}
	return j-1;
}

void quickSort (vi &a, int lo, int hi) {

	// base case
	if (lo >= hi) {
		return;
	}

	int piv = a[hi]
	int piInd = partition(a, lo, hi, piv)
	quickSort(a, lo, piInd - 1);
	quickSort(a, piInd + 1, hi);
}

int main()
{
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0; i<n; i++) {
    	cin>>a[i];
    }
    partition(a, 0, 3, 2);

    for (auto x: a){
    	cout << x << " ";
    }
    cout<<endl;
}