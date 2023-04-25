#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <queue>
#include <map>
#include <thread>
#include <list>
#include <bitset>
//#include <bits/stdc++.h>
using namespace std;
///////////////////
#define endl '\n'
#define MAX 9'223'372'036'854'775'807
#define debug(x) cout<<"[" << #x << " is: " << x << "] "<<endl
#define not_less_than(v, n) lower_bound(v.begin(), v.end(), n)                   
#define not_more_than(v, n) lower_bound(v.rbegin(), v.rend(), n, greater<int>()) 
#define more_than(v, n) upper_bound(v.begin(), v.end(), n)                     
#define less_than(v, n) upper_bound(v.rbegin(), v.rend(), n, greater<int>())     
#define sort_pair_second(v) sort(v.begin(), v.end(), [](const auto &a, const auto &b) { return a.second < b.second; });
#define rsort_pair_second(v) sort(v.rbegin(), v.rend(), [](const auto &a, const auto &b) { return a.second < b.second; });

void solve();
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //  #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //  #endif
    long long test_cases = 1;
    //cout << "Test Cases!\n";
    //cin >> test_cases;
    while (test_cases--) solve();
}

int won(vector<vector<char>> v) {
    map<char, int>freq;

    //top
    if (v[0][1] != '.') {
        if (v[0][0] == v[0][1] && v[0][2] == v[0][1]) {
            freq[v[0][1]]++;
            v[0][0] = v[0][1] = v[0][2] = '.';
        }
    }

    //center
    if (v[1][1] != '.') {
        if (v[1][0] == v[1][1] && v[1][2] == v[1][1]) {
            freq[v[1][1]]++;
            v[1][0] = v[1][1] = v[1][2] = '.';
        }

        if (v[0][1] == v[1][1] && v[2][1] == v[1][1]) {
            freq[v[1][1]]++;
            v[0][1] = v[1][1] = v[2][1] = '.';
        }

        //1st diagonal
        else if (v[0][0] == v[1][1] && v[2][2] == v[1][1]) {
            freq[v[1][1]]++;
            v[0][0] = v[1][1] = v[2][2] = '.';
        }

        //2nd diagonal
        else if (v[0][2] == v[1][1] && v[2][0] == v[1][1]) {
            freq[v[1][1]]++;
            v[0][2] = v[1][1] = v[2][0] = '.';
        }
    }

    //bottom
    if (v[2][1] != '.') {
        if (v[2][0] == v[2][1] && v[2][2] == v[2][1]) {
            freq[v[2][1]]++;
            v[2][0] = v[2][1] = v[2][2] = '.';
        }
    }

    //right
    if (v[1][2] != '.') {
        if (v[0][2] == v[1][2] && v[2][2] == v[1][2]) {
            freq[v[1][2]]++;
            v[0][2] = v[1][2] = v[2][2] = '.';
        }
    }

    //left
    if (v[1][0] != '.') {
        if (v[0][0] == v[1][0] && v[2][0] == v[1][0]) {
            freq[v[1][0]]++;
            v[0][0] = v[1][0] = v[2][0] = '.';
        }
    }

    if (freq['X'] && freq['0'] || freq['x'] > 1 || freq['0'] > 1)
        return -1;

    if (freq['X'])
        return 1;

    if (freq['0'])
        return 2;

    return 0;
}

void solve() {
    int x = 0, o = 0;
    vector<vector<char>>v(3, vector<char>(3));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'X')
                x++;

            else if (v[i][j] == '0')
                o++;
        }

    //illegal
    if (o > x || x > o + 1) {
        cout << "illegal\n";
        return;
    }

    //win, draw or 2 illegal wins
    int winner = won(v);

    if (winner == -1)
        cout << "illegal\n";

    else if (winner == 1) {
        if (o == x)
            cout << "illegal\n";
        else
            cout << "the first player won\n";
    }

    else if (winner == 2) {
        if (x > o)
            cout << "illegal\n";
        else
            cout << "the second player won\n";
    }

    else {
        if (x + o == 9)
            cout << "draw\n";

        else if (x == o)
            cout << "first\n";

        else cout << "second\n";
    }
}