#include <bits/stdc++.h>
using namespace std;

/*
Previous smaller element for normal or straight array
*/

vector <int> NPE(vector <int> a) {
    int n = a.size();
    vector <int> ans;
    stack <int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() and st.top() >= a[i])
        {
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

}