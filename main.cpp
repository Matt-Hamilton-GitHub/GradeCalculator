//                                             ********* Writer: Matt Hamilton   *********
 //                                             ******** Class: CO SCI 140       ******** 
 //                                              ******* Professor: Luis Flores  *******
 //                                               *****           Midterm        *****
 //                                                **** ======================== ****
 //                                                 **  *** *** *** *** *** ***  **
 //

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;

struct StudentInfo // here I declared a stuct with a student data
{
  char name[50];
  int IDnumber;
  int *tests;
  double average; 
  char grade;
  
};

//Function Prototypes
StudentInfo *ArrayData(int, int);
void getData(StudentInfo[], int, int);
void showData(StudentInfo[], int, int);

int main(){

	int NumOfStudents{0};
    int NumOfTests{0};
    
    StudentInfo *arrays; //Pointer to StudentInfo array
    
    cout << "How many students? ";
    cin >> NumOfStudents;//get number of students 
 
    cout << "How many tests per students? ";
    cin >> NumOfTests;//get number of tests per student
    
    arrays = ArrayData(NumOfStudents, NumOfTests);
    
    getData(arrays, NumOfStudents, NumOfTests);
    
    showData(arrays, NumOfStudents, NumOfTests);


	system("pause");
    return 0;
}

void getData(StudentInfo list[], int s, int t)
{
    int total = 0;
    
    //ask for student name
    for ( int count{0}; count < s; count++){
        cin.get();
        cout << "Student name: ";
        cin.getline(list[count].name, 50);
    
    
    //ask for id number fo each student
    cout << "ID Number: ";
    cin >> list[count].IDnumber;

   //collect test scores for each student 
    total = 0;
for(int i{0}; i < t; i++){
    
    cout << "\tTest # " << (i+1) << ":";
    do { cin >> list[count].tests[i];
        if(list[count].tests[i] < 0)
        cout << "Enter 0 or greater.\n";
    }
    while(list[count].tests[i] < 0);
        total+=list[count].tests[i];
}

//Evaluate the grade 

list[count].average = static_cast <double> (total) / t;

if (list[count].average >=91)
    list[count].grade = 'A';
else if (list[count].average >= 81 && list[count].average <= 90)
    list[count].grade = 'B';
else if (list[count].average >= 71 && list[count].average <= 80)
    list[count].grade = 'C';
else if (list[count].average >= 61 && list[count].average <=70)
    list[count].grade = 'D';
else 
    list[count].grade = 'F';
    
    }
}

 
StudentInfo *ArrayData (int s, int t)
{
    StudentInfo *ptr;
    //Allocate the array
    ptr = new StudentInfo[s];
    
    for (int count {0}; count < s; count++){
        ptr[count].tests = new int[t];
    }
    
    return ptr;
}

void showData(StudentInfo list[], int s, int t)//show all the students' data
{
    cout << fixed << showpoint << setprecision(1);
    for(int var {0}; var < s; var++){
        cout <<"Student name: " << list[var].name << endl;
        cout <<"ID number: " << list[var].IDnumber << endl;
        cout << "Average test score: " << list[var].average << endl;
        cout << "Grade: " << list[var].grade << endl << endl;
    }
}