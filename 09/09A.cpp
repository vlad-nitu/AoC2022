#pragma once
#define NMAX 1001
#include <bits/stdc++.h>

using namespace std;
ifstream f("09A.in");
ofstream g("09A.out");

struct hash_pair {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }

};

unordered_set<pair<int, int>, hash_pair> vis;
string pos, aux;
unordered_map<string, pair<int, int>> dirs;
int n;
int main()
{

    dirs["L"] = {-1, 0};
    dirs["R"] = {1, 0};
    dirs["U"] = {0, 1};
    dirs["D"] = {0, -1};

    vector<pair<int, int>> pairs;
    for (int i = 0; i < 2; ++i)
        pairs.push_back({0,0});

    vis.insert({0, 0});

    while (f >> pos >> aux) {
        n = stoi(aux);
        for (int k = 0; k < n; ++k) {

            int dx = dirs[pos].first;
            int dy = dirs[pos].second;
            pairs[0] = {pairs[0].first + dx, pairs[0].second + dy};

            for (int i = 0; i < 2; ++i) {
                pair<int, int> head = pairs[i];
                pair<int, int> tail = pairs[i + 1];

                if (abs(head.first - tail.first) > 1) {
                    tail.first += (head.first - tail.first) / 2;
                    if (head.second != tail.second)
                        tail.second = head.second;
                }

                if (abs(head.second - tail.second) > 1) {
                    tail.second += (head.second - tail.second) / 2;
                    if (head.first != tail.first)
                        tail.first = head.first;
                }

                pairs[i + 1] = tail;
            }

            vis.insert(pairs[1]);
        }



    }

    g << vis.size() << '\n';
    return 0;
}