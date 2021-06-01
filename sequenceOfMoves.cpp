// Taher Anaya [ 11819939 ]
#include <bits/stdc++.h>

using namespace std;
queue<string> myQ;

void printPath(pair<int, int> A[], int n, pair<int, int> B[], int m) {

    double dis[n][m];
    int i = 0, j = 0;
    double temp;

    while (true) {
        dis[i][j] = sqrt(pow((A[i].second - B[j].second), 2) + pow((A[i].first - B[j].first), 2));
        if (i == n - 1 && j == m - 1)break;

        if (i < n - 1)
            dis[i + 1][j] = sqrt(pow((A[i + 1].second - B[j].second), 2) + pow((A[i + 1].first - B[j].first), 2));
        if (j < m - 1)
            dis[i][j + 1] = sqrt(pow((A[i].second - B[j + 1].second), 2) + pow((A[i].first - B[j + 1].first), 2));
        if (i < n - 1 && j < m - 1)
            dis[i + 1][j + 1] = sqrt(pow((A[i + 1].second - B[j + 1].second), 2) + pow((A[i + 1].first - B[j + 1].first), 2));

        temp = min({dis[i + 1][j], dis[i][j + 1], dis[i + 1][j + 1]});

        if (i < n - 1 && j < m - 1) {
            if (dis[i + 1][j + 1] == temp) {
                i++;
                j++;
                myQ.push("[Both human and robot move]");
            } else if (dis[i + 1][j] == temp) {
                i++;
                myQ.push("[Only human moves]");
            } else {
                j++;
                myQ.push("[Only robot moves]");
            }
        } else if (i < n - 1) {
            i++;
            myQ.push("[Only human moves]");
        } else if (j < m - 1) {
            j++;
            myQ.push("[Only robot moves]");
        }
    }
    cout << "The sequence of movements is: " << endl;
    while (!myQ.empty()) {
        cout << myQ.front();
        if (myQ.size() > 1)
            cout << " Then ";
        myQ.pop();
    }
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

int main() {

    int n;
    cin >> n;
    pair<int, int> A[n];
    readSeq(A, n);

    int m;
    cin >> m;
    pair<int, int> B[m];
    readSeq(B, m);
    //Up To Here, Read Inputs Is Finished//

    printPath(A, n, B, m);

    return 0;
}
