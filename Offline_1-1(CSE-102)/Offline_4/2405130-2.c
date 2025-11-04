#include <stdio.h>
#include <stdlib.h>

void swap(char **a, char **b)
{
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

int compareWords(char *a, char *b)
{
    while (*a!='.' && *b!='.')
    {
        if (*a < *b) return -1;
        if (*a > *b) return 1;
        a++;
        b++;
    }
    if (*a == '.' && *b != '.') return -1;
    if (*a != '.' && *b=='.') return 1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    char** c =(char**)malloc(n*sizeof(char*));
    for(int k=0;k<n;k++){
        *(c+k) =(char*)malloc(26 * sizeof(char));
        scanf("%s",*(c+k));
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(compareWords(*(c+j), *(c+j+1))>0){
                swap((c+j),(c+j+1));
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%s\n",*(c+i));
        free (*(c+i));
    }
    free (c);
}
