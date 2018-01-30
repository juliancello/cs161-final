/*
Name: Julian Kosanovic
Date: 12/12/2017
CS 161 Final Exam

I have only written code listed under the function "delEven()"
*/

//This program is your final exam.
//Please insert code in the function called void delEven(int [], int &); to delete
//all even numbers in the list given.  All you need to do is to fill the function.

#include <iostream>
#include <fstream>
using namespace std;

//constants
const int CAP = 100;

//function prototypes
bool openFile(ifstream &);
void readData(ifstream &, int [], int &);
void printData(const int [], int);
void delEven(int [], int &);

//main
int main()
{
	ifstream inFile;
	int list[CAP], size = 0;

	if (!openFile(inFile))
	{
		cout << "Program terminating!! File not found!" << endl;
		return -1;
	}
	//read the data from the file
	readData(inFile, list, size);
	inFile.close();
	cout << "Data in file:" << endl;
	printData(list, size);
	delEven(list, size);
	printData(list, size);
	//end program
	cin.ignore(100, '\n');
	cout << "Press any key to continue...";
	getchar();

	return 0;
}

//function to open file
bool openFile(ifstream &inFile)
{
	inFile.open("numbers.txt");
	if (!inFile)
	{
		return false;
	}
	return true;
}

//reads the data from the file
void readData(ifstream &inFile, int list[], int &size)
{
	while (!inFile.eof())
	{
		inFile >> list[size++];
	}
}

//function to delete all even numbers in the list.

void delEven(int list[], int &size)
{
    int temp = size, zeroCounter = 0, z = 0;
	for (int i = 0; i < size; ++i){ //This iterates through the list and deletes the even numbers.
        if (list[i] % 2 == 0){
            list[i] = 0;
            --temp; //Will eventually resize relevant part of list[]
            ++zeroCounter; //Counts how many even numbers have been replaced by zeros
        }
    }
    while (z <= zeroCounter){ //Do as many times as there are zeros to get rid of all zeros in relevant part of the list
        for (int i = 0; i < size; ++i){
            //Find every index where there is a zero and...
            if (list[i] == 0){
                list[i] = list[i+1]; //Move number in the next index left one index.
                list[i+1] = 0;
            }
        }
        ++z;
    }
    size = temp;
}

//print the contents of the array
void printData(const int list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << endl;
	}
	cout << endl;
}

















