//
// Created by Vlad Nitu on 01.12.2022.
//
#pragma once
#define NMAX 2002
#include <bits/stdc++.h>
using namespace std;
ifstream f ("03B.in");
ofstream g ("03B.out");

int ans = 0;
string x, y, z;

int main() {

    unordered_map<char, int> priority;
    int k = 1;
    for (char ch = 'a'; ch <= 'z'; ++ch)
        priority[ch] = k++;
    for (char ch = 'A'; ch <= 'Z'; ++ch)
        priority[ch] = k++;

    while (f >> x >> y >> z) {
        vector<char> v1, v2, v3, intersect, aux;
        v1 = vector<char>(x.begin(), x.end());
        v2 = vector<char>(y.begin(), y.end());
        v3 = vector<char>(z.begin(), z.end());

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sort(v3.begin(), v3.end());

        std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(aux));
        std::set_intersection(v3.begin(), v3.end(), aux.begin(), aux.end(), back_inserter(intersect));
        ans += priority[intersect[0]];
    }
    g << ans << '\n';
    return 0;
}