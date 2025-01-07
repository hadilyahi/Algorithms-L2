#include <stdio.h>

struct Student {
    char name[50];
    int marks[5];
    int total;
    float avreage;
};

int main(){
    struct Student students[5];
    int num_Students = 5;
    int num_Subjects = 5;
    for(int i=0  ; i<num_Students ; i++){
    printf("Enter the student data\n");

    printf("name: ");
    scanf("%s",students[i].name);

    students[i].total = 0;
    for(int i=0 ; i<num_Subjects ; i++){
        printf("Enter the mark of subject %d: ",i+1);
        scanf("%d",&students[i].marks[i]);
        students[i].total += students[i].marks[i];

    }
    students[i].avreage = students[i].total / num_Subjects;
    }
    printf("\nResults:\n");
   
    for(int i=0 ; i<num_Students ; i++){
        printf("Student %s has total %d and avreage %f\n",students[i].name,students[i].total,students[i].avreage);
    }

    return 0;
    
}