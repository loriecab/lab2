// copyright loriecab 2022
#include <stdio.h>
#include <stdlib.h>


typedef struct str{
	int num;
	str* second = NULL;
}str;


str* CreateNode(int n) {
	str* node = (str*)malloc(sizeof(str));

	node-> num = n;
	node-> second = NULL;

	return node;
}

void push(str* node, int n) {
	str* ptr = (str*)malloc(sizeof(str));
	str* sec = node;
	while(1) {
		if (sec->second == NULL) {
			break;
		}
		sec = sec->second;
	}

	sec->second = ptr;
	ptr->num = n;
	ptr->second = NULL;
}

void out(str* node) {
	while(1) {
		if (sec->second == NULL) {
			break;
		}
		sec = sec->second;
	}
}

int main() {

	int n;
	char trash;
	

	
	//printf("%d", begin->num);



	if (scanf("%d%c", &n, &trash) == 2 && trash == '\n') {
		str* begin = CreateNode(n);
		while(scanf("%d%c", &n, &trash) == 2 && trash == '\n') {
			if (n == 1) {
				if (scanf("%d%c", &n, &trash) == 2 && trash == '\n') {
					//printf("%d", begin->num);
					push(begin, n);
				} else {
					printf("n/a");
				}
			}
		}


	} else {
		printf("n/a");
	}
	




	return 0;
}
