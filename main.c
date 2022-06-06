#include <stdio.h>
#include <stdlib.h>
#include "char_array_extras.h"

struct Exam{
    int marks;
    char grade;
    char* exam_name;
}EXAM_DEFAULT;

int main()
{
    printf("Enter the number of exams you would like to add: ");

    int exam_num = 0;

    scanf("%d", &exam_num);

    fflush(stdin);

    struct Exam* exam_p_list[exam_num];

    char test_name[100];

    struct Exam* new_exam_p = NULL;

    for (int index_1 = 0; index_1 < exam_num; index_1++){
        new_exam_p = (struct Exam*)malloc(sizeof(EXAM_DEFAULT));

        //struct Exam* new_exam_p; //This caused Issue #001

        printf("\nEnter the name of the exam: ");

        fgets(test_name, 100, stdin);

        fflush(stdin);

        new_exam_p->exam_name = init_default_char_arr();

        new_exam_p->exam_name = store_string(new_exam_p->exam_name, test_name);

        printf("\nEnter the grade you obtained for this exam: ");

        //printf("\nValue of index_1: %d", index_1); //index_1 is 0 here

        scanf("%c", &(new_exam_p->grade)); //scanf in this line only reads 1 value

        //new_exam_p->grade = 'F';

        /*
        Further experimentation seems to reveal that index_1 is storing the decimal value of the character stored in
        the new_exam_p->grade char variable. It is currently unknown as to why this behaviour is occurring
        (Edit: This problem was resolved after creating an Exam struct first, then assigning the address of this struct
         as the value of the new_exam_p pointer variable, the warning given by the compiler under build messages mentioned
         something new_exam_p may be uninitialized)
        */

        //printf("\nValue of index_1: %d", index_1); //Issue #001: index_1 is 66 here, index_1 seems to be storing the decimal value of B, which is 66

        fflush(stdin);

        printf("\nEnter the number of marks you obtained for this exam: ");

        scanf("%d", &(new_exam_p->marks));

        fflush(stdin);

        exam_p_list[index_1] = new_exam_p;

        printf("\nExam entry stored successfully.\n");
    }

    for (int i = 0; i < exam_num; i++){
        printf("\n\nEntry for exam %d", i + 1);

        printf("\nExam name: %s", exam_p_list[i]->exam_name);

        printf("Grade obtained: %c", exam_p_list[i]->grade);

        printf("\nNumber of marks obtained: %d", exam_p_list[i]->marks);
    }

    return 0;
}
