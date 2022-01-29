#include <bits/stdc++.h>
using namespace std;

/*
For straight normal array
*/
vector <int> NSE(vector <int> a) {
    int n = a.size();
    vector <int> ans(n, -1);
    stack <int> st;

    for (int i = n - 1; i >= 0; i --) {
        while(!st.empty() and st.top() >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(a[i]);
    }
    return ans;
}

int main () {
    vector <int> a = {3, 4, 7, 1, 2, 4, 5};
    for (auto x: NSE(a)) {
        cout << x << " ";
    }
    cout << " \n";
}