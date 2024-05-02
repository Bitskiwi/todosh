// INCLUDES

#include <stdio.h>

// TASK STRUCTURE

struct task {
	char *name;
	int status;
	int priority;
	int init;
};

// TASK CONSTRUCTOR

struct task new_task(char *name, int status, int priority){
	struct task instance;
	instance.name = name;
	instance.status = status;
	instance.priority = priority;
	instance.init = 1;
	return instance;
}

// LIST STRUCTURE

struct todo {
	struct task tasks[100];
};

// END OF ARRAY

int EOA(struct todo list){
	for(int i = 0; i < sizeof(list.tasks) / sizeof(list.tasks[0]); i++){
		if(list.tasks[i].init == 0){
			return i;
		}
	}
}

// PRINT LIST

void print_list(struct todo list){
	for(int i = 0; i < EOA(list); i++){
		printf(list.tasks[i].name, "%s\n");
	}
}

// APPEND TO LIST

struct todo append_to_list(struct todo list, struct task instance){
	list.tasks[EOA(list)] = instance;
	return list;
}
