// PatientsInFile.cpp : Defines the entry point for the console application.
//Nile Weadick

#include "stdafx.h"
#include "iostream"
#include "iomanip"
#include "string"
#include "fstream"

using namespace std;

int main()
{
	//Declare files

	ifstream PATIENTS;

//Open files

	PATIENTS.open(".txt");

	if (!PATIENTS.is_open())
	{
		cout << "File failed to open" << endl;
		string junk;
		cout << endl << "Hit any key to continue...";
		cin >> junk;
		return 0;
	}

//Declare variables

	string firstName, lastName, inputLine, room;
	int pulse, respiration, oxygen, normal, check, alert, critical, indicator;

	// Display top

	cout << "Room Name                  Pulse  Respir  Oxygen";
	cout << endl << "-----------------------------------------------------" << endl;

	normal = 0;
	check = 0;
	alert = 0;
	critical = 0;
	//indicator = 0;

// Read file
	
	while (PATIENTS >> firstName >> lastName >> pulse >> respiration >> oxygen >> room)
	{

// Display 

		string fullname = lastName + ", " + firstName;

		//cout << endl << room << "  " << lastName << ", " << firstName;
		 
		cout << endl << room << "  " << right << fullname << setw(30);
		indicator = 0;

	// Pulse

		if(pulse >= 60 && pulse <= 100)
		{
			cout << setw(14) << pulse;
		}
		if (pulse < 60)
		{
			cout << setw(11) << "Low=" << pulse;
			indicator++;
		}
		if (pulse > 100)
		{
			cout << setw(8) << "High=" << pulse ;
			indicator++;
		}

//Respiration

		if (respiration >= 12 && respiration <= 20)
		{
			cout << setw(8) << respiration;
		}
			
		if (respiration < 12)
		{
			cout << setw(6) << "Low=" << respiration;
			indicator++;
		}	
		if (respiration > 20)
		{
			cout << setw(6) << "High=" << respiration;
			indicator++;
		}
		
// Oxygen

		if(oxygen >= 92 && oxygen <= 100)
		{
			cout << setw(8) << oxygen;
		}
		if (oxygen < 92)
		{
			cout << setw(6) << "Low=" << oxygen ;
			indicator++;
		}
		if (oxygen > 100)
		{
			cout << setw(6) << "High=" << oxygen ;
			indicator++;
		}
// Indicator

		if (indicator == 0)
		{
			normal++;
			cout << endl;
		}
		if (indicator == 1)
		{
			cout << " CHECK";
			check++;
			cout << endl;
		}
		if (indicator == 2)
		{
			alert++;
			cout << " ALERT***"<< endl;
		}
		if (indicator == 3)
		{
			critical++;
			cout << " CRITICAL***"<< endl;
		}
}

// Totals

	cout << endl << endl << "Totals" << endl;
	cout << normal << " Normals" << endl;
	cout << alert << " ALERT" << endl;
	cout << check << " CHECK" << endl;
	cout << critical << " CRITICAL" << endl;

// Close files 

	PATIENTS.close();
	
// Freeze screen

	string junk;
	cout << endl << "Hit any key to continue...";
	cin >> junk;


	return 0;
}

