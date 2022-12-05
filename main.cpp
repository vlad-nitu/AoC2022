
#define NMAX 2002
#include <bits/stdc++.h>
using namespace std;
ifstream f ("day1.in");
ofstream g ("day1.out");
int x;

int main() {

    string s;
    int Max1, Max2, Max3;
    Max1 = Max2=  Max3 = -1;
    int curr = 0;
    while (getline(f, s)){
        if (!s.empty())
            curr += stoi(s);
        else
        {
            if (curr > Max1) {
                Max3 = Max2;
                Max2 = Max1;
                Max1 = curr;
            }
            else if (curr > Max2)
            {
                Max3 = Max2;
                Max2 = curr;
            }
            else if (curr > Max3)
                Max3 = curr;

            curr = 0;
        }


    }

    if (curr != 0) {

        if (curr > Max1) {
            Max3 = Max2;
            Max2 = Max1;
            Max1 = curr;
        }
        else if (curr > Max2)
        {
            Max3 = Max2;
            Max2 = curr;
        }
        else if (curr > Max3)
            Max3 = curr;
    }
    g << Max1 + Max2 + Max3 << '\n';

}
