#ifndef IO_TREATMENT
#define IO_TREATMENT

#include <stdbool.h>

void CommandToLowerCase(char* command_from_user, char* command_lowercase);
void ExecuteCommand(node* my_list, char* command_lowercase, bool have_next_command);


#endif

