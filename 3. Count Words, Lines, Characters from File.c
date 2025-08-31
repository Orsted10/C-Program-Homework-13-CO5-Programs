#include <stdio.h>

int main() {
    FILE *file;
    char filename[50];
    char ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    while ((ch = fgetc(file)) != EOF) {
        characters++;
        
        if (ch == '\n') {
            lines++;
        }
        
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }
    
    fclose(file);
    
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
    
    return 0;
}
