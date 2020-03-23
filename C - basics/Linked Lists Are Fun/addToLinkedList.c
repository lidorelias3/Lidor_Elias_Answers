#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node* next;
}node;

void print_linked_list(node* head);
void insert_new_node(node** head, node* new_node, int place);

int main()
{
	/*Creating nodes to check if we inserting them right*/
	node* node_to_add = (node*)malloc(sizeof(node));
	node_to_add->next = NULL;
	node_to_add->val = 99;

	node* more_node_to_add = (node*)malloc(sizeof(node));
	more_node_to_add->next = NULL;
	more_node_to_add->val = 88;

	/*Create linked list*/
	node* head = NULL;
	head = (node*)malloc(sizeof(node));
	if (head == NULL)
	{
		return 1;
	}
	head->val = 1;
	head->next = (node*)malloc(sizeof(node));
	head->next->val = 2;
	head->next->next = NULL;

	print_linked_list(head);
	insert_new_node(&head, node_to_add, 1);
	print_linked_list(head);
	insert_new_node(&head, more_node_to_add, 0);
	print_linked_list(head);

	system("PAUSE");
}

void print_linked_list(node* head)
{
	/*Function will print a linked list*/
	node* curr = head;
	while (curr != NULL)
	{
		printf("%d ---> ", curr->val);
		curr = curr->next;
	}
	printf("NULL\n");
}


void insert_new_node(node** head, node* new_node, int place)
{
	/*Function will insert a node to a specific place*/
	node* curr = *head;
	int counter = 1;
	/*Special case - For starting position*/
	if (place == 0)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		while (curr != NULL)
		{
			/*If that is the place*/
			if (counter == place)
			{
				/*get next for new node*/
				new_node->next = curr->next;
				/*Get curr next point to new node */
				curr->next = new_node;
			}
			counter += 1;
			curr = curr->next;
		}
	}
}