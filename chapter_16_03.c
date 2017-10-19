#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define PI 4*atan(1)

struct polar{
	double magnitude;
	double angle;
};

struct rect {
	double x;
	double y;
};

struct rect polar_to_rect(struct polar);

int main(void)
{
	struct polar input;
	struct rect result;

	puts("Enter magnitude and angle; enter q to quit:");
	while (scanf("%lf%lf", &input.magnitude, &input.angle) == 2)
	{
		result = polar_to_rect(input);
		printf("x = %.2f, y = %.2f\n", result.x, result.y);
		puts("Next input (q to quit):");
	}
	puts("Bye.");

	return 0;
}

struct rect polar_to_rect(struct polar p)
{
	struct rect r;
	r.x = p.magnitude*cos(p.angle*PI / 180);
	r.y = p.magnitude*sin(p.angle*PI / 180);

	return r;
}