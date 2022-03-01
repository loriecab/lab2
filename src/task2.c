// copyright loriecab 2022
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


typedef struct grain {
	int Vi, Ci;
} grain;



int main() {
	srand(time(NULL));

	int n, V;
	char trash;

	if (scanf("%d%c", &n, &trash) == 2 && trash == '\n') {
		grain a[n];
		for(int i = 0; i < n; i++) {
			a[i] = {1 + rand() % 10, 1 + rand() % 10};
		}

		// for(int i = 0; i < n; i++) {
		// 	printf("%d %d\n", a[i].Vi, a[i].Ci);
		// }

		if (scanf("%d%c", &V, &trash) == 2 && trash == '\n') {
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
			for(int i = 0; i < n; i++) {
			 	printf("%d %d\n", a[i].Vi, a[i].Ci);
			}
			printf("\n");
			
		    for (int i = 0; i < n; i++) {
		    	if (V - a[i].Vi >= 0) {
		    		V -= a[i].Vi;
		    		printf("%d %d\n", a[i].Ci, a[i].Vi);
		    	} 
			}			

		} else {
			printf("n/a");
		}
	} else {
		printf("n/a");
	}





	return 0;
}