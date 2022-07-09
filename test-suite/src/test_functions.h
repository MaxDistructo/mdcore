#pragma once
#include <cstdio>
#include <cstring>

bool compareFile(FILE* f1, FILE* f2)
{
  int N = 10000;
  char buf1[N];
  char buf2[N];

  do {
    size_t r1 = fread(buf1, 1, N, f1);
    size_t r2 = fread(buf2, 1, N, f2);

    if (r1 != r2 ||
        memcmp(buf1, buf2, r1)) {
      return 0;  // Files are not equal
    }
  } while (!feof(f1) && !feof(f2));

  return feof(f1) && feof(f2);
}