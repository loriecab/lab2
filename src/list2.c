// copyright loriecab 2022
#include <stdio.h>
#include <stdlib.h>


typedef struct str {
	int num;
	str* second = NULL;
} str;

str* CreateNode(int n) {
	str* node = (str*)malloc(sizeof(str));
	node-> num = n;
	node-> second = node;
	return node;
}

void push(str* node, int n) {
	str* ptr = (str*)malloc(sizeof(str));
	str* sec = node;
	while(sec->second != node) {
		sec = sec->second;
	}
	sec->second = ptr;
	ptr->num = n;
	ptr->second = node;
}

void out(str* node) {
	printf("elements:");
	str* sec = node;
	while(sec->second != node) {
		printf(" %d", sec->num);
		sec = sec->second;
	}
	printf(" %d\n\n", sec->num);
}

void DeleteList(str* node) {
	str* sec = node;
	str* ptr;
	while(sec->second != node) {
		ptr = sec->second;
		free(sec);
		sec = ptr;
	} 
	free(sec);
}

int main() {
	int n;
	char trash;

	while (1) {
		printf("creating the first node: ");
		if (scanf("%d%c", &n, &trash) == 2 && trash == '\n') {
			str* begin = CreateNode(n);
			system("clear");
			printf("first element: %d\n", begin->num);
			while(1) {
				printf("adding element/elements - 1\noutput elements - 2\ndeleting all elements - 3\n");
				if (scanf("%d%c", &n, &trash) == 2 && trash == '\n') {	
					if (n == 1) {
						system("clear");
						while(1) {
							if (scanf("%d%c", &n, &trash) == 2 && 
								(trash == ' ' || trash == '\n')) {
								push(begin, n);
								if (trash == '\n')
									break;
							} else {
								printf("n/a");
								break;
							}
							if (trash == '\n') {
								break;
							}		
						}
						system("clear");
					} else if (n == 2) {
						system("clear");
						out(begin);
					} else if (n == 3) {
						system("clear");
						DeleteList(begin);
						printf("all items removed\n");
						break;
				 	} else {
						printf("n/a");
						break;
					}
				} else {
					printf("n/a");
				}
			}
		}
		printf("create a list again? any key/n: ");
		if (scanf("%c", &trash) == 1 && trash == 'n') {
			break;
		}
	}
	return 0;
}
