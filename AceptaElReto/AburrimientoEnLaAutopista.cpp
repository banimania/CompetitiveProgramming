#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  string matrEdu, letrasEdu, numsEdu, matr, letras, nums;
  int antiguos, nuevos;
  cin >> t;
  while (t--) {
    cin >> matrEdu;

    letrasEdu = matrEdu.substr(4, 3);
    numsEdu = matrEdu.substr(0, 4);

    antiguos = 0, nuevos = 0;
    while (cin >> matr) {
      if (matr == "0") {
        break;
      }

      letras = matr.substr(4, 3);

      if (letras < letrasEdu) {
        antiguos++;
      } else if (letras > letrasEdu) {
        nuevos++;
      } else {
        nums = matr.substr(0, 4);
        if (numsEdu > nums) {
          antiguos++;
        } else {
          nuevos++;
        }
      }

    }

    cout << antiguos << ' ' << nuevos << '\n';
  }
  return 0;
}
