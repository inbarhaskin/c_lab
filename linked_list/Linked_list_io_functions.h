#ifndef Linked_list_functions
#define Linked_list_functions
#define COMMAND_MAX_SIZE 100
#define _CRT_SECURE_NO_WARNINGS 
//typedef struct node* node; //Define node as pointer of data type struct LinkedList
typedef struct node {
	// node contain its value and pointer to next node
	int data;
	struct node* next_node;
}node;

node* add_start(node* current_head, int value);
node* add_last(node* head, int value);
node* add_after(node* head, int new_value, int searched_value);
int index(node* head, int value);
node* del_node(node* head, int index_to_delete);
void print_list(node* head);
void free_all_list(node* head);


#endif