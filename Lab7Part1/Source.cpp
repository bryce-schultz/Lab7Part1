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
void calculateIndAverageAndGrade(float testScores[][3],  float indsAverage[], char letterGrade[], int studentCounter);
void calculateOverallAverage(float indsAverage[], int studentCounter, float &overallClassAverage);
void printReport(int id[], float testScores[][3], float indsAverage[], char letterGrade[], float classAverage, int numberOfStudents);
void printTitleAndHeading();
void printIndInfo(int id[], float testScores[][3], float indsAverage[], char letterGrade[], int numberOfStudents);
void printTotalAndClassAverage(int numberOfStudents, float classAverage);

int main() {
	int id[MAX_STUDENTS];
	float testScores[MAX_STUDENTS][3];
	float indsAverage[MAX_STUDENTS];
	char letterGrade[MAX_STUDENTS];
	float classAverage = 0.0f;
	int studentCounter = 0;

	inputData(id, testScores, studentCounter);
	processData(testScores, indsAverage, letterGrade, studentCounter, classAverage);
	printReport(id, testScores, indsAverage, letterGrade, classAverage, studentCounter);

	cin.ignore(2);
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

void processData(float testScores[][3], float indsAvergae[], char letterGrade[], int studentCounter, float &overallClassAverage) {
	calculateIndAverageAndGrade(testScores, indsAvergae, letterGrade, studentCounter);
	calculateOverallAverage(indsAvergae, studentCounter, overallClassAverage);
}

void calculateIndAverageAndGrade(float testScores[][3], float indsAverage[], char letterGrade[], int studentCounter) {
	for (int i = 0; i < studentCounter; i++) {
		indsAverage[i] = (testScores[i][0] + testScores[i][1] + testScores[i][2]) / 3;

		if (indsAverage[i] >= A_GRADE) letterGrade[i] = 'A';
		else if (indsAverage[i] >= B_GRADE) letterGrade[i] = 'B';
		else if (indsAverage[i] >= C_GRADE) letterGrade[i] = 'C';
		else if (indsAverage[i] >= D_GRADE) letterGrade[i] = 'D';
		else letterGrade[i] = 'F';
	}
}

void calculateOverallAverage(float indsAverage[], int studentCounter, float &overallClassAverage) {
	float totalAverages = 0.0f;

	for (int i = 0; i < studentCounter; i++) {
		totalAverages += indsAverage[i];
	}
	overallClassAverage = totalAverages / studentCounter;
}

void printReport(int id[], float testScores[][3], float indsAverage[], char letterGrade[], float classAverage, int numberOfStudents) {
	printTitleAndHeading();
	printIndInfo(id, testScores, indsAverage, letterGrade, numberOfStudents);
	printTotalAndClassAverage(numberOfStudents, classAverage);
}

void printTitleAndHeading() {
	cout << "\t\t ** Welcome to the Grader Program ** \n";
	cout << "ID \tQuiz 1 \tQuiz 2 \tQuiz 3 \tAverage \tGrade \n\n";
}

void printIndInfo(int id[], float testScores[][3], float indsAverage[], char letterGrade[], int numberOfStudents) {
	cout << setprecision(3);
	for (int i = 0; i < numberOfStudents; i++) {
		cout << "\n" << id[i] << "\t" << testScores[i][0] << "\t" << testScores[i][1] << "\t" << testScores[i][2] << "\t" << indsAverage[i] << "\t\t" << letterGrade[i] << "\n";
	}
}

void printTotalAndClassAverage(int numberOfStudents, float classAverage) {
	cout << "\n\n** Number of Students: " << numberOfStudents << " Overall Class Average: " << classAverage << " **\n";
}
