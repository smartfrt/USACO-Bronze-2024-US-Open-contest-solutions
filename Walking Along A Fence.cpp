#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, p;
    cin >> n >> p;

    vector<pair<int,int>> posts(p);
    for (int i = 0; i < p; i++) {
        cin >> posts[i].first >> posts[i].second;
    }

    static int label[1001][1001];
    for (int x = 0; x <= 1000; x++)
        for (int y = 0; y <= 1000; y++)
            label[x][y] = -1;

    int perimeter = 0;

    auto walkSegment = [&](pair<int,int> start, pair<int,int> end) {
        bool sameX = (start.first == end.first);
        bool sameY = (start.second == end.second);
        
        int dx = end.first - start.first;
        int dy = end.second - start.second;
        int dist = abs(dx) + abs(dy);     

        int stepX = (dist == 0 ? 0 : dx / dist);
        int stepY = (dist == 0 ? 0 : dy / dist);

        for (int i = 0; i < dist; i++) {
            int x = start.first;
            int y = start.second;

            label[x][y] = perimeter;
            perimeter++;

            start.first += stepX;
            start.second += stepY;
        }
    };

    for (int i = 0; i < p; i++) {
        pair<int,int> a = posts[i];
        pair<int,int> b = posts[(i + 1) % p];
        walkSegment(a, b);
    }

    for (int q = 0; q < n; q++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int p1 = label[x1][y1];
        int p2 = label[x2][y2];

        int clockwise = abs(p2 - p1);
        int counterClockwise = perimeter - clockwise;

        cout << min(clockwise, counterClockwise) << endl;
    }

    return 0;
}
