#include <stdio.h>
 
int main(void) {
    int i;
    char instr[101];
 
    for (i=0; i<100; i++) {
        gets(instr);
        puts(instr);
        instr[0] = '\0';
    }
}
