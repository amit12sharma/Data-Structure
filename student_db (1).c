#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 10
#define FILE_NAME "student grade.txt"

typedef struct
{
	char name[NAME_LEN + 1]; 
	int number;		
	int science;
	int math;	
	int english; 
	int socialsci;
	int hindi;
	int average; 
	int sum;	
} student;		 
typedef struct node
{
	student stu;	   
	struct node *next; 
} studentNode;		  
typedef struct
{
	studentNode *head; 
	studentNode *tail; 
	int count;		   
} studentList;		   

void initialize(studentList *L);
void enter(studentList *L);		 
void display(studentList *L);	 
void find(studentList *L);		 
void modify(studentList *L);	 
void sort(studentList *L);		 
void write(studentList *L);		
void read(studentList *L);		

int main()
{
	
	printf("		**************Student Database management system**************\n");
	printf("		*  1.Enter new student Details                         *\n");
	printf("		*  2.Modify student Details by name                     *\n");
	printf("		*  3.Search student scores by name                     *\n");
	printf("		*  4.Display the results of all students               *\n");
	printf("		*  5.Display student scores by average                 *\n");
	printf("		*  6.Exit student achievement management system        *\n");
	printf("		********************************************\n");
	printf("  	                                                \n");
	
	studentList *L = (studentList *)malloc(sizeof(studentList));
	
	initialize(L);
	read(L);
	
	while (1)
	{
		int code;
		printf("Please enter the number corresponding to the operation you want to perform: ");
		scanf("%d", &code);
		switch (code)
		{
		case 1:
			enter(L);
			break;
		case 2:
			modify(L);
			break;
		case 3:
			find(L);
			break;
		case 4:
			display(L);
			break;
		case 5:
			sort(L);
			break;
		case 6:
			write(L);
			free(L->head); 
			free(L);	  
			return 0;
		default:
			printf("%d Is an invalid number, please re-enter!\n\n", code);
			break;
		}
	}
	return 0;
}

void initialize(studentList *L)
{
	
	studentNode *s = (studentNode *)malloc(sizeof(studentNode));
	s->next = NULL;
	L->head = s;
	L->tail = s;
	L->count = 0;
}

void enter(studentList *L)
{
	studentNode *s = (studentNode *)malloc(sizeof(studentNode));
	printf("Please enter student name:");
	scanf("%s", s->stu.name);
	printf("Please enter student RollNO:");
	scanf("%d", &s->stu.number);
	printf("Please enter your Science score:");
	scanf("%d", &s->stu.science);
	printf("Please enter your math score:");
	scanf("%d", &s->stu.math);
	printf("Please enter your English score:");
	scanf("%d", &s->stu.english);
	printf("Please enter your Socialscience score:");
	scanf("%d", &s->stu.socialsci);
	printf("Please enter your hindi score:");
	scanf("%d", &s->stu.hindi);
	s->stu.sum = s->stu.science + s->stu.math + s->stu.english + s->stu.socialsci + s->stu.hindi;
	s->stu.average = s->stu.sum / 5;
	if (L->head == L->tail)
	{
		L->tail = s;
	}
	s->next = L->head->next;
	L->head->next = s;
	L->count++;
	printf("Information entered successfully!\n\n");
}

void display(studentList *L)
{
	printf("share%d Group student data:\n", L->count);
	printf("full name\tStudent number\tScience\tmathematics\tEnglish\t\tSocialscience\thindi\tTotal score\taverage\t\tResult\n");
	studentNode *p;
	p = L->head;
	while (p->next)
	{
		p = p->next;
		printf("%s", p->stu.name);
		printf("\t\t%d", p->stu.number);
		printf("\t\t%d", p->stu.science);
		printf("\t%d", p->stu.math);
		printf("\t\t%d", p->stu.english);
		printf("\t\t%d", p->stu.socialsci);
		printf("\t\t%d", p->stu.hindi);
		printf("\t%d", p->stu.sum);
		printf("\t\t%d", p->stu.average);
		(p->stu.average < 50) ? printf("\t\tFail") : printf("\t\tPass");
		printf("\n");
	}
	printf("\n");
}

void find(studentList *L)
{
	printf("Please enter student name:");
	char name[NAME_LEN + 1];
	scanf("%s", name);
	studentNode *p = L->head->next;
	while (p)
	{
		if (strcmp(p->stu.name, name) == 0)
		{
			printf("full name\tStudent number\tScience\tmathematics\tEnglish\tSocialscience\thindi\tTotal score\taverage\n");
			printf("%s", p->stu.name);
			printf("\t\t%d", p->stu.number);
			printf("\t\t%d", p->stu.science);
			printf("\t\t%d", p->stu.math);
			printf("\t\t%d", p->stu.english);
			printf("\t\t%d", p->stu.socialsci);
			printf("\t\t%d", p->stu.hindi);
			printf("\t\t%d", p->stu.sum);
			printf("\t\t%d", p->stu.average);
			printf("\n\n");
			return;
		}
		p = p->next;
	}
	printf("I didn't find this%s Information!\n\n", name);
}

void modify(studentList *L)
{
	printf("Please enter student name:");
	char name[NAME_LEN + 1];
	scanf("%s", name);
	studentNode *p = L->head->next;
	while (p)
	{
		if (strcmp(p->stu.name, name) == 0)
		{
			printf("Please re-enter the information:\n");
			printf("Please enter student Rollno:");
			scanf("%d", &p->stu.number);
			printf("Please enter your Science score:");
			scanf("%d", &p->stu.science);
			printf("Please enter your math score:");
			scanf("%d", &p->stu.math);
			printf("Please enter your English score:");
			scanf("%d", &p->stu.english);
			printf("Please enter your Socialscience score:");
			scanf("%d", &p->stu.socialsci);
			printf("Please enter your hindi score:");
			scanf("%d", &p->stu.hindi);
			p->stu.sum = p->stu.science + p->stu.math + p->stu.english + p->stu.socialsci + p->stu.hindi;
			p->stu.average = p->stu.sum / 5;
			printf("Information modified successfully!\n\n");
			return;
		}
		p = p->next;
	}
	printf("I didn't find this%s Information!\n\n", name);
}

void sort(studentList *L)
{
	if (L->count < 2)
	{
		printf("List sorting completed!\n");
		display(L);
		return;
	}
	studentNode *p, *pre, *tmp;
	p = L->head->next;
	L->head->next = NULL;
	while (p)
	{
		tmp = p->next;
		pre = L->head;
		while (pre->next != NULL && pre->next->stu.average > p->stu.average)
			pre = pre->next;
		if (pre->next == NULL)
		{
			L->tail = p;
		}
		// insert
		p->next = pre->next;
		pre->next = p;
		// Skip to next
		p = tmp;
	}
	printf("List sorting completed!\n");
	display(L);
}

void write(studentList *L)
{
	// Open file flow
	FILE *fp = fopen(FILE_NAME, "w");
	if (fp == NULL)
	{
		printf("file%s Open failed\n", FILE_NAME);
		exit(EXIT_FAILURE);
	}
	// Output the total number of student nodes on the first line
	fprintf(fp, "%d\n", L->count);
	// Create a node pointer to the head node
	studentNode *p;
	p = L->head->next;
	// Traverse the linked list and output a set of data as a row
	while (p)
	{
		fprintf(fp, "%s ", p->stu.name);
		fprintf(fp, "%d ", p->stu.number);
		fprintf(fp, "%d ", p->stu.science);
		fprintf(fp, "%d ", p->stu.math);
		fprintf(fp, "%d ", p->stu.english);
		fprintf(fp, "%d ", p->stu.socialsci);
		fprintf(fp, "%d ", p->stu.hindi);
		fprintf(fp, "%d ", p->stu.sum);
		fprintf(fp, "%d ", p->stu.average);
		fprintf(fp, "\n");
		// Free node space after output
		studentNode *next = p->next;
		free(p);
		p = next;
	}
	// Close file stream
	fclose(fp);
	// Interactive information
	printf("Data saved! Thanks for using. Bye!\n");
}

void read(studentList *L)
{
	// Open file stream
	FILE *fp = fopen(FILE_NAME, "r");
	if (fp == NULL)
	{
		printf("file%s Open failed\n", FILE_NAME);
		exit(EXIT_FAILURE);
	}
	// Read the total number of student nodes in the first row
	fscanf(fp, "%d", &L->count);
	// The data is read circularly, and the number of cycles is count
	for (int i = 1; i <= L->count; i++)
	{
		// Create a new node
		studentNode *s = (studentNode *)malloc(sizeof(studentNode));
		// Read data
		fscanf(fp, "%s ", s->stu.name);
		fscanf(fp, "%d ", &s->stu.number);
		fscanf(fp, "%d ", &s->stu.science);
		fscanf(fp, "%d ", &s->stu.math);
		fscanf(fp, "%d ", &s->stu.english);
		fscanf(fp, "%d ", &s->stu.socialsci);
		fscanf(fp, "%d ", &s->stu.hindi);
		fscanf(fp, "%d ", &s->stu.sum);
		fscanf(fp, "%d ", &s->stu.average);
		// Insert the new node into the tail of the linked list (tail insertion method)
		s->next = NULL;
		L->tail->next = s;
		L->tail = s;
	}
	// Close file stream
	fclose(fp);
}
