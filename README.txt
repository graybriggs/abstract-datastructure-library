+-----------------------+ 
| C Abstract Data Types |
+-----------------------+


It is the programmer's responsibility to manage the data that is managed by these data structures.
A section of code such as:

	list* lst;
	init_list(lst);
	float* f = (float*)malloc(sizeof(float));
	*f = 7.77f;
	insert_at(lst, f, 2);
	delete_at(lst, 2);

deletes the user memory allocated outside of the list structure. If the user wants to reinsert
data it must be reallocated. This is just a word of warning to be vigilant. These data
structures should handle any type passed.

Graham Briggs, February - May 2013