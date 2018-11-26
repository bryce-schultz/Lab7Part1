#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <stdio.h>

using namespace std;

//constants
const float A_GRADE = 92.0f;
const float B_GRADE = 84.0f;
const float C_GRADE = 75.0f;
const float D_GRADE = 65.0f;
const int MAX_STUDENTS = 20;

//function prototypes
void inputData(int id[], float testScores[][3], int &studentCounter);
void processData(float testScores[][3], float indsAvergae[], char letterGrade[], int studentCounter, float &overallClassAverage);
void calculateIndAverageAndGrade(float testScores[][3],  float indsAverage[], char letterGrade[], int counter);
void calculateOverallAverage(float indsAverage[], int studentCounter, float &overallClassAverage);
void printReport(int id[], float testScores[][3], float indsAverage[], char letterGrade[], float classAverage, int numberOfStudents);
void printTitleAndHeading();
void printIndInfo(int id[], float testScores[][3], float indsAveragep[], char letterGrade[], int numberOfStudents);
void printTotalAndClassAverage(int numberOfStudents, float classAverage);

int main() {
	int id[MAX_STUDENTS];
	float testScores[MAX_STUDENTS][3];
	float indsAverage[MAX_STUDENTS];
	char letterGrade[MAX_STUDENTS];
	float classAverage = 0.0f;
	int studentCounter = 0;

	inputData(id, testScores, studentCounter);
	//processData(testScores, indsAverage, letterGrade, studentCounter, classAverage);
	//printReport(id, testScores, indsAverage, letterGrade, classAverage, studentCounter);

	cin.ignore();
	return 0;
}

void inputData(int id[], float testScores[][3], int &studentCounter) {
	char again = 'Y';
	cout << "Enter student data (y/n)? ";
	cin >> again;
	again = toupper(again);

	while (again == 'Y' && studentCounter < MAX_STUDENTS) {
		cout << "\nEnter in student id: ";
		cin >> id[studentCounter];

		cout << "\nEnter 3 exam scores: ";
		cin >> testScores[studentCounter][0] >> testScores[studentCounter][1] >> testScores[studentCounter][2];

		studentCounter++;
		cout << "\nDo another (y/n)? ";
		cin >> again;
		again = toupper(again);
	}
}

//TODO: implement the process dataFunction, Pg. 358







void processData(float testScores[][3], float indsAvergae[], char letterGrade[], int studentCounter, float &overallClassAverage);
void calculateIndAverageAndGrade(float testScores[][3], float indsAverage[], char letterGrade[], int counter);
void calculateOverallAverage(float indsAverage[], int studentCounter, float &overallClassAverage);
void printReport(int id[], float testScores[][3], float indsAverage[], char letterGrade[], float classAverage, int numberOfStudents);
void printTitleAndHeading();
void printIndInfo(int id[], float testScores[][3], float indsAveragep[], char letterGrade[], int numberOfStudents);
void printTotalAndClassAverage(int numberOfStudents, float classAverage);
