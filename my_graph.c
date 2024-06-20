#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

#include <string.h>


int main(){
    char c;
    scanf("%c",&c);
    while(c!=EOF || c!='D'){
        switch(c){
            case 'A':
                prog1();
            break;
            
            case 'B':
                prog2();
            break;

            case 'C':
                prog3();
            break;
        }
    scanf("%c",&c);
    }
    return 0;
} 