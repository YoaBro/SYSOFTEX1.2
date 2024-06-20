#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"
#include <math.h>
#include <string.h>

#define SIZE 3
#define INF 1000000

#define W 20
#define maxItems 5

int mat[SIZE][SIZE];

//graph related functions

int min(int a, int b){
    if(a<=b){
        return a;
    }
    else return b;
}

//finds and saves the shortest path for every (i,j) and saves in graph (as that is all we need)
void minPath(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if((!(i==j)) && (mat[i][j]==0)){
                mat[i][j]=INF;
            }
        }
    } 

    for(int k=0; k<SIZE; k++){
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(mat[i][j] >= INF){
                mat[i][j]=0;
            }
        }
    }
}

//for us
void checkMatrix() {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void prog1(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("in place (%d,%d)\n", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    minPath();
}

void prog2(){
    int i,j;
    scanf("%d%d",&i,&j);
    if(i==j || mat[i][j]==0){
        printf("FALSE\n");
    }
    else{
        printf("TRUE\n");
    }
}

void prog3(){
    int i,j;
    scanf("%d%d",&i,&j);
    printf("shortest path of (%d,%d) is:\n",i,j);
    if(mat[i][j]==0){
        printf("-1\n");
    }
    else {
        printf("%d\n",mat[i][j]);
    }
}


//knapsack related functions
int max(int a, int b){
    if(a>=b){
        return a;
    }
    else return b;
}

int knapSack(int weights[], int values[] , int selected_bool[]){
    int maxPr=0;

    int k[maxItems+1][W+1];

    for(int i=0; i<=maxItems; i++){
        for(int j=0; j<=W; j++){
            if (i==0 || j==0)
            {
                k[i][j]=0;
            }else if(weights[i-1]<=j){
                k[i][j]=max((k[i-1][j]),(values[i-1]+k[i-1][j-weights[i-1]]));
            }else{
                k[i][j]=k[i-1][j];
            }
        }
    }

    int w = W;
    for (int i = maxItems; i > 0; i--) {
        printf("i is: %d\n",i);
        printf("k[i][w] is: %d.\nk[i-1][w] is: %d.\n",k[i][w] , k[i - 1][w]);
        if (k[i][w] != k[i - 1][w]) {//reminder: for the k the item is in the i'th place
            printf("is def\n");
            selected_bool[i - 1] = 1;
            w -= weights[i - 1];
        }
    }
 
    maxPr = k[maxItems][W];
    return maxPr;
}