// Taher Anaya [ 11819939 ]
// Dynamic Programming Code

#include <bits/stdc++.h>

using namespace std;

pair<int, int> *A;
pair<int, int> *B;

double dis(int i, int j) {
    return sqrt(pow((A[i].second - B[j].second), 2) + pow((A[i].first - B[j].first), 2));
}

double dynamicFun(int n, int m) {

    double myF[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0)
                myF[i][j] = dis(i, j);
            else if (i == 0)
                myF[i][j] = max(dis(i, j), myF[i][j - 1]);
            else if (j == 0)
                myF[i][j] = max(dis(i, j), myF[i - 1][j]);
            else
                myF[i][j] = max(dis(i, j), min({myF[i - 1][j], myF[i][j - 1], myF[i - 1][j - 1]}));
        }
    }
    return myF[n - 1][m - 1];

}


// Two functions To Read Inputs
void readSeq(pair<int, int> myP[], int n) {

    int counter = 0;
    int arr[2 * n];
    string str;
    cin >> str;

    arr[0] = 0;
    int sign = 0;
    for (char i : str) {
        if (i == '-') {
            sign = 1;
        } else if (i != ',') {
            arr[counter] = arr[counter] * 10 + (int) i - 48;
        } else {
            arr[counter] *= (int) pow(-1, sign);
            sign = 0;
            arr[++counter] = 0;
        }
    }
    if (sign)
        arr[counter] *= (int) pow(-1, sign);

    counter = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        myP[counter].first = arr[i];
        myP[counter++].second = arr[i + 1];
    }

}

void readLen(int myArr[]) {

    int counter = 0;
    string str;
    cin >> str;

    myArr[0] = 0;
    for (char i : str)
        i != ',' ? myArr[counter] = myArr[counter] * 10 + (int) i - 48 : myArr[++counter] = 0;

}

int main() {

    int n;
    cin >> n;
    A = new pair<int, int>[n];
    readSeq(A, n);

    int m;
    cin >> m;
    B = new pair<int, int>[m];
    readSeq(B, m);

    int l;
    cin >> l;
    int L[l];
    readLen(L);

    //Up To Here, Read Inputs Is Finished//

    int res = ceil(dynamicFun(n - 1, m - 1));

    sort(L, L + l);

    for (int i = 0; i < l; ++i) {
        if (L[i] >= res) {
            cout << L[i];
            break;
        }
    }

    return 0;
}
