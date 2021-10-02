#include <stdio.h>
#include <string.h>

// Patient Details
struct Patient {
    char name[255];
    int age;
    char doctor[255];
    char disease[255];
    bool Active;
};

// Docter Details
struct Doctor{
    char name[255];
    char spesialist[255];
    bool Active;
};

// Global Declared Variables
Doctor doctors[100];
Patient patients[100];
int total_patients = 0;
int total_doctors = 0;

// Function for the rest of the code prototype
void addPatient(Patient p);
void addDoctor(Doctor d);
void showPatients();
void showDoctors();
void removePatient();
void removeDoctor();
void frontMenu();
void patientChoices();
void doctorChoices();
void doctorList();
void patientList();
void mainMenu();
void exitMenu();

// main function
int main() {
    mainMenu();
    return 0;
}

//patients

// show patient on the list
void showPatients() {
    for(int i = 0; i < total_patients; i++) {
        if(patients[i].Active) {
              printf("%s %d %s %s\n", patients[i].name, patients[i].age, patients[i].doctor, patients[i].disease);
        }
    }
}

// add patient to the list
void addPatient(Patient p) {
    strcpy(patients[total_patients].name, p.name);
    patients[total_patients].age = p.age;
    strcpy(patients[total_patients].doctor, p.doctor);
    strcpy(patients[total_patients].disease, p.disease);
    patients[total_patients].Active = true;
    total_patients++;
}

// remove patient from the list
void removePatient() {
    char patientRemoved[255];
    printf("Insert the name of patient that you want to remove from the list: ");
    scanf("%[^\n]", patientRemoved); getchar();
    for(int i = 0; i < total_patients; i++) {
        if(strcmp(patients[i].name, patientRemoved) == 0) {
            patients[i].Active = false;
            puts("Patient has been removed!");
        } else{
        	  puts("Patient not found!");
		    }
    }
}

//doctor

// add doctor to the list
void addDoctor(Doctor d) {
    strcpy(doctors[total_doctors].name, d.name);
    strcpy(doctors[total_doctors].spesialist, d.spesialist);
    doctors[total_doctors].Active = true;
    total_doctors++;
}

// show doctor listed
void showDoctors(){
    for(int i = 0; i < total_doctors; i++) {
        if(doctors[i].Active) {
              printf("%s %s\n", doctors[i].name, doctors[i].spesialist);
        }
    }
}

// remove doctor from the list
void removeDoctor(){
    char doctorRemoved[255];
    printf("Insert the name of doctor that you want to remove from the list: ");
    scanf("%[^\n]", doctorRemoved); getchar();
    for(int i = 0; i < total_doctors; i++) {
        if(strcmp(doctors[i].name, doctorRemoved) == 0) {
            doctors[i].Active = false;
            puts("Doctor has been removed!");
        } else{
        	  puts("Doctor not found!");
		    }
    }
}

//mainmenu
void frontMenu(){
  puts("Healthy Forever Main Menu");
  puts("1. Patient ");
  puts("2. Doctor ");
  puts("3. Exit HealthyForever");
  puts("Enter The Number that you choose: ");
}

//patientmenu
void patientChoices() {
    puts("Patient Main Menu");
    puts("1. Add patient & their details");
    puts("2. Show doctor available");
    puts("3. Remove patient from the list");
    puts("4. Go back");
}

// list of doctor
void doctorList() {
    puts("Doctor list");
    puts("1. Normal List");
    puts("2. Sort List");
}

// list of patient
void patientList() {
    puts("Doctor list");
    puts("1. Normal List");
}


//doctor
void doctorChoices() {
    puts("Doctor Main Menu");
    puts("1. Add doctor to the list");
    puts("2. Show Patient that is on the list");
    puts("3. Remove doctor from the list");
    puts("4. Go back");
}


//exit choice
void exitMenu(){
  puts("Are you sure you want to exit?");
  puts("1. Yes");
  puts("2. No");
}

// All of the menu function
void mainMenu() {
    bool inApplication = true;

    while(inApplication) {
        frontMenu();
        int frontChoice;
        do {
            printf("////\n");
            scanf("%d", &frontChoice); getchar();
        } while(frontChoice < 1 || frontChoice > 3);

        if(frontChoice==1){
            patientChoices();
            int choice = -1;

            do {
                printf("////\n");
                scanf("%d", &choice); getchar();
            } while(choice < 1 || choice > 4);

            if(choice == 1) {
              Patient newPatient;
              printf("Enter the Patient Name: ");
              scanf("%[^\n]", newPatient.name); getchar();
              printf("Enter the Patient Age: ");
              scanf("%d", &newPatient.age); getchar();
              printf("Enter the Doctor name that you want : ");
              scanf("%[^\n]", newPatient.doctor); getchar();
              printf("Enter the Disease : ");
              scanf("%[^\n]", newPatient.disease); getchar();
              addPatient(newPatient);
            } else if(choice == 2) {
                doctorList();
                int sortChoice;
                do {
                    printf("////\n");
                    scanf("%d", &sortChoice); getchar();
                } while(sortChoice < 1 || sortChoice > 2);
                if(sortChoice==1)
                  showDoctors();
                else if (sortChoice==2)
                  printf("Nanti dulu ya\n");
             } else if(choice == 3) {
                removePatient();
            } else if(choice == 4) {
                // frontMenu();
              }
        } else if(frontChoice==2){
            doctorChoices();
            int choice2 = -1;

            do {
                printf("////\n");
                scanf("%d", &choice2); getchar();
            } while(choice2 < 1 || choice2 > 4);

            if(choice2 == 1) {
              Doctor newDoctor;
              printf("Enter the Doctor Name: ");
              scanf("%[^\n]", newDoctor.name); getchar();
              printf("Enter the Doctor Specialist : ");
              scanf("%[^\n]", newDoctor.spesialist); getchar();
              addDoctor(newDoctor);
            } else if(choice2 == 2) {
                patientList();
                int sortChoice;
                do {
                    printf("///\n");
                    scanf("%d", &sortChoice); getchar();
                } while(sortChoice < 1 || sortChoice > 2);
                if(sortChoice==1)
                  showPatients();
                else if (sortChoice==2){
                  printf("Nanti dulu ya\n");
                }
            }  else if(choice2 == 3) {
                removeDoctor();
            } else if(choice2 == 4) {
                frontMenu();
            } 
        } else if (frontChoice == 3){
                exitMenu();
                int exitChoice;
                do {
                    printf("///\n");
                    scanf("%d", &exitChoice); getchar();
                } while(exitChoice < 1 || exitChoice > 2);
                if(exitChoice==1){
                    printf("Apabila butuh bantuan lagi, silahkan konsultasi ke pihak kami lagi ya!\n");
                    printf("Helthy Forever senang dapat membantu :D\n");
                    inApplication = false;
                }
                else if(exitChoice==2) {
                    frontMenu();
              }
        }
    }
}
