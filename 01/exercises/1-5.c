#include <stdio.h>

int main() {
  float celsius;                             
  for (int i = 300; i >= 0; i -= 20) {
     celsius = (5.0/9.0) * (i-32.0);
     printf("%3d %6.1f\n", i, celsius);      
  }
}                                                       

