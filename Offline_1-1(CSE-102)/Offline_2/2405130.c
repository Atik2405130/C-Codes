#include <stdio.h>

#include <math.h>

#include <string.h>

#include "utils.c"

#define MAX_SIZE 1000000

#define MAX_BINS 1000

#define MAX_STARS 50

double array[MAX_SIZE];
int initialized=0;

void commands(void){
    printf("Commands:\n");
    printf("  set     - Set array size,seed, and distribution (uniform or gaussian)\n");
    printf("  min     - Print minimum value\n");
    printf("  max     - Print maximun value\n");
    printf("  mean    - Print mean value\n");
    printf("  stddev  - Print standard deviation\n");
    printf("  hist    - Plot histogram\n");
    printf("  summary - Print min, max, mean, stddev\n");
    printf("  help    - Show this help message\n");
    printf("  exit    - Exit the program\n");
}
int compare_double(const void *a, const void *b){
    double da = *(double*)a;
    double db = *(double*)b;
    if(da < db) return -1;
    if(da > db) return 1;
    return 0;
}

int main(){
    commands();
    int elements;


    while(1){
        printf("\nEnter command:");
        char command[20];
        scanf("%s",command);

        if(strcmp(command,"set")==0){
            int seed;
            double min,max,stddev,mean;
            char a[20];
            printf("Enter number of elements (<=1000000): ");
            scanf("%d", &elements);
            printf("Enter seed: ");
            scanf("%d", &seed);

            while(1){
                printf("Distribution? (uniform/gaussian): ");
                scanf("%s",a);
                if(strcmp(a,"uniform")==0){
                    printf("Enter min and max : ");
                    scanf("%lf %lf",&min,&max);
                    populate_array_uniform(array,elements,min,max,seed);
                    printf("Array initialized with uniform distribution\n");
                    initialized=1;
                    break;
                }
                else if(strcmp(a,"gaussian")==0){
                    printf("Enter mean and stddev: ");
                    scanf("%lf %lf",&mean,&stddev);
                    populate_array_gaussian(array,elements,mean,stddev,seed);
                    printf("Array initialized with gaussian distribution\n");
                    initialized=1;
                    break;
                }
                else {
                    printf("Invalid distribution\n");
                }
            }
        }  
           if(!initialized){
            printf("Array not initialized. Use 'set' command first.\n");
            continue;
          
        }
        
        
        double meanp,sum=0;
        for(int i=0;i<elements;i++){
            sum+=array[i];
        }
        meanp=sum/elements;

        double minp=array[0];
        for(int k=1;k<elements;k++){
            if(minp>array[k])
            minp=array[k];
        }

        double maxp=array[0];
        for(int l=1;l<elements;l++){
            if(array[l]>maxp)
            maxp=array[l];
        }

        double stdr,sum2=0;
        for(int t=0;t<elements;t++){
            sum2+=((array[t]-meanp)*(array[t]-meanp))/elements;
        }
        stdr=sqrt(sum2);
       

        qsort(array,elements,sizeof(double), compare_double);

        double medianp;
        if(elements%2==0){
            medianp=(array[elements/2-1]+ array[elements/2])/2.0;
        }
        else{
            medianp=array[elements/2];
        }

        while(1){
            printf("\nEnter command : ");
            char command[20];
            scanf("%s",command);
            if(strcmp(command,"max")==0){
                printf("Max        : %11.4lf\n",maxp);
            }
            else if(strcmp(command,"min")==0){
                printf("Min        : %11.4lf\n",minp);
            }
            else if(strcmp(command,"mean")==0){
                printf("Mean       : %11.4lf\n",meanp);
            }
            else if(strcmp(command,"stddev")==0){
                printf("Std Dev    : %11.4lf\n",stdr);
            }
            else if(strcmp(command,"median")==0){
                printf("Median     : %11.4lf\n",medianp);
            }
            else if(strcmp(command,"summary")==0){
                printf("Min        :%lf\n",minp);
                printf("Max        :%lf\n",maxp);
                printf("Mean       :%lf\n",meanp);
                printf("Std Dev    :%lf\n",stdr);
                printf("Median     :%lf\n",medianp);
            }
                
               
            else if(strcmp(command,"hist")==0){
                printf("Enter number of bins: ");
                int bins;
                scanf("%d",&bins);
                if(bins>MAX_BINS){
                    printf("Invalid number of bins\n");
                    continue;
                }
                double bin_width=(maxp-minp)/bins;

                int bin_counts[MAX_BINS]={0};

                 for(int u=0;u<elements;u++){
                    int bin_index=(int)((array[u]-minp)/bin_width);
                    if(bin_index>=bins)
                    bin_index=bins-1;
                    bin_counts[bin_index]++;
                }

                int max_count=bin_counts[0];
                for(int i=1;i<bins;i++){
                    if(bin_counts[i]>max_count){
                        max_count=bin_counts[i];
                    }
                }
                double current_min=minp;

                double current_max=minp + bin_width;

                int star_count;
                
                for(int bin=0;bin<bins;bin++){
                    printf("[ %6.2f - %6.2f ]:",current_min,current_max);
                    star_count = (max_count > MAX_STARS) ? 

                                      
                    (bin_counts[bin] * MAX_STARS / max_count) : 
                                       
                    bin_counts[bin];

                    for(int star=0;star<star_count;star++){
                        printf("*");
                    }
                    printf("\n");

                    current_min= current_max;

                    current_max+=bin_width;
                 
                }
            }
            else if(strcmp(command,"help")==0){
                commands();
            }
            else if(strcmp(command,"exit")==0){
                break;
            }
            else {
                printf("Unknown command. Type 'help' for list of commands");
            }

        }
    }
    return 0;
    
}








