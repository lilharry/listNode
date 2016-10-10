#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {int i;struct node* next;};

void print_list(struct node* list){
	printf("[");
	while(list){
		printf("%d,",list->i);
		list = list->next;
	}
	printf("]\n");
}
struct node* insert_front(struct node* list, int x){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->i = x;
	new->next = list;
	return new;
}

struct node* free_list(struct node* list){
	struct node* og = list;
	struct node* temp;
	while (list){
		temp = list->next;
		free(list);
		list = temp;
	}
	return og;
}

int main(){
	struct node*a = (struct node*)malloc(sizeof(struct node));
	struct node*b = (struct node*)malloc(sizeof(struct node));
	struct node*c = (struct node*)malloc(sizeof(struct node));
	a->i=1;
	b->i=2;
	c->i=3;
	a->next=b;
	b->next=c;
	print_list(a);
	print_list(b);
	print_list(c);
	a = insert_front(a,0);
	print_list(a);
	free_list(a);
	return 0;
}