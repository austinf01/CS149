#include <stdio.h>
#include <math.h>

int main(void) {
    double x;
    double y;
    double z;

        printf("Enter x, y, and z values: \n");
        scanf("%lf", &x);
        scanf("%lf", &y);
        scanf("%lf", &z);
        printf("%0.2f ", pow(x,z));
        printf("%0.2f ", pow(x,pow(y,2)));
        printf("%0.2f ", fabs(y));
        printf("%0.2f ", sqrt(pow(x*y,z)));

    return 0;
}