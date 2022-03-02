// copyright loriecab 2022
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

typedef struct grain {
	int Vi, Ci;
} grain;

void filling(grain* a, int n) {
	for(int i = 0; i < n; i++) {
		a[i] = {1 + rand() % 10, 1 + rand() % 10};
	}
}

void bubbleSort(grain* a, int n) {
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[i].Ci > a[j].Ci) {
				num = a[i].Ci;
				a[i].Ci = a[j].Ci;
				a[j].Ci = num;
			}
		}
	}
}

void printGrain(grain* a, int n) {
	for (int i = 0; i < n; i++) {
	 	printf("%d %d\n",a[i].Ci, a[i].Vi);
	}
}

void bucketLoading(grain* a, int n, int V) {
	for (int i = 0; i < n; i++) {
    	if (V - a[i].Vi >= 0) {
    		V -= a[i].Vi;
    		printf("%d %d\n", a[i].Ci, a[i].Vi);
    	} 
	}	
}

void mainProcess(grain* a, int n, int V) {
	bubbleSort(a, n);
	printGrain(a, n);
	printf("\n");
	bucketLoading(a, n, V);
}

void inputV(grain* a, int n) {
	int V;
	char trash;
	if (scanf("%d%c", &V, &trash) == 2 && trash == '\n') {
		mainProcess(a, n, V);
	} else {
		printf("n/a");
	}
}

void inputGrains() {
	int n;
	char trash;
	if (scanf("%d%c", &n, &trash) == 2 && trash == '\n') {
		grain a[n];
		filling(a, n);
		inputV(a, n);
	} else {
		printf("n/a");
	}
}


void Main() {
	srand(time(NULL));
	inputGrains();
}

int main() {
	Main();
	return 0;
}
