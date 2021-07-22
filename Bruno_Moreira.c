#include <stdio.h>
#include <stdlib.h>

void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);

int main (void) {
  int i;
  int v[8] = { 1, 8, 1, 3, 3, 8, 9, 5 };

  mergesort(v, 8);

  printf("\nBarraca [1] vendeu [%d]\n", v[0]);
  printf("Barraca [2] vendeu [%d]\n", v[1]);
  printf("Barraca [3] vendeu [%d]\n", v[2]);
  printf("Barraca [4] vendeu [%d]\n", v[3]);
  printf("Barraca [5] vendeu [%d]\n", v[4]);
  printf("Barraca [6] vendeu [%d]\n", v[5]);
  printf("Barraca [7] vendeu [%d]\n", v[6]);
  printf("Barraca [8] Vendeu [%d]\n", v[7]);

  putchar('\n');

  return 0;
}

void mergesort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}

void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}


void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {

    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}