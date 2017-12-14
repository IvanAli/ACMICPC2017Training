#include <iostream>
#include <cstring>
#include <queue>
#include <set>
 
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
 
string grid[1000];
bool visited0[1000][1000];
int visited1[1000][1000];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m, v; cin >> n >> m >> v;
    int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1; x0--; y0--; x1--; y1--;
    for (int i = 0; i < n; i++) cin >> grid[i];
 
    queue<piii> q[2];
    set<pii> inserted;
    int i1 = 0;
    q[i1].push(piii(0, pii(x0, y0)));
 
    memset(visited0, 0, sizeof 0);
    memset(visited1, 0, sizeof 0);
    int marker = 0;
    bool success = false;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while (!success) {
        int i2 = (i1+1)%2;
        int cnt = 0;
        marker++;
        while (!q[i1].empty()) {
            piii curr = q[i1].front(); q[i1].pop();
            int t = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            if (visited0[x][y] || visited1[x][y] == marker) continue;
            if (t == 0) visited0[x][y] = true;
            visited1[x][y] = marker;
 
            if (x == x1 && y == y1) {
                success = true;
                break;
            }
 
            if (grid[x][y] == 'F' && inserted.count(curr.second) == 0 && !visited0[x][y]) {
                inserted.insert(curr.second);
                q[i2].push(piii(0, curr.second));
                cnt++;
            }
 
            if (t < v) {
                for (int k = 0; k < 4; k++) {
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        q[i1].push(piii(t+1, pii(nx, ny)));
                    }
                }
            }
        }
        i1 = i2;
        if (cnt == 0) break;
    }
    cout << (success ? "Hello, Deimos!" : "Dire victory") << endl;
}