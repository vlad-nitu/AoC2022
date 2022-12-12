#define NMAX 1001
#define ll long long

#include <bits/stdc++.h>

using namespace std;
ifstream f("012A.in");
ofstream g("012A.out");

struct monk {
    vector<int> holds;
    string op;
    int test;
    int true_to;
    int false_to;

};

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

ll ans = 0;
int x, y, xf, yf, N, M;
char c;
int a[42][78];
bool viz[42][78];
const vector<int> dx{-1,1,0,0};
const vector<int> dy{0,0,-1,1};


bool valid (int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M && !viz[x][y]);
}

int BFS (int x, int y) {
    viz[x][y] = true;
    std::queue<pair<int, int> > Q;
    Q.push({x, y});

    while (!Q.empty()) {
          int sz = Q.size();
        for (int i = 0; i < sz; ++i) {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();

            if (x == xf && y == yf)
                return ans;

            for (int dir = 0; dir < 4; ++dir) {
                int xx = x + dx[dir];
                int yy = y + dy[dir];
                if (valid(xx, yy) && a[xx][yy] - a[x][y] <= 1)
                {
                    viz[xx][yy] = true;
                    Q.push({xx, yy});
                }

            }
        }
        ans ++;
    }

    return -1;
}

int main() {
    N = 41; M = 77;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            f >> c;
            if (c == 'S')
            {
                a[i][j] = 0;
                x = i; y = j;
            }

            else if (c == 'E')
            {
                a[i][j] = 'z' - 'a';
                xf = i; yf = j;
            }
            else
                a[i][j] = c - 'a';
        }

    g << BFS(x, y);
    return 0;

}