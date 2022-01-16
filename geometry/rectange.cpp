#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
#define int long long
const int M = 1e9 + 7;
const int INF = 1e18 + 5;

class Point {
public:
    int x, y;
    Point() {}

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void print(){
        cout << "[" << this->x << "," << this->y << "]";
    }

    static Point read() {
        int x, y;
        cin >> x >> y;
        return Point(x, y);
    }
};

class Rect {
public:
    Point one, two;
    Rect(Point one, Point two) {
       this->one = one;
       this->two = two;
    }

    void print() {
        one.print();
        cout << " ";
        two.print();
        cout << "\n";
    }

    static Rect read() {
        Point one = Point::read();
        Point two = Point::read();

        Rect rect(one, two);
        return rect;
    }
};

bool is_covered(Rect white, Rect black) {
    return white.one.x >= black.one.x
        && white.one.y >= black.one.y
        && white.two.x <= black.two.x
        && white.two.y <= black.two.y;
}

vector<Rect> split(Rect white, Rect black){
    vector<Rect> a;

    if(white.two.y > black.two.y) {
        Rect rect(Point(white.one.x, black.two.y),
                         Point(white.two.x, white.two.y));
        a.push_back(rect);
    }

    if(white.one.y < black.one.y) {
        Rect rect(Point(white.one.x, white.one.y),
                  Point(white.two.x, black.one.y));
        a.push_back(rect);
    }

    if(white.two.x > black.two.x) {
        Rect rect(Point(black.two.x, white.one.y),
                  Point(white.two.x, white.two.y));
        a.push_back(rect);
    }

    if(white.one.x < black.one.x) {
        Rect rect(Point(white.one.x, white.one.y),
                  Point(black.one.x, white.two.y));
        a.push_back(rect);
    }

    return a;
}

void solve(){
    Rect white = Rect::read();
    Rect black1 = Rect::read();
    Rect black2 = Rect::read();

//    white.print();
//    black1.print();
//    black2.print();

    if(is_covered(white, black1) || is_covered(white, black2)){
        cout << "NO\n";
        return;
    }

    vector<Rect> whites = split(white, black1);

    bool white_visible = false;

//    cout << "\nafter split:\n";
    for(Rect w : whites){
//        w.print();
        if(!is_covered(w, black2)){
            white_visible = true;
        }
    }

    if(white_visible){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


}

signed main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}