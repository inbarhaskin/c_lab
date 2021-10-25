#include "linked_list_io_functions.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define LINE_SIZE 100;
//linked list functions-> single way
//remember to always send back the head list
node* create_node(int value) {
	node* new_node = (node*)malloc(sizeof(node)); // allocate memory using malloc()
	if (new_node != NULL) {
		new_node->data = value;
		new_node->next_node = NULL;// make next point to NULL
	}
	return new_node;//return the new node
}
node* add_start(node* current_head, int value)
{
	//get pointer to node that will become head
	node* new_head = create_node(value);
	new_head->next_node = current_head;
	return new_head;
}

node* add_last(node* head, int value)
{
	node* new_last = create_node(value);
	//end case: got empty list, this node will be the head
	if (head == NULL)
		return new_last;
	//if not- will find the head
	node* temp = head;
	while (temp->next_node != NULL)
		temp = temp->next_node;
	//now temp points to current last node
	temp->next_node = new_last;
	return head;
}

node* add_after(node* head, int new_value, int searched_value)
{
	//if the function fail will return NULL, it shuld be checked in main!
	
	//end case: got empty list will exit the program
	if (head == NULL)
	{
		printf("requested value wasnt found, got empty list");
		//free(new_middle);
		return NULL;
	}
	//if not- will look for the value
	node* temp = head;
	while (temp!= NULL) {
		if (temp->data == searched_value)
		{
			node* new_middle = create_node(new_value);
			new_middle->next_node = temp->next_node;
			temp->next_node = new_middle;
			return head;
		}
		temp = temp->next_node;
	}
	//if we are here, the searched value wasnt found!
	printf("requested value wasnt found!");
	return NULL;
}

int index(node* head, int value) 
{//notice- this function return only index number and not the head! 
	//if index doesn't exit will return -1
	int curr_index = 0;
	//end case: got empty list will return -1
	if (head == NULL)
	{
		printf("%d", -1);
		return -1;
	}
	//if not- will look for the value
	node* temp = head;

	while (temp != NULL) {
		if (temp->data == value)
		{
			printf("%d", curr_index);
			return value;
		}
		temp = temp->next_node;
		curr_index++;
	}
	//if we are here, the searched value wasnt found!
	printf("%d", -1);
	return -1;
}

node* del_node(node* head, int index_to_delete)
{
	// if we need to delete the first node, just free and update head
	node* new_head;
	if (index_to_delete == 0) {
		new_head = head->next_node;
		free(head);
		return new_head;
	}

	node* ptr_to_node = head, * previous_ptr = NULL;
	int count_current_index = 0;

	// traverse the list until getting the right node
	while (count_current_index < index_to_delete)
	{
		previous_ptr = ptr_to_node;
		ptr_to_node = ptr_to_node->next_node;
		count_current_index++;
	}

	// update the 'next' field of the previous node
	previous_ptr = ptr_to_node->next_node;
	free(ptr_to_node);
	return head;
}

void print_list(node* head) {
	node* iteration_ptr = head;
	// for the case of an empty list
	if (iteration_ptr == NULL) {
		printf_s("[]");
		return;
	}
	else {
		printf_s("[");
		while (iteration_ptr != NULL) {
			printf_s("%d", iteration_ptr->data);
			iteration_ptr = iteration_ptr->next_node;
			if (iteration_ptr != NULL) { // we only need comma+space if there's another node after
				printf_s(", ");
			}
		}
		printf_s("]");
		return;
	}
}

void free_all_list(node* head) {
	node* iteration_ptr = head, * temp_ptr = NULL;
	while (iteration_ptr != NULL) {
		temp_ptr = iteration_ptr->next_node;
		free(iteration_ptr);
		iteration_ptr = temp_ptr;
	}

	head = NULL; // not sure if its ok to do so
	return;
}
///TODO: adding an exit() function on IO module

///NIR: I dont think it should be here


