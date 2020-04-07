#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<ctype.h>
#define MAXN 100

void printMainMenu(){
	printf("-------------------STUDENT MANAGE-------------------------------\n");
	printf("1.Add a student name into the array. \n");
	printf("2.Remove a student name.\n");
	printf("3.Search a student name. \n");
	printf("4.Output student names in ascending orders alphabetically. \n");
	printf("5.Exit the program.\n");
	printf("----------------------------------------------------------------\n");
}

void add(char names[][30], int *pn, char name[30]){
	// char name[30] containt each name
	// char names[][30] la array 2d ccontaint all element 
	// int *pn 
	strcpy(names[*pn], name);
	(*pn)++;
	printf("Add succesfull\n");
}
void ascendingName(char names[][30], int *n){
	for(int i = 0;i < *n -1; i++)
		for(int j = i + 1; j < *n; j++){
			if(strcmp(names[i],names[j]) < 0){
				char c[30];
				strcpy(c, names[i]);
				strcpy(names[i], names[j]); 
				strcpy(names[j],c);
			}
		}
}
/// a ,b,  d , e
// id, name, diem
//
int find(char names[][30], int *pn, char name[30]) {
	for(int i = 0; i < (*pn); i++)
		if(strcmp(name,names[i]) == 0){
			return i;
		
	}
	return -1;
}
void removeStd(char names[][30], int *pn, char name[]){
	int pos = find(names, &pn, name);
	if(pos < 0) 
		printf("Not found\n");
	else{
		for(int i = pos ; i < *pn ; i++)
			strcpy(names[i], names[i+1]);
		(*pn)--;
		
		printf("Removed\n");
		
	}

}
void list(char names[][30], int *pn){
	for(int i = 0 ; i < *pn; i++)
		printf("%d: %s\n",i+1,names[i]);
}		
int main(){
	int choice, pn = 0;
	char names[10][30];
	char name[30];
	
	do{
		printMainMenu();
		printf("Choice =");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
					fflush(stdin);
					printf("Enter name:");
					gets(name);
					if(pn >= MAXN) printf("Add failed\n");
					else{
						
						add(names, &pn, name);
						
					}
					break;
			case 2:
					printf("Which student you'd like to remove:");
					fflush(stdin);
					gets(name);		
						int pos = find(names, &pn, name);
					if(pos < 0)
						printf("Not found\n")	;
					else
						removeStd(names, &pn, name);
					
					break;
			case 3:
				printf("Enter name you want to find:"); 
				fflush(stdin);
				gets(name);	
				int pos1 = find(names, &pn, name);
				if(pos1 < 0) 
					printf("Not found\n");						
				else 
					printf("The position of student name in list is  %d\n", pos1 + 1);
				 break;
			case 4:
				printf("Total students: %d\n", pn);
				ascendingName(names,&pn);
				list(names, &pn);
			default:
				break;
		}
	}while(choice != 5);
}	
	
	

