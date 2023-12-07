//Jonathan Robinson
//COP2535.0M1
// This program will analyze a year's worth of rainfall data from a text file called rain2019.txt and 
// then display the total and average rainfall along with the driest and wettest month.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

/****************************************
*	RainData Class Declaration	*
****************************************/

class RainData {

private:
	float rain[12];		// holds value of monthly rainfall
	float total;		// holds the value for total rainfall
	float average;		// average amount of rainfall per year
	float most;			// most rainfall month number in the array
	float least;		// least rainfall month number in the array
	string mostMonth;	// String name for the month depending on the array element
	string leastMonth;	

	void getData();				// Inputs data from the Rain2019 file into the rain array then closes the file.
	void totalRainfall();		// Gets the total amount of rainfall from the rain array 
	void averageRainfall();		// Averages the data 
	void driestMonth();			// Sorts through the array to find the least amount of rainfall in the year and the month name
	void wettestMonth();		// Sorts through the array to find the most amount of rainfall in the year and the month name
	void displayReport();		// Displays a report to the user showing the total and average rainfall along with the wettest and driest months and the amount for the month

public:
	const int MONTHS = 12;			// holds value for amount of months in the year
	RainData();						// Default Constructor
	string monthCase(int date);		// Switch case function to get the name of the month depending on the array's position.
	void run();						// Function to run all the private functions in order of data processing to then display the "displayReport()" function
};

/********************************
*	RainData Constructor	*
********************************/

RainData::RainData() {
	float rain[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	float total = 0;
	float average = 0;
	float most = 0;
	float least = 0;
	string mostMonth = "";
	string leastMonth = "";
}

/********************************
*	Private Functions	*
********************************/

// Inputs data from the Rain2019 file into the rain array then closes the file.
void RainData::getData() {

	int count = 0;
	ifstream inputFile;

	inputFile.open("rain2019.txt");		//Opens the text file rain2019 and sets it to inputFile 

	if (!inputFile) 
		cout << "Error opening rain2019 text file\n";
		
	else {
		while (count < MONTHS && inputFile >> rain[count]) {	// Runs throught the file and adds each line into the rain[] array
			count++;
		}
	}
}

// Switch case function to get the name of the month depending on the array's position.
string RainData::monthCase(int date) {
	string  monthName;
	switch (date) {
		case 0: 
			monthName = "January";
			break;
		case 1: 
			monthName = "February";
			break;
		case 2: 
			monthName = "March";
			break;
		case 3: 
			monthName = "April";
			break;
		case 4: 
			monthName = "May";
			break;
		case 5: 
			monthName = "June";
			break;
		case 6: 
			monthName = "July"; 
			break;
		case 7: 
			monthName = "August"; 
			break;
		case 8: 
			monthName = "September"; 
			break;
		case 9:
			monthName = "October"; 
			break;
		case 10: 
			monthName = "November"; 
			break;
		case 11: 
			monthName = "December"; 
			break;
	}

	return monthName;
}

// Gets the total amount of rainfall from the rain array 
void RainData::totalRainfall() {
	total = 0;
	for (int count = 0; count < MONTHS; count++) {
		total += rain[count];
	}
}

// Averages the data 
void RainData::averageRainfall() {
	average = total / MONTHS;
}

// Sorts through the array to find the least amount of rainfall in the year and the month name
void RainData::driestMonth() {
	least = rain[0];
	for (int count = 0; count < MONTHS; count++) {
		if (rain[count] < least) {
			least = rain[count];
			leastMonth = monthCase(count);
		}
	}
}

// Sorts through the array to find the most amount of rainfall in the year and the month name
void RainData::wettestMonth() {
	most = rain[0];
	for (int count = 0; count < MONTHS; count++) {
		if (rain[count] > most) {
			most = rain[count];
			mostMonth = monthCase(count);
		}
	}
}

// Displays a report to the user showing the total and average rainfall along with the wettest and driest months and the amount for the month
void RainData::displayReport() {

	cout << fixed << setprecision(2) <<"2019 Rain Report for Alachua County\n\n" <<

		"Total rainfall:  " << total << " inches\n" <<
		"Average monthly rainfall:  " << average << " inches\n" <<
		"The least amount of rain fell in " << leastMonth << " with " << least << " inches.\n" <<
		"The most rain fell in " << mostMonth << " with " << most << " inches.\n\n" <<

		"End of report.\n";
}

// Function to run the whole program
void RainData::run() {
	getData();
	totalRainfall();
	averageRainfall();
	driestMonth();
	wettestMonth();
	displayReport();
}

/********************************
*	Main Program		*
********************************/

int main() {

	// Program code goes here
	RainData rain;
	rain.run();

	return 0;
}