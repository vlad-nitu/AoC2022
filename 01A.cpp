//
// Created by Vlad Nitu on 01.12.2022.
//
#pragma once
#define NMAX 2002
#include <bits/stdc++.h>
using namespace std;
ifstream f ("01A.in");
ofstream g ("01A.out");

int x;

int main() {
    string s;
    int Max = -1;
    int curr = 0;
    while (getline(f, s)) {
        if (!s.empty())
            curr += stoi(s);
        else {
            Max = max(Max, curr);
            curr = 0;
        }
    }

    if (curr != 0)
        Max = max(Max, curr);

    g << Max << '\n';
}