#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my_mat.h"
#include <string.h>

#define W 20
#define maxItems 5

//knapsack
int main(){
    int values[] = {0,0,0,0,0};
    int wheights [maxItems] = {0};
    int result [W] = {0};
    char items [maxItems];

    for(int i=0; i<maxItems; i++){
        scanf("%s", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &wheights[i]);
    }
 
    int maxProf = knapSack(wheights,values,result);

    printf("maximum profit: %d\n", maxProf);
    
    printf("selected items: \n");
    for(int i=0; i<maxItems; i++){
        if(result[i]==1){
            printf(" %c \n", items[i]);
        }
    }

    return 0;
}