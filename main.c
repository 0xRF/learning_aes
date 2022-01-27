#include <stdio.h>
#include "include/rijindael.h"
#include <string.h>
int main ()
{

  uint32_t test = 0xa0a1a2a3;
  uint32_t test2 = 0xa1a2a3a0;
  uint32_t test3 = RotByte (test);
  printf ("%d\n", (uint32_t)test);
  printf ("%d\n", (uint32_t)test2);
  printf ("%d\n", (uint32_t)test3);

  char *payload = "Two One Nine Two";
  char key[16] = {};
  uint8_t* enc = encrypt_rijndael (payload, key, 4, 16, 16);

  return 0;
}
