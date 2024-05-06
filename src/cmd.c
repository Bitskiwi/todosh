// INCLUDES

#include <stdio.h>
#include "todo.c"

// CREATE A TODO LIST

struct todo todo_list;

// COMMANDS

void cmd_new(){
	init_todo_file();
}

void cmd_add(char *name){
	struct task instance = new_task(name, 0, 0);
	todo_list = append_to_list(todo_list, instance);
	save_todo(todo_list);
}

void cmd_list(){
	print_list(todo_list);
}

void cmd_mark(){}
