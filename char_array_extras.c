#include <stdio.h>
#include <stdlib.h>

const int INITIAL_ARR_SIZE = 10;

char* init_default_char_arr(){
    char* new_char_ptr = (char*)malloc(INITIAL_ARR_SIZE * sizeof(char));

    return new_char_ptr;
}

int get_length_of_text(char* text){
    int i = 0;
    int text_length = 0;

    while (*(text + i) != '\0'){
        text_length++;
        i++;
    }

    text_length++;

    return text_length;
}

char* store_string(char* target_char_arr_p, char* str){
    int str_length = get_length_of_text(str);

    int target_char_length = get_length_of_text(target_char_arr_p);

    if (target_char_length < str_length){
        target_char_arr_p = (char*)malloc(str_length * sizeof(char));

        target_char_length = get_length_of_text(target_char_arr_p);
    }

    for (int i = 0; i < str_length; i++){
        *(target_char_arr_p + i) = *(str + i);
    }

    return target_char_arr_p;
}
