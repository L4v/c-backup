#include <stdio.h>
#include <math.h>
#define MAX 20

struct point{
	int x;
	int y;
};

int dist(int * x, int * y){
	return sqrt(pow(*x, 2) + pow(*y, 2));
}

void defPoints(struct point points[], int * n){
	int i = 0;
	puts("Uneti tacke:");
	for (i = 0; i < *n; i ++)
		scanf("%i%i", &(points[i].x), &(points[i].y));
}

void prntPoints(struct point points[], int * n){
	int i;
	puts("Points:");
	for(i = 0; i < *n; i ++)
		printf("(%i, %i) ", points[i].x, points[i].y);
	puts("");
}

void findClosest(struct point points[], int * n, struct point * zPoint){
	int i;
	int min = dist(&(points[0].x), &(points[0].y));
	*zPoint = points[0];
	for(i = 0; i < *n; i ++)
		if( min > dist(&(points[i].x), &(points[i].y))){
			min = dist(&(points[i].x), &(points[i].y));
			*zPoint = points[i];
			}
	printf("Closest: (%i, %i)\n", zPoint->x, zPoint->y);
}

int main(void){
	int n, i;
	struct point zPoint;
	do{
		puts("Uneti broj tacaka:");
		scanf("%i", &n);
	}while(n <= 0 || n > MAX);
	struct point points[n];
	
	defPoints(points, &n);
	prntPoints(points, &n);
	findClosest(points, &n, &zPoint);
	
	return 0;
}
