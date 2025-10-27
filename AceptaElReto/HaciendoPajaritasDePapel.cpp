#include <bits/stdc++.h>
using namespace std;

void pajaritas(int ancho, int alto, int &ans) {
  if (ancho < 10 || alto < 10) return;

  ans++; // pajarita inicial

  int maxi = max(ancho, alto);
  int mini = min(ancho, alto);

  int anchoSobrante = maxi - mini;
  int altoSobrante = mini;

  if (anchoSobrante < 10 || altoSobrante < 10) return;

  int maxii = max(anchoSobrante, altoSobrante);
  int minii = min(anchoSobrante, altoSobrante);

  int num = maxii / minii;
  ans += num;
  int maxiiSobrante = maxii - num * minii;

  pajaritas(maxiiSobrante, minii, ans);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  while (cin >> a >> b) {
    if (!a && !b) break;

    int ans = 0;

    pajaritas(a, b, ans);

    cout << ans << "\n";
  }
  return 0;
}
