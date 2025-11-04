#include<stdio.h>
#include<stdlib.h>

void removeNegatives(int* input, int n, int** output, int* newSize){

    int c=0;
    for(int k=0;k<n;k++){
        if(*(input+k)>=0){
            c++;  // non negative numbers count
        }
    } 
    *newSize= c;
    *output = (int*)malloc(c * sizeof(int));

    int i=0;
    for(int j=0;j<n;j++){
        if(*(input + j)>=0){
            *(*output+i) = *(input + j);
            i++;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int *input = (int*)malloc(n * sizeof(int));
    for(int k=0;k<n;k++){
        scanf("%d",(input+k));
    }
    int *output,newSize;
    
    removeNegatives(input, n ,&output ,&newSize);

    printf("%d\n", newSize);
    for(int k=0;k<newSize;k++){
        printf("%d ",*(output+k));
    }
    free(input);
    free(output);
    return 0;
}











