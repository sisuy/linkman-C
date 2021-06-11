#include<stdio.h>
#include"stdlib.h"
#include"string.h"
#define Status int;
#define TRUE 1;
#define FALSE 0;

	typedef struct linkman
{
		char *name;	//name is limited in 0 - 30 
		int phone;
		struct linkman *group;
}linkman;

	typedef struct  Linklist
	{
		linkman** list;
		int size;
	}Linklist;

	//create a new linkman, and return it
	linkman* create(char* name, int phone);

	//add new linkman to linklist
	Status addlinkman(Linklist* linklist, int phone, char* name);
	
	//display all linkmen
	void display(Linklist* linklist);

	//get number of linkman
	int getNum(Linklist* linklist);

	//find the linkman by entering name
	linkman* getman(Linklist* linklist, char* name);

	//remove the linkman by name
	Status removeman(Linklist* linklist, char* name);

	//save linklist
	Status saveList(Linklist* linklist);
	
	//load list
	Linklist* loadList();

