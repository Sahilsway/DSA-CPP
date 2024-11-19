#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    bool firstRowZero = false, firstColZero = false;

    for (int i = 0; i < m; i++) {
        if (mat[i][0] == 0) firstColZero = true;
    }

    for (int j = 0; j < n; j++) {
        if (mat[0][j] == 0) firstRowZero = true;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            mat[i][0] = 0;
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            mat[0][j] = 0;
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    setZeroes(mat);

    // Print the updated mat
    for (const auto &row : mat) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
