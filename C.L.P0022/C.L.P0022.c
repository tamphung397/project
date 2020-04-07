#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<ctype.h> 
#define MAXN 100

void printMainMenu(){
	printf("-------------------STUDENT MANAGE-------------------------------\n");
	printf("1.Add a student name into the array. \n");
	printf("2.Search a student name. \n");
	printf("3.Output\n");
	printf("4.Exit the program.\n");
	printf("----------------------------------------------------------------\n");
}

void add(char names[][30], int *pn, char name[30], char codes[][30], char code[30],char datesOfBirth[][30],char dateOfBirth[30], float arr[], float point){
	strcpy(names[*pn], name);
	strcpy(codes[*pn], code);
	strcpy(datesOfBirth[*pn], dateOfBirth);
	arr[*pn] = point;
	(*pn)++;

	printf("Add succesfull\n");

	
}
void AsendingName(char names[][30], int *n,char codes[][30],char datesOfBirth[][30],float arr[]){
	for(int i = 0;i < *n -1; i++)
		for(int j = *n - 1; j > i; j--){
			if(strcmp(names[j],names[j-1]) < 0){
				char c[30];
				strcpy(c, names[j]);                            // b   se123 20/2/2000 6.5
				strcpy(names[j], names[j-1]);                   // a   se214  18/8/2000 9
				strcpy(names[j-1],c);                        
				

				strcpy(c, datesOfBirth[j]);
				strcpy(datesOfBirth[j], datesOfBirth[j-1]); 
				strcpy( datesOfBirth[j-1],c);
	
				
				strcpy(c, codes[j]);
				strcpy(codes[j], codes[j-1]); 
				strcpy(codes[j-1],c);
				
				float d;
				d = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = d;
			}
		}
}
 int find(char names[][30], int *pn, char name[30]) {
	for(int i = 0; i < (*pn); i++)
		if(strcmp(name,names[i]) == 0){
			return i;
	 	
	}
	return -1;
}

void list(char names[][30], int *pn,char codes[][30],char datesOfBirth[][30], float arr[]){
	printf("============================================================================================\n");
    printf("     Code                      Name                   Date Of Birth       Point learing\n");
	for(int i = 0 ; i < *pn; i++){
	printf("     %-26s%-23s%-20s%.3f\n", codes[i],names[i],datesOfBirth[i],arr[i]);
	
	}
}		


void readFromFile(char studentName[][30], char studentCode[][30], char dob[][30], int *n,  float point[]){
    FILE* f = fopen("Student.txt","r");
    fscanf(f,"%d%*c",n);
    for(int i = 0; i < *n; i++){
    	fscanf(f,"%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c%f%*c", studentCode[i], studentCode[i],studentName[i],dob[i], &point[i]);
	}
	fclose(f);
}

void writeOnFile(char studentName[][30], char studentCode[][30], char dob[][30], int n,  float point[]){
    FILE* f = fopen("Student.txt", "w");
    int i;
    fprintf(f, "%d\n", n);
    for (i = 0; i < n; i++){
        fprintf(f, "Student %d:\n%s\n%s\n%s\n%f\n", i+1, studentCode[i], studentName[i], dob[i], point[i]);
    }
    fclose(f);
}

int main(){
	int choice, pn = 0;
	float arr[100], point;
	char names[10][30]; 
	char name[30];
	char codes[10][30];
	char code[30];
	char datesOfBirth[10][30];
	char dateOfBirth[30];
	readFromFile(names,codes,datesOfBirth, &pn,arr);
	do{
		printMainMenu();
		fflush(stdin);
		printf("Choice =");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				do{
					fflush(stdin);
					printf("Enter code:");
					gets(code);
					fflush(stdin);
					
					printf("Enter name:");
					gets(name);
					fflush(stdin);
				
					printf("Enter day of birth:");
					gets(dateOfBirth);
					fflush(stdin);
					printf("Enter point learing:");
					scanf("%f",&point);
					if(pn >= MAXN) printf("Add failed\n");
					else{
						
					add(names, &pn, name, codes,code, datesOfBirth,dateOfBirth,arr,point);
					AsendingName(names,&pn,codes,datesOfBirth,arr);
					}
					printf("Press any key to continue\n");
				}while(getch()!=27);
				
					break;
		
			case 2:
				do{
					printf("Enter name you want to find:"); 
					fflush(stdin);
					gets(name);	
					int pos1 = find(names, &pn, name);
					if(pos1 < 0) 
						printf("Not found\n");						
					else {
				
						printf("Name = %s\n", names[pos1]);
						printf("Code = %s\n", codes[pos1]);
						printf("Day of birth = %s\n", datesOfBirth[pos1]);
						printf("Point learing = %.3f\n",arr[pos1]);
					}
					printf("Press any key to continue\n");
				}while(getch() != 27);
			
				 break; 
			case 3:			
				list(names, &pn,codes,datesOfBirth,arr);
				
			default:
				break;
		}
		
	}while(choice != 4);
	writeOnFile(names,codes,datesOfBirth,pn,arr);
}	
	
	

