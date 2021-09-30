// sort a k soreted array
#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>

void sortKSortedArray (vi &a, int x) {

	// create an empty priority queue

	priority_queue < int, vi, greater<int> > pq;

	// fill priority queue with first 'k+1' elements
	for (int i=0; i < k + 1; i++) {
		pq.push(a[i]);
	}

	// keep track of index to update the value
	// and keep adding next elements to the array
	int index = 0;

	for (int i = k+1; i < n; i++) {
		a[index++] = pq.top();
		pq.pop();
		pq.push(a[i]);
	}

	while(!pq.empty()) {
		a[index++] = pq.top();
		pq.pop();
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