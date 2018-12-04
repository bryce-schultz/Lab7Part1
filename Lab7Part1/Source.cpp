/*
Bryce Schultz
CS 133U
11/30/2018

Description: the program allows you to enter grades for students then view the data with a visual.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

//constants
const float A_GRADE = 92.0f;
const float B_GRADE = 84.0f;
const float C_GRADE = 75.0f;
const float D_GRADE = 65.0f;
const int MAX_STUDENTS = 20;

//function prototypes
void inputData(int id[], float testScores[][3], int &studentCounter);
void processData(float testScores[][3], float indsAvergae[], char letterGrade[], int studentCounter, float &overallClassAverage, int numberOfGrades[]);
void calculateIndAverageAndGrade(float testScores[][3],  float indsAverage[], char letterGrade[], int studentCounter);
void calculateOverallAverage(float indsAverage[], int studentCounter, float &overallClassAverage);
void printReport(int id[], float testScores[][3], float indsAverage[], char letterGrade[], float classAverage, int numberOfStudents, int numberOfGrades[]);
void printTitleAndHeading();
void printIndInfo(int id[], float testScores[][3], float indsAverage[], char letterGrade[], int numberOfStudents);
void printTotalAndClassAverage(int numberOfStudents, float classAverage);
void calculateNumberOfGrades(char letterGrade[], int numberOfStudents, int numberOfGrades[]);
void printGradeGraph(int numberOfGrades[]);


//main
int main() {
	//declare all arrays and variables
	int id[MAX_STUDENTS];
	int numberOfGrades[5] = { 0 };
	float testScores[MAX_STUDENTS][3];
	float indsAverage[MAX_STUDENTS];
	char letterGrade[MAX_STUDENTS];
	float classAverage = 0.0f;
	int studentCounter = 0;

	//call necessary functions
	inputData(id, testScores, studentCounter);
	processData(testScores, indsAverage, letterGrade, studentCounter, classAverage, numberOfGrades);
	printReport(id, testScores, indsAverage, letterGrade, classAverage, studentCounter, numberOfGrades);

	//keep window open
	cin.ignore(2);
	return 0;
}

//get input from the user
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

//process the input by calling several functions
void processData(float testScores[][3], float indsAvergae[], char letterGrade[], int studentCounter, float &overallClassAverage, int numberOfGrades[]) {
	calculateIndAverageAndGrade(testScores, indsAvergae, letterGrade, studentCounter);
	calculateOverallAverage(indsAvergae, studentCounter, overallClassAverage);
	calculateNumberOfGrades(letterGrade, studentCounter, numberOfGrades);
}

//calculates the individuals averge and letter grade
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

//calculates the class average
void calculateOverallAverage(float indsAverage[], int studentCounter, float &overallClassAverage) {
	float totalAverages = 0.0f;

	for (int i = 0; i < studentCounter; i++) {
		totalAverages += indsAverage[i];
	}
	overallClassAverage = totalAverages / studentCounter;
}

//prints the report by calling several other print functions
void printReport(int id[], float testScores[][3], float indsAverage[], char letterGrade[], float classAverage, int numberOfStudents, int numberOfGrades[]) {
	printTitleAndHeading();
	printIndInfo(id, testScores, indsAverage, letterGrade, numberOfStudents);
	printTotalAndClassAverage(numberOfStudents, classAverage);
	printGradeGraph(numberOfGrades);
}

//prints the title and heading
void printTitleAndHeading() {
	cout << "\n\t\t ** Welcome to the Grader Program ** \n";
	cout << "ID \tQuiz 1 \tQuiz 2 \tQuiz 3 \tAverage \tGrade \n\n";
}

//prints information about the individuals
void printIndInfo(int id[], float testScores[][3], float indsAverage[], char letterGrade[], int numberOfStudents) {
	cout << setprecision(3);
	for (int i = 0; i < numberOfStudents; i++) {
		cout << "\n" << id[i] << "\t" << testScores[i][0] << "\t" << testScores[i][1] << "\t" << testScores[i][2] << "\t" << indsAverage[i] << "\t\t" << letterGrade[i] << "\n";
	}
}

//prints the class average
void printTotalAndClassAverage(int numberOfStudents, float classAverage) {
	cout << "\n\n** Number of Students: " << numberOfStudents << " Overall Class Average: " << classAverage << " **\n";
}

//claculates the number of each grade recieved in the class
void calculateNumberOfGrades(char letterGrade[], int numberOfStudents, int numberOfGrades[]) {
	for (int i = 0; i < numberOfStudents; i++) {
		if (letterGrade[i] == 'A') {
			numberOfGrades[0]++;
		}
		else if (letterGrade[i] == 'B') {
			numberOfGrades[1]++;
		}
		else if (letterGrade[i] == 'C') {
			numberOfGrades[2]++;
		}
		else if (letterGrade[i] == 'D') {
			numberOfGrades[3]++;
		}
		else {
			numberOfGrades[4]++;
		}
	}
}

//prints a graph of the grades in two optional forms
void printGradeGraph(int numberOfGrades[]) {
	int choice = 0;
	cout << "\nChoose a form for the graph: \n1) Vertical \n2) Horizaontal\n";
	cin >> choice;

	

	switch (choice) {

		//the vertical method
		case 1: {

			//calculate the highest scored grade
			int mostStars = 0;
			for (int i = 0; i < 5; i++) {
				if (numberOfGrades[i] > mostStars) {
					mostStars = numberOfGrades[i];
				}
			}

			cout << "\n";

			//loop for the number of rows needed
			for (int i = 0; i < mostStars; i++) {
				//loop for the number of colums needed
				for (int j = 0; j < 5; j++) {
					//determine if a star or blank space should be drawn
					if ((mostStars - i) <= numberOfGrades[j]) {
						cout << "*\t";
					}
					else {
						cout << "\t";
					}
				}
				//end the line after each row
				cout << "\n";
			}
			//add the legend at the bottom
			cout << "A\tB\tC\tD\tF";
			break;
		}

		//the horizontal method
		case 2: {
			//create an array or cstring to store ther different letters, note this could be initialized in a more simple way (char letter[] = "ABCDF"), but viually this makes more sense.
			char letter[] = { 'A', 'B', 'C', 'D', 'F' };
			string stars = "";
			cout << "\n";
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < numberOfGrades[i]; j++) {
					stars += "* ";
				}
				cout << letter[i] << "'s: " << stars << "\n";
				stars = "";
			}
			break;
		}
		default: {
			cout << "\nInvalid Choice!\n";
			printGradeGraph(numberOfGrades);
		}
	}
}
