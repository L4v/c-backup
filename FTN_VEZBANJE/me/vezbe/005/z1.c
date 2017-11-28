//z1.c NIZ TACAKA U RAVNI
#include <stdio.h>
#include <math.h>
#define MAX 30

typedef struct{
	int x, y;
} point2d;

typedef struct{
	int x, y, z;
} point3d;

void defpts2d(point2d pts[], int * n){
	int i;
	puts("Uneti tacke:");
	for (i = 0; i < *n; i ++)
		scanf("%i%i", &(pts[i].x), &(pts[i].y));
}

void closest2d(point2d pts[], int * n){
	int i;
	point2d min = pts[0];
	for(i = 0; i < *n; i ++){
		if(sqrt(pow(min.x, 2) + pow(min.y, 2)) > sqrt(pow(pts[i].x, 2) + pow(pts[i].y, 2)))
			min = pts[i];
	}
	printf("Najbliza je (%i, %i)\n", min.x, min.y);
}

void defpts3d(point3d pts[], int * n){
	int i;
	puts("Uneti tacke:");
	for(i = 0; i < *n; i ++)
		scanf("%i%i%i", &(pts[i].x), &(pts[i].y), &(pts[i].z));
}

void closest3d(point3d pts[], int * n){
	int i;
	point3d min = pts[0];
	for( i = 0; i < *n; i ++)
		if(sqrt(pow(min.x, 2) + pow(min.y, 2) + pow(min.z, 2)) > sqrt(pow(pts[i].x, 2) + pow(pts[i].y, 2) + pow(pts[i].z, 2)))
			min = pts[i];
	printf("Najbliza je (%i, %i, %i)\n", min.x, min.y, min.z);
}

void farthest3d(point3d pts[], int * n){
	int i;
	point3d max = pts[0];
	for( i = 0; i < *n; i ++)
		if(sqrt(pow(max.x, 2) + pow(max.y, 2) + pow(max.z, 2)) < sqrt(pow(pts[i].x, 2) + pow(pts[i].y, 2) + pow(pts[i].z, 2)))
			max = pts[i];
	printf("Najudaljenija je (%i, %i, %i)\n", max.x, max.y, max.z);
}

int main(void){
	int n;
	do{
		puts("Uneti broj tacaka:");
		scanf("%i", &n);
	}while(n <= 0 || n > MAX);
	
	point2d pts2d[n];
	point3d pts3d[n];	
	defpts3d(pts3d, &n);
	farthest3d(pts3d, &n);
	
	return 0;
}
