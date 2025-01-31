#include <cstdlib>
#include <iostream>

typedef long long int ll;

int main() {
  int tt;
  std::cin >> tt;

  for (int t = 0; t < tt; t++) {
    int x, y, k;
    std::cin >> x >> y >> k;

    /*int ax = 0;
    int ay = y -1;
    int bx = x;
    int by = 0;

    int cx = 0;
    int cy = 1;
    int dx = x;
    int dy = y;*/

    int ax = 0;
    int ay = 0;
    int bx = 0;
    int by = 0;

    int cx = 0;
    int cy = 0;
    int dx = 0;
    int dy = 0;

    /*if (x >= k && y >= k) {
      by = k;
      dx = k;
    } else if (x >= k && k > y) {
      by = y;
      bx = x - (x % 2 == 0 ? 1 : 0);
      cy = y;
      dx = x - (x % 2 == 0 ? 1 : 0);
    } else if (k > x && y >= k){
      bx = x;
      by = y - (y % 2 == 0 ? 1 : 0);
      cx = x;
      dy = y - (y % 2 == 0 ? 1 : 0);
    }*/

    /*if (x >= k && y >= k) {
      bx = k;
      dy = k;
    } else if (k > x) {
      int xd = std::min(x, y);
      bx = xd;
      by = xd;
      cy = y;
      dx = x;
      dy = y - by;
    } else if (k > y) {
      int xd = std::min(x, y);
      bx = xd;
      by = xd;
      cx = x;
      dy = y;
      dx = x - bx;
    }*/

    if (x >= k && y >= k) {
      bx = k;
      dy = k;
    } else {
      int xd = std::min(x, y);
      bx = xd;
      by = xd;
      cy = xd;
      dx = xd;
    }
    std::cout << ax << " " << ay << " " << bx << " " << by << std::endl;
    std::cout << cx << " " << cy << " " << dx << " " << dy << std::endl;

  }
}
