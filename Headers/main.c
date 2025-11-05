#include <stdio.h>
#include "rad2volume.h"

int main() {
    double radius = 3.0, volume;
    volume = radius2Volume(radius);
    printf("%f %f", MY_PI, volume);

    return 0;
}
