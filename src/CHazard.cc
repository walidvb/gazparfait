#include "CHazard.h"


/*inline double CHazard::unif(double a, double b) {
    return a + (rand() / double(RAND_MAX)) * (b - a);
}*/

double CHazard::gauss(double moyenne, double ecart_type) {	
  double v1;
  double v2;
  double s ;

  do {
    v1 = unif(-1.0, 1.0);
    v2 = unif(-1.0, 1.0);
    s = v1*v1 + v2*v2;
  } while ((s >= 1.0) or (s == 0.0));

  double x(sqrt(-2.0 * log(s) / s));
  if (unif(0.0, 1.0) > 0.5)
    x *= v1;
  else
    x *= v2;

  return moyenne + ecart_type * x;
}
