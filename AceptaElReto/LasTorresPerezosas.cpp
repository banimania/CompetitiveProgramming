#include <stdio.h>
#include <string.h>

#define MAXN 15

static char a[MAXN][MAXN];
static int dp[2][MAXN];

int fast_int() {
  int x = 0, c = getchar_unlocked();
  while (c < '0' || c > '9') c = getchar_unlocked();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar_unlocked();
  }
  return x;
}

int main() {
  setvbuf(stdout, NULL, _IOFBF, 1 << 20);

  int n, i, j, cr, lr;
  while ((n = fast_int()) && n) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        char c = getchar_unlocked();
        while (c != '.' && c != 'X') c = getchar_unlocked();
        a[i][j] = c;
      }
    }

    cr = 1;
    lr = 0;
    dp[cr][0] = 1;
    memset(dp[lr], 0, sizeof(dp[lr]));

    for (i = n - 1; i >= 0; i--) {
      for (j = 0; j < n; j++) {
        if (i == n - 1 && j == 0) continue;
        dp[cr][j] = 0;
        if (a[i][j] == '.') {
          // if (i + 1 < n) dp[cr][j] += dp[lr][j];
          dp[cr][j] = dp[lr][j];
          if (j - 1 >= 0) dp[cr][j] += dp[cr][j - 1];
        }
      }
      cr ^= 1;
      lr ^= 1;
    }

    printf("%d\n", dp[lr][n - 1]);
  }
}
