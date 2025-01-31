#include <stdio.h>

int sum(int* a, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum;
}

int main() {
  int t;
  scanf("%i", &t);

  while (t--) {
    int n;
    scanf("%i", &n);

    int steps = 0;
    
    int a[n];
    for (int i = 0; i < n; i++) {
      int num;
      scanf("%i", &num);
      
      if (num == 0) {
        steps++;
        num++;
      }

      a[i] = num;
    }

    if (sum(a, n) == 0) {
      steps++;
    }

    printf("%i\n", steps);

  }

  return 0;
}
