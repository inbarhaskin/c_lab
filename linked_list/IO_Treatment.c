#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "linked_list_io_functions.h"
#include "IO_Treatment.h"

#define _CRT_SECURE_NO_WARNINGS

void CommandToLowerCase(char* command_from_user, char* command_lowercase)
{
	int index = 0;
	while (command_from_user[index] != '\n') {
		command_lowercase[index] = tolower(command_from_user[index]);
		index++;
	}
	command_lowercase[index] = '\0';
	return;
}


void ExecuteCommand(node* my_list, char* command_lowercase, bool have_next_command)
{
	char* operation;
	char* str_i;
	char* str_j;
	//inbar change- dosent compile
	/*
	operation = strtok(command_lowercase, " ");
	str_i = strtok(NULL, " ");
	str_j = strtok(NULL, " ");

	int i, j;
	i = atoi(str_i);

	if (strcmp(operation, "add_end") == 0) {
		my_list = add_last(my_list, i);
	}
	else if (strcmp(operation, "add_start") == 0) {
		my_list = add_start(my_list, i);
	}
	else if (strcmp(operation, "add_after") == 0) {
		j = atoi(str_j);
		my_list = add_after(my_list, i, j);
	}
	else if (strcmp(operation, "index") == 0) {
		index(my_list, i);
	}
	else if (strcmp(operation, "del_index") == 0) {
		my_list = del_node(my_list, i);
	}
	else if (strcmp(operation, "print") == 0) {
		print_list(my_list);
	}
	else if (strcmp(operation, "exit") == 0) {
		free_all_list(my_list);
		have_next_command = false;
	}
	else { //illegal command
		printf("illegal command\n");
	}
	*/
}
