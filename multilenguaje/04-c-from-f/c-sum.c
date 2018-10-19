#include <stdlib.h>
#include "c-sum.h"

int sum_abs_(int *in, int num) {
   int i,sum;

   for (i=0,sum=0; i < num; ++i) {
       sum += abs(in[i]);
   }
   return sum;
}
 
