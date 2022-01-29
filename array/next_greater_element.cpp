#include <bits/stdc++.h>
using namespace std;

/*
variant 1
next greater element for an element in the array
is the first next element that occurs on right of the array
if not found return -1
*/

/*
variant 2
next greater element for an element in the array
is the first next element that occurs on right of the array
here we consier the array as circular, so if we cant find on right
we start once again from left till we reach the element
if not found for greatest element return -1 
*/

/*
Approach is to think solution for variant 1 and then
apply circular array logic that is applying modulo to get relevant index
to get solution for variant 2
doing only optimized solution here
*/

vector <int> NGE(vector <int> a) {
    vector <int> ans(a.size(), -1);
    stack <int> st;
    int n = a.size();
    for (int i = 2*n-1; i >= 0; i--) {
        while(!st.empty() or st.top() <= a[i%n]) {
            st.pop();
        }

        if (i < n) {
            if (!st.empty()) {
                ans[i] = st.top();
            }
        }
        st.push(ans[i]);
    }
    return ans;
}

int main () {

}