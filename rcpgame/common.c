/* Name:    common.c
 * Version: v1.0
 * Content: common functions
 */
#include <time.h>
#include "common.h"

int genRand(void){
  srand(time(NULL));
  return (rand() % 100 + 1);
}
/* EOF */

