//
// Created by Vlad Nitu on 01.12.2022.
//
#pragma once
#define NMAX 2002
#include <bits/stdc++.h>
using namespace std;
ifstream f ("03A.in");
ofstream g ("03A.out");

int x, ans = 0;
string s;

int main() {

    unordered_map<char, int> priority;
    int k = 1;
    for (char ch = 'a'; ch <= 'z'; ++ch)
        priority[ch] = k++;
    for (char ch = 'A'; ch <= 'Z'; ++ch)
        priority[ch] = k++;

    while (f >> s) {
        int N = s.size();
        vector<char> v1, v2, intersect;
        v1 = vector<char>(s.begin(), s.begin() + N / 2);
        v2 = vector<char>(s.begin() + N / 2, s.end());

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(intersect));
        ans += priority[intersect[0]];
    }
    g << ans << '\n';
    return 0;
}