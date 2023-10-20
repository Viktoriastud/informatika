#include <stdio.h>
#include <math.h>

float function_U (float x, float z, float y) {

  float U = (1 / (tan (pow (x, y) + 3 * pow (z, 2)))) - log (fabs ((pow (x, 3) - y) / z));
  return U;
}

int main () {
    float x_min = 1;
    float z_min = 1;
    float y_min = 0.1;
    float U_min = function_U (x_min, z_min, y_min);
        for (float x = 1; x <= 2; x++) {
            for (float z = 1; z <= 3; z += 2) {
	            for (float y = 0.1; y <= 0.7; y += 0.7) {
	                if (function_U (x, z, y) < U_min) {
		  U_min = function_U (x, z, y);
		  x_min = x;
		  z_min = z;
		  y_min = y;
	                }
	      printf ("x=%f z=%f y=%f U=%f\n", x, z, y, function_U (x, z, y));
	          }
	     }
        }
  printf ("x_min=%f z_min=%f y_min=%f U_min=%f\n", x_min, z_min, y_min, U_min);
  return 0;
}
