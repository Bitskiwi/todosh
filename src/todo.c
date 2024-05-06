// INCLUDES

#include <stdio.h>
#include "file.c"

// TASK STRUCTURE

struct task {                                                                  // create a task structure
	char *name;                                                                // create member name
	int status;                                                                // create member status
	int init;                                                                  // create a flag to check if the task is empty or not
};

// TASK CONSTRUCTOR

struct task new_task(char *name, int status, int priority){                    // create a constructor for task struct
	struct task instance;                                                      // create an instance of task
	instance.name = name;                                                      // initialize name member
	instance.status = status;                                                  // initialize status member
	instance.init = 1;                                                         // set init flag true
	return instance;                                                           // return the instance
}

// LIST STRUCTURE

struct todo {                                                                  // create a structure for todo list
	struct task tasks[100];                                                    // create an array to store tasks in todo list
};

// END OF ARRAY

int EOA(struct todo list){                                                     // function to find end of array
	for(int i = 0; i < sizeof(list.tasks) / sizeof(list.tasks[0]); i++){       // iterate through todo list
		if(list.tasks[i].init == 0){                                           // if an uninitialized task is found
			return i;                                                          // return the index
		}
	}
}

// PRINT LIST

void print_list(struct todo list){                                             // function to print todo list
	for(int i = 0; i < EOA(list); i++){                                        // iterate through initialized todo list
		printf(list.tasks[i].name);                                            // print task name
		printf("\n");                                                          // newline
	}
}

// APPEND TO LIST

struct todo append_to_list(struct todo list, struct task instance){            // function to append to todo list
	list.tasks[EOA(list)] = instance;                                          // set the first uninitialized task to the instance passed into function
	return list;                                                               // return modified list
}


// SAVE TO FILE

void save_todo(struct todo list){
	init_todo_file();
	for(int i = 0; i < EOA(list); i++){
		char task_str[100];
		char status[1];
		sprintf(status, "%d", list.tasks[i].status);
		strcat(task_str, status);
		strcat(task_str, list.tasks[i].name);
		append_todo_file(task_str);
	}
}

// CONTENTS

// LOAD FILE

void parse_todo_file(struct todo target){
	char *todo_read = read_todo_file();
	printf("%c", todo_read[0]);
}
