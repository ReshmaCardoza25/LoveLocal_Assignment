#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    int length = 0;
    int i = strlen(s) - 1;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    while (i >= 0 && s[i] != ' ') {//To count the characters of the last word
        length++;
        i--;
    }

    return length;
}

int main() {
    char input[100];
    printf("Enter the string: "); //To get input from the user
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    int result = lengthOfLastWord(input);
    printf("Length of the last word: %d\n", result);//To print the length of the last word

    return 0;
}
