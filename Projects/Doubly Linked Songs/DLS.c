#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_MAX 256

typedef struct Element_s {
	char name[NAME_MAX];
	long duration;
	struct Element_s *next;
	struct Element_s *prev;
} Element_t;

void read_in(Element_t *item) {
	char *newline;
	(void) printf("Name: ");
	fgets(item->name, NAME_MAX, stdin);
	if((newline = strchr(item->name, '\n')) != NULL)
		*newline = '\0';
	(void) printf("Dauer: ");
	scanf("%ld", &item->duration);
	(void) getchar();
}

Element_t *allocate(void) {
	Element_t *elem = malloc(sizeof(Element_t));
	if (elem == NULL) {
		(void) fprintf(stderr, "Error: no memory available!\n");
	} else {
		read_in(elem);
		elem->next = elem->prev = NULL;
	}
	return elem;
}

Element_t *find_end(Element_t *list) {
	while (list->next != NULL)
		list = list->next;
	return list;
}

Element_t *push_back(Element_t *list) {
	Element_t *elem = allocate();
	if (elem == NULL) {
		(void) fprintf(stderr, "Error: no memory allocated for push_back!\n");
		return list;
	}
	if (list != NULL) {
		Element_t *end = find_end(list);
		end->next = elem;
		elem->prev = end;
	} else
		list = elem;
	return list;
}

void cleanup_list(Element_t *list) {
	Element_t *next;
	while (list != 0) {
		next = list->next;
		free(list);
		list = next;
	}
}

void print_element(Element_t *elem) {
	(void) printf("Name: %s\nDauer: %ld\n", elem->name, elem->duration);
}

void print_list(Element_t *list) {
	long i = 0;
	while (list != 0) {
		i++;
		(void) printf("%ld. ", i);
		print_element(list);
		list = list->next;
	}
}

void print_list_reverse(Element_t *list) {
#if 1
	long i = 0;
	Element_t *end = find_end(list);
	while (end != NULL) {
		i++;
		(void) printf("%ld. ", i);
		print_element(end);
		end = end->prev;
	}
#else
	if(list != NULL) {
		print_list_reverse(list->next);
		print_element(list);
	}
#endif
}

Element_t *get_element(Element_t *list, long index) {
	long i;
	for(i = 0; list != NULL; list = list->next)
		if (index == i++)
			return list;
	return NULL;
}

long num_elements(Element_t *list) {
	long num;
	for(num = 0; list != NULL; list = list->next)
		num++;
	return num;
}

Element_t *pop_back (Element_t *list) {
	if (list != NULL) {
		Element_t *end = find_end(list);
		if(end != NULL) {
			if(end->prev != NULL)
				end->prev->next = NULL;
			else
				list =  NULL;
			free(end);
		}
	}
	return list;
}

void insert(Element_t *list, long insertAfter) {
	Element_t *elem;
	list = get_element(list, insertAfter);
	if (list != NULL) {
		elem = allocate();
		if (elem == NULL) {
			(void) fprintf(stderr, "Error: no memory allocated for insert!\n");
			return;
		}
		if (list->next != NULL)
			list->next->prev = elem;
		elem->next = list->next;
		elem->prev = list;
		list->next = elem;
	} else
		(void) fprintf(stderr, "Element %ld not found\n", insertAfter);
}

Element_t *push_front(Element_t *list) {
	Element_t *elem = allocate();
	if (elem == 0) {
		(void) fprintf(stderr, "Error: no memory allocated for push_front!\n");
		return list;
	}
	elem->next = list;
	if(list != NULL)
		list->prev = elem;
	return elem;
}

void print_list_random(Element_t *list) {
	if(list != NULL) {
		if(rand() > RAND_MAX / 2) {
			print_list_random(list->next);
			print_element(list);
		} else {
			print_element(list);
			print_list_random(list->next);
		}
	}
}

void bubblesort(Element_t *field[], long num) {
	Element_t *ptr;
	long i, j;
	for(j = num - 1; j > 0; j--) {
		for(i = 0; i < j; i++) {
			if(strcmp(field[i]->name, field[i+1]->name) > 0) {
				ptr = field[i];
				field[i] = field[i+1];
				field[i+1] = ptr;
			}
		}
	}
}

void sort_list(Element_t **list) {
	long i = 0;
	long num = num_elements(*list);
	if(num < 2) {
		(void) printf("List too small!\n");
		return;
	}

	Element_t *list2 = *list;
	Element_t *field[num];

	for(i = 0; i < num; i++) {
		field[i] = list2;
		list2 = list2->next;
	}

	bubblesort(field, num);

	for(i = 0; i < num; i++) {
		field[i]->prev = (i == 0) ? NULL : field[i-1];
		field[i]->next = (i == num-1) ? NULL : field[i+1];
	}

	*list = field[0];
}

Element_t *show_off(Element_t *list) {
	long num;
	list = push_back(list);
	list = push_back(list);
	list = push_back(list);

	(void) printf("\nlisting: \n");
	print_list(list);
	(void) printf("\nreverse listing: \n");
	print_list_reverse(list);

	if((num = num_elements(list)) > 1) {
		(void) printf("\nElementzahl: %ld\n", num);
		(void) printf("\nVorletztes Element:\n");
		print_element(get_element(list, num - 2));
	}

	list = pop_back(list);

	(void) printf("\nPoppend back listing: \n");
	print_list(list);

	(void) putchar('\n');
	insert(list, 0);
	(void) putchar('\n');

	(void) printf("\ninsert listing: \n");
	print_list(list);

	return list;
}

int main() {
	char c;
	Element_t *list = NULL;
	srand(time(NULL));

	do {
		(void) printf("\n0. demo\n");
		(void) printf("1. push front\n");
		(void) printf("2. push back\n");
		(void) printf("3. pop back\n");
		(void) printf("4. print list\n");
		(void) printf("5. print list random\n");
		(void) printf("6. sort list\n");
		(void) printf("9. exit\n\n");

		c = getchar();
		getchar();
		switch(c) {
		case '0':
			list = show_off(list);
			break;
		case '1':
			list = push_front(list);
			break;
		case '2':
			list = push_back(list);
			break;
		case '3':
			list = pop_back(list);
			break;
		case '4':
			print_list(list);
			break;
		case '5':
			print_list_random(list);
			break;
		case '6':
			sort_list(&list);
		default
				:
			break;
		}
	} while(c != '9');

	cleanup_list(list);
	return EXIT_SUCCESS;
}
