#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST 100

typedef int element;
typedef struct {
	element array[MAX_LIST];
	int size;
}ArrayListtype;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	return;
}
void init(ArrayListtype* L) {
	L->size = 0;
}
int is_empty(ArrayListtype* L) {

	return L->size == 0;
}
int is_full(ArrayListtype* L) {
	
	return L->size == MAX_LIST;
}
element get_entry(ArrayListtype* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("position error");
	return L->array[pos];
}
void print_list(ArrayListtype* L) {
	int i;
	for (i = 0; i < L->size; i++){
		printf("%d->", L->array[i]);
	}

	printf("\n");
	printf("\n");
}

void insert(ArrayListtype* L, int pos, element item) {
	int move = 0;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i];
			move++;
		}
		L->array[pos] = item;
		L->size++;
	}
	printf("\nMove: %d\n\n", move);
}
element delete(ArrayListtype* L, int pos) {
	element item;
	int move = 0;

	if (pos < 0 || pos >= L->size)
		error("position error");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++) {
		L->array[i] = L->array[i + 1];
		move++;
	}
	L->size--;
	printf("Move: %d\n", move);
	printf("Delete: %d\n", item);
	printf("\n");
	return item;
}

int main(void) {
	ArrayListtype list;

	init(&list);
	int answer;
	int num, pos;


	while (1) {
		printf("Menu\n");
		printf("(1) Insert\n");
		printf("(2) Delete\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");
		printf("Enter the menu: ");
		scanf_s("%d", &answer);

		if (answer > 3 || answer < 0) {
			error("Invalid Menu. Please select again..\n");

		}
		else if (answer == 0) {
			printf("Exit the program.\n\n");
			exit(1);
		}
		else
			if (answer == 1) {
				if (is_full(&list)) {
					error("List is full\n");

				}
				else {

					printf("Enter the number and position: ");
					scanf_s("%d %d", &num, &pos);
				
					if (is_empty(&list) && pos != 0) {
						printf("List size is zero. please enter again (number position): ");
						scanf_s("%d %d", &num, &pos);
					}
					insert(&list, pos, num);
				}

			}
			else if (answer == 2) {
				if (is_empty(&list)) {
					error("List is empty\n");

				}
				else {
					printf("Enter the position: ");
					scanf_s("%d", &pos);
					printf("\n");
					delete(&list, pos);
				}

			}
			else if (answer == 3) {
				print_list(&list);
			}

	}
}