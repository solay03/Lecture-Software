/*******************************************************************
*project.c
*a C program that handles assignment marks for a 
*course module
*262888
*version Three
********************************************************************/

#include <stdio.h>

const int MAX = 75;
const int AMOUNT = 100;


int EnterScreen(char Name[][AMOUNT]);
int MainMenu(int NubOfStudents, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[]);
void SelectScreen(int Option, int NumOfStudent, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[]);
void EnterMarks(int NumOfStudent, char Name[][AMOUNT],  double Marks1[], double Marks2[], double Marks3[], int Pin[]);
void DisplayMarks(int NumOfStudent, char Name[][AMOUNT],  double Marks1[], double Marks2[], double Marks3[], int Pin[]);
void SuperVisor(int NumOfStudent, char Name[][AMOUNT],  double Marks1[], double Marks2[], double Marks3[], int Pin[]);
void ChangeMarks(int NumOfStudent, char Name[][AMOUNT],  double Marks1[], double Marks2[], double Marks3[], int Pin[], int Check);
void SuperVisorMenu(int NumOfStudent, char Name[][AMOUNT],  double Marks1[], double Marks2[], double Marks3[], int Pin[]);
void ChangeName(int NumOfStudent, char Name[][AMOUNT],  double Marks1[], double Marks2[], double Marks3[], int Pin[]);
void AddStudent(int NumOfStudent, char Name[][AMOUNT],  double Marks1[], double Marks2[], double Marks3[], int Pin[]);
void CheckMarks(int I,int CourseWorkNum ,double Marks1[], double Marks2[], double Marks3[],int NumOfStudent, char Name[][100], int Pin[]);
void InputMarks(int NumOfStudent, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[] );



int main()
{
	int i = 0;
	char name[MAX][AMOUNT];
	double marks1[MAX];
	double marks2[MAX];
	double marks3[MAX];
	int pin[1] = {1234};
	int NumOfStudent = EnterScreen(name);
	MainMenu(NumOfStudent, name, marks1, marks2, marks3, pin);
}

/* ask for number of students and there names */
int EnterScreen(char Name[MAX][AMOUNT])
{
	int numofstu = 0;
	printf("Enter Screen\n");
	printf("============");
	printf("\n\n");
	printf("Enter Number of student: ");
	scanf("%d%*c", &numofstu);
	
	
	if(numofstu > 75 || numofstu < 1)
	{
		printf("Error! Must be between 1 and 75!\n\n");
		main();
	}

	for(int i = 0; i < numofstu; i++)
	{
		printf("Enter Students name: ");
		scanf(" %[^\n]", &Name[i]);
		printf("\n");
		
	}
	
	printf("\n\n");
	return numofstu;
}

/* displays the main menu */
int MainMenu(int NumOfStudent, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[])
{
	int option = 0;
	printf("Main Menu\n");
	printf("===========");
	printf("\n\n");
	printf("1. Enter Marks\n");
	printf("2. Display a particular students mark\n");
	printf("3. Supervisor mode\n");
	printf("4. Exit Program\n\n");
	printf("Select option: ");
	scanf("%d", &option);
	printf("\n");
		
	SelectScreen(option, NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);	
	
}

/* deals with selection from main menu */
void SelectScreen(int Option, int NumOfStudent, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[])
{
	if(Option == 1)
	{
		EnterMarks(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	else if(Option == 2)
	{
		DisplayMarks(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	else if (Option == 3)
	{
		SuperVisor(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	else if (Option == 4)
	{
		_Exit(1);	
	}
	else
	{
		printf("incorrect input!\n");
		printf("\n\n");
		MainMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
}



/* allow user to enter marks*/
void EnterMarks(int NumOfStudent, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[])
{
	int CourseWork = 0;
	printf("Enter Marks\n");
	printf("===========\n\n");
	printf("Enter coursework number: ");
	scanf("%d", &CourseWork);
	
	
	
	if(CourseWork == 1)
	{
		for(int i = 0; i < NumOfStudent; i++)
		{
			printf("\nMarks achieved by %s:  ", &Name[i]);
			scanf("%lf%*c", &Marks1[i]);
			
			CheckMarks(i,CourseWork, Marks1, Marks2, Marks3, NumOfStudent, Name, Pin);
			
		}
	}
	
	else if(CourseWork == 2)
	{
		for(int i = 0; i < NumOfStudent; i++)
		{
			printf("\nMarks achieved by %s:  ", &Name[i]);
			scanf("%lf%*c", &Marks2[i]);
			
			CheckMarks(i,CourseWork, Marks1, Marks2, Marks3, NumOfStudent, Name, Pin);
			
		}
	}
	
	else if(CourseWork == 3)
	{
		for(int i = 0; i < NumOfStudent; i++)
		{
			printf("\nMarks achieved by %s:  ", &Name[i]);
			scanf("%lf%*c", &Marks3[i]);
		
			CheckMarks(i,CourseWork, Marks1, Marks2, Marks3, NumOfStudent, Name, Pin);
		}
	}
	
	else
	{
		printf("Error! Number must be between 1 and 3!");
		EnterMarks(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	
	InputMarks(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	printf("\n");
	printf("students marks have been recorded! \n\n");
	MainMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);

}



/* Display the marks on screen */
void DisplayMarks(int NumOfStudent, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[])
{

	int Ans = 0;
	char Enter= 'a';
	printf("Display Marks\n");
	printf("=============\n");
	for(int i = 0; i < NumOfStudent; i++)
	{
		printf("\n %02d) %s ",i+1 ,&Name[i]);
	
		
	}
	
	printf("\n Enter number for student: ");
	scanf("%d", &Ans);
	printf("\n");
	
	if (Ans <= NumOfStudent)
	{
		printf(" %s scored:\n %3.2f in coursework one\n",&Name[Ans-1], Marks1[Ans-1]);
		printf(" %3.2f in coursework two\n", Marks2[Ans-1]);
		printf(" %3.2f in coursework three\n", Marks3[Ans-1]);
		double total = Marks1[Ans-1] * 0.2 + Marks2[Ans-1] * 0.3 + Marks3[Ans-1] * 0.5;
		printf(" Total percentage: %3.2f\n", total); 	
	}
	
	else
	{
		printf("Invalid number of students!\n\n");
		DisplayMarks(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
		
	}
	
	
	printf("\n press enter to return to main menu\n\n");
	scanf("%c");
	scanf("%c", &Enter);
	
	if(Enter == 10)
	{
		MainMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
}

void SuperVisor(int NumOfStudent, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[])
{
	int AnsPin = 0;
	
	printf("Enter pin: ");
	scanf("%d", &AnsPin);
	
	if(AnsPin != Pin[0])
	{
		printf("Incorrect pin! try again\n\n");
		SuperVisor(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	SuperVisorMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
}
	
void SuperVisorMenu(int NumOfStudent, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[])
{
	int option = 0;
	int check = 0;
	printf("\nSupervisor\n");
	printf("==========\n\n");
	printf("1. Change pin\n");
	printf("2. Change marks\n");
	printf("3. Change students name\n");
	printf("4. Add new Student\n");
	printf("5. Back to Main Menu\n\n");
	printf("Select Option: ");
	scanf("%d", &option);
	printf("\n");
	
	if(option == 1)
	{
		int NewPin = 0;
		printf("Enter your new pin: ");
		scanf("%d", &NewPin);
		printf("\n");
		Pin[0] = NewPin;
		SuperVisorMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	
	else if (option == 2)
	{
		ChangeMarks(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin, check);
	}
	else if(option == 3)
	{
		ChangeName(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	else if(option == 4)
	{
		AddStudent(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	
	
	else if (option == 5)
	{
		MainMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);	
	}
	
	else 
	{
		printf("Invalid input! Must be between 1 and 5!\n\n");
	} 
	
}



void ChangeMarks(int NumOfStudent, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[], int Check)
{
	int Ans = 0;
	int CourseNum = 0;
	for(int i = 0; i < NumOfStudent; i++)
	{
		printf("\n %02d) %s: ",i+1 ,&Name[i]);
	}
	printf("\n Enter number for student: ");
	scanf("%d", &Ans);
	printf("\n");
	printf("What course work mark would you like to change: ");
	scanf("%d", &CourseNum);
	
	int I = Ans-1;
			
	if (CourseNum == 1)
	{
		printf("Enter New Mark: ");
		scanf("%lf%*c", &Marks1[Ans-1]);
		CheckMarks(I,CourseNum, Marks1, Marks2, Marks3, NumOfStudent, Name, Pin);
		printf("\n%s new mark is %3.2f \n\n", &Name[Ans-1], Marks1[Ans-1]);
		
	}	
		
	else if(CourseNum == 2)
	{
		printf("Enter New Mark: ");
		scanf("%lf%*c", &Marks2[Ans-1]);
		CheckMarks(I,CourseNum, Marks1, Marks2, Marks3, NumOfStudent, Name, Pin);
		printf("\n%s new mark is %3.2f\n\n", &Name[Ans-1], Marks2[Ans-1]);	
	}
	else if(CourseNum == 3)
	{
		printf("Enter New Mark: ");
		scanf("%lf%*c", &Marks3[Ans-1]);
		CheckMarks(I,CourseNum, Marks1, Marks2, Marks3, NumOfStudent, Name, Pin);
		printf("\n%s new mark is %3.2f\n\n", &Name[Ans-1], Marks3[Ans-1]);	
	}
	
	if (Check == 1)
	{
		MainMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	
	else
	{
		SuperVisorMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	
	
	
	
}

void ChangeName(int NumOfStudent, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[])
{	
	int Ans = 0;
	for(int i = 0; i < NumOfStudent; i++)
	{
		printf("\n %02d) %s: ",i+1 ,&Name[i]);
	}
	printf("\n Enter number for student: ");
	scanf("%d", &Ans);
	printf("\n");
	
	printf("Enter New name:");
	scanf(" %[^\n]", &Name[Ans-1]);
	SuperVisorMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
}
void AddStudent(int NumOfStudent, char Name[][100], double Marks1[], double Marks2[], double Marks3[], int Pin[])
{
	if (NumOfStudent < 75)
	{
		printf("Enter New students name: ");
		scanf(" %[^\n]", &Name[NumOfStudent]);
		NumOfStudent++;
		printf("%d", NumOfStudent);
		SuperVisorMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	else
	{
		printf("Error! you have the maximum amount of students!\n");
		SuperVisorMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
}

void CheckMarks(int I ,int CourseWorkNum ,double Marks1[], double Marks2[], double Marks3[],int NumOfStudent, char Name[][100], int Pin[])
{
	if (Marks1[I] > 100 || Marks1[I] < 0 || Marks2[I] > 100 || Marks2[I] < 0 || Marks3[I] > 100 || Marks3[I] < 0)
	{
		printf("Invalid amount of marks entered!\n\n");
		MainMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
}

void InputMarks(int NumOfStudent, char Name[][AMOUNT], double Marks1[], double Marks2[], double Marks3[], int Pin[])
{
	char answer = 'a';
	int check = 1;
	printf("Are the makrs you inputted correct(y/n)? ");
	scanf("%c%*c", &answer);
	
	if (answer == 'y')
	{
		MainMenu(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin);
	}
	
	else if (answer == 'n')
	{
		ChangeMarks(NumOfStudent, Name, Marks1, Marks2, Marks3, Pin, check);
	}
	
}
