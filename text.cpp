// A C++ Program to Implement a Calendar
// of an year
#include<bits/stdc++.h>
using namespace std;

/*A Function that returns the index of the day
of the date- day/month/year
For e.g-

Index	 Day
0		 Sunday
1		 Monday
2		 Tuesday
3		 Wednesday
4		 Thursday
5		 Friday
6		 Saturday*/
int dayNumber(int day, int month, int year)
{

	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
					4, 6, 2, 4 };
	year -= month < 3;
	return ( year + year/4 - year/100 +
			year/400 + t[month-1] + day) % 7;
}

/*
A Function that returns the name of the month
with a given month number

Month Number	 Name
0			 January
1			 February
2			 March
3			 April
4			 May
5			 June
6			 July
7			 August
8			 September
9			 October
10			 November
11			 December */
string event(int i)
{
    string jan[]={"\n2,9,16,23--sunday\n13,14,15- unit test II\n26--republic day\n5--display of attendance\n10--hod feedback\n25--unit test 2 nd result"};
    string feb[]={"\n7 to 11-poe\n14--starting of theory exam\n28--national science day"};
    string march[]={"1 -- start of 4 th sem\n6,13,20,27--sunday\n30--hackthon\n4--project progress review"};
    string April[]={"\n3,7,17,24--sunday\n8--display of attendance\n9--feedback of student\n18 to 20--unit test 1st\n30--result unit test 2nd\n4--presentation of synopsis of project"};
    string may[]={"\n1,8,15,22,29--sunday\n9 to 12--industrial visit\n16 to 21--sports week\n23 to 28--traditional days\n3--project presentation demo 1st"};
    string Jun[]={"\n5,12,19,26--sunday\n6--display of atttendance\n14--unit test 2nd\n29-unit test 2nd result"};
    string July[]={"\n3,10,17,24,31--sunday\n4--final detentation list\n6-parents meet\n18 to 22--oral\practical exam\n25--starting of theory exam"};
    string Aug[]={"4--end"};
    string sep[]={"\n5,12,19,26--sunday\n6,7--webinar\n14--webinar\n17--engineering day\n1--start of III sem"};
    string oct[]={"\n3,10,17,24,31--sunady\n25--webinar\n4--display of attendance\n10 to 12--unit test 1st\n28--display of unit test result"};
    string nov[]={"\n7,14,21,28--sunday\n6--display of atttendance\n15--feedback of student"};
    string dec[]={"\n5,12,19,26--sunday\n6--session on training and placement\n14--seminar on ethical engineer\n17--freshers party\n29--parents meeting"};
    if(i==0)
    {
        return(jan[i]);
    }
    else if(i==1)
    {
        return(feb[0]);
    }
    else if(i==2)
    {
        return(march[0]);
    }
    else if(i==3)
    {
        return(April[0]);
    }
    else if(i==4)
    {
        return(may[0]);
    }
    else if(i==5)
    {
        return(Jun[0]);
    }
    else if(i==6)
    {
        return(July[0]);
    }
    else if(i==7)
    {
        return(Aug[0]);
    }
    else if(i==8)
    {
        return(sep[0]);
    }
    
    else if(i==9)
    {
        return(oct[0]);
    }
    
    else if(i==10)
    {
        return(nov[0]);
    }
    
    else if(i==11)
    {
        return(dec[0]);
    }
    
}
string getMonthName(int monthNumber)
{
	string months[] = {"January", "February", "March",
					"April", "May", "June",
					"July", "August", "September",
					"October", "November", "December"
					};

	return (months[monthNumber]);
}

/* A Function to return the number of days in
a month

Month Number	 Name	 Number of Days
0			 January	 31
1			 February 28 (non-leap) / 29 (leap)
2			 March	 31
3			 April	 30
4			 May		 31
5			 June	 30
6			 July	 31
7			 August	 31
8			 September 30
9			 October	 31
10			 November 30
11			 December 31

*/
int numberOfDays (int monthNumber, int year)
{
	// January
	if (monthNumber == 0)
		return (31);

	// February
	if (monthNumber == 1)
	{
		// If the year is leap then February has
		// 29 days
		if (year % 400 == 0 ||
				(year % 4 == 0 && year % 100 != 0))
			return (29);
		else
			return (28);
	}

	// March
	if (monthNumber == 2)
		return (31);

	// April
	if (monthNumber == 3)
		return (30);

	// May
	if (monthNumber == 4)
		return (31);

	// June
	if (monthNumber == 5)
		return (30);

	// July
	if (monthNumber == 6)
		return (31);

	// August
	if (monthNumber == 7)
		return (31);

	// September
	if (monthNumber == 8)
		return (30);

	// October
	if (monthNumber == 9)
		return (31);

	// November
	if (monthNumber == 10)
		return (30);

	// December
	if (monthNumber == 11)
		return (31);
}

// Function to print the calendar of the given year
void printCalendar(int year)
{
	printf ("		 Calendar - %d\n\n", year);
	int days;

	// Index of the day from 0 to 6
	int current = dayNumber (1, 1, year);

	// i --> Iterate through all the months
	// j --> Iterate through all the days of the
	//	 month - i
	for (int i = 0; i < 12; i++)
	{
		days = numberOfDays (i, year);

		// Print the current month name
		printf("\n ------------%s-------------\n",
			getMonthName (i).c_str());

		// Print the columns
		printf(" Sun\t Mon\t Tue\t Wed\t Thu\t Fri\t Sat\n");

		// Print appropriate spaces
		int k;
		for (k = 0; k < current; k++)
			printf("\t");

		for (int j = 1; j <= days; j++)
		{
			printf("%5d\t", j);

			if (++k > 6)
			{
				k = 0;
				printf("\n");
			}
		}
		if (k)
			printf("\n");
            //printf("\n\n%d\n\n",i);    
            printf("%s",event(i).c_str());
		current = k;
	}

	return;
}


// Driver Program to check above functions
int main()
{
	int year = 2016;
	printCalendar(year);

	return (0);
}
