// INCLUDES

#include <stdio.h>

// TODO FILE

FILE *todo_file;                                                               // create a pointer to the save file

// CREATE FILE

void init_todo_file(){                                                         // function to generate or clear a save
	todo_file = fopen(".todo", "w");                                           // open .todo for writing
	fprintf(todo_file, "");
	fclose(todo_file);                                                         // close .todo
}

// APPEND FILE

void append_todo_file(char *data){                                             // function to append data to .todo
	todo_file = fopen(".todo", "a");                                           // open .todo for appending
	fprintf(todo_file, data);                                                  // append data
	fclose(todo_file);                                                         // close file
}

// READ FILE

char *read_todo_file(){                                                        // function to read data from .todo
	todo_file = fopen(".todo", "r");                                           // open for reading

char contents[1000];
	fgets(contents, 1000, todo_file);                                          // write the read data to contents string
	fclose(todo_file);
	return contents;
}
