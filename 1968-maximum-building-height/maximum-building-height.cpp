struct Point {
    int x, y;
    Point() {x = y = 0;}
    Point(const int & _x, const int & _y) {
        x = _x, y = _y;
    }

    bool operator<(const Point & p) {
        return x == p.x?y <= p.y:x<p.x;
    }
};

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<Point> pts;
        for (auto & r: restrictions) {
            pts.push_back({r[0], r[1]});
        }
        pts.push_back({1, 0});
        ::sort(begin(pts), end(pts));
        if (pts.back().x != n) {
            pts.push_back({n, 1000000000});
        }
        
        int sz = pts.size();
        for (int i = 0; i < sz-1; ++i) {
            int xdiff = pts[i+1].x - pts[i].x;
            if (pts[i+1].y > pts[i].y + xdiff) {
                pts[i+1].y = pts[i].y + xdiff;
            }
        }
        for (int i = sz-2; i>= 0; --i) {
            int xdiff = pts[i+1].x - pts[i].x;
            if (pts[i].y > pts[i+1].y + xdiff) {
                pts[i].y = pts[i+1].y + xdiff;
            }
        }
        int h = 0;
        for (int i = 0; i < sz-1; ++i) {
            h = max(h, max(pts[i].y, pts[i+1].y));
            int x1 = pts[i].x, x2 = pts[i+1].x;
            int y1 = pts[i].y, y2 = pts[i+1].y;
            int twox = x1+x2+y2-y1;
            if (twox >= 2*x1 && twox <= 2*x2) {
                int mid = twox/2;
                int newy = y1 + mid - x1;
                h = max(newy, h);
            }
        }
        return h;
    }
};