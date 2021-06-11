#include"linkman.h"
#include"string.h"


linkman* create(char* name, int phone) {
	linkman* person = (linkman*)malloc(sizeof(linkman));
	if (person == NULL) {
		printf("create false: memory is not enought to create a new linkman.\n");
		return NULL;
	}
	person->phone = phone;
	person->name = name;
	person->group = NULL;
	return person;
	}

Status addlinkman(Linklist *linklist,int phone,char* name) {
	linklist->list = realloc(linklist->list, linklist->size + sizeof(linkman));
	linklist->size ++;
	if (linklist ->list == NULL) {
		printf("add false:memory is not enough.\n");
		return FALSE;
	}
	linkman* newlink = create(name, phone);
	linklist->list[linklist->size - 1] = newlink;
	printf("\n\t\tnew link man information:\n\t\tname:%s\n\t\tphone:%d\n", newlink->name, newlink->phone);
	return TRUE;
}

void display(Linklist* linklist) {
	if (linklist == NULL) {
		printf("null prt.\n");
		return;
	}
	for (int i = 0; i < linklist->size; i++) {
		linkman *dis = linklist->list[i];
		if(dis != NULL){
			printf("\n\t\tnew link man information:\n\t\tname:%s\n\t\tphone:%d\n", dis->name, dis->phone);
		}
		
	}
	printf("display finished\n");
}

int getNum(Linklist* linklist) {
	if (linklist == NULL) {
		printf("false getNum:null pointer");
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < linklist->size; i++) {
		if (linklist->list[i] != NULL) {
			sum++;
		}
	}
	return sum;
}

linkman* getman(Linklist* linklist, char* name){
	if (linklist == NULL) {
		printf("false getman:linklist is a null pointer\n");
	}
	for (int i = 0; i < linklist->size; i++) {
		if (linklist->list[i] != NULL) {
			if (!strcmp(linklist->list[i]->name, name)) {
				printf("\n\t\tnew link man information:\n\t\tname:%s\n\t\tphone:%d\n", linklist->list[i]->name, linklist->list[i]->phone);
				return linklist->list[i];
			}
			printf("can't find the linkman.\n");
			return NULL;
		}
	}
}

Status removeman(Linklist* linklist, char* name) {
	linkman* man = getman(linklist, name);
	if (man == NULL) {
		return FALSE;
	}
	for (int i = 0; i < linklist->size; i++) {
		if (linklist->list[i] != NULL) {
			if (!strcmp(linklist->list[i]->name, name)) {
				free(linklist->list[i]);
				linklist->list[i] = NULL;
				return TRUE;
			}
		}
	}
	return FALSE;
}

Status saveList(Linklist* linklist) {
	FILE* file = NULL;
	printf("Please enter the document name:\n");
	char* name = (char*)malloc(sizeof(char) * 30);
	scanf_s("%s", name, 30);
	fopen_s(&file, name, "w");

	if (file == NULL) {
		printf("error in open file.\n");
		return FALSE;
	}
	for (int i = 0; i < linklist->size; i++) {
		if (linklist->list[i] != NULL) {
			fputs("name: ",file);
			fputs(linklist->list[i]->name, file);
			fputs("\n",file);
			fputs("phone: ", file);
			char* num = (char*)malloc(sizeof(char) * 30);
			itoa(linklist->list[i] ->phone, num, 10);
			fputs(num, file);
			fputs("\n\n", file);
		}
	}
	fclose(file);
	printf("success:save link list\n");
	return TRUE;
}

Linklist* loadList() {
	Linklist* linklist = (Linklist*)malloc(sizeof(linklist));
	linklist->list = (linkman*)malloc(sizeof(linkman));
	linklist->size = 0;
	FILE* file = NULL;
	printf("please enter the document name\n");
	char* name = (char*)malloc(sizeof(char) * 30);
	char* space = (char*)malloc(sizeof(char) * 30);
	int phone = 0;
	char* fname = (char*)malloc(sizeof(char) * 30);
	scanf_s("%s", fname, 30);
	fopen_s(&file,fname, "r");
	while (!feof(file)) {
			fscanf(file, "%s %s", space, name,30);
			fscanf(file, "%s %d\n", space, &phone, 30 );
			addlinkman(linklist, phone, name);
	}
	fclose(file);
	return linklist;
}



