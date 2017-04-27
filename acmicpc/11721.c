#include <stdio.h>
 
int main(void) {
    int i=0;
    char instr[101];
 
    scanf("%s", instr);
    while (instr[i] != '\0') {
        if ((i > 0) && (i % 10 == 0)) printf("\n");
        printf("%c", instr[i++]);
    }
    return 0;
}

