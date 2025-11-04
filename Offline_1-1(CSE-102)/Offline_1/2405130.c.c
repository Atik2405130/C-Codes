#include<stdio.h>

int main(){

int n,k,t,total_energy=0;

scanf("%d",&n);

for(int i=1;i<=n;i++){
        int sum=0,evensum=0,oddsum=0,altsum=0,energylevel=0,sign=-1,con=0,p=0,b=0;

scanf("%d",&k);

for(int r=1;r<=k;r++){
    scanf("%d",&t);

sum+=t;

sign*=-1;

altsum+=t * sign;

if(r%2==0)
    evensum+=t;

else oddsum+=t;
}

for(int a=1;a<=sum;a++){

    if(sum%a==0)

    p++;
}
if(p==2){
    energylevel +=5;
    con++;
}

int real_sum=sum;
do{
        b=b*10+(sum%10);
        sum=sum/10;
}
while(sum!=0);

if(b==real_sum){
    energylevel+=3;
    con++;
}
if(altsum%7==0){
    energylevel+=4;
    con++;
}
if(evensum==oddsum){
    energylevel+=2;
    con++;
}

total_energy+=energylevel;

printf("Row %d:",i);

if(con==4)printf("ULTRA-");

else if(con==3)printf("HIGH-");

else if(con==2)printf("MEDIUM-");

else if(con==1)printf("LOW-");

else printf("INACTIVE-");

printf("Energy Level %d\n",energylevel);
}

printf("Total Energy: %d",total_energy);

return 0;
}














