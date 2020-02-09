#include <fstream>
#include <chrono>
#include "linkedlist.h"
#include "Hashtable.h"

using namespace std;
using namespace chrono;


int main()
{

	auto start = high_resolution_clock::now();//start timer
	Hashtable names;
	string statement;
	string statement1;
	string statement2;
	string statement3;
	int pos, quantity;


	ifstream csv;
	csv.open("OnlineRetail.csv"); //open the file



	if (csv.is_open())
	{
		getline(csv, statement);								//skip first line
		while (getline(csv, statement))							//reading column by column
		{
			pos = statement.find(';');							//find the first semicolon
			statement = statement.erase(0, pos + 1);			//erase before the first semicolon
			pos = statement.find(';');
			statement1 = statement.substr(0, pos);				// find the string after first semicolon
			statement = statement.erase(0, pos + 1);			//erase after the second semicolon
			pos = statement.find(';');
			statement2 = statement.substr(0, pos);				// find the string after second semicolon
			statement = statement.erase(0, pos + 1);			//erase after the third semicolon
			pos = statement.find(';');
			statement3 = statement.substr(0, pos);				// find the string after third semicolon
			pos = statement.find(';');


			quantity = stoi(statement3);


			names.insert(statement1, "\t\t" + statement2, quantity); //insert top10 value

		}
		cout << "Stock Code" << "\t" << "Description" << endl;
		names.topten();												//print top10 value as sort
	}
	else
	{
		cout << "Error ! File can not be opened !" << endl;		//error message
	}

	auto stop = high_resolution_clock::now();					//stop timer
	auto duration = duration_cast<milliseconds>(stop - start);	// start timer - stop timer
	auto durati = duration_cast<seconds>(stop - start);

	cout << "Total Elapsed Time : " << (double)duration.count() / 1000 << " seconds" << endl;


	return 0;
}