#include <iostream>
#include <string>

using namespace std;

void assignCourseGrade(int numCourses, string courseLetterGrades[], double* courseGrades );
double calculateGPA(int numCourses, double* courseGrades);

int main(int argc, char* argv[])
{
	if(argc % 2 == 0 || argc == 1){
		cerr<<"Usage: ./gpa course letterGrade"<<endl;
		exit(1);
  	}
	
    string courseNames[5];
    double courseGrades[5];
    string courseLetterGrades[5];
    int numCourses = int(argc/2);

    // buggy CS16 A CS24 A+ CS32 A

    for (int i = 0, j = 1; i< argc/2; i++, j+=2){
        courseNames[i] = string(argv[j]);
        courseLetterGrades[i] = string(argv[j + 1]);
        cout<<courseNames[i] << "   "<<courseLetterGrades[i]<<endl;
    }

    assignCourseGrade(numCourses, courseLetterGrades, courseGrades );

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    double result = calculateGPA(numCourses, courseGrades);
    cout<<"GPA: "<< result <<endl;

    return 0;
}


void assignCourseGrade(int numCourses, string courseLetterGrades[], double* courseGrades ){

    for(int i =0 ; i < numCourses; i++){
        if(courseLetterGrades[i]=="A" || courseLetterGrades[i]=="A+"){
            courseGrades[i] = 4.0;
        }else if(courseLetterGrades[i]=="A-"){
            courseGrades[i] = 3.7;
        }else if(courseLetterGrades[i]=="B+"){
            courseGrades[i] = 3.3;
        }else if(courseLetterGrades[i]=="B"){
            courseGrades[i] = 3.0;
        }else if(courseLetterGrades[i]=="B-"){
            courseGrades[i] = 2.7;
        }else if(courseLetterGrades[i]=="C+"){
            courseGrades[i] = 2.3;
        }else if(courseLetterGrades[i]=="C"){
            courseGrades[i] = 2.0;
        }else if(courseLetterGrades[i]=="C-"){
            courseGrades[i] = 1.7;
        }else if(courseLetterGrades[i]=="D+"){
            courseGrades[i] = 1.3;
        }else if(courseLetterGrades[i]=="D"){
            courseGrades[i] = 1.0;
        }else {
            courseGrades[i] = 0.0;
        }
    }
}

double calculateGPA(int numCourses, double* courseGrades){
    double sum = 0;
    for (int i = 0; i < numCourses; i++){
        sum+=courseGrades[i];
    }
    return sum/numCourses;
}
