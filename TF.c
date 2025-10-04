/*#include<stdio.h>
int main(){
    char str[100];
    scanf("%s",str);
    char *p,*q;
    p=str;
    q=str;
    while(*q!='\0'){
        q++;
    }
    q--;
    char tmp;
    while(q>p){
        tmp=*p;
        *p=*q;
        *q=tmp;
        p++;
        q--;
    }
    printf("%s",str);
}*/
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *s;
    s=malloc(80*sizeof(char));
    fgets(s,80,stdin);
    char *portion=strtok(s," ");
    while(portion!=NULL){
    printf("%s\n",portion);
    portion=strtok(NULL," ");
    }
    free(s);
}*/

/*#include<stdio.h>
int isprime(int i){
    if(i<=1) return 0;
    for(int j=2;j*j<=i;j++){
        if(i%j==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int k;
    scanf("%d",&k);
    for(int i=2;i<=k;i++){
        if(isprime(i) && isprime(2*i+1)){
            printf("%d\n",i);
        }
    }
}*/
/*#include<stdio.h>
enum color{
    red,
    green,
    blue
};
int main(){
    enum color show=green;
    const char *colorname[]={"red","green","blue"};
    printf("%s",colorname[show]);
}*/

/*#include<stdio.h>
#include<string.h>
int main(){
    int len;
    char *s="Atik is a good boy";
    len=strlen(s);
    printf("%d",len);
}*/

/*#include<stdio.h>
int main(){
    int n=10;
    int m=1;
    int c=n & m;
    if(c)
    printf("Odd");
    else printf("Even");
}*/

/*#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int m=1;
    m<<=31;
    if(n&m)
    printf("Negative");
    else printf("Positive");
}*/
/*#include<stdio.h>
void printBits(int n){
    unsigned k=1;
    k<<=31;
    for(int i=1;i<=32;i++){
        if(n & k){
            printf("1");
        }
        else printf("0");
         k>>=1;
        if (i%4==0){
            printf(" ");
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printBits(n);
    return 0;
}*/
/*#include<stdio.h>

int setBit(int n, int p){
    unsigned k=1;
    k<<=p;
    return n|k;
}
int setBits(int n,int p,int x){
    for(int i=0;i<x;i++){
        n=setBit(n,p-i);
    }
    return n;
}
int main(){
    int n,p,x;
    scanf("%d%d%d",&n,&p,&x);
    n=setBits(n,p,x);
    printf("%d\n",n);
}*/
/*#include<stdio.h>
int resetBit(int n, int p){
    unsigned m=1;
    m<<p;
    m=~m;
    return n & m;
}*/

/*int rightRotate(int x, int n){
    unsigned y=x;
    int s= 8*sizeof(int)-1;
    return (~(~0<<n)&x) << (s-n+1)|(y>>n);
}*/

/*#include<stdio.h>
char *strrev(char *s){
    char *p,*q;
    p=s;
    while(*p!='\0'){
        p++;
    }
    p--;
    q=s;
    while(q<p){
        char t= *p;
        *p=*q;
        *q=t;
        q++;
        p--;
    }

    return s;
}
int main(){
    char str[]="Atik is a good Boy";
    strrev(str);
    printf("%s",str);
}*/

/*#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    fgets(str,100,stdin);
    char *p=strtok(str," ");
    while(p!=NULL){
        printf("%s\n",p);
        p=strtok(NULL," ");
    }
}*/

/*#include<stdio.h>
#include<stdlib.h>
int main(){
    int m,n,l;
    m=3;
    n=4;
    l=5;
    int ***arr;
    arr=malloc(m*sizeof(int**));
    for(int i=0;i<m;i++){
        arr[i]=malloc(n*sizeof(int*));
        for(int j=0;j<n;j++){
            arr[i][j]=malloc(l*sizeof(int));
        }
    }
}*/

/*#include<stdio.h>
int isprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int main(){
    int k;
    scanf("%d",&k);
    for(int g=1;g<=k;g++){
        if(isprime(g) && isprime(2*g+1)){
            printf("%d ",g);
        }
    }
}*/

/*#include<stdio.h>
int findTrailingZeros(int n){
    unsigned m=1;
    int count=0;
    while((n & m)==0){
        count++;
        m<<=1;
    }
    return count;
}*/

/*#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int dcount=0;
    int acount=0;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            dcount++;
        }
        else if(arr[i]<arr[i+1]){
            acount++;
        }
    }
    if(acount==(n-1)) printf("%c",'A');
    else if(dcount==(n-1)) printf("%c",'D');
    else printf("%c",'U');
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>=max){
            max=arr[i];
        }
    }
    int min=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<=min){
            min=arr[i];
        }
    }
    int k=max-min;
    int usum=0;
    printf("\n%d",k);
    for(int i=0;i<n;i++){
        if(i<n-1 && arr[i]==arr[i+1]) continue;
        else usum+=arr[i];
    }
    printf("\nSum is %d",usum);
}*/

/*#include<stdio.h>
int calculateHindex(int C[],int N){
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(C[j]>C[i]){
                int temp=C[i];
                C[i]=C[j];
                C[j]=temp;
            }
        }
    }
    int max=C[0];
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(C[j]>C[i]){
                max=C[j];
            }
        }
    }
    for(int i=0;i<N;i++){

    }
}
int main(){
    int N;
    scanf("%d",&N);
    int C[N];
    for(int i=0;i<N;i++){
        scanf("%d",&C[i]);
    }
}*/

/*#include<stdio.h>
int main(){
    int n,d=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        d=0;
        for(int j=i+1;j<n;j++){
            if(i!=j && (arr[i]==arr[j])){
                d=1;
            }
        }
        if(d!=1)printf("%d",arr[i]);
    }
}*/
/*#include<stdio.h>
int main(){
    char c;
    scanf("%c",&c);
    printf("%d",c);
}*/

/*#include<stdio.h>
int main(){
    char a;
    scanf("%c",&a);
    int n;
    scanf("%d",&n);
    a=a-'A';
    a=a+n%26;
    a=a+'A';
    printf("%c",a);
}*/

/*#include<stdio.h>
int main(){
    float x;
    scanf("%f",&x);
    int a=0;
    a=(int)x;
    printf("floor value is : %d ",a);
    int z=0;
    if((x-a)>0.5){
        z=(int)(x+1);
    }
    else{
        z=(int)(x);
    }
    printf("Round value is %d",z);
    int y=(int)(x)+1;
    printf("Ceil value is  %d",y);
}*/

/*#include<stdio.h>
int main(){
    int a,b,c;
    a=6;
    b=5;
    c=2;
    if(a>b>c)
    printf("Atik has a gf");
    else printf("No");
}*/

/*#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int max;
    int smax;
    if(a>b){
        max=a;
        smax=b;
    }
    else{
        max=b;
        smax=a;
    }
    if(c>max){
        smax=max;
        max=c;
    }
    else if(c<max && c>smax){
        smax=c;
    }
    printf("%d%d",max,smax);
}*/

/*#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n>=90)
    printf("Yes");
    if(n>=80)
    printf("No");
}*/

/*#include<stdio.h>
int main(){
    int year;
    scanf("%d",&year);
    if(year%400==0 || (year%100!=0 && year%4==0)){
        printf("Leap year");
    }
    else printf("Not leap year");
}*/

/*#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int max,smax;
    max=(a>b)?a:b;
    smax=(a>b)?b:a;
    int d=(max>c)?max:c;
    int e=(max>c)?c:max;
    d=max;
    e=smax;
    printf("%d %d ",max,smax);
}*/
/*#include<stdio.h>
int main(){
    int p1,p2,next;
    int n;
    scanf("%d",&n);
    p1=1;
    p2=1;
    for(int i=3;i<=n;i++){
        next=p1+p2;
        p1=p2;
        p2=next;
    }
    if(n<=2)printf("%d",p1);
    else printf("%d",next);
}*/

/*#include<stdio.h>
int main(){
    int n=1234;
    int t=n;
    int r=0;
    while(t>0){
        int a=t%10;
        r=r*10+a;
        t/=10;
    }
    printf("%d",r);
}*/
/*#include<stdio.h>
int isperfect(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            sum+=i;
        }
    }
    if(sum==n) return 1;
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(isperfect(i))
        printf("%d\n",i);
    }
}*/

/*#include<stdio.h>
int main(){
    int n;
    int isprime;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        isprime=0;
        for(int j=2;j<i;j++){
            if(i%j==0)
            isprime=0;
            else isprime=1;
        }
        if(isprime)printf("%d ",i);
    }
}*/

/*#include<stdio.h>
int main(){
    int n;
    int count=0;
    int a=0,b=1,c;
    scanf("%d",&n);
    if(n>=0){
        printf("0 ");
        count++;
    }
    if(n>=1){
        printf("1 ");
        count++;
    }
    while(1){
        c=a+b;
        if(c>n)break;
        a=b;
        b=c;
        printf("%d ",c);
        count++;
    }
    printf("Fibonacci number upto %d are %d",n,count);
}*/

/*#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}*/

/*#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int space=1;space<=(n-i);space++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}*/

/*#include<stdio.h>
int main(){
    int arr[]={1,3,2,5,8,3};
    int max=(arr[0]>arr[1])?arr[0]:arr[1];
    int smax=(arr[0]>arr[1])?arr[1]:arr[0];
    for(int i=2;i<6;i++){
        if(arr[i]>max){
            smax=max;
            max=arr[i];
        }
        else if(arr[i]<max && arr[i]>smax){
            smax=arr[i];
        }
    }
    printf("%d %d",max,smax);
}*/
/*#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}*/

/*#include<stdio.h>
int fibo(int n){
    int p1,p2;
    int next;
    p1=1;
    p2=1;
    if(n<=2)return 1;
    for(int i=3;i<=n;i++){
        next=p1+p2;
        p1=p2;
        p2=next;
    }
    return next;
}
int main(){
    int n;
    scanf("%d",&n);
    int z=fibo(n);
    printf("%d",z);
}*/

/*#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int p1,p2,next;
    p1=0;
    p2=1;
    for(int i=3;i<=n;i++){
        next=p1+p2;
        p1=p2;
        p2=next;
    }
    printf("%d",next);
}*/

/*#include<stdio.h>
int isprime(int n){
    int i;
    for(i=2;i*i<=n;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
int isfactor(int n,int i){
    if(n%i==0)return 1;
    else return 0;
}
int howmanytimes(int n,int i){
    int count=0;
    while(n%i==0){
        count++;
        n/=i;
    }
    return count;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(isprime(i) && isfactor(n,i))
        printf("%d %d\n",i,howmanytimes(n,i));
    }
}*/

/*#include<stdio.h>
#include<stdlib.h>
int main(){
    int n=5;
    int *a;
    a=malloc(5*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",a[3]);
}*/
/*#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int main(){
    int **a;
    a=(int**)malloc(4*sizeof(int));
    for(int i=0;i<4;i++){
        *(a+i)=(int*)malloc(5*sizeof(int));
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            *(*(a+i)+j)=getchar();
        }
    }
}*/
/*#include<stdio.h>
#include<stdlib.h>

char *strtoks(char *s,char c){
    static char *gstr;
    gstr=s;
    char *r=gstr;
    while(*gstr!='\0' && *gstr!=c)
        gstr++;
    if(*gstr==c){
        *gstr='\0';
        gstr++;
    }
    return r;
}
int main(){
    char str[]="Atik.is.a.good.boy";
    char *token;
    token=strtoks(str,'.');
    while(token!=NULL){
        printf("%s\n",token);
        strtoks(NULL,'.');
    }
}*/

/*#include<stdio.h>
#include<stdlib.h>
char *strtoks(char *s,char c){
    static char *gstr;
    if(s!=NULL){
        gstr=s;
    }
    if(gstr==NULL || *gstr=='\0'){
        return NULL;
    }
    char *r=gstr;
    while(*gstr!='\0' && *gstr!=c){
        gstr++;
    }
    if(*gstr==c){
        *gstr='\0';
        gstr++;
    }
    return r;
}
int main(){
    char str[]="Atik.is.a.good.boy";
    char c='.';
    char *p=strtoks(str,c);
    while(p!=NULL){
        printf("%s\n",p);
        p=strtoks(NULL,c);
    }
}*/


/*#include<stdio.h>
char *strtoks(char *s ,char c){
    static char *gstr;
    if(s!=NULL){
        gstr=s;
    }
    if( gstr==NULL || *gstr=='\0'){
        return NULL;
    }
    char *r=gstr;
    while(*gstr && *gstr!=c){
        gstr++;
    }
    if(*gstr==c){
        *gstr='\0';
        gstr++;
    }
    return r;
}
int main(){
    char str[]="Atik,is,a,good,boy";
    char c=',';
    char *p;
    p=strtoks(str,c);
    while(p){
        printf("%s\n",p);
        p=strtoks(NULL,c);
    }
}*/
// TF 2023 strtok
/*#include<stdio.h>
#include<string.h>
char *strtoks(char *s, char *d){
    static char *gstr;
    if(s!=NULL){
        gstr=s;
    }
    if(gstr==NULL || *gstr=='\0'){
        return NULL;
    }
    char *r=gstr;
    while(*gstr!='\0' && !strchr(d,*gstr)){
        gstr++;
    }
    if(*gstr){
        *gstr='\0';
        gstr++;
    }
    return r;
}

int main(){
    char str[]="Atik,who is a good boy,is my friend";
    char d[]=" ,";
    char *p;
    p=strtoks(str,d);
    while(p!=NULL){
        printf("%s\n",p);
        p=strtoks(NULL,d);
    }
}*/
//--------TF 23-24---------hex to oct----//
/*#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char hex[100];
    scanf("%s",hex);
    int len=strlen(hex);
    int dec=0;
    for(int i=0;i<len;i++){
        if(hex[i]=='A') dec+=10*(pow(16,(len-1-i)));
        else if(hex[i]=='B') dec+=11*(pow(16,(len-1-i)));
        else if(hex[i]=='C') dec+=12*(pow(16,(len-1-i)));
        else if(hex[i]=='D') dec+=13*(pow(16,(len-1-i)));
        else if(hex[i]=='E') dec+=14*(pow(16,(len-1-i)));
        else if(hex[i]=='F') dec+=15*(pow(16,(len-1-i)));
        else dec+=(hex[i]-'0')*(pow(16,(len-1-i)));
    }
    int temp=dec;
    int octalsize=0;
    while(temp!=0){
        temp/=8;
        octalsize++;
    }
    int octal[octalsize];
    int i=octalsize-1;
    while(dec!=0){
        octal[i]=(dec%8);
        dec/=8;
        i--;
    }
    for(int i=0;i<octalsize;i++){
        printf("%d",octal[i]);
    }
}*/

//--------TF---------22-23 1.b)-----//

/*#include<stdio.h>
#include<math.h>
int isprime(int n){
    for(int i=2;i*i<n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    int count=0;
    for(int i=3;i<=n;i++){
        if(isprime(pow(2,i)-1)){
            printf("%d\n",i);
            count++;
            if(count==5) break;
        }
    }
}*/

//--------TF 22-23------1.a)
/*#include<stdio.h>
int main(){
    int speed;
    char q;
    printf("What is the speed ?\n ");
    scanf("%d",&speed);
    getchar();
    printf("Had a previous ticket ? \n");
    scanf("%c",&q);
    if(speed<=100){
        printf("Not applicable\n ");
    }
    else if(speed>=101 && speed<=120 && q=='n'){
        printf("Car is fined 50$\n");
    }
    else if(speed>120 && q=='n'){
        printf("Car is fined 80$\n");
    }
    else if(speed>100 && q=='y'){
        printf("Car is fined 150$\n");
    }
    return 0;
}*/

//------2.b)--------//
/*#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    switch((n%2==0)+(n%5!=0)){
        case 2:printf("Yes");
        break;
        default:printf("No");
    }
}*/
//------------22-23--3.a)-------------//
/*#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    int found;
    for(int i=0;i<N;i++){
        found=0;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                found=1;
                break;
            }
        }
        if(found==1)continue;
        for(int k=i+1;k<N;k++){
            if(arr[i]==arr[k]){
                printf("%d\n",arr[i]);
                break;
            }
        }
    }
}*/
//--------------3.c)----------------//
/*#include<stdio.h>
#include<math.h>
int main(){
    int n,d;
    scanf("%d%d",&n,&d);
    int temp=n;
    int nr=0;
    int count=0;
    while(temp!=0){
        nr=nr*10+(temp%10);
        temp/=10;
        count++;
    }
    int result=d*(pow(10,count))+nr;
    printf("%d",result);
}*/

//------------22-23--------3.b)-----//

/*#include<stdio.h>
int main(){
    int n1,n2;
    printf("Please enter number of elements : ");
    scanf("%d%d",&n1,&n2);
    int arr1[n1],arr2[n2];
    printf("Please enter the digits for array 1 : ");
    for(int i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Please enter the digits for array 2 : ");
    for(int j=0;j<n2;j++){
        scanf("%d",&arr2[j]);
    }
    int found;
    for(int i=0;i<n1;i++){
        found=0;
        for(int j=0;j<n2;j++){
            if(arr1[i]==arr2[j]){
                found=1;
                break;
            }
            else{
                found=0;
            }
        }
        if(!found)printf("%d\n",arr1[i]);
    }
}*/

/*#include<stdio.h>
#include<stdlib.h>
char *string(char *s , int n){
    int temp=n;
    int i=0;
    while(temp!=0){
        s[i++]=temp%10+'0';
        temp/=10;
    }
    s[i]='\0';
    char *p=s;
    while(*p!='\0'){
        p++;
    }
    p--;
    char *q;
    q=s;
    while(q<p){
        char t=*q;
        *q=*p;
        *p=t;
        p--;
        q++;
    }
    return s;
}
int main(){
    int n;
    scanf("%d",&n);
    char str[1000];
    string(str,n);
    printf("%s",str);
}*/

/*#include<stdio.h>
int truncate(float x){
    return (int)(x);
}
int rounding(float x){
    x=x-0.5;
    return (int)(x);
}
int ceiling(float x){
    return (int)(x);
}
int main(){
    float x;
    scanf("%f",&x);
    printf("%d %d %d",truncate(x),rounding(x),ceiling(x));
}*/
//------------22-23-----5.a)----//
/*#include<stdio.h>
int main(){
    char str[100];
    fgets(str,sizeof(str),stdin);
    int len=0;
    while(str[len]!='\0'){
        len++;
    }
    int i;
    for(int i=0;i<len/2;i++){
        char temp=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]=temp;
    }
    str[len]='\0';
    printf("%s",str);
}*/

//------------22-23--------5.b)--//

/*#include<stdio.h>
#include<string.h>
int main(){
    char str[5];
    fgets(str,5,stdin);
    for(int j=0;j<strlen(str);j++){
        str[j]='a'+(str[j]-'a'+2)%26;
    }
    printf("%s",str);
}*/

// #include<stdio.h>
// #include<math.h>

// int isprime(int n)
// {
//     for(int i=2;i*i<=n;i++){
//         if(n%i==0) return 0;
//     }
//     return 1;
// }
// int main()
// {
//     int n;
//     int count=0;
//     scanf("%d",&n);
//     for(int i=2;i<=n;i++)
//     {
//         if(isprime((pow(2,i)-1)))
//         {
//             printf("%d\n",i);
//             count++;
//         }
//         if(count==5)break;
//     }
// }
// #include<stdio.h>
// #include<math.h>
// int isprime(int n)
// {
//     for(int i=2;i*i<=n;i++)
//     {
//         if(n%i==0)return 0;
//     }
//     return 1;
// }
// int main()
// {
//     int n;
//     int count=0;
//     scanf("%d",&n);
//     int p;
//     for(int i=2;i<=n;i++)
//     {
//         p=pow(2,i)-1;
//         if(isprime(p))
//         {
//             printf("%d\n",p);
//             count++;
//         }
//         if(count==5)break;
//     }
// }
// #include<stdio.h>
// int main(){
//     int m,n;
//     int count=0;
//     scanf("%d%d",&m,&n);
//     unsigned a=1<<31;
//     int b=m^n;
//     while(b)
//     {
//         if((a&b)==0)
//         count++;
//         b>>=1;
//     }
//     printf("Bits in common is %d ",count);
// }

// #include<stdio.h>
// int main()
// {
//     int a,b;
//     int count=0;
//     scanf("%d%d",&a,&b);
//     int r=a & b;
//     while(r){
//         if(r & 1)count++;
//         r>>=1;
//     }
//     printf("%d",count);
// }

// #include<stdio.h>
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     switch((n%2==0)+(n%5!=0)){
//         case 2:printf("YES");
//         break;
//         case 1:printf("NO");
//         break;
//     }
// }

// #include<stdio.h>
// int main()
// {
//     int N;
//     scanf("%d",&N);
//     int arr[N];
//     for(int i=0;i<N;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     for(int i=0;i<N;i++)
//     {
//         for(int j=0;j<i;j++)
//         {
//             if(arr[j]==arr[i]) continue;
//         }
//         for(int k=i+1;k<N;k++)
//         {
//             if(arr[k]==arr[i])
//             printf("%d ",arr[i]);
//         }
//     }
// }

// #include<stdio.h>
// int main()
// {
//     int n,d;
//     scanf("%d%d",&n,&d);
//     int tmp=n;
//     int r=d;
//     while(tmp!=0){
//         r=r*10+tmp%10;
//         tmp/=10;
//     }
//     printf("%d",r);
// }

// #include<stdio.h>
// #include<stdlib.h>
// char *string(int n)
// {
//     char *str;
//     str=(char*)malloc(n*sizeof(int));
//     int temp=n;
//     int i=0;
//     int r=0;
//     while(temp!=0)
//     {
//         r=r*10+temp%10;
//         temp/=10;
//     }
//     while(r!=0){
//         str[i++]=r%10+'0';
//         r/=10;
//     }
//     str[i]='\0';
//     return str;
//     free(str);
// }
// int main(){
//     int n;
//     scanf("%d",&n);
//     char *str=string(n);
//     printf("%s",str);
// }

// #include<stdio.h>
// int truncate(float x)
// {
//     return (int)x;
// }
// int rounding(float x)
// {
//     return (int)(x-0.5);
// }
// int ceiling(float x)
// {
//     return (int)x;
// }
// int main()
// {
//     float n;
//     scanf("%f",&n);
//     printf("%d\n",truncate(n));
//     printf("%d\n",rounding(n));
//     printf("%d",ceiling(n));
// }

// #include<stdio.h>
// int main()
// {
//     char str[100], reversedStr[100];
//     gets(str);
//     int len=0;
//     int k=0;
//     while(str[k]!='\0'){
//         len++;
//         k++;
//     }
//     k--;
//     for(int i=0;i<len;i++)
//     {
//         reversedStr[i]=str[len-1-i];
//     }
//     puts(reversedStr);
// }

/*#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    fgets(str,sizeof(str),stdin);
    for(int i=0;i<strlen(str);i++)
    {
        str[i]='a'+(str[i]-'a'+2)%26;
    }
    printf("%s",str);
}*/

// #include<stdio.h>
// #include<stdlib.h>
// int **takematrix(int rows,int columns)
// {
//     int **matrix;
//     matrix=(int**)malloc(rows*sizeof(int));
//     for(int i=0;i<rows;i++)
//     {
//         *(matrix+i)=(int*)malloc(columns*sizeof(int));
//     }
//     for(int i=0;i<rows;i++)
//     {
//         for(int j=0;j<columns;j++)
//         {
//             scanf("%d",*(matrix+i)+j);
//         }
//     }
//     return matrix;
// }
// void printMatrix(int **array,int row,int column)
// {
//     for(int i=0;i<row;i++)
//     {
//         for(int j=0;j<column;j++)
//         {
//             printf("%d ",*(*(array+i)+j));
//         }
//         printf("\n");
//     }
// }

// int **multiplyMatrix(int **a,int **b,int rowsA,int columnsA,int rowsB,int columnsB)
// {
//     int **result;
//      result=(int**)malloc(rowsA*sizeof(int));
//     for(int i=0;i<rowsA;i++)
//     {
//         *(result+i)=(int*)malloc(columnsB*sizeof(int));
//     }
//     for(int i=0;i<rowsA;i++)
//     {
//         for(int j=0;j<columnsB;j++)
//         {
//             int sum=0;
//             for(int k=0;k<columnsA;k++)
//             {
//                 sum+=(*(*(a+i)+k))*(*(*(b+k)+j));
//             }
//             *(*(result+i)+j)=sum;
//         }
//     }
//     return result;
// }
// void freeMatrix(int **matrix,int row)
// {
//     for(int i=0;i<row;i++)
//     {
//         free(*(matrix+i));
//     }
//     free(matrix);
// }
// int main()
// {
//     int **mat1=takematrix(3,4);
//     int **mat2=takematrix(4,5);
//     int **mat3=multiplyMatrix(mat1,mat2,3,4,4,5);
//     printMatrix(mat3,3,5);
//     freeMatrix(mat1,3);
//     freeMatrix(mat2,4);
//     freeMatrix(mat3,3);
// }

// #include<stdio.h>
// void swap(int a,int b)
// {
//     int *A=&a;
//     int *B=&b;
//     int *temp;
//     temp=;
//     A=B;
//     B=temp;
// }
// int main()
// {
//     int a=10;
//     int b=30;
//     swap(a,b);
//     printf("%d %d",a,b);
// }

// #include<stdio.h>
// int main()
// {
//     int r,c;
//     printf("Enter the row and column : ");
//     scanf("%d %d",&r,&c);
//     int matrix[r][c];
//     for(int i=0;i<r;i++)
//     {
//         for(int j=0;j<c;j++)
//         {
//             scanf("%d",&matrix[i][j]);
//         }
//     }
//     int max=matrix[0][0];
//     for(int i=0;i<r;i++)
//     {
//         if((matrix[i][i])>max)
//         {
//             max=matrix[i][i];
//         }
//     }
//     printf("Maximum value is : %d\n",max);
//     int min=matrix[0][0];
//     for(int j=0;j<r;j++)
//     {
//         if(matrix[j][j]<min)
//         {
//             min=matrix[j][j];
//         }
//     }
//     printf("Minimum value is : %d",min);
//     return 0;
// }
// #include<stdio.h>
// int fibo(int n)
// {
//     if(n==1)return 0;
//     if(n==2)return 1;
//     return fibo(n-1)+fibo(n-2);
// }
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int x=fibo(n);
//     printf("%d",x);
// }

// #include<stdio.h>
// int fact(int n)
// {
//     if(n==1)return 1;
//     return n*fact(n-1);
// }
// int main()
// {
//     int f;
//     scanf("%d",&f);
//     int r=fact(f);
//     printf("%d",r);
// }
// #include<stdio.h>
// int sum(int *a,int n)
// {
//     if(n==0)return 0;
//     return sum(a,n-1)+a[n-1];
// }
// int main()
// {
//     int a[5]={1,2,4,9,7},n=5;
//     printf("%i",sum(a,n));
//     return 0;
// }
// #include<stdio.h>
// int sum(int n)
// {
//     if(n==0)return 0;
//     int digit=n%10;
//     if(digit%2==0)
//     return digit+sum(n/10);
//     else return sum(n/10);
//     return 0;
// }
// int main()
// {
//     int n=1234;
//     int r=sum(n);
//     printf("%d",r);
// }

// #include<stdio.h>
// #include<stdbool.h>
// bool binary(int arr[],int l,int r,int x)
// {
//     if(l>r)return false;
//     int mid=(l+r)/2;
//     if(x==arr[mid])return true;
//     else if(arr[mid]>x) return binary(arr,l,mid-1,x);
//     else return binary(arr,mid+1,r,x);
// }
// int main()
// {
//     int arr[5]={3,5,6,7,8,};
//     int l=0,r=4;
//     if(binary(arr,l,r,5))printf("Found");
//     else printf("Not found");
// }

#include<stdio.h>
int nthnum(int a,int d,int n)
{
    if(n==1)return a;
    return a+nthnum(a+d);
}
