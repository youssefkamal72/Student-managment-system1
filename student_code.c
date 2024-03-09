#include <stdio.h>
#include <string.h>
int option,numStudents=4,new; 
int checkid=0,index;
int removeId;
float highest_gpa = 0;
int highest_gpa_index = -1;
float lowest_gpa = 4;
int lowest_gpa_index = -1;
float newValue;
typedef struct
 { 
int id;
char first_name[50]; 
char last_name[50]; 
char gender;
int academic_year;
float gpa;
char name[50];int age;
}student; 

student students[100] = 
{
{.id=1234567,.name="Mohammed Kamal",.gpa=3.5,.academic_year=3}, 
{.id=1122334,.name="Ahmed Fathy",.gpa=2.5,.academic_year=4},
{.id=7654321,.name="Youssef Kamal",.gpa=3.8,.academic_year=3},
{.id=2224446,.name="Sayed Ahmed",.gpa=1.8,.academic_year=2}
};
//function to add a student
int addstudent()
{
//Adding a student
printf("Enter student's first name: ");
scanf("%s", students[numStudents].first_name);
printf("Enter student's last name: ");
scanf("%s", students[numStudents].last_name);
if (strlen(students[numStudents].first_name) == 0 || strlen(students[numStudents].last_name) == 0) {
    printf("Error: Please enter both the first and last names.\n");
    return 0;
}
printf("Enter student's id (7 digits): ");
scanf("%d", &students[numStudents].id);
for (int i = 0; i < numStudents; i++) 
        {
                if(students[i].id==students[numStudents].id)
                {
                    checkid=1;
                    index=i;
                    printf("ERROR ID already taken \n");
                    return 0;
                }
        }
// Check if the id is unique and has 7 digits
if (students[numStudents].id < 1000000 || students[numStudents].id > 9999999) {
    printf("Error: Please enter a unique 7-digit student id.\n");
    return 0;
}
printf("Enter student's gender (M/F): ");
scanf(" %c", &students[numStudents].gender);
if (students[numStudents].gender != 'M' && students[numStudents].gender != 'm' 
&& students[numStudents].gender != 'F' && students[numStudents].gender != 'f') {
    printf("Error: Please enter 'M' for Male or 'F' for Female.\n");
    return 0;
}
printf("Enter student's academic year (1-5): ");
scanf("%d", &students[numStudents].academic_year);
if (students[numStudents].academic_year < 1 || students[numStudents].academic_year > 5) {
    printf("Error: Please enter a valid academic year between 1 and 5.\n");
    return 0;
}
printf("Enter student's GPA (0.0-4.0): ");
scanf("%f", &students[numStudents].gpa);
if (students[numStudents].gpa < 0.0 || students[numStudents].gpa > 4.0) {
    printf("Error: Please enter a positive floating number between 0.0 and 4.0 for GPA.\n");
    return 0;
}
// Print student information
printf("\nStudent Information:\n");
printf("Name: %s %s \n", students[numStudents].first_name, students[numStudents].last_name); 
printf("ID: %d \n", students[numStudents].id); 
printf("Gender: %c \n", students[numStudents].gender); 
printf("Academic Year: %d \n", students[numStudents].academic_year); 
printf("GPA: %.2f \n", students[numStudents].gpa);
numStudents++;
return 0;
}
//function to remove a student
void removingstudent()
{ 
    printf("Enter the ID of the student you wish to remove: ");
 scanf("%d",&removeId);
 //first check ID format 
    if (removeId < 1000000 || removeId > 9999999) 
    {
        printf("Invalid ID");
    } 
    //remove the ID entered
    else 
{
        for (int i = 0; i < numStudents; i++) 
        {
                if(students[i].id==removeId)
                {
                    checkid=1;
                    index=i;
                }
             
                if(checkid==1)
                {
                // Remove student data
                for (int j = index; j < numStudents - 1; j++) 
                {
                    students[j].id=students[j+1].id;
                    strcpy(students[j].name, students[j+1].name);
                    students[j].gpa=students[j+1].gpa;
                    students[j].academic_year=students[j+1].academic_year;
                    students[j].age = students[j+1].age;
                }
                numStudents--;
                printf("Operation Successful\n");
                break;
            }
        }
        if (checkid!=1)
         {
            printf("ID not found \n");
        }
    }
   printf("The updated student list is \n");
    for (int i = 0; i < numStudents; i++) {
    printf("{.id=%d,.name=\"%s\",.gpa=%.1f,.academic_year=%d},\n",
     students[i].id, students[i].name, students[i].gpa, students[i].academic_year);
    }
}
//function to find a student
void retrievingstudent()
{
    int choice;
printf("Choose an option:\n");
printf("1. Search by name \n"); 
printf("2. Search by ID \n"); 
scanf("%d", &choice);
//search about student by name
if(choice == 1) {
    char searchName[50];
    puts("Enter the name to search: ");
    gets(searchName);
    gets(searchName);
    int found = 0;
    for(int i = 0; i < numStudents; i++) {
        if(strcmp(students[i].name, searchName) == 0) {
            printf("Operation Successful - Student ID: %d, GPA: %.2f \n", students[i].id, students[i].gpa); found = 1; break; } }
    if(!found) {
        printf("Student not found.\n");
    }
}
//search about student by ID
else if(choice == 2)  
{
    int searchID;
    printf("Enter the ID to search: ");
    scanf("%d", &searchID);
    int found = 0;
    for(int i = 0; i < numStudents; i++) {
        if(students[i].id == searchID) {
            printf("Operation Successful - Student Name: %s, GPA: %.2f \n", students[i].name, students[i].gpa); found = 1; break; } }
    if(!found) {
        printf("Student not found.\n");
    }
}
else {
    printf("Invalid option.\n");
}

}
//function to update the students GPA or academic year
void updatestudent()
{
    int id;
    // Ask user for student ID
printf("Enter student id: ");
scanf("%d", &id);
int studentIndex = -1;
// Check if student ID is valid and exists
for (int i = 0; i < numStudents; i++) {
    if (students[i].id == id) {
        studentIndex = i;
        break;
    }
}
if (studentIndex == -1) {
    printf("Invalid student id or student does not exist.\n");

}
// Ask user for update option
printf("Choose an option to update:\n1) Update Academic Year\n2) Update GPA\n"); scanf("%d", &option);
// Update the selected option
switch(option) {
    case 1:
        printf("Enter new Academic Year: ");
        scanf("%d", &new);
        students[studentIndex].academic_year = new;
        break;
    case 2:
        printf("Enter new GPA: ");
        scanf("%f", &newValue);
        students[studentIndex].gpa = newValue;
        break;       
    default:
        printf("Invalid option chosen.\n");
        break;
}
// Display updated data
printf("Student ID: %d \n Academic Year: %d \n GPA: %.2f ", students[studentIndex].id, students[studentIndex].academic_year,
 students[studentIndex].gpa);
}
//function to give information about GPA
void infosgpa()
{
    // Iterate through the array of students
    for (int i = 0; i < numStudents; i++) {
        // Check if the GPA of the current student is higher than the current highest GPA
        if (students[i].gpa > highest_gpa) 
        {
            highest_gpa = students[i].gpa;
            highest_gpa_index = i;
        }
        // Check if the GPA of the current student is lower than the current lowest GPA
        else if (students[i].gpa < lowest_gpa) 
        {
            lowest_gpa = students[i].gpa;
            lowest_gpa_index = i;
        }
    }
    // Print the details of the student with the highest GPA
    printf("Student with the highest GPA:\n");
    printf("ID: %d\n", students[highest_gpa_index].id);
    printf("Name: %s\n", students[highest_gpa_index].name);
    printf("GPA: %.2f\n", students[highest_gpa_index].gpa);
    printf("Academic Year: %d\n", students[highest_gpa_index].academic_year);
     // Print the details of the student with the lowest GPA
    printf("\n Student with the lowest GPA:\n");
    printf("ID: %d\n", students[lowest_gpa_index].id);
    printf("Name: %s\n", students[lowest_gpa_index].name);
    printf("GPA: %.2f\n", students[lowest_gpa_index].gpa);
    printf("Academic Year: %d\n", students[lowest_gpa_index].academic_year);
    return 0;
}
int main() 
{
     char cont='c';
    int operation;
    while(cont=='c'|| cont == 'C')
    {
    printf("Choose an operation:\n");
    printf("1. Add a new student \n");
    printf("2. Removing a student \n");
    printf("3. Retrieving a student \n");
    printf("4. Updating a students data \n");
    printf("5. Information about GPAs \n");
    scanf("%d", &operation);
    switch(operation) {
        case 1:
            printf("You chose Add a new student \n");
            addstudent();
            break;
        case 2:
            printf("You chose Removing a student \n");
            removingstudent();
            break;
        case 3:
            printf("You chose Retrieving a student \n");
            retrievingstudent();
            break;
        case 4:
            printf("You chose Updating a students data \n");
            updatestudent();
            break;
         case 5:
            printf("You chose information about GPAs \n");
            infosgpa();
            break;
        default:
            printf("Invalid operation");
            break;
    }
    printf("\nPlease enter C to continue or any other key to close\n");
    scanf(" %c",&cont);
    }
    return 0;
}