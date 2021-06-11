#include"linkman.h"
#include<stdio.h>
#define status int;
#define true 1;
#define false 0;

void printSTART() {
	void function();
	printf("Welcome to linkman:\n");
	printf("this is a application which modify a linkman\n");
	function();
}

void function() {
	printf("function:\n\n");
	printf("\t\t\t1.add new linkman\n");
	printf("\t\t\t2.display all linkmen\n");
	printf("\t\t\t3.get the sum of the linkman\n");
	printf("\t\t\t4.find the linkman by entering name\n");
	printf("\t\t\t5.remove the linkman by entering name\n");
	printf("\t\t\t6.save link list in a txt document\n");
	printf("\t\t\t7.print function list\n");
	printf("\t\t\t8.load list from txt\n");
	printf("\t\t\t9.exit\n");
}

int main() {
	int control = 0;
	Linklist* linklist = (Linklist*)malloc(sizeof(Linklist));
	linklist->list = (linkman*)malloc(sizeof(linkman));
	linklist->size = 0;
	printSTART();
	
	while (1) {
		printf("Please enter the number to choose function.\n");
		scanf_s("%d", &control);
		switch (control)
		{
			case 1:
				printf("please enter the name:\n");
				char* name = (char*)malloc(sizeof(char) * 30);
				int phone ;				
				scanf_s("%s", name,30); 
				printf("please enter the phone number:\n");
				scanf_s("%d", &phone,30);
				addlinkman(linklist, phone, name);
				printf("finished add.\n");
				continue;
			case 2:
					printf("linklist size:%d\n", linklist->size);
					display(linklist);
					continue;
			case 3:
				printf("linkman sum:%d\n", getNum(linklist));
				continue;
			case 4:
				printf("find linkman:\nPlease enter the name:\n");
				char* n = (char*)malloc(sizeof(char) * 30);
				scanf_s("%s", n, 30);
				linkman* man = getman(linklist, n);
				continue;
			case 5:
				printf("remove linkman:\nPlease enter the name:\n");
				char* n1 = (char*)malloc(sizeof(char) * 30);
				scanf_s("%s", n1, 30);
				removeman(linklist, n1);
				continue;
			case 6:
				saveList(linklist);
				continue;
			case 7:
				function();
				continue;
			case 8:
				linklist = loadList();
				continue;
			case 9:
				break;
		}
		exit(0);
	}

	return 0;
}

