//
// Created by Vlad Nitu on 03.12.2022.
//
#pragma once
#define NMAX 2002
#include <bits/stdc++.h>
using namespace std;
ifstream f ("04B.in");
ofstream g ("04B.out");

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }

};

int x;
string s;
int main() {
    int ans = 0;

    while (f >> s) {
        stringstream ss(s);
        string word;
        vector<pair<int, int>> v;
        while (!ss.eof()){
            getline(ss, word, ',');

            stringstream split(word);
            string start, end;
            getline(split, start, '-');
            getline(split, end, '-');

            int s = stoi(start);
            int e = stoi(end);

            v.push_back({s,e});
        }

        if ((v[0].first <= v[1].second && v[0].first >= v[1].first)
            ||
            (v[1].first <= v[0].second && v[1].first >= v[0].first))
            ans ++;
    }

    g << ans << '\n';
    return 0;
}