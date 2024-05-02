// INCLUDES

#include <stdio.h>
#include <string.h>
#include "cmd.c"

// PARSE ARGS

void parse_args(int count, char* list[]){                                      // create a function to parse the command line arguments
	for(int arg = 0; arg < count; arg++){                                      // iterate through argument list
		if(strcmp(list[arg], "new") == 0){
			cmd_new();
		}
		if(strcmp(list[arg], "add") == 0){
			arg++;
			cmd_add(list[arg]);
		}
		if(strcmp(list[arg], "list") == 0){
			cmd_list();
		}
	}
}

// MAIN FUNCTION

int main(int argc, char* argv[]){
	cmd_add("test");
	parse_args(argc, argv);
}
