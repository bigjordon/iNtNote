#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
	struct list * next;
} list;

typedef struct listnode {
	list list;
	int data;
}listnode;

list* listadd(list *head, list *new) {
	if (!head) {
		return head;
	}	
	if (!new) {
		return head;
	}
	new->next = head->next;
	head->next = new;
	return head;
}
list * creatlist(int n)
{
	int i;	
	list * head =  malloc(sizeof(list));
	listnode * node = NULL;
	head->next = NULL;
	if (n == 0)
		return head; 
	for (i=0; i<n; i++) {
		node = malloc(sizeof(listnode));	
		memset(node, 0, sizeof(node));
		node->data = i;
		listadd(head, &(node->list));
	}
	return head;
}
list* reverselist(list * head)
{
	list * p = NULL, *next = NULL, *tmp ,*first;
	if (!head)
		return NULL;
	if(!head->next)
		return head;
	p = head->next; // head->next is the fitst node
	first = p;
	next = p->next;

	while(next) {
		head->next = next;
		tmp = next->next;
		if (first == p){ 
			p->next = NULL; //essencil
		}
		next->next = p;

		p = head->next;
		next = tmp;
	}
	return head;

}
void printlist(list * head)
{
	listnode *p = (listnode*) (head->next);
	while(p) {
		printf("%d ", p->data);
		p = (listnode*)(p->list.next);
	}
}
int main()
{
	list *head = creatlist(10);
	printf("new list:\n");
	printlist(head);
	reverselist(head);
	printf("reverse list:\n");
	printlist(head);

	return 0;
}
