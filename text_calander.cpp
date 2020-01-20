#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <fstream>
/*
Deepan Patel
CSCI 1060U-008
OCT 11th 2018

Formula used to find the start of the month found from website below:
http://mathforum.org/library/drmath/view/55837.html
*/

using namespace std;

//Global variables
//Added a blank index to make the month number line up(eg.6 = Jun)
string Months[] = {" ","January","February","March","April","May","June","July",
                "August","September","October","November","December"};

//Same thing is done to num of days so the index = month number
int Num_of_days[] ={0,31,28,31,30,31,30,31,31,30,31,30,31};


//declaration of functions
void printMonth(int month,int year);
void printYear(int year);
bool check_leap(int year);
int Which_day(int year, int month);

int main(){
  //Title of program
  cout << endl;
  cout << "|<><><><><><>| Calander Program - Deepan |<><><><><><>|" << endl;
  cout << endl;

  while(true){
    int user_month, user_year;
    string user_input;

    //User input
    cout << "Type in 'month' for month calander and 'year' for a year calander"
         << endl;
    cout << "Would you like a month or year calander? ";
    getline(cin,user_input);

    //If user choose to print  month
    if(user_input == "month"){

      cout << "Enter the year: ";
      cin >> user_year;
      cout << "Enter the month (using numbers): ";
      cin >> user_month;
      cout << endl;

      printMonth(user_month,user_year);
      break;
    }
    //If user choose to print a year calander
    else if (user_input=="year"){
      cout << "Enter the year: ";
      cin >> user_year;

      printYear(user_year);
      break;

    }
    else{
      //If user enter anything other than "month" or "year"
      cout << "Please make sure you're spelling month or year correctly"
           << endl;
      cout << "Please try again! "
           << endl;
    }

  }

  return 0;

}

//definition of functions

//Function which tell us which day the first day lands on
int Which_day (int year, int month){
  int d = 1; // d = day
  int y = year;
  int m = month;

  //Equation found from the website cited at the top of the code
  //This equation output which day the  certain date lands on (eg thurs..etc)
  // 0=Sat 1=Sun 2=Mon 3=Tue 4=Wen 5=Thur 6=Fri
  int N = ((d + 2*m + (3*(m+1)/5) + y + (y/4) - (y/100) + (y/400) + 2)%7);

  return N;

}

void printMonth(int month,int year){
  cout << endl; //Creates space for new calander

  //Displays basic stucture of calander
  cout << Months[month] << " " << year << endl;
  cout << endl;
  cout << " S   M  Tu   W  Th   F   S" << endl;


  //First thing to check is if it a leap year or not
  int leap_val = 0; // if it is a leap year this value is changed to 1 for feb
  if(check_leap(year)==true && month==2){
    leap_val = 1;
  }
  //Based of website:jan=13 & Feb=14 these values need to be used for special cases
  int month1 = month;
  int year1 = year;

  if(month == 1){
    month1 = 13;
    year1 = year-1;
  }
  if(month == 2){
    month1 = 14;
    year1 = year-1;
  }

  //Store which day the month starts in N using the Which_day Function
  int N = Which_day(year1,month1);
  if(N==0){
    N=7;
  }

  //Set num days based on the Num_of_days list
  int num_days = Num_of_days[month] + leap_val; // you add 1 to this value if leap year

  int SIZE = num_days + (N-1);

  int day = 1;
  int count = 0; //Needed to count till 7 to start new line for calander
  int calander[SIZE];

  //Store values into a calander list
  //0's are added for spaces on the calander(eg. if 1st is on tues,then 2 zeros)
  //and then afer the 0's are all added days are added starting from the 1st
  for(int i=0; i<SIZE;i++){
    if(i < N-1){
      calander[i] = 0;
    }
    else{
      calander[i] = day;
      day++;
    }

  }


  //Printing calander
  //Variation of if statment because there is variation of spacing depending
  //on the len of the day(eg.if 1 digit then 3 spaces follow, 2dig=2spaces)
  for(int i=0;i<SIZE;i++){
    if(calander[i] == 0){
      cout << "    ";
      count ++;
    }
    else{
      if(calander[i] < 10){
        cout << " " << calander[i] << "  ";
        count ++;

        //reset value of count when count equals 7 new line is made
        if(count ==7){
          cout << endl;
          count = 0;
        }
      }
      else{
        cout << calander[i] << "  ";
        count ++;
        //reset value of count when count equals 7 new line is made
        if(count == 7){
          cout << endl;
          count = 0;
        }
      }

    }

  }
  cout << endl; //Creates space for new calander


}
//Prints out all the years using the printMonth
void printYear(int year){
  //Loops 12 times
  for(int i=1;i<13;i++){
    printMonth(i,year);
  }

}

//Function which returns True if leap year based on the 3 given cases
bool check_leap(int year){
  //Case 1 if both year is divisible by 4 evenly and not 100 then true
  if(year%4==0 && year%100!=0){
    return true;
  }
  //Case 2 if year is both evenly divisble by 100 and 400 and 4 then true
  else if(year%400==0 && year%100==0 && year%4==0){
    return true;
  }
  //If both cases are false then returns false
  else{
    return false;
  }
}
