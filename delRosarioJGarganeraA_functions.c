/*************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and 
applying the concepts learned. I have constructed the functions and their respective algorithms 
and corresponding code by myself. The program was run, tested, and debugged by my own efforts. I 
further certify that I have not copied in part or whole or otherwise plagiarized the work of other 
students and/or persons.
 
 Del Rosario, Johann James J., DLSU ID# 12206075
 Garganera, Aira Jin B., DLSU ID# 12205373
*************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <conio.h>

//

#define MAX_IMPRESSIONS 20
#define MAX_SYMPTOMS 20

//

typedef char String5[6];
typedef char String10[11];
typedef char String15[16];
typedef char String20[21];
typedef char String50[51];
typedef char String150[151];

//

typedef struct
{
	String50 nameSymptom;
	String150 questionSymptom;
} SymptomType;

typedef struct
{
	int numSymptoms;
	String50 nameIllness;
	int Symptom[MAX_SYMPTOMS];
} ImpressionType;

typedef struct
{
	String5 ID;
	String10 Password;
} IDPassType;

typedef struct
{
	String50 namePatient;
	String50 numPatient;
	int agePatient;
	char genderPatient;
} PatientType;

//

void 
gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x / 2;
	coord.Y = y / 2;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void 
LoadingScreen()
{
	int i, j;
	gotoxy(75, 5);
	printf("LOADING");
	gotoxy(60, 8);
	for (i = 0; i <= 21; i++)
	{
		for (j = 0; j <= 100000000; j++)
			;
		printf("%c", '.');
	}
	gotoxy(60, 12);
	printf("Thank you for waiting!\n");
	Sleep(3000);
	system("cls");
}

/* DisplayMenu displays the Menu #1 and returns the user's choice of User Type
	@return choice - valid character from the choices
	Pre-condition: User enters only one character
	Member contribution: Improvement of both solutions.
*/
char 
DisplayMenu()
{
	char choice;
	printf("\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |            Medical Diagnosis           |\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |               Menu Options             |\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |   D - Doctor                           |\n");
	printf("\t\t   |   P - Patient                          |\n");
	printf("\t\t   |   A - Administrator                    |\n");
	printf("\t\t   |   E - Exit                             |\n");
	printf("\t\t   +----------------------------------------+\n");

	printf("\n\t\t   Enter your User Type: ");
	scanf(" %c", &choice);

	while (choice != 'D' && choice != 'd' && choice != 'P' && choice != 'p' && choice != 'A' && choice != 'a' && choice != 'E' && choice != 'e')
	{
		printf("\n\t\t   Please input a valid type.\n");
		printf("\n\t\t   Enter your User Type: ");
		scanf(" %c", &choice);
	}
	system("cls");
	return choice;
}

/* DocMenu displays the MENU #2 Doctor and returns the user's choice from the Doctor Menu
	@return choice - valid character from the choices
	Pre-condition: User enters only one character
	Member contribution: Improvement of both solutions.
*/
char 
DocMenu()
{
	char choice;
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |             Medical Diagnosis          |\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |                 Doctor                 |\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |  L - Log-in                            |\n");
	printf("\t\t   |  C - Create a new list of symptoms and |\n");
	printf("\t\t   |       impressions                      |\n");
	printf("\t\t   |  U - Use the existing list of symptoms |\n");
	printf("\t\t   |       and impressions                  |\n");
	printf("\t\t   |  D - Display Symptoms                  |\n");
	printf("\t\t   |  M - Modify Symptoms                   |\n");
	printf("\t\t   |  E - Exit                              |\n");
	printf("\t\t   +----------------------------------------+\n");

	printf("\n\t\t   Enter Choice: ");
	scanf(" %c", &choice);

	while (choice != 'L' && choice != 'C' && choice != 'U' && choice != 'D' && choice != 'M' && choice != 'E' &&
		   choice != 'l' && choice != 'c' && choice != 'u' && choice != 'd' && choice != 'm' && choice != 'e')
	{
		printf("\n\t\t   Invalid Choice. Please pick a valid choice.");
		printf("\n\t\t   Enter Choice: ");
		scanf(" %c", &choice);
	}

	Sleep(2000);
	system("cls");

	printf("\n");
	return choice;
}

/* AdminMenu displays the MENU #3 Administrator and returns the user's choice from the Administrator Menu
	@return choice - valid character from the choices
	Pre-condition: User enters only one character.
	Member contribution: Improvement of both solutions.
*/
char 
AdminMenu()
{
	char choice;
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |            Medical Diagnosis           |\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |                 Admin                  |\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |   L - Log-in                           |\n");
	printf("\t\t   |   D - Create new Doctor credentials    |\n");
	printf("\t\t   |   U - Create new User credentials      |\n");
	printf("\t\t   |   O - Display Doctor credentials       |\n");
	printf("\t\t   |   S - Display User credentials         |\n");
	printf("\t\t   |   E - Exit                             |\n");
	printf("\t\t   +----------------------------------------+\n");

	printf("\n\t\t   Enter Choice: ");
	scanf(" %c", &choice);

	while (choice != 'L' && choice != 'D' && choice != 'U' && choice != 'O' && choice != 'S' && choice != 'E' &&
		   choice != 'l' && choice != 'd' && choice != 'u' && choice != 'o' && choice != 's' && choice != 'e')
	{
		printf("\n\t\t   Invalid Choice. Please pick a valid choice.\n");
		printf("\n\t\t   Enter Choice: ");
		scanf("  %c", &choice);
	}

	Sleep(2000);
	system("cls");

	return choice;
}

/* VerifyLogin verifies if the ID and Password are contained in the provided text file
	@param fileName - name of the file that contains the list of IDs and Passwords
	@param ID - user ID to be verified
	@param Password - user Password to be verified
	@return 1 if the ID and Password are found and 0 if not found
	Pre-condition: The file exists.
	Member contribution: Improvement of both solutions.
*/
int 
VerifyLogin(String15 fileName,
			String5 ID,
			String10 Password)
{
	FILE *fp;
	String5 compID;
	String10 compPassword;

	fp = fopen(fileName, "r");

	while (fscanf(fp, "%s %s", compID, compPassword) == 2)
	{
		if (strcmp(compID, ID) == 0 && strcmp(compPassword, Password) == 0)
			return 1;
	}

	fclose(fp);

	return 0;
}

/* LogIn asks the user to input ID and Password, verifies if valid, and prompts the user to try again if not valid
	@param fileName - name of the file that contains the list of IDs and Passwords
	@param ID - address where verified user ID is stored
	@param Password - address where verified user Password is stored
	@returns verify, which is 1 if the ID and Password are valid and 0 if invalid
	Pre-condition: If prompted to try again, user only enters 'Y'/'y' or 'N'/'n'
	Member contribution: Improvement of both solutions.
*/
int 
Login(String15 fileName,
	  String5 *ID,
	  String10 *Password)
{
	int verify = 0;
	int flag = 0;
	char choice;

	printf("\nEnter your ID: ");
	scanf(" %s", ID);

	printf("Enter your Password: ");
	scanf(" %s", Password);

	verify = VerifyLogin(fileName, *ID, *Password);

	while (verify != 1 && flag == 0)
	{
		printf("\nIncorrect ID or Password. \n");
		printf("Try again? Yes (Y) or No (N)\n");
		scanf(" %c", &choice);
		if (choice == 'Y' || choice == 'y')
		{

			printf("Enter your ID: ");
			scanf(" %s", ID);

			printf("Enter your Password: ");
			scanf(" %s", Password);

			verify = VerifyLogin(fileName, *ID, *Password);
		}
		else
			flag = 1;
	}

	if (verify == 1)
		printf("You have successfully logged in!\n");

	return verify;
}

/* appendID adds (appends) a valid set of ID and password to the provided file
	@param fileName - name of the file that contains the list of IDs and Passwords
	@param ID - valid ID to be stored in the file
	@param Password - valid ID to be stored in the file
	Pre-condition: The file must exist.
	Member contribution: Improvement of both solutions.
*/
void 
appendID(String15 fileName,
		 String5 ID,
		 String10 Password)
{
	FILE *fp;
	fp = fopen(fileName, "a");
	fprintf(fp, "\n%s %s", ID, Password);

	fclose(fp);
}

/* addID asks the administrator to input ID and Password to be appended to the provided file
	@param fileName - name of the file that contains the list of IDs and Passwords
	@param userName - string containing the User type (i.e. Doctor, Patient)
	Pre-condition: The file must exist.
	Member contribution: Improvement of both solutions.
*/
void 
addID(String15 fileName,
	String15 userName)
{
	char *tempID = malloc(6 * sizeof(char));
	char *tempPass = malloc(11 * sizeof(char));

	int invalid = 0;
	int invalid1 = 0;
	int i;

	do
	{
		invalid = 0;
		printf("Enter %s's ID# (Up to 5 digits): ", userName);
		scanf(" %s", tempID);

		// check if valid ID
		if (strlen(tempID) <= 5)
		{
			for (i = 0; i < strlen(tempID); i++)
			{
				if (tempID[i] < 48 || tempID[i] > 57)
					invalid = 1;
			}
		}
		else
			invalid = 1;

		if (invalid)
			printf("Invalid ID. Please try again.\n");

	} while (invalid);

	do
	{
		invalid1 = 0;
		i = 0;
		printf("Enter Password (Up to 10 Alphanumeric characters): ");
		scanf(" %s", tempPass);

		// check if valid Password
		if (strlen(tempPass) <= 10)
		{
			while (invalid1 != 1 && i < strlen(tempPass))
			{
				if (tempPass[i] < 48 || (tempPass[i] > 57 && tempPass[i] < 65) || (tempPass[i] > 90 && tempPass[i] < 97) || tempPass[i] > 122)
					invalid1 = 1;
				else
					i++;
			}
		}
		else
			invalid1 = 1;

		if (invalid1)
			printf("Invalid Password. Please try again.\n");

	} while (invalid1);

	appendID(fileName, tempID, tempPass);

	free(tempID);
	free(tempPass);
}

/* displayIDs displays the list of IDs and Passwords stored in the provided text file
	@param fileName - name of the file that contains the list of IDs and Passwords
	@param userName - string containing the User type (i.e. Doctor, Patient)
	Pre-condition: The file must exist.
	Member contribution: Improvement of both solutions.
*/
void 
displayIDs(String15 fileName,
			String15 userName)
{
	FILE *fp;
	String5 tempID;
	String10 tempPass;
	int count = 1;

	fp = fopen(fileName, "r");
	while (fscanf(fp, "%s %s", tempID, tempPass) == 2)
	{
		printf("%s %d: \n", userName, count);
		printf("ID#: %s\tPassword: %s\n\n", tempID, tempPass);

		count++;
	}
	fclose(fp);
}

/* administratorFunction displays the Administrator Menu, and prompts the user to choose an action.
   It loops and calls the designated functions as per the user's choice, until the user chooses 'E'.
	@returns flag, which is 1 to exit the Administrator Menu loop if the user chooses 'E' (exit)
*/
int 
administratorFunction()
{
	char AdminChoice;
	int flag = 0, adminVerified = 0;
	String5 AdminID;
	String10 AdminPassword;

	while (!flag)
	{
		AdminChoice = AdminMenu();
		switch (AdminChoice)
		{
		case 'L':
		case 'l':
			adminVerified = Login("Administrators.txt", &AdminID, &AdminPassword);
			break;
		case 'D':
		case 'd':
			if (adminVerified)
			{
				addID("Doctors.txt", "Doctor");
			}
			else
				printf("Please log-in first to unlock this feature.\n");
			break;
		case 'U':
		case 'u':
			if (adminVerified)
			{
				addID("Patients.txt", "Patient");
			}
			else
				printf("Please log-in first to unlock this feature.\n");
			break;
		case 'O':
		case 'o':
			if (adminVerified)
			{
				displayIDs("Doctors.txt", "Doctor");
			}
			else
				printf("Please log-in first to unlock this feature.\n");
			break;
		case 'S':
		case 's':
			if (adminVerified)
			{
				displayIDs("Patients.txt", "Patient");
			}
			else
				printf("Please log-in first to unlock this feature.\n");
			break;
		case 'E':
		case 'e':
			flag = 1;
			break;
		}
	}

	return flag;
}

/* InputSymptomsFile stores the Symptoms array of struct SymptomType into the provided file
	@param fileName - name of the file to contain the list of Symptoms
	@param Symptoms - array of StructureType, which contains the Symptoms to be stored into the file
	@param numSymptoms - number of elements in the Symptoms array
	Member contribution: Improvement of both solutions.
*/
void 
InputSymptomsFile(String15 fileName,
				  SymptomType Symptoms[MAX_SYMPTOMS],
				  int numSymptoms)
{
	FILE *fp;
	int i;
	fp = fopen(fileName, "w");

	fprintf(fp, "%d\n", numSymptoms);
	for (i = 0; i < numSymptoms; i++)
	{
		fprintf(fp, "%d\n", i + 1);
		fprintf(fp, "%s\n%s\n", Symptoms[i].nameSymptom, Symptoms[i].questionSymptom);
	}

	fclose(fp);
}

/* InputSymptoms asks the user to input Symptom information into the Symptoms array, and stores it into the "Symptoms.txt" file
	@param Symptoms - array of StructureType, which contains the Symptoms to be stored into the file
	@returns numSymptoms, which is the number of elements in the Symptoms array
	Member contribution: Improvement of both solutions.
*/
int 
InputSymptoms(SymptomType Symptoms[MAX_SYMPTOMS])
{
	int i;
	int numSymptoms;

	do
	{
		printf("How many symptoms do you want to consider? (maximum 20)\n");
		scanf(" %d", &numSymptoms);
	} while (numSymptoms > 20);

	for (i = 0; i < numSymptoms; i++)
	{
		printf("\nWhat is the symptom? ");
		scanf(" %[^\n]s", Symptoms[i].nameSymptom);

		printf("\nHow do you want to ask the symptom? \n");
		scanf(" %[^\n]s", Symptoms[i].questionSymptom);
	}

	InputSymptomsFile("Symptoms.txt", Symptoms, numSymptoms);
	return numSymptoms;
}

void 
displaySymptoms(SymptomType Symptoms[MAX_SYMPTOMS],
				int numSymptoms)
{
	int j;
	for (j = 0; j < numSymptoms; j++)
	{
		printf("%d. %s\n", j + 1, Symptoms[j].nameSymptom);
	}
}

void 
displayImpressions(ImpressionType Impressions[MAX_IMPRESSIONS],
				   SymptomType Symptom[MAX_SYMPTOMS],
				   int numImpressions)
{
	int j, i;
	int index;
	for (j = 0; j < numImpressions; j++)
	{
		printf("Impression #%d: %s", j + 1, Impressions[i].nameIllness);
		for (i = 0; i < Impressions[i].numSymptoms; j++)
		{
			index = Impressions[j].Symptom[i];
			printf("%d. %s\n", i + 1, Symptom[index].nameSymptom);
		}
	}
}

/* InputImpressionsFile stores the Impressions array of struct ImpressionType into the provided file
	@param fileName - name of the file to contain the list of Impressions
	@param Impressions - array of ImpressionType, which contains the Impressions to be stored into the file
	@param numImpressions - number of elements in the Impressions array
	Member contribution: Improvement of both solutions.
*/
void 
InputImpressionsFile(String50 fileName,
					 ImpressionType Impressions[MAX_IMPRESSIONS],
					 int numImpressions)
{
	FILE *fp;
	int i, j;
	fp = fopen(fileName, "w");

	fprintf(fp, "%d\n", numImpressions);
	for (i = 0; i < numImpressions; i++)
	{
		fprintf(fp, "#%d\n", i + 1);
		fprintf(fp, "%s\n", Impressions[i].nameIllness);
		for (j = 0; j < Impressions[i].numSymptoms; j++)
		{
			fprintf(fp, "%d\n", Impressions[i].Symptom[j]);
		}
	}

	fclose(fp);
}

/* InputImpressions asks the user to input Impression information into the Impressions array, and stores it into the "Impressions.txt" file.
   It then returns the number of elements in the Impressions array.
	@param Impressions - array of ImpressionType, which contains the Impressions to be stored into the file
	@param Symptoms - array of Symptomtype, used to display the list of symptoms
	@param numSymptoms - number of elements in the Symptoms array, used to display the list of symptoms
	@returns numImpressions, which is the number of elements in the Impressions array
	Member contribution: Improvement of both solutions.
*/
int 
InputImpressions(ImpressionType Impressions[MAX_IMPRESSIONS],
				 SymptomType Symptoms[MAX_SYMPTOMS],
				 int numSymptoms)
{
	int numImpressions, numPresentSymptoms;
	int i, j, temp;

	do
	{
		printf("How many impressions do you want to enter? (Maximum 20)\n");
		scanf(" %d", &numImpressions);
		if (numImpressions > MAX_IMPRESSIONS)
		{
			printf("Invalid input. Please enter a number less than or equal to %d.\n", MAX_IMPRESSIONS);
		}
	} while (numImpressions > MAX_IMPRESSIONS);

	for (i = 0; i < numImpressions; i++)
	{
		printf("Impression #%d:\n", i + 1);
		printf("What is the illness? ");
		scanf(" %[^\n]", Impressions[i].nameIllness);
		// display list of symptoms
		displaySymptoms(Symptoms, numSymptoms);

		do
		{
			printf("\nHow many of the symptoms above are present in a %s case? (Maximum %d)\n", Impressions[i].nameIllness, numSymptoms);
			scanf(" %d", &numPresentSymptoms);
			if (numPresentSymptoms > numSymptoms)
			{
				printf("Invalid input. Please enter a number less than or equal to %d.\n", numSymptoms);
			}
		} while (numPresentSymptoms > numSymptoms);

		Impressions[i].numSymptoms = numPresentSymptoms;

		// copy symptom name to [impression] symptom list
		printf("Enter the corresponding number of each symptom. \n");
		for (j = 0; j < Impressions[i].numSymptoms; j++)
		{
			scanf(" %d", &temp);
			Impressions[i].Symptom[j] = temp;
		}
	}
	InputImpressionsFile("Impressions.txt", Impressions, numImpressions);
	return numImpressions;
}

/* ExistingSymptoms scans and stores the list of symptoms in the text file into the Symptoms array.
   It then returns the number of elements in the Symptoms array.
	@param fileName - name of the file to contain the list of Symptoms
	@param Symptoms - array of Symptomtype, where the scanned data is stored
	@returns numSymptoms, which is the number of elements in the Symptoms array
	Member contribution: Improvement of both solutions.
*/
int 
ExistingSymptoms(String15 fileName,
				SymptomType Symptoms[MAX_SYMPTOMS])
{
	FILE *fp;
	int i = 0;
	int count;
	int numSymptoms;
	fp = fopen(fileName, "r");

	fscanf(fp, "%d", &numSymptoms);
	while (fscanf(fp, "%d %[^\n] %[^\n]", &count, Symptoms[i].nameSymptom, Symptoms[i].questionSymptom) == 3)
	{
		i++;
	}

	fclose(fp);
	// InputSymptomsFile("TESTSymptoms.txt", Symptoms, numSymptoms); //test output
	return numSymptoms;
}

/* ExistingImpressions scans and stores the list of impressions in the text file into the Impressions array.
   It then returns the number of elements in the Impressions array.
	@param Impressions - array of ImpressionType, where the scanned data is stored
	@param fileName - name of the file to contain the list of Impressions
	@returns numImpressions, which is the number of elements in the Impressions array
	Member contribution: Improvement of both solutions.
*/
int 
UseExistingImpressions(ImpressionType Impressions[MAX_IMPRESSIONS],
					String15 fileName)
{
	int i = 0, j = 0, temp;
	String5 count;
	int numImpressions;
	FILE *fp;
	fp = fopen(fileName, "r");

	fscanf(fp, " %d", &numImpressions);

	for (i = 0; i < numImpressions; i++)
	{
		Impressions[i].numSymptoms = 0;
		fscanf(fp, " %s", count);
		fscanf(fp, " %[^\n]", Impressions[i].nameIllness);
		j = 0;
		while (fscanf(fp, " %d", &temp) == 1)
		{
			Impressions[i].Symptom[j] = temp;
			Impressions[i].numSymptoms += 1;
			j++;
		}
	}

	// InputImpressionsFile("TESTImpressions.txt", Impressions, numImpressions); //test output
	fclose(fp);
	return numImpressions;
}

/* DisplayImpression asks the user for the name of the impression, and displays information about the impression.
	@param Impressions - array of ImpressionType which contains the data to be displayed
	@param Symptoms - array of SymptomType, which is used to display the names of the symptoms in the impression
	Pre-condition: User does not enter an impression name that exceeds 50 characters.
	Member contribution: Improvement of both solutions.
*/
void 
DisplayImpression(ImpressionType Impressions[MAX_IMPRESSIONS],
				SymptomType Symptoms[MAX_SYMPTOMS],
				int numImpressions)
{
	int i = 0, j, found = 0, impNum, temp, n;
	String50 tempName;

	printf("What is the impression? ");
	scanf(" %[^\n]", tempName);

	while (i < numImpressions && found == 0)
	{
		if (strcmp(tempName, Impressions[i].nameIllness) == 0)
		{
			impNum = i;
			found = 1;
		}
		i++;
	}

	if (found != 1)
	{
		printf("Impression not found.\n");
	}
	else
	{
		n = Impressions[impNum].numSymptoms;
		printf("\n\t\t\t   Symptoms of %s are: \n", Impressions[impNum].nameIllness);
		for (j = 0; j < n; j++)
		{
			temp = Impressions[impNum].Symptom[j];
			printf("\t\t\t\t  %d. %s\n", j+1, Symptoms[temp - 1].nameSymptom);
		}
	}
	printf("\n");
}

/* ModifyImpression asks the user for the name of the Impression, displays its symptoms, and asks the user to
   modify the symptoms, and updates the data for the chosen Impression.
	@param fileName - name of the file to contain the list of Impressions, where the updated list of Impressions will be stored
	@param Impressions - array of ImpressionType, where the modified data is stored
	@param numImpressions - number of elements in the Impressions array
	@param Symptoms - array of SymptomType, which is used to display the list of symptoms
	@param numSymptoms - number of elements in the Symptoms array
	Pre-condition: User does not enter an impression name that exceeds 50 characters.
	Pre-condition: User does not enter a symptom number that is not included in the list of symptoms.		
	Member contribution: Improvement of both solutions.
*/
void 
ModifyImpression(String50 fileName,
				ImpressionType Impressions[MAX_IMPRESSIONS],
				int numImpressions,
				SymptomType Symptoms[MAX_SYMPTOMS],
				int numSymptoms)
{
	String50 input_impression;
	int i = 0, j, numPresentSymptoms, temp;

	printf("What is the Impression? ");
	scanf(" %[^\n]", input_impression);

	while (i < numImpressions && strcmp(input_impression, Impressions[i].nameIllness) != 0)
	{
		// If the input impression is not found, move on to the next impression
		i++;
	}

	if (i == numImpressions)
	{
		// If the impression is not found in the array, print an error message and return
		printf("Impression not found.\n");
		return;
	}

	// Print the symptoms of the selected impression
	printf("Symptoms of %s are:\n", Impressions[i].nameIllness);
	for (j = 0; j < Impressions[i].numSymptoms; j++)
	{
		printf("\t%s\n", Symptoms[Impressions[i].Symptom[j] - 1].nameSymptom);
	}

	// Ask the user to modify the symptoms
	printf("\nYou can modify the symptoms of %s.\nBelow is a list of symptoms:\n", Impressions[i].nameIllness);
	displaySymptoms(Symptoms, numSymptoms);

	printf("\nHow many of the symptoms above are present in a %s case?\n", Impressions[i].nameIllness);
	scanf("%d", &numPresentSymptoms);
	Impressions[i].numSymptoms = numPresentSymptoms;

	printf("Enter the corresponding number of each symptom.\n");
	for (j = 0; j < Impressions[i].numSymptoms; j++)
	{
		scanf("%d", &temp);
		Impressions[i].Symptom[j] = temp; // Subtract 1 to convert from 1-based indexing to 0-based indexing
	}

	// Print the updated symptoms of the selected impression
	printf("Here are the NEW symptoms for %s:\n", Impressions[i].nameIllness);
	for (j = 0; j < Impressions[i].numSymptoms; j++)
	{
		temp = Impressions[i].Symptom[j];
		printf("%d. %s\n", j + 1, Symptoms[temp - 1].nameSymptom);
	}

	// Write the updated data back to the input file
	InputImpressionsFile("Impressions.txt", Impressions, numImpressions);
	printf("\n");
}

/* doctorFunction displays the Doctor Menu, and prompts the user to choose an action.
   It loops and calls the designated functions as per the user's choice, until the user chooses 'E'.
	@param Symptoms - array of SymptomType, which will be updated to store information about the Symptoms
	@param Impressions - array of ImpressionType, which will be updated to store information about the Impressions
	@param numSymptomsRETURN - address where the number of elements in the Symptoms array will be stored
	@param numImpressionsRETURN - address where the number of elements in the Impressions array will be stored
	@returns flag, which is 1 to exit the Doctor Menu loop if the user chooses 'E' (exit)
	Member contribution: Improvement of both solutions.
*/
int 
doctorFunction(SymptomType Symptoms[MAX_SYMPTOMS],
			   ImpressionType Impressions[MAX_IMPRESSIONS],
			   int *numSymptomsRETURN,
			   int *numImpressionsRETURN)
{
	int DocChoice;
	int docVerified;
	String5 DocID;
	String10 DocPassword;
	int flag = 0;
	int numSymptoms = 0, numImpressions = 0;

	while (!flag)
	{
		DocChoice = DocMenu();
		switch (DocChoice)
		{
		case 'L':
		case 'l':
			docVerified = Login("Doctors.txt", &DocID, &DocPassword);
			break;
		case 'C':
		case 'c':
			if (docVerified == 1)
			{
				numSymptoms = InputSymptoms(Symptoms);
				numImpressions = InputImpressions(Impressions, Symptoms, numSymptoms);
			}
			else
				printf("Please log-in to access this function.\n");
			break;
		case 'U':
		case 'u':
			if (docVerified == 1)
			{
				numSymptoms = ExistingSymptoms("Symptoms.txt", Symptoms);
				numImpressions = UseExistingImpressions(Impressions, "Impressions.txt");
				printf("Successfully loaded the existing symptoms and impressions.\n");
				flag = 1;
			}
			else
				printf("Please log-in to access this function.\n");
			break;
		case 'D':
		case 'd':
			if (docVerified == 1)
			{
				if (numSymptoms > 0 && numImpressions > 0)
					DisplayImpression(Impressions, Symptoms, numImpressions);
				else
					printf("No existing data for symptoms and impressions. Use C or U first.\n");
			}
			else
				printf("Please log-in to access this function.\n");
			break;
		case 'M':
		case 'm':
			if (docVerified == 1)
			{
				if (numSymptoms > 0 && numImpressions > 0)
					ModifyImpression("Impressions.txt", Impressions, numImpressions, Symptoms, numSymptoms);
				else
					printf("No existing data for symptoms and impressions. Use C or U first.\n");
			}
			else
				printf("Please log-in to access this function.\n");
			break;
		case 'E':
		case 'e':
			flag = 1;
			break;
		}
	}

	*numSymptomsRETURN = numSymptoms;
	*numImpressionsRETURN = numImpressions;

	return flag;
}

/* EnterPatientInfo prompts the patient to enter their information (name, patient number, age, and gender)
	@param Patient - contains the address of struct PatientType which will contain information about the patient.
	Pre-Condition: Patient does not include any whitespaces in entering the patient number.
				   Patient only enters one character in entering patient gender.
	Member contribution: Improvement of both solutions.
*/
void 
EnterPatientInfo(PatientType *Patient)
{
	printf("\nWhat is your name? ");
	scanf(" %[^\n]", Patient->namePatient);

	printf("\nWhat is your patient number: ");
	scanf(" %s", Patient->numPatient);

	do
	{
		printf("\nEnter your age: ");
		scanf(" %d", &Patient->agePatient);
	} while (Patient->agePatient > 100 || Patient->agePatient < 0);

	do
	{
		printf("\nGender (M/F): ");
		scanf("  %c", &Patient->genderPatient);
	} while (Patient->genderPatient != 'F' && Patient->genderPatient != 'f' && Patient->genderPatient != 'M' && Patient->genderPatient != 'm');
}

/* Questions displays the list of questions for each Symptom in the array Symptoms
	@param Symptoms - array of struct SymptomType which contains the questions to be displayed
	@param numSymptoms - number of elements in the Symptoms array
	@param tempArray - array which will contain the index + 1 (to align with Impressions.Symptoms) of each symptom that the user responded with 'Y'/'y'
	@returns ctr, which contains the number of elements in the tempArray / number of symptoms that the patient has
	Member contribution: Improvement of both solutions.
*/
int 
Questions(SymptomType Symptoms[MAX_SYMPTOMS],
		  int numSymptoms,
		  int tempArray[MAX_SYMPTOMS])
{
	int i, ctr = 0;
	char patientChoice;

	for (i = 0; i < numSymptoms; i++)
	{
		do
		{
			printf("%s (Y/N)\n", Symptoms[i].questionSymptom);
			scanf(" %c", &patientChoice);
		} while (patientChoice != 'Y' && patientChoice != 'y' && patientChoice != 'N' && patientChoice != 'n');

		if (patientChoice == 'Y' || patientChoice == 'y')
		{
			tempArray[ctr] = i + 1;
			ctr++;
		}
	}

	return ctr;
}

/* linearSearch performs linear search for an integer in an array of integers
	@param n - integer to be searched for
	@param array2 - array of integers, which is the array to be searched in
	@param numArray2 - number of elements in array2
	@returns found, which is 1 if the integer is found, and 0 if it is not found
	Member contribution: Improvement of both solutions.
*/
int 
linearSearch(int n,
			 int array2[MAX_SYMPTOMS],
			 int numArray2)
{
	int found = 0;
	int i = 0;

	while (found == 0 && i < numArray2)
	{
		if (array2[i] == n)
		{
			found = 1;
		}
		i++;
	}

	return found;
}

/* PrintImpressions searches for the impressions to be printed, and stores them into an array
	@param tempImpArray - array where the impressions to be printed will be stored
	@param Immpressions - array of struct ImpressionType, which contains the list of Impressions to be used
	@param Symptoms - array of struct SymptomType, which contains the list of Symptoms to be used
	@param tempArray - array of integers, which contains the list of symptoms present in the patient
	@param numPatientSymp - number of elements in tempArray / number of symptoms present in patient
	@param numImpressions - number of elements in Impression array
	@returns k, which is the number of impressions to be printed
	Member contribution: Improvement of both solutions.
*/
int 
PrintImpressions(String50 tempImpArray[MAX_IMPRESSIONS],
				 ImpressionType Impressions[MAX_IMPRESSIONS],
				 SymptomType Symptoms[MAX_SYMPTOMS],
				 int tempArray[MAX_SYMPTOMS],
				 int numPatientSymp,
				 int numImpressions)
{
	int i, j, k = 0;
	int counter = 0;

	for (i = 0; i < numImpressions; i++)
	{
		counter = 0;

		for (j = 0; j < numPatientSymp; j++)
		{
			counter += linearSearch(tempArray[j], Impressions[i].Symptom, Impressions[i].numSymptoms);
		}

		if (Impressions[i].numSymptoms <= 3)
		{
			if (counter == Impressions[i].numSymptoms)
			{
				strcpy(tempImpArray[k], Impressions[i].nameIllness);
				k++;
			}
		}
		else if (Impressions[i].numSymptoms > 3)
		{
			if (counter >= 3)
			{
				strcpy(tempImpArray[k], Impressions[i].nameIllness);
				k++;
			}
		}
	}

	return k;
}

/* DisplayHPI displays the HPI of the patient, and stores it into a text file
	@param Patient - struct PatientType, which contains information of the patient to be displayed
	@param numPatientSymp - number of symptoms present in patient
	@param Symptoms - array of struct SymptomType, which contains the list of Symptoms to be used
	@param Impressions - array of struct ImpressionType, which contains the list of Impressions to be used
	@param tempArray - array of integers, which contains the list of symptoms present in the patient
	@param numImpressions - number of elements in Impression array
	Member contribution: Improvement of both solutions.
*/
void 
DisplayHPI(PatientType Patient,
		   int numPatientSymp,
		   SymptomType Symptoms[MAX_SYMPTOMS],
		   ImpressionType Impressions[MAX_IMPRESSIONS],
		   int tempArray[MAX_SYMPTOMS],
		   int numImpressions)
{
	String15 tempFileName;
	String10 tempGender;
	String5 pronoun;
	String50 tempImpArray[MAX_IMPRESSIONS];
	int numImp;
	int tempIndex;
	int i;

	if (Patient.genderPatient == 'F' || Patient.genderPatient == 'f')
	{
		strcpy(tempGender, "female");
		strcpy(pronoun, "She");
	}

	else
	{
		strcpy(tempGender, "male");
		strcpy(pronoun, "He");
	}

	printf("\tHistory of Present Illness\n");
	printf("%s, patient # %s is a %d-year old %s. ", Patient.namePatient, Patient.numPatient, Patient.agePatient, tempGender, pronoun);

	if (numPatientSymp == 0)
		printf("%s has no symptoms. ", pronoun);
	else if (numPatientSymp == 1)
		printf("%s has %s. ", pronoun, Symptoms[tempArray[0]-1].nameSymptom);
	else
	{
		printf("%s has ", pronoun);
		for (i = 0; i < numPatientSymp; i++)
		{
			tempIndex = tempArray[i] - 1;
			if (i == numPatientSymp - 1)
				printf("and %s. ", Symptoms[tempIndex].nameSymptom);
			else if (i == numPatientSymp - 2)
				printf("%s ", Symptoms[tempIndex].nameSymptom);
			else
				printf("%s, ", Symptoms[tempIndex].nameSymptom);
		}
	}

	numImp = PrintImpressions(tempImpArray, Impressions, Symptoms, tempArray, numPatientSymp, numImpressions);
	if (numImp == 0)
		printf("No impressions detected.\n");
	else if (numImp == 1)
		printf("Impression is %s", tempImpArray[0]);
	else
	{
		printf("Impressions are ");
		for (i = 0; i < numImp; i++)
		{
			if (i == numImp - 1)
				printf("and %s. \n", tempImpArray[i]);
			else if (i == numImp - 2)
				printf("%s ", tempImpArray[i]);
			else
				printf("%s, ", tempImpArray[i]);
		}
	}
	
	strcpy(tempFileName, Patient.numPatient);
	strcat(tempFileName, ".txt");

	FILE *fp;
	fp = fopen(tempFileName, "w");

	fprintf(fp, "\tHistory of Present Illness\n");
	fprintf(fp, "%s, patient # %s is a %d-year old %s. ", Patient.namePatient, Patient.numPatient, Patient.agePatient, tempGender, pronoun);

	if (numPatientSymp == 0)
		fprintf(fp, "%s has no symptoms. ", pronoun);
	else if (numPatientSymp == 1)
		fprintf(fp, "%s has %s. ", pronoun, Symptoms[tempArray[0]-1].nameSymptom);
	else
	{
		fprintf(fp, "%s has ", pronoun);
		for (i = 0; i < numPatientSymp; i++)
		{
			tempIndex = tempArray[i] - 1;
			if (i == numPatientSymp - 1)
				fprintf(fp, "and %s. ", Symptoms[tempIndex].nameSymptom);
			else if (i == numPatientSymp - 2)
				fprintf(fp, "%s ", Symptoms[tempIndex].nameSymptom);
			else
				fprintf(fp, "%s, ", Symptoms[tempIndex].nameSymptom);
		}
	}

	numImp = PrintImpressions(tempImpArray, Impressions, Symptoms, tempArray, numPatientSymp, numImpressions);
	if (numImp == 0)
		fprintf(fp, "No impressions detected.\n");
	else if (numImp == 1)
		fprintf(fp, "Impression is %s. ", tempImpArray[0]);
	else
	{
		fprintf(fp, "Impressions are ");
		for (i = 0; i < numImp; i++)
		{
			if (i == numImp - 1)
				fprintf(fp, "and %s. \n", tempImpArray[i]);
			else if (i == numImp - 2)
				fprintf(fp, "%s ", tempImpArray[i]);
			else
				fprintf(fp, "%s, ", tempImpArray[i]);
		}
	}
	fclose(fp);
	Sleep(10000);
	system("cls");
}

// FUNCTIONS for when the User chooses the FILIPINO language.
// Member contribution: Improvement of both solutions.

char 
DisplayMenuT()
{
	char choice;
	printf("\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |            MENYU #1 Mga User           |\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |            Mga Opsyon sa Menu          |\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |   D - para sa Doktor                   |\n");
	printf("\t\t   |   P - para sa Pasyente                 |\n");
	printf("\t\t   |   A - para sa Administrador            |\n");
	printf("\t\t   |   E - para mag-Exit                    |\n");
	printf("\t\t   +----------------------------------------+\n");

	printf("\n\t\t   Piliin ang nararapat na titik sa iyong uri: ");
	scanf(" %c", &choice);

	while (choice != 'D' && choice != 'd' && choice != 'P' && choice != 'p' && choice != 'A' && choice != 'a' && choice != 'E' && choice != 'e')
	{
		printf("\n\t\t   Mangyaring maglagay ng wastong titik.\n");
		printf("\n\t\t   Piliin ang nararapat na titik sa iyong uri: ");
		scanf(" %c", &choice);
	}
	Sleep(2000);
	system("cls");
	return choice;
}

char 
DocMenuT()
{
	char choice;
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |             MENYU #2 Doktor            |\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |  L - Mag-log in                        |\n");
	printf("\t\t   |  C - Lumikha ng bagong listahan        |\n");
	printf("\t\t   |      ng sintomas at impresyon          |\n");
	printf("\t\t   |  U - Gamitin ang kasalukuyang listahan |\n");
	printf("\t\t   |      ng sintomas at impresyon          |\n");
	printf("\t\t   |  D - Ipakita ang mga Sintomas          |\n");
	printf("\t\t   |  M - Baguhin ang mga Sintomas ng       |\n");
	printf("\t\t   |      Impression                        |\n");
	printf("\t\t   |  E - Bumalik sa Main Menyu             |\n");
	printf("\t\t   +----------------------------------------+\n");

	printf("\n\t\t   Piliin ang titik na iyong ninananis: ");
	scanf(" %c", &choice);

	while (choice != 'L' && choice != 'C' && choice != 'U' && choice != 'D' && choice != 'M' && choice != 'E' &&
		   choice != 'l' && choice != 'c' && choice != 'u' && choice != 'd' && choice != 'm' && choice != 'e')
	{
		printf("\t\t   Mangyaring maglagay ng wastong titik.\n");
		printf("\n\t\t   Piliin ang titik na iyong ninananis: ");
		scanf(" %c", &choice);
	}

	Sleep(2000);
	system("cls");

	printf("\n");
	return choice;
}

char 
AdminMenuT()
{
	char choice;
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |         MENYU #3 Administrador         |\n");
	printf("\t\t   +----------------------------------------+\n");
	printf("\t\t   |  L - Mag-log in                        |\n");
	printf("\t\t   |  D - Lumikha ng bagong mga kredensyal  |\n");
	printf("\t\t   |      ng log-in para sa Doktor          |\n");
	printf("\t\t   |  U - Lumikha ng bagong mga kredensyal  |\n");
	printf("\t\t   |      ng log-in para sa User            |\n");
	printf("\t\t   |  O - Ipakita ang listahan ng mga       |\n");
	printf("\t\t   |      kredensyal ng log-in ng mga Doktor|\n");
	printf("\t\t   |  S - Ipakita ang listahan ng mga       |\n");
	printf("\t\t   |      kredensyal ng log-in ng mga User  |\n");
	printf("\t\t   |  E - Lumabas                           |\n");
	printf("\t\t   +----------------------------------------+\n");

	printf("\n\t\t   Piliin ang titik na iyong ninananis: ");
	scanf(" %c", &choice);

	while (choice != 'L' && choice != 'D' && choice != 'U' && choice != 'O' && choice != 'S' && choice != 'E' &&
		   choice != 'l' && choice != 'd' && choice != 'u' && choice != 'o' && choice != 's' && choice != 'e')
	{
		printf("\t\t   Mangyaring maglagay ng wastong titik.\n");
		printf("\n\t\t   Piliin ang titik na iyong ninananis: ");
		scanf("  %c", &choice);
	}

	Sleep(2000);
	system("cls");

	return choice;
}

int 
VerifyLoginT(String15 fileName,
			String5 ID,
			String10 Password)
{
	FILE *fp;
	String5 compID;
	String10 compPassword;

	fp = fopen(fileName, "r");

	while (fscanf(fp, "%s %s", compID, compPassword) == 2)
	{
		if (strcmp(compID, ID) == 0 && strcmp(compPassword, Password) == 0)
			return 1;
	}

	fclose(fp);

	return 0;
}

int 
LoginT(String15 fileName,
		String5 *ID,
		String10 *Password)
{
	int verify = 0;
	int flag = 0;
	char choice;

	printf("\nIlagay ang iyong ID: ");
	scanf(" %s", ID);

	printf("Ilagay ang iyong password: ");
	scanf(" %s", Password);

	verify = VerifyLoginT(fileName, *ID, *Password);

	while (verify != 1 && flag == 0)
	{
		printf("\nMali ang ID o Password. \n");
		printf("Subukan ulit? Oo (O) o Hindi (H)\n");
		scanf(" %c", &choice);
		if (choice == 'O' || choice == 'o')
		{
			printf("\nIlagay ang iyong ID: ");
			scanf(" %s", ID);

			printf("Ilagay ang iyong password: ");
			scanf(" %s", Password);

			verify = VerifyLogin(fileName, *ID, *Password);
		}
		else
			flag = 1;
	}

	if (verify == 1)
		printf("Matagumpay na nakalog-in!\n");

	return verify;
}

void 
appendIDT(String15 fileName,
		String5 ID,
		String10 Password)
{
	FILE *fp;
	fp = fopen(fileName, "a");
	fprintf(fp, "\n%s %s", ID, Password);

	fclose(fp);
}

void 
addIDT(String15 fileName,
		String15 userName)
{
	char *tempID = malloc(6 * sizeof(char));
	char *tempPass = malloc(11 * sizeof(char));

	int invalid = 0;
	int invalid1 = 0;
	int i;

	do
	{
		invalid = 0;
		printf("Ilagay ang ID# ni %s (Hanggang sa 5 bilang lamang): ", userName);
		scanf(" %s", tempID);

		// check if valid ID
		if (strlen(tempID) <= 5)
		{
			for (i = 0; i < strlen(tempID); i++)
			{
				if (tempID[i] < 48 || tempID[i] > 57)
					invalid = 1;
			}
		}
		else
			invalid = 1;

		if (invalid)
			printf("Hindi wasto ang ID. Subukan ulit.\n");

	} while (invalid);

	do
	{
		invalid1 = 0;
		i = 0;
		printf("Ilagay ang Password (Hanggang sa 10 na karakter): ");
		scanf(" %s", tempPass);

		// check if valid Password
		if (strlen(tempPass) <= 10)
		{
			while (invalid1 != 1 && i < strlen(tempPass))
			{
				if (tempPass[i] < 48 || (tempPass[i] > 57 && tempPass[i] < 65) || (tempPass[i] > 90 && tempPass[i] < 97) || tempPass[i] > 122)
					invalid1 = 1;
				else
					i++;
			}
		}
		else
			invalid1 = 1;

		if (invalid1)
			printf("Hindi wasto ang Password. Subukan ulit.\n");

	} while (invalid1);

	appendIDT(fileName, tempID, tempPass);

	free(tempID);
	free(tempPass);
}

void 
displayIDsT(String15 fileName,
			String15 userName)
{
	FILE *fp;
	String5 tempID;
	String10 tempPass;
	int count = 1;

	fp = fopen(fileName, "r");
	while (fscanf(fp, "%s %s", tempID, tempPass) == 2)
	{
		printf("%s %d: \n", userName, count);
		printf("ID#: %s\tPassword: %s\n\n", tempID, tempPass);

		count++;
	}
	fclose(fp);
}

int 
administratorFunctionT()
{
	char AdminChoice;
	int flag = 0, adminVerified = 0;
	String5 AdminID;
	String10 AdminPassword;

	while (!flag)
	{
		AdminChoice = AdminMenuT();
		switch (AdminChoice)
		{
		case 'L':
		case 'l':
			adminVerified = LoginT("Administrators.txt", &AdminID, &AdminPassword);
			break;
		case 'D':
		case 'd':
			if (adminVerified)
			{
				addIDT("Doctors.txt", "Doctor");
			}
			else
				printf("Mangyaring mag-log in muna upang ma-unlock ang feature na ito.\n");
			break;
		case 'U':
		case 'u':
			if (adminVerified)
			{
				addIDT("Patients.txt", "Patient");
			}
			else
				printf("Mangyaring mag-log in muna upang ma-unlock ang feature na ito.\n");
			break;
		case 'O':
		case 'o':
			if (adminVerified)
			{
				displayIDsT("Doctors.txt", "Doctor");
			}
			else
				printf("Mangyaring mag-log in muna upang ma-unlock ang feature na ito.\n");
			break;
		case 'S':
		case 's':
			if (adminVerified)
			{
				displayIDsT("Patients.txt", "Patient");
			}
			else
				printf("Mangyaring mag-log in muna upang ma-unlock ang feature na ito.\n");
			break;
		case 'E':
		case 'e':
			flag = 1;
			break;
		}
	}

	return flag;
}

void 
InputSymptomsFileT(String15 fileName,
					SymptomType Symptoms[MAX_SYMPTOMS],
					int numSymptoms)
{
	FILE *fp;
	int i;
	fp = fopen(fileName, "w");

	fprintf(fp, "%d\n", numSymptoms);
	for (i = 0; i < numSymptoms; i++)
	{
		fprintf(fp, "%d\n", i + 1);
		fprintf(fp, "%s\n%s\n", Symptoms[i].nameSymptom, Symptoms[i].questionSymptom);
	}

	fclose(fp);
}

int 
InputSymptomsT(SymptomType Symptoms[MAX_SYMPTOMS])
{
	int i;
	int numSymptoms;

	do
	{
		printf("Ilang sintomas ang gusto mong isaalang-alang? (Hanggang 20 lamang)\n");
		scanf(" %d", &numSymptoms);
	} while (numSymptoms > 20);

	for (i = 0; i < numSymptoms; i++)
	{
		printf("\nAno ang sintomas? ");
		scanf(" %[^\n]s", Symptoms[i].nameSymptom);

		printf("\nPaano mo gustong itanong ang sintomas? \n");
		scanf(" %[^\n]s", Symptoms[i].questionSymptom);
	}

	InputSymptomsFileT("symptomsTagalog.txt", Symptoms, numSymptoms);
	return numSymptoms;
}

void 
displaySymptomsT(SymptomType Symptoms[MAX_SYMPTOMS],
				int numSymptoms)
{
	int j;
	for (j = 0; j < numSymptoms; j++)
	{
		printf("%d. %s\n", j + 1, Symptoms[j].nameSymptom);
	}
}

void 
displayImpressionsT(ImpressionType Impressions[MAX_IMPRESSIONS],
					SymptomType Symptom[MAX_SYMPTOMS],
					int numImpressions)
{
	int j, i;
	int index;
	for (j = 0; j < numImpressions; j++)
	{
		printf("Impresyon #%d: %s", j + 1, Impressions[i].nameIllness);
		for (i = 0; i < Impressions[i].numSymptoms; j++)
		{
			index = Impressions[j].Symptom[i];
			printf("%d. %s\n", i + 1, Symptom[index].nameSymptom);
		}
	}
}

void 
InputImpressionsFileT(String50 fileName,
					ImpressionType Impressions[MAX_IMPRESSIONS],
					int numImpressions)
{
	FILE *fp;
	int i, j;
	fp = fopen(fileName, "w");

	fprintf(fp, "%d\n", numImpressions);
	for (i = 0; i < numImpressions; i++)
	{
		fprintf(fp, "#%d\n", i + 1);
		fprintf(fp, "%s\n", Impressions[i].nameIllness);
		for (j = 0; j < Impressions[i].numSymptoms; j++)
		{
			fprintf(fp, "%d\n", Impressions[i].Symptom[j]);
		}
	}

	fclose(fp);
}

int 
InputImpressionsT(ImpressionType Impressions[MAX_IMPRESSIONS],
				SymptomType Symptoms[MAX_SYMPTOMS],
				int numSymptoms)
{
	int numImpressions, numPresentSymptoms;
	int i, j, temp;

	do
	{
		printf("Ilang impresyon ang gusto mong ilagay? (Hanggang 20 lamang): ");
		scanf(" %d", &numImpressions);
		if (numImpressions > MAX_IMPRESSIONS)
		{
			printf("Mangyaring maglagay ng bilang na mas mababa o katumbas ng %d.\n", MAX_IMPRESSIONS);
		}
	} while (numImpressions > MAX_IMPRESSIONS);

	for (i = 0; i < numImpressions; i++)
	{
		printf("Impresyon #%d:\n", i + 1);
		printf("Anong karamdaman ito? ");
		scanf(" %[^\n]", Impressions[i].nameIllness);

		// display list of symptoms
		displaySymptomsT(Symptoms, numSymptoms);

		do
		{
			printf("\nMangyaring ipaalam, ilan sa mga nabanggit na sintomas sa itaas ang nararanasan sa karamdaman na %s? (Hanggang %d)\n", Impressions[i].nameIllness, numSymptoms);
			scanf(" %d", &numPresentSymptoms);
			if (numPresentSymptoms > numSymptoms)
			{
				printf("Mangyaring maglagay ng bilang na mas mababa o katumbas ng %d.\n", numSymptoms);
			}
		} while (numPresentSymptoms > numSymptoms);

		Impressions[i].numSymptoms = numPresentSymptoms;

		// copy symptom name to [impression] symptom list
		printf("Mangyaring maglagay ng korespondeng bilang para sa bawat sintomas. \n");
		for (j = 0; j < Impressions[i].numSymptoms; j++)
		{
			scanf(" %d", &temp);
			Impressions[i].Symptom[j] = temp;
		}
	}
	InputImpressionsFileT("impressionsTagalog.txt", Impressions, numImpressions);
	return numImpressions;
}

int 
ExistingSymptomsT(String15 fileName,
				SymptomType Symptoms[MAX_SYMPTOMS])
{
	FILE *fp;
	int i = 0;
	int count;
	int numSymptoms;
	fp = fopen(fileName, "r");

	fscanf(fp, "%d", &numSymptoms);
	while (fscanf(fp, "%d %[^\n] %[^\n]", &count, Symptoms[i].nameSymptom, Symptoms[i].questionSymptom) == 3)
	{
		i++;
	}

	fclose(fp);
	// InputSymptomsFile("TESTSymptoms.txt", Symptoms, numSymptoms); //test output
	return numSymptoms;
}

int 
UseExistingImpressionsT(ImpressionType Impressions[MAX_IMPRESSIONS],
						String15 fileName)
{
	int i = 0, j = 0, temp;
	String5 count;
	int numImpressions;
	FILE *fp;
	fp = fopen(fileName, "r");

	fscanf(fp, " %d", &numImpressions);

	for (i = 0; i < numImpressions; i++)
	{
		Impressions[i].numSymptoms = 0;
		fscanf(fp, " %s", count);
		fscanf(fp, " %[^\n]", Impressions[i].nameIllness);
		j = 0;
		while (fscanf(fp, " %d", &temp) == 1)
		{
			Impressions[i].Symptom[j] = temp;
			Impressions[i].numSymptoms += 1;
			j++;
		}
	}

	// InputImpressionsFile("TESTImpressions.txt", Impressions, numImpressions); //test output
	fclose(fp);
	return numImpressions;
}

void 
DisplayImpressionT(ImpressionType Impressions[MAX_IMPRESSIONS],
					SymptomType Symptoms[MAX_SYMPTOMS],
					int numImpressions)
{
	int i = 0, j, found = 0, impNum, temp, n;
	String50 tempName;

	printf("Ano and impresyon? ");
	scanf(" %[^\n]", tempName);

	while (i < numImpressions && found == 0)
	{
		if (strcmp(tempName, Impressions[i].nameIllness) == 0)
		{
			impNum = i;
			found = 1;
		}
		i++;
	}

	if (found != 1)
	{
		printf("Ang impresyon ay hindi nahanap.\n");
	}
	else
	{
		n = Impressions[impNum].numSymptoms;
		printf("\n\t\t\t   Ang sintomas ng %s ay: \n", Impressions[impNum].nameIllness);
		for (j = 0; j < n; j++)
		{
			temp = Impressions[impNum].Symptom[j];
			printf("\t\t\t\t  %d. %s\n", j+1, Symptoms[temp - 1].nameSymptom);
		}
	}
}

void 
ModifyImpressionT(String50 fileName,
				ImpressionType Impressions[MAX_IMPRESSIONS],
				int numImpressions,
				SymptomType Symptoms[MAX_SYMPTOMS],
				int numSymptoms)
{
	String50 input_impression;
	int i = 0, j, numPresentSymptoms, temp;

	printf("Ano and impresyon? ");
	scanf(" %[^\n]", input_impression);

	while (i < numImpressions && strcmp(input_impression, Impressions[i].nameIllness) != 0)
	{
		// If the input impression is not found, move on to the next impression
		i++;
	}

	if (i == numImpressions)
	{
		// If the impression is not found in the array, print an error message and return
		printf("Ang impresyon ay hindi nahanap.\n");
		return;
	}

	// Print the symptoms of the selected impression
	printf("Ang sintomas ng %s ay: \n", Impressions[i].nameIllness);
	for (j = 0; j < Impressions[i].numSymptoms; j++)
	{
		printf("\t%s\n", Symptoms[Impressions[i].Symptom[j] - 1].nameSymptom);
	}

	// Ask the user to modify the symptoms
	printf("\nMaaring mong baguhin ang mga sintomas ng %s. Narito ang listahan ng mga sintomas: \n", Impressions[i].nameIllness);
	displaySymptomsT(Symptoms, numSymptoms);

	printf("\n\nMangyaring ipaalam, ilan sa mga nabanggit na sintomas sa itaas ang nararanasan sa karamdaman na %s?\n", Impressions[i].nameIllness);
	scanf("%d", &numPresentSymptoms);
	Impressions[i].numSymptoms = numPresentSymptoms;

	printf("Mangyaring maglagay ng korespondeng bilang para sa bawat sintomas. \n");
	for (j = 0; j < Impressions[i].numSymptoms; j++)
	{
		scanf("%d", &temp);
		Impressions[i].Symptom[j] = temp; // Subtract 1 to convert from 1-based indexing to 0-based indexing
	}

	// Print the updated symptoms of the selected impression
	printf("\nNarito and mga bagong sintomas para sa %s:\n", Impressions[i].nameIllness);
	for (j = 0; j < Impressions[i].numSymptoms; j++)
	{
		temp = Impressions[i].Symptom[j];
		printf("%d. %s\n", j + 1, Symptoms[temp - 1].nameSymptom);
	}

	// Write the updated data back to the input file
	InputImpressionsFileT("impressionsTagalog.txt", Impressions, numImpressions);
}

int 
doctorFunctionT(SymptomType Symptoms[MAX_SYMPTOMS],
				ImpressionType Impressions[MAX_IMPRESSIONS],
				int *numSymptomsRETURN,
				int *numImpressionsRETURN)
{
	int DocChoice;
	int docVerified;
	String5 DocID;
	String10 DocPassword;
	int flag = 0;
	int numSymptoms = 0, numImpressions = 0;

	while (!flag)
	{
		DocChoice = DocMenuT();
		switch (DocChoice)
		{
		case 'L':
		case 'l':
			docVerified = LoginT("Doctors.txt", &DocID, &DocPassword);
			break;
		case 'C':
		case 'c':
			if (docVerified == 1)
			{
				numSymptoms = InputSymptomsT(Symptoms);
				numImpressions = InputImpressionsT(Impressions, Symptoms, numSymptoms);
			}
			else
				printf("Mangyaring mag-log in muna upang ma-unlock ang feature na ito.\n");
			break;
		case 'U':
		case 'u':
			if (docVerified == 1)
			{
				numSymptoms = ExistingSymptomsT("symptomsTagalog.txt", Symptoms);
				numImpressions = UseExistingImpressionsT(Impressions, "impressionsTagalog.txt");
				printf("\nMatagumpay na nakuha ang impormasyon para sa mga sintomas at impresyon.\n");
				flag = 1;
			}
			else
				printf("Mangyaring mag-log in muna upang ma-unlock ang feature na ito.\n");
			break;
		case 'D':
		case 'd':
			if (docVerified == 1)
			{
				if (numSymptoms > 0 && numImpressions > 0)
					DisplayImpressionT(Impressions, Symptoms, numImpressions);
				else
					printf("Walang mga datos para sa mga sintomas at impresyon. Maaari mong gamitin ang C o U muna.\n");
			}
			else
				printf("Mangyaring mag-log in muna upang ma-unlock ang feature na ito.\n");
			break;
		case 'M':
		case 'm':
			if (docVerified == 1)
			{
				if (numSymptoms > 0 && numImpressions > 0)
					ModifyImpressionT("impressionsTagalog.txt", Impressions, numImpressions, Symptoms, numSymptoms);
				else
					printf("Walang mga datos para sa mga sintomas at impresyon. Maaari mong gamitin ang C o U muna.\n");
			}
			else
				printf("Mangyaring mag-log in muna upang ma-unlock ang feature na ito.\n");
			break;
		case 'E':
		case 'e':
			flag = 1;
			break;
		}
	}

	*numSymptomsRETURN = numSymptoms;
	*numImpressionsRETURN = numImpressions;

	return flag;
}

void 
EnterPatientInfoT(PatientType *Patient)
{
	printf("\nAno po ang inyong pangalan? ");
	scanf(" %[^\n]", Patient->namePatient);

	printf("\nAno po ang inyong ID bilang pasyente: ");
	scanf(" %s", Patient->numPatient);

	do
	{
		printf("\nIlang taong gulang? ");
		scanf(" %d", &Patient->agePatient);
		if (Patient->agePatient > 100 || Patient->agePatient < 0)
			printf("Ilagay ang wastong kasarian.\n");
	} while (Patient->agePatient > 100 || Patient->agePatient < 0);

	do
	{
		printf("\nKasarian (L/B): ");
		scanf("  %c", &Patient->genderPatient);
		if (Patient->genderPatient != 'B' && Patient->genderPatient != 'b' && Patient->genderPatient != 'L' && Patient->genderPatient != 'l')
			printf("Ilagay ang wastong edad. \n");
	} while (Patient->genderPatient != 'B' && Patient->genderPatient != 'b' && Patient->genderPatient != 'L' && Patient->genderPatient != 'l');
}

int 
QuestionsT(SymptomType Symptoms[MAX_SYMPTOMS],
			int numSymptoms,
			int tempArray[MAX_SYMPTOMS])
{
	int i, ctr = 0;
	char patientChoice;
	for (i = 0; i < numSymptoms; i++)
	{
		do
		{
			printf("%s (O/H)\n", Symptoms[i].questionSymptom);
			scanf(" %c", &patientChoice);
			if (patientChoice != 'O' && patientChoice != 'o' && patientChoice != 'H' && patientChoice != 'h')
				printf("Ilagay ang wastong titik (O/H).\n");
		} while (patientChoice != 'O' && patientChoice != 'o' && patientChoice != 'H' && patientChoice != 'h');

		if (patientChoice == 'O' || patientChoice == 'o')
		{
			tempArray[ctr] = i + 1;
			ctr++;
		}
	}
	return ctr;
}

int 
linearSearchT(int n,
			int array2[MAX_SYMPTOMS],
			int numArray2)
{
	int found = 0;
	int i = 0;

	while (found == 0 && i < numArray2)
	{
		if (array2[i] == n)
		{
			found = 1;
		}
		i++;
	}

	return found;
}

int 
PrintImpressionsT(String50 tempImpArray[MAX_IMPRESSIONS],
				ImpressionType Impressions[MAX_IMPRESSIONS],
				SymptomType Symptoms[MAX_SYMPTOMS],
				int tempArray[MAX_SYMPTOMS],
				int numPatientSymp,
				int numImpressions)
{
	int i, j, k = 0;
	int counter = 0;

	for (i = 0; i < numImpressions; i++)
	{
		counter = 0;

		for (j = 0; j < numPatientSymp; j++)
		{
			counter += linearSearchT(tempArray[j], Impressions[i].Symptom, Impressions[i].numSymptoms);
		}

		if (Impressions[i].numSymptoms <= 3)
		{
			if (counter == Impressions[i].numSymptoms)
			{
				strcpy(tempImpArray[k], Impressions[i].nameIllness);
				k++;
			}
		}
		else if (Impressions[i].numSymptoms > 3)
		{
			if (counter >= 3)
			{
				strcpy(tempImpArray[k], Impressions[i].nameIllness);
				k++;
			}
		}
	}

	return k;
}

void 
DisplayHPIT(PatientType Patient,
			int numPatientSymp,
			SymptomType Symptoms[MAX_SYMPTOMS],
			ImpressionType Impressions[MAX_IMPRESSIONS],
			int tempArray[MAX_SYMPTOMS],
			int numImpressions)
{
	String15 tempFileName;
	String10 tempGender;
	String5 pronoun;
	String50 tempImpArray[MAX_IMPRESSIONS];
	int numImp, tempIndex;
	int i;

	if (Patient.genderPatient == 'B' || Patient.genderPatient == 'b')
	{
		strcpy(tempGender, "babae");
		strcpy(pronoun, "Siya");
	}

	else
	{
		strcpy(tempGender, "lalaki");
		strcpy(pronoun, "Siya");
	}

	printf("\tKasaysayan ng Kasalukuyang Kalagayan ng Sakit\n");
	printf("Si %s, ay isang pasyente na may ID# %s na %d-taong gulang na %s. ", Patient.namePatient, Patient.numPatient, Patient.agePatient, tempGender, pronoun);

	if (numPatientSymp == 0)
		printf("Siya ay walang nararamdaman na sintomas. ");
	else if (numPatientSymp == 1)
	{
		printf("%s ay may sintomas na ", pronoun);
		printf("%s. ", Symptoms[tempArray[0]-1].nameSymptom);
	}
	else
	{
		printf("%s ay may sintomas na ", pronoun);
		for (i = 0; i < numPatientSymp; i++)
		{
			tempIndex = tempArray[i] - 1;
			if (i == numPatientSymp - 1)
				printf("at %s. ", Symptoms[tempIndex].nameSymptom);
			else if (i == numPatientSymp - 2)
				printf("%s ", Symptoms[tempIndex].nameSymptom);
			else
				printf("%s, ", Symptoms[tempIndex].nameSymptom);
		}
	}

	numImp = PrintImpressionsT(tempImpArray, Impressions, Symptoms, tempArray, numPatientSymp, numImpressions);
	if (numImp == 0)
		printf("Walang naiulat na impresyon.\n");
	else if (numImp == 1)
		printf("Ang naiulat na impresyon ay %s.", tempImpArray[0]);
	else
	{
		printf("Ang mga naiulat na impresyon ay ");
		for (i = 0; i < numImp; i++)
		{
			if (i == numImp - 1)
				printf("at %s. \n", tempImpArray[i]);
			else if (i == numImp - 2)
				printf("%s ", tempImpArray[i]);
			else
				printf("%s, ", tempImpArray[i]);
		}
	}

	strcpy(tempFileName, Patient.numPatient);
	strcat(tempFileName, ".txt");

	FILE *fp;
	fp = fopen(tempFileName, "w");

	fprintf(fp, "\tKasaysayan ng Kasalukuyang Kalagayan ng Sakit\n");
	fprintf(fp, "%s, pasyente # %s ay isang %d taong gulang na %s. ", Patient.namePatient, Patient.numPatient, Patient.agePatient, tempGender, pronoun);

	if (numPatientSymp == 0)
		fprintf(fp, "Siya ay walang nararamdaman na sintomas. ");
	else if (numPatientSymp == 1)
	{
		fprintf(fp, "%s ay may sintomas na ", pronoun);
		fprintf(fp, "%s.", Symptoms[0].nameSymptom);
	}
	else
	{
		fprintf(fp, "%s ay may sintomas na ", pronoun);
		for (i = 0; i < numPatientSymp; i++)
		{
			tempIndex = tempArray[i];
			if (i == numPatientSymp - 1)
				fprintf(fp, "at %s. ", Symptoms[tempIndex].nameSymptom);
			else if (i == numPatientSymp - 2)
				fprintf(fp, "%s ", Symptoms[tempIndex].nameSymptom);
			else
				fprintf(fp, "%s, ", Symptoms[tempIndex].nameSymptom);
		}
	}

	numImp = PrintImpressionsT(tempImpArray, Impressions, Symptoms, tempArray, numPatientSymp, numImpressions);
	if (numImp == 0)
		fprintf(fp, "Walang naiulat na impresyon.\n");
	else if (numImp == 1)
		fprintf(fp, "Ang naiulat na impresyon ay %s.", tempImpArray[0]);
	else
	{
		fprintf(fp, "Ang mga impresyon ay ");
		for (i = 0; i < numImp; i++)
		{
			if (i == numImp - 1)
				fprintf(fp, "at %s. \n", tempImpArray[i]);
			else if (i == numImp - 2)
				fprintf(fp, "%s ", tempImpArray[i]);
			else
				fprintf(fp, "%s, ", tempImpArray[i]);
		}
	}
	fclose(fp);
	Sleep(10000);
	system("cls");
}
