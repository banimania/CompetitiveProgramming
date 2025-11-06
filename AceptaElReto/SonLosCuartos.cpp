#include <stdio.h>

int main() {
  short t;
  scanf("%hd", &t);
  getchar();

  while (t--) {
    unsigned short len = 0;

    while (getchar() != '\n') len++;
    if (len < 71) {
      if (len == 0) {
        printf("MARISA NARANJO\n");
      } else {
        printf("TARDE\n");
      }
    } else if (len > 71) {
      printf("SALIDA NULA\n");
    } else {
      printf("CORRECTO\n");
    }
  }
  return 0;
}
