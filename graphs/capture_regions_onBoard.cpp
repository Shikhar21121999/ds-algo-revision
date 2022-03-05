#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define vvc vector<vector<char> >
int X[] = {0, 0, -1, 1};
int Y[] = {-1, 1, 0, 0};

bool isEscaping (pii curr, pii parent, vvc &matr, int &row, int &col) {
    cout << parent.first << " " << parent.second << " " << curr.first << " " << curr.second << endl;

    // try to escape from this coord
    for (int k = 0; k < 4; k++) {
        int nextI = curr.first + X[k];
        int nextJ = curr.second + Y[k];

        // if next is invalid state it means isEscaping
        if (nextI == 0 or nextI == row-1 or nextJ == 0 or nextJ == col-1 and matr[nextI][nextJ] == 'O') {
            return true;
        }
        // pre-condition checks
        if (nextI != parent.first and nextJ != parent.second and nextI >= 0 and nextI < row and nextJ >= 0 and nextJ < col and matr[nextI][nextJ] == 'O') {
            // if we can escape we do not make any changes
            if (isEscaping({nextI, nextJ}, curr, matr, row, col)) {
                return true;
            }
        }
    }
    matr[curr.first][curr.second] = 'X';
    return false;
}


void solve(vector<vector<char> > &matr) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int row = matr.size();
    int col = matr[0].size();

    if (row < 3 or col < 3) {
        return;
    }

    for (int i = 1; i < row-1; i++) {
        for (int j = 1; j < col-1; j++) {
            if (matr[i][j] == 'O') {
                isEscaping({i, j}, {-1, -1}, matr, row, col);
            }
        }
    }
    return;

}

void printMatr (vvc matr) {
    for (auto word: matr) {
        for (auto ch: word) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main () {
    vector < string > inp = {
        "XOXXXXOOXX", "XOOOOXOOXX", "OXXOOXXXOO", "OXOXOOOXXO", "OXOOXXOOXX", "OXXXOXXOXO", "OOXXXXOXOO"
    };
    
    vvc matr;
    for (auto word : inp) {
        vector < char> temp;
        for (auto ch: word) {
            temp.push_back(ch);
        }
        matr.push_back(temp);
    }
    // printMatr(matr);
    solve(matr);

    // print matr
    printMatr(matr);
}