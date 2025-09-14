//Header line
#include<stdio.h>
//Declaring functions.

int highest_marks(int row,int col,int arr[][col]);
int lowest_marks(int row,int col,int arr[][col]);
float average_marks(int row,int col,int arr[][col]);
float Calculating_percentage(int stdIndx,int col,int arr[][col]);
char Calculating_letter_grade(float percentage);
void printing_report(int i,int high,int low,float average,float percentage[],char letter_grade[]);
//=============================================================================================================
//global variables
int maxSub = 100;
//=============================================================================================================
//Main function starts here.
int main() {

    //Greetings.
    printf("*************************************\n");
    printf("Welcome To Student Grade Analyser\n");
    int stdNum,subNum;
    printf("*************************************\n");
    //Taking inputs for stdNum and subNum.
    printf("\nEnter Student number to proceed :");
    scanf("%d",&stdNum);
    printf("\nEnter Subject number to proceed :");
    scanf("%d",&subNum);
        if(stdNum<=0||subNum<=0){
            printf("Invalid Entry\nOnly positive integer are valid.");
            return -1;
        }
    //printing the variables for check.
    printf("\nTotal no. of Students : %d\nTotal no. of Subjects : %d\n",stdNum,subNum);
    //Creating An Array.
    int grades[stdNum][subNum];

    //Loop for taking in grades.
    for(int i=0; i<stdNum; i++) {
        for(int j=0; j<subNum; j++) {
            printf("*************************************\n");
            printf("Enter the Marks of Student %d for Subject %d : ",i+1,j+1);
            scanf("%d",&grades[i][j]);
            if(grades[i][j]<0||grades[i][j]>100){
                printf("Invalid Entry\nOnly positive integer Are valid\nwith and between 0 to 100 only");
                return -1;
            }
        }
        printf("*************************************\n");
    }

    //Doing calculation and storing them in their respective variables
    int lowestMarks = lowest_marks(stdNum,subNum,grades);
    int highestMarks = highest_marks(stdNum,subNum,grades);
    float averageMarks = average_marks(stdNum,subNum,grades);

    //Calculating the percentage
    float percentage[stdNum];
    char letter_grade[stdNum];
    for(int i = 0; i<stdNum; i++) {
        percentage[i] = Calculating_percentage(i,subNum,grades);
        //Calculating the Grades A,B,C,D,E & F.
        letter_grade[i] = Calculating_letter_grade(percentage[i]);
    }

    //Printing values
    for(int i = 0; i<stdNum; i++) {
        printing_report(i,highestMarks,lowestMarks,averageMarks,percentage,letter_grade);
    }

    //main ends.
    return 0;
}
/*stdNum is number of Students
subNum is number of Subjects */

//=============================================================================================================
//Functions Definition

//function for finding highest marks
int highest_marks(int row,int col,int arr[][col]) {
    int x = arr[0][0];
    //loop to calculate highest
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(x<arr[i][j]) {
                x = arr[i][j];
            }
        }
    }
    return x;
}

//Function for finding the lowest marks
int lowest_marks(int row,int col,int arr[][col]) {
    int x = arr[0][0];
    //loop to calculate lowest
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(x>arr[i][j]) {
                x = arr[i][j];
            }
        }
    }
    return x;
}
//function for finding the average marks
float average_marks(int row,int col,int arr[][col]) {
    int sum = 0;
    float x;
    //loop to calculate sum
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            sum = sum + arr[i][j];
        }
    }
    //finding average
    x = (float)sum/(row*col);
    return x;
}
//finding percentage per student
float Calculating_percentage(int stdIndx,int col,int arr[][col]) {//stdIndx is student index
    int sum = 0;
    //loop for calculating sum
    for(int j = 0; j<col; j++) {
        sum = sum + arr[stdIndx][j];
    }
    //calculating percentage
    float x = (float)sum/(col*maxSub)*100;
    return x;
}
//finding grades for students by if else ladder
char Calculating_letter_grade(float percentage) {
    if(percentage>=91) {
        return 'A';
    }
    else if(percentage>=81) {
        return 'B';
    }
    else if(percentage>=71) {
        return 'C';
    }
    else if(percentage>=61) {
        return 'D';
    }
    else if(percentage>=51) {
        return 'E';
    }
    else {
        return 'F';
    }
}

//function to print students report
void printing_report(int i,int high,int low,float average,float percentage[],char letter_grade[]) {
    if(i==0) {
        printf("*************************************\n");
        printf("Highest Score : %d\n",high);
        printf("Lowest Score : %d\n",low);
        printf("Average Score : %.2f\n",average);
        printf("*************************************\n");
    }
    printf("*************************************\n");
    printf("Student : %d\n",i+1);
    printf("Total Percentage Gained : %.2f\n", percentage[i]);
    printf("Grade Obtained : %c\n",letter_grade[i]);
    printf("*************************************\n");
}
//=============================================================================================================
    