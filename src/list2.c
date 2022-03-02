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

void DeleteElement(str* node, int n) {
	str* sec = node;
	str* ptr;
	int i = 0;
	int j = 0;
	int res = 1;
	sec = sec->second->second;

	while(sec != node->second) {
		sec = sec->second;
		i++;
	}
	i++;
	while (1) {
		if (n == sec->num) {
			break;
		} else if (j == i) {
			res = 0;
			break;
		}
		ptr = sec;
		sec = sec->second;
		j++;
	}
	if (res) {
		ptr->second = sec->second;
		free(sec);
	}
}

void addElement(str* node, int n) {
	str* sec = node;
	int num, res = 1;
	char trash;
	while (n != sec->num) {
		sec = sec->second;
		if (sec == node) {
			res = 0;
			break;
		}
	}
	if (res) {
		printf("enter the value of the added element: "); 
		if (scanf("%d%c", &num, &trash) == 2 && trash == '\n') {
			str* ptr = (str*)malloc(sizeof(str));
			ptr->second = sec->second;
			sec->second = ptr;
			ptr->num = num;
		}
	} else {
		printf("element not found \n");
	}
}


void printMenu() {
	printf("adding element/elements - 1");
	printf("\noutput elements         - 2");
	printf("\ndeleting all elements   - 3");
	printf("\ndeleting an element     - 4");
	printf("\nadding an element       - 5\n");
}

void choice1(int* res, str* begin) {
	int n;
	char trash;
	system("clear");
	while(1) {
		if (scanf("%d%c", &n, &trash) == 2 && 
			(trash == ' ' || trash == '\n')) {
			push(begin, n);
			if (trash == '\n')
				break;
		} else {
			*res = 0;
			break;
		}
		if (trash == '\n') {
			break;
		}	
	}
	system("clear");
}

void choice2(str* begin) {
	system("clear");
	out(begin);
}

void choice3(str* begin) {
	system("clear");
	DeleteList(begin);
	printf("all items removed\n");
}

void choice4(str* begin, int* res) {
	int n;
	char trash;
	system("clear");
	printf("enter the value of the element to be removed: ");
	if (scanf("%d%c", &n, &trash) == 2 && trash == '\n') {
		DeleteElement(begin, n);
	} else {
		*res = 0;
	}
}

void choice5(str* begin, int* res) {
	int n;
	char trash;
	system("clear");
	printf("enter the value of the element: ");
	if (scanf("%d%c", &n, &trash) == 2 && trash == '\n') {
		addElement(begin, n);
	} else {
		*res = 0;
	}
}

void BeginInput(str* begin, int* res) {
	int n;
	char trash;
	system("clear");
	printf("first element: %d\n", begin->num);
	while(1) {
		printMenu();
		if (scanf("%d%c", &n, &trash) == 2 && trash == '\n') {
			if (n == 1) {
				choice1(&*res,  begin);
			} else if (n == 2) {
				choice2(begin);
			} else if (n == 3) {
				choice3(begin);
				break;
			} else if (n == 4) {
				choice4(begin, &*res);
			} else if (n == 5) {
				choice5(begin, &*res);
		 	} else {
				res = 0;
				break;
			}
		} else {
			*res = 0;
			break;
		}
		if (*res == 0) {
			break;
		}
	}
}

void checkRes(int res) {
	if (res == 0) {
		system("clear");
		printf("n/a");
	}
}

void mainWhile() {
	int n;
	char trash;
	int res = 1;
	while (1) {
		printf("creating the first node: ");
		if (scanf("%d%c", &n, &trash) == 2 && trash == '\n') {
			str* begin = CreateNode(n);
			BeginInput(begin, &res);
		} else {
			res = 0;
			break;
		}
		if (res == 1) {	
			printf("create a list again? any key/n: ");
			if (scanf("%c", &trash) == 1 && trash == 'n') {
				break;
			}
		} else {
			system("clear");
			break;
		}
	}
	checkRes(res);
}


int main() {
	mainWhile();
	return 0;
}
