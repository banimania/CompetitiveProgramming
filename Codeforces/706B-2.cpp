#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	vector<int> xi(n);
	int max = 0;
	int min = 0;
	for(int i = 0;i<n;i++){
		int x;
		cin >> x;
		xi[i] = x;
		if(i == 0){
			max = x;
			min = x;		
		}
		if(max < x){
			max = x;
		}
		if(min > x){
			min = x;
		}
	}
	sort(xi.begin(), xi.end());

  int q;
  cin >> q;
  for (int h = 0; h < q; h++) {
    int m;
    cin >> m;

    if (xi[n - 1] <= m) {
      cout << n << endl;
      continue;
    }

    int bajo = 0;
    int alto = n - 1;
    int mitad;
    while (alto > bajo) {
      mitad = bajo + (alto - bajo) / 2;
      if (xi[mitad] > m) {
        alto = mitad;
      } else {
        bajo = mitad + 1;
      }
    }

    cout << bajo << endl;
  }
}
 
 
 
int main(){
	solve();
	return 0;
}
