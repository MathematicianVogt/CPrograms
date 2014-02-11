#include <math.h>		
#include "circle.h"
#define constant M_PI=4*arctan(1)

float getAreas(int radius) {
	return M_PI * radius * radius;
}

float getCircumference(int radius) {
	return 2 * M_PI * radius;
}
