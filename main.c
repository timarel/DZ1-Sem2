#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *dict_input = fopen("dict.txt", "r");
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    const char symbols[] = "/.,{}[]()";
    char word_check[10];
    char dict_word[10];

    printf("!WARNING \n");
    int counter = 0;
    while(fscanf(input, "%s", word_check) != EOF) {
        int j = 0;
        for(int i = 0; i < strlen(symbols); i++) {
            char *sym = strchr(word_check,symbols[i]);
            if(sym!=NULL){
                word_check[sym] = '';
            }
        }
        while(fscanf(dict_input, "%s", dict_word) != EOF){
            if(strcmp(word_check, dict_word)==0){
                j = 0;
                break;
            } else
                j++;
        }
        if(j!=0){
            counter++;
            printf("%s \n", word_check);
            fprintf(output,"%s\n", word_check);
        }
        dict_input = fopen("dict.txt", "r");
    }
    if(counter == 0) {
        printf("All clear.");
    }
    return 0;
}
