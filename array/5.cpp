#include <bits/stdc++.h>
using namespace std;

# define vi vector<int>
# define pii pair<int, int>

void basicTraversal() {
	vi a(5, 0);
	for (auto x: a) {
		cout <<x<<" ";
	}
	cout<<"\n";
}

void matrixTraversal() {
	vector<vector<int>> matr(5, vi(5,1));
	for(int i=0;i<matr.size();i++) {
		for(int j=0;j<matr[i].size();j++){
			cout<<matr[i][j]<<" ";
		}
		cout<<"\n";
	}

}

void reserveSizeDemo() {
	vi a;
	a.reserve(5);
	cout<<a.size(); // outputs 0
	a.resize(5,6);
	cout<<a.size();
	for(auto x:a) {
		cout<<x<<" ";
	}
}

void reverseDemo() {
	vector<int> a;
	for(int i=0;i<5;i++){
		a.push_back(i+10);
	}
	for(auto x:a){
		cout<<x<<" ";
	}
	cout<<"\n";

	reverse(a.begin(),a.end());
	for(auto x:a){
		cout<<x<<" ";
	}
	cout<<"\n";
}

void sortDemo() {
	vector <int> a;
	for(int i=0;i<5;i++){
		a.push_back(i+10);
	}
	for(auto x:a){
		cout<<x<<" ";
	}
	cout<<"\n";
	sort(a.begin(),a.end(), greater<int>());
	for(auto x:a){
		cout<<x<<" ";
	}
	cout<<"\n";
}

bool greater_first(pii a, pii b) {
	return a.first > b.first;
}

bool greater_second(pii a, pii b) {
	return a.second > b.second;
}

void printVectorPairII (vector <pii> a) {
	for (auto x:a) {
		cout<<x.first<<" "<<x.second<<"\n";
	}
}

void sortPairDemo() {
	vector<pair<int,int>> a;

	for(int i=0;i<5;i++) {
		a.push_back({i+2,i-5});
	}
	printVectorPairII(a);

	// reverse vector of pair int int
	reverse(a.begin(), a.end());
	printVectorPairII(a);

	// sort according to first element
	sort(a.begin(),a.end(), greater_second);
	printVectorPairII(a);
}


int main() {
	sortPairDemo();
}