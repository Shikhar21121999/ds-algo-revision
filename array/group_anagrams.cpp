#include <bits/stdc++.h>
using namespace std;

// Problem: Group Anagrams. Given an array of strings strs, group the anagrams together. You can return the answer in any order. An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// typically using all the original letters exactly once
// brute force will not work TC = > 
// for each string count and store number of characters in that string
// now all the string which have same number of characters of a particular type have to be put together in an array or vector


int main() {
	int n;
	cin>>n;
	vector<string> strs(n);
	for(int i=0;i<n;i++) {
		cin>>strs[i];
	}

	// take a string store the count of each character in a map
	// for each incoming string count of each character should be same
	for(int i=0;i<n;i++){
		
	}

	// test input
	for(auto x:strs) {
		cout<<x<<endl;
	}
	return 0;
}