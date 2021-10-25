#include <stdio.h>
#include <stdbool.h>

#include "linked_list_io_functions.h"
#include "IO_Treatment.h"
#include "Linked_list_io_functions.h"



int main()
{
	node* my_list = create_node(0);
	char command_from_user[COMMAND_MAX_SIZE];
	char command_lowercase[COMMAND_MAX_SIZE];
	//bool have_next_command = true;
	bool have_next_command = false; //just for now
	while (have_next_command) {
		//scanf("%s", command_from_user);
		CommandToLowerCase(command_from_user, command_lowercase);
		ExecuteCommand(my_list, command_lowercase, have_next_command);

	}
	//inbar code- example for run
	char my_operatin[100];
	node* head_list = NULL;
	node* my_node;
	int exit_flag = 0;
	head_list = add_start(head_list, 5);
	head_list = add_last(head_list, 6);
	printf("my value %d \n", head_list->data);
	head_list = add_after(head_list, 4, 5);
	print_list(head_list);
	printf("\n");
	index(head_list, 5);
	printf("\n");
	exit_flag=index(head_list, 17); //should get back -1 and exit
	if (exit_flag == -1) {
		free_all_list(head_list); //will free all nodes
	}
	//creating new list just to tru=y
	printf("this is new list \n");
	node* new_head = NULL;
	new_head = add_start(new_head, 5);
	new_head= add_start(new_head, 7);
	new_head = add_last(new_head, 23);
	print_list(new_head); //should print 7 5 23
	new_head = add_after(new_head, 22, 29); //29 dosent exit-> will get back null
	if (new_head==NULL)
	{ 
		printf("got null so exit program");
		free_all_list(head_list); //will free all nodes
	}
		
	return 0;
}