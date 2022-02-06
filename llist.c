#include "llist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ih[] = "ih";
char it[] = "it";
char dh[] = "dh";
char f[] = "f";
char p[] = "p";

int main(int argc, char const *argv[])
{
	struct node *head = NULL;
	for (int i = 1; i < argc; ++i)
	{
			// ih command
		if (strcmp(argv[i], ih) == 0){
			if (i == argc - 1 || strcmp(argv[i+1], p) == 0){
				printf("No node given to insert after ih command\n");
			}
			else{
				int x = atoi(argv[i+1]);
				struct node *n = node_alloc(x);
				llist_insert_head(&head, n);
			}
		}
			// it command
		if (strcmp(argv[i], it) == 0){
			if (i == argc - 1 || strcmp(argv[i+1], p) == 0){
				printf("No node given to insert after it command\n");
			}
			else{
				int x = atoi(argv[i+1]);
				struct node *n = node_alloc(x);
				llist_insert_tail(&head, n);
			}
		}
			// p command
		if (strcmp(argv[i], p) == 0){
			if(head != NULL){
				llist_print(head);
				printf("\n");
			}
			else{
				printf("[empty]\n");
			}
		}
			// dh command
		if (strcmp(argv[i], dh) == 0){
			llist_delete_head(&head);
		}
			// f command
		if (strcmp(argv[i], f) == 0){
			llist_free(&head);
		}
	}

}

struct node *node_alloc(int value){
	struct node *new_node = malloc(sizeof(struct node));
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}
void node_free(struct node *n){
	free(n); 
}
void llist_free(struct node **head){
	struct node *current = *head;
	struct node *next;
	while(current != NULL){
		next = current->next;
		node_free(current);
		current = next;
	}
	*head = NULL;
}
void llist_print(struct node *head){
	while(head->next != NULL){
		printf("%d -> ", head->value);
		head = head->next;
	}
	printf("%d", head->value);
}
void llist_insert_head(struct node **head, struct node *n){
	struct node *new_node = malloc(sizeof(struct node));
	new_node = n;
	new_node->next = *head;
	*head = new_node;
}
struct node *llist_delete_head(struct node **head){
	if(*head != NULL){
		struct node *to_delete = *head;
		*head = (*head)->next;
		printf("value deleted = %d\n", to_delete->value);
		return to_delete;
	}
	else{
		return NULL;
	}
}
void llist_insert_tail(struct node **head, struct node *n){
	struct node *new_node = malloc(sizeof(struct node));
	new_node = n;
	if(*head == NULL){
		*head = new_node;
	}
	else{
		struct node *last_node = *head;
		while(last_node->next != NULL){
			last_node = last_node->next;
		}
		last_node->next = new_node;
	}

}
