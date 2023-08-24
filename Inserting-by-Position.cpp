#include<iostream>

using namespace std;

const int MAX_SIZE = 1000;
typedef int ELEMENTTYPE;

void printReverse(ELEMENTTYPE list[], int last)
{
	int length = 0;
	for(; last >= length; length++)
	{
		if(list[length] == '\0')
		{
			break;
			length++;
		}
	}
	
	for(int currentPos = length - 1; currentPos >= 0; currentPos--)
    {
        cout << "Data in position " << currentPos+1 << ": " << list[currentPos] << endl;
    }
}

int countTarget(ELEMENTTYPE list[], int last, int target)
{
	int counter = 0;
	for(int length = 0; length <= last; length++)
	{
		if(target == list[length])
		{
			counter++;
		}
	}
	
	return(counter);
}

void insertItem(ELEMENTTYPE list[], int *last, int newdata, int pos)
{
	int index;
	
	for(index = *last; index >= pos; index--)
	{
		list[index+1] = list[index];
	}
		
	list[pos] = newdata;
	(*last)++;
	cout << "Item Successfully Added!" << endl << endl;
}

void printOddNumbersAndPosition(ELEMENTTYPE list[],int last)
{
	for(int length = 0; length <= last; length++)
	{
		if(list[length] % 2 != 0) 
		{
			cout << "Data " << list[length] << " in position " << length + 1 << endl;
		}
	}
	cout << "DONE" << endl;
}

main()
{
	ELEMENTTYPE list[MAX_SIZE] = {2,4,3,8,5,12,8};
	int last = 6;
	int ctr;
	int target;
	int newdata;
	int pos;
	
	printReverse(list,last);
	
	cout << "Enter the number you want count: ";
	cin >> target;
	cout << endl;
	
	ctr = countTarget(list, last, target);
	
	cout << "There are " << ctr << " of the number " << target << endl;
	
	cout << "Enter position of insertion: ";
	cin >> pos;
	while(pos > last + 2)
	{
		cout << "Input Invalid!" << endl;
		cout << "Enter position of insertion: ";
		cin >> pos;
	}
	cout << endl;
	
	cout << "Enter new data to insert: ";
	cin >> newdata;
	cout << endl;
	
	insertItem(list,&last,newdata,pos-1);
	
	printReverse(list,last);
	
	cout << "Printing odd numbers and its position" << endl << endl;
	printOddNumbersAndPosition(list,last);
}
