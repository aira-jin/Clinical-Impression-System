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
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "delRosarioJGarganeraA_functions.c"

//

int main()
{
	char UserType, DocChoice, PatientChoice, AdminChoice;
	int exit, docFlag, patientFlag, adminFlag;
	int docVerified, adminVerified;
	IDPassType docID, adminID;
	int numSymptoms = 0, numImpressions = 0;
	ImpressionType Impressions[MAX_IMPRESSIONS];
	SymptomType Symptoms[MAX_SYMPTOMS];

	int patientVerified, tempArray[MAX_SYMPTOMS], numPatientSymp, i;
	char patientChoice = 1;
	String5 patientID;
	String10 patientPass;
	PatientType Patient;
	int numImp;
	String50 tempImpArray[MAX_IMPRESSIONS];
	String50 space = "\t\t\t";
	String50 space2 = "\t\t\t\t";
	String50 space3 = "\t\t   ";

	char lang;
	int langexit;

	do
	{
		 LoadingScreen();

		printf("%s+----------------------------------------+\n", space3);
		printf("%s|            Language Options            |\n", space3);
		printf("%s+----------------------------------------+\n", space3);
		printf("%s|   E - English                          |\n", space3);
		printf("%s|   F - Filipino                         |\n", space3);
		printf("%s+----------------------------------------+\n", space3);

		printf("\n\t\t   Enter your choice: ", space);
		scanf(" %c", &lang);

		switch (lang)
		{
		case 'E':
		case 'e':
			printf("\n\t\t   English language selected\n");
			Sleep(3000);
			system("cls");

			do
			{

				UserType = DisplayMenu();
				switch (UserType)
				{
				case 'D':
				case 'd':
					do
					{
						docFlag = doctorFunction(Symptoms, Impressions, &numSymptoms, &numImpressions);
					} while (!docFlag);

					break;
				case 'P':
				case 'p':
					PatientChoice = 1;
					switch (PatientChoice)
					{
					case 1:
						numSymptoms = ExistingSymptoms("Symptoms.txt", Symptoms);
						numImpressions = UseExistingImpressions(Impressions, "Impressions.txt");

						patientVerified = Login("Patients.txt", &patientID, &patientPass);
						if (patientVerified != 1)
							break;
					case 2:
						EnterPatientInfo(&Patient);
					case 3:
						numPatientSymp = Questions(Symptoms, numSymptoms, tempArray);
					case 4:
						DisplayHPI(Patient, numPatientSymp, Symptoms, Impressions, tempArray, numImpressions);
					case 5:
						break;
					}
					break;
				case 'A':
				case 'a':
					do
					{
						adminFlag = administratorFunction();
					} while (!adminFlag);
					break;
				case 'E':
				case 'e':
					exit = 1;
					break;
				}

			} while (exit != 1);

			break;
		case 'F':
		case 'f':
			printf("\n\t\t   Tagalog ang lenguwahe na iyong napili.");
			Sleep(3000);
			system("cls");
			do
			{

				UserType = DisplayMenuT();
				switch (UserType)
				{
				case 'D':
				case 'd':
					do
					{
						docFlag = doctorFunctionT(Symptoms, Impressions, &numSymptoms, &numImpressions);
					} while (!docFlag);

					break;
				case 'P':
				case 'p':
					numSymptoms = ExistingSymptomsT("symptomsTagalog.txt", Symptoms);
					numImpressions = UseExistingImpressionsT(Impressions, "impressionsTagalog.txt");

					PatientChoice = 1;
					switch (PatientChoice)
					{
					case 1:
						patientVerified = LoginT("Patients.txt", &patientID, &patientPass);
						if (patientVerified != 1)
							break;
					case 2:
						EnterPatientInfoT(&Patient);
					case 3:
						numPatientSymp = QuestionsT(Symptoms, numSymptoms, tempArray);
					case 4:

						DisplayHPIT(Patient, numPatientSymp, Symptoms, Impressions, tempArray, numImpressions);
					case 5:
						break;
					}
					break;
				case 'A':
				case 'a':
					do
					{
						adminFlag = administratorFunctionT();
					} while (!adminFlag);
					break;
				case 'E':
				case 'e':
					exit = 1;
					break;
				}
			} while (exit != 1);
		break;
		default: {
			system("cls");
			printf("%sInvalid choice.\n", space3);
		}
	}
			
} while (lang != 'E' && lang != 'e' && lang != 'F' && lang != 'f');

	return 0;
}
