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
//     matrix=(int**)malloc(rows*sizeof(int*));
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

// #include<stdio.h>
// int nthnum(int a,int d,int n)
// {
//     if(n==1)return a;
//     return d+nthnum(a,d,n-1);
// }
// int sum(int a,int d,int n)
// {
//     if(n==1)return a;
//     else return (a+(n-1)*d)+sum(a,d,n-1);
// }
// int main()
// {
//     int a=3,d=2,n=2;
//     int r=nthnum(a,d,n);
//     printf("%d\n",r);
//     printf("%d\n",sum(a,d,n));
// }

// #include<stdio.h>
// int rtol(int n)
// {
//     if(n<10)return n;
//     int s=n%10;
//     printf("%d",s);
//     return rtol(n/10);
// }
// int ltor(int n)
// {
//     if(n<10)
//     {
//         printf("%d",n);
//         return;
//     }
//     ltor(n/10);
//     printf("%d",n%10);
// }
// int main()
// {
//     printf("%d\n",rtol(12345));
//     printf("%d\n",ltor(12345));
// }

// #include<stdio.h>
// int max(int arr[],int n)
// {
//     if(n==1)return arr[0];
//     int maxv=max(arr+1,n-1);
//     return (maxv>arr[0]?maxv:arr[0]);
// }
// int main()
// {
//     int array[5]={1,2,3,4,5};
//     int x=max(array,5);
//     printf("%d",x);
// }

// #include<stdio.h>
// int main()
// {
//     FILE *fp;
//     fp=fopen("sample.txt","r+");
//     if(fp==NULL)
//     {
//         fprintf(stderr,"File opening failed");
//         return 1;
//     }
//     //fprintf(fp,"%d %f %c",2,2.5,'s');
//     fseek(fp,0,SEEK_END);
//     fclose(fp);
// }

// #include<stdio.h>
// int main()
// {
//     FILE *fp;
//     int x;
//     fp=fopen("sample.txt","r+");
//     while(1)
//     {
//         int i=fscanf(fp,"%d",&x);
//         if(i==EOF)break;
//         else printf("%d\n",x);
//     }
// }

// #include<stdio.h>
// int main()
// {
//     FILE *fp=fopen("sample.txt","r+");
//     if(fp==NULL)
//     {
//         fprintf(stderr,"File opening failed");
//         return 1;
//     }
//     int num;
//     int sum=0;
//     while(1)
//     {
//         int i=fscanf(fp,"%d",&num);
//         if(i==EOF) break;
//         if(num%2!=0)sum+=num;
//     }
//     fprintf(fp,"Total sum of the odd numbers is : %d",sum);
//     fclose(fp);
// }

// #include<stdio.h>
// int main()
// {
//     FILE *fp1,*fp2;
//     fp1=fopen("new.txt","w+");
//     fp2=fopen("sample.txt","r");
//     char str[100];
//     for(int i=0;i<2;i++)
//     {
//         fgets(str,sizeof(str),fp2);
//         fprintf(fp1,"%s\n",str);
//     }
// }

// #include<stdio.h>
// int main()
// {
//     FILE *fp;
//     fp=fopen("sample.txt","w+");
//     if(fp==NULL)
//     {
//         fprintf(stderr,"File opening failed");
//         return 1;
//     }
//     for(int i=0;i<5;i++)
//     {
//         char name[50];
//         int mark;
//         printf("Enter name of the Student : ");
//         scanf("%s",name);
//         fprintf(fp,"%s ",name);
//         for(int j=0;j<5;j++)
//         {
//             printf("Enter number of the students : ");
//             scanf("%d",&mark);
//             fprintf(fp," Mark for subject %d : %d",j+1,mark);
//         }
//         fprintf(fp,"\n");
//     }
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     FILE *fp;
//     fp=fopen("sample.txt","w+");
//     if(fp==NULL)
//     {
//         fprintf(stderr,"File cannot be opened");
//         return 1;
//     }
//     for(int i=0;i<2;i++)
//     {
//         char name[50];
//         int mark;
//         printf("Enter the name of the student : ");
//         scanf("%s",name);
//         fprintf(fp,"%s",name);
//         for(int j=0;j<5;j++)
//         {
//             printf("Enter mark for subject %d : ",j+1);
//             scanf("%d",&mark);
//             fprintf(fp," %d",mark);
//         }
//         fprintf(fp,"\n");
//     }
//     rewind(fp);
//     char best[50],worst[50];
//     int bestm=0,worstm=0;
//     int bm=-1,wm=999;
//     for(int i=0;i<2;i++)
//     {
//         int a,b,c,d,e;
//         char name[50];
//         fscanf(fp,"%s%d%d%d%d%d",name,&a,&b,&c,&d,&e);
//         int total=a+b+c+d+e;
//         if((total)>bm)
//         {
//             strcpy(best,name);
//             bestm=total;
//             bm=total;
//         }
//         if((total<wm))
//         {
//             strcpy(worst,name);
//             worstm=total;
//             wm=total;
//         }
//     }
//     fclose(fp);
//     printf("%s has got best marks , best mark : %d",best,bestm);
//     printf("%s has got worst marks , worst mark :%d",worst,worstm);
// }

//#include<stdio.h>
// #include<string.h>
// int main()
// {
//     FILE *fp;
//     fp=fopen("sample.txt","w+");
//     if(fp==NULL)
//     {
//         fprintf(stderr,"File opening failed");
//         return 1;
//     }
//     int student;
//     int subject;
//     printf("How many Students are there? : ");
//     scanf("%d",&student);
//     printf("How many subjects? : ");
//     scanf("%d",&subject);
//     int id;
//     for(int i=0;i<student;i++)
//     {
//         printf("Enter Student ID : ");
//         scanf("%d",&id);
//         fprintf(fp,"ID : %d ",id);
//         int mark;
//         int total=0;
//         int m;
//         int highest=0;
//         for(int j=0;j<subject;j++)
//         {
//             printf("Enter number for Subject %d : ",j+1);
//             scanf("%d",&mark);
//             if(mark>highest) highest=mark;
//             fprintf(fp," %d ",mark);
//             total+=mark;
//         }
//         printf("Total and highest mark for student %d is : %d and %d\n",i+1,total,highest);
//         fprintf(fp,"\n");
//     }
//     rewind(fp);
//     fclose(fp);
// } /
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// #include<ctype.h>
// #include<assert.h>

// #define m 5 //assuming m=5(101,103,163,141,129)
// char sub[m][8]={"CSE101","CSE103","EEE163","MATH141","PHY129"};
// int main(){
//     FILE *fp=fopen("marks.txt","r+");
//     assert(fp!=NULL);
//     printf("Do you want to entry a new student's information?(Yes or No) ");
//     char choice[4];
//     scanf("%s",choice);
//     while(strcmp(choice,"Yes")==0){
//         int studentID;
//         printf("Enter Student ID: ");
//         scanf("%d", &studentID);
//         int marks[m];
//         for(int i=0;i<m;i++){
//             printf("Enter %s Marks: ", sub[i]);
//             scanf("%d", &marks[i]);
//         }
//         fprintf(fp, "%d ", studentID);
//         for(int i=0;i<m;i++){
//             fprintf(fp, "%d ",marks[i]);
//         }
//         fprintf(fp, "\n");
//         printf("Do you want to enter another student's information?(Yes or No) ");
//         scanf("%s",choice);
//     }
//     rewind(fp);
//     int studentID[100];
//     int marks[100][m];
//     int num_of_students=0;
//     while(fscanf(fp, "%d", &studentID[num_of_students])==1){
//         for(int j=0;j<m;j++){
//             fscanf(fp, "%d", &marks[num_of_students][j]);
//         }
//         num_of_students++;
//     }
//     printf("Wanna see marks of a particular student?(Yes or No) ");
//     scanf("%s",choice);
//     while(strcmp(choice,"Yes")==0){
//         int id;
//         printf("Enter Student ID: ");
//         scanf("%d", &id);
//         int found = 0;
//         for(int i=0;i<num_of_students;i++){
//             if(studentID[i] == id){
//                 found = 1;
//                 printf("Marks of Student ID %d:\n", id);
//                 for(int j=0;j<m;j++){
//                     printf("%-10s", sub[j]);
//                 }
//                 printf("\n");
//                 for(int j=0;j<m;j++){
//                     printf("%-10d", marks[i][j]);
//                 }
//                 break;
//             }
//         }
//         if(!found) {
//             printf("Student ID %d not found.\n", id);
//         }
//         printf("Wanna see marks of another student?(Yes or No) ");
//         scanf("%s",choice);
//     }
//     int totalmarks[num_of_students];
//     for(int i=0;i<num_of_students;i++){
//         totalmarks[i] = 0;
//         for(int j=0;j<m;j++){
//             totalmarks[i] += marks[i][j];
//         }
//     }
//     printf("%-15s%-15s\n","Student ID","Total Mark");
//     for(int i=0;i<num_of_students;i++){
//         printf("%-15d%-15d\n", studentID[i], totalmarks[i]);
//     }
//     printf("Highest marks in indivisual subject:\n");
//     for(int i=0;i<m;i++){
//         printf("%-10s", sub[i]);
//     }
//     printf("\n");
//     for(int i=0;i<m;i++){
//         int highest = 0;
//         for(int j=0;j<num_of_students;j++){
//             if(marks[j][i] > highest){
//                 highest = marks[j][i];
//             }
//         }
//         printf("%-10d", highest);
//     }
//     printf("\n");
//     fclose(fp);
//     return 0;
// }

// #include <stdio.h>

// int main() {
//     FILE *fp;
//     fp = fopen("sample.txt", "w+");
//     if (fp == NULL) {
//         fprintf(stderr, "File opening failed\n");
//         return 1;
//     }

//     int student, subject;
//     printf("How many Students are there? : ");
//     scanf("%d", &student);
//     printf("How many subjects? : ");
//     scanf("%d", &subject);

//     for (int i = 0; i < student; i++) {
//         int id, mark, total = 0, highest = 0;
//         printf("Enter Student ID : ");
//         scanf("%d", &id);
//         fprintf(fp, "%d ", id);  // Write only the ID

//         for (int j = 0; j < subject; j++) {
//             printf("Enter number for Subject %d : ", j + 1);
//             scanf("%d", &mark);
//             fprintf(fp, "%d ", mark);
//             total += mark;
//             if (mark > highest) highest = mark;
//         }

//         printf("Total and highest mark for student %d is : %d and %d\n", i + 1, total, highest);
//         fprintf(fp, "\n");
//     }

//     // Search for a student ID
//     rewind(fp);
//     int search_id;
//     printf("\nEnter ID to search: ");
//     scanf("%d", &search_id);

//     int id, mark, total, found = 0;
//     while (fscanf(fp, "%d", &id) == 1) {
//         total = 0;
//         if (id == search_id) {
//             for (int i = 0; i < subject; i++) {
//                 fscanf(fp, "%d", &mark);
//                 total += mark;
//             }
//             printf("Total marks for student ID %d: %d\n", id, total);
//             found = 1;
//             break;
//         } else {
//             // Skip marks for this student
//             for (int i = 0; i < subject; i++) {
//                 fscanf(fp, "%d", &mark);
//             }
//         }
//     }

//     if (!found) {
//         printf("Student ID %d not found.\n", search_id);
//     }

//     fclose(fp);
//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     FILE *fp;
//     fp=fopen("sample.txt","r+");
//     if(fp==NULL)
//     {
//         fprintf(fp,"Error opening file");
//         return 1;
//     }
//     int m;
//     while(1)
//     {
//         int i=fscanf(fp,"%d",&m);
//         if(i==EOF)break;
//         printf("%d\n",m);
//     }

// }

// #include<stdio.h>
// typedef struct
// {
//     char name[30];
//     int id;
//     int mark;
//     char cg; 
// }student;
// char CGPA(int mark)
// {
//     if(mark>=80)return 'A';
//     else if(mark>=70)return 'B';
//     else if(mark>=60)return 'C';
//     else if(mark>=50)return 'D';
//     else return 'F';
// }
// float avg(student s[],int N)
// {
//     int sum=0;
//     for(int i=0;i<N;i++)
//     {
//         sum+=s[i].mark;
//     }
//     return sum/N;
// }
// int main()
// {
//     student s[5];
//     for(int i=0;i<5;i++)
//     {
//         printf("Enter Name of the student : ");
//         scanf("%s",s[i].name);
//         printf("Enter Student ID : ");
//         scanf("%d",&s[i].id);
//         printf("Enter Marks : ");
//         scanf("%d",&s[i].mark);
//         s[i].cg=CGPA(s[i].mark);
//         printf("CGPA for student ID %d is : %c\n",s[i].id,s[i].cg);
//     }
// }

// #include<stdio.h>
// #include<string.h>
// typedef struct
// {
//     char name[10];
//     int ID;
//     float cgpa;
// }Student;
// int main()
// {
//     int n;
//     printf("How many Students? : ");
//     scanf("%d",&n);
//     Student s[n];
//     for(int i=0;i<n;i++)
//     {
//         printf("Enter name of the student : ");
//         scanf("%s",s[i].name);
//         printf("Enter Student ID : ");
//         scanf("%d",&s[i].ID);
//         printf("Ënter Student's CGPA : ");
//         scanf("%f",&s[i].cgpa);
//     }
// }
// #include<stdio.h>

// struct student
// {
//     char name[10];
//     int ID;
//     float cgpa;
// };

// void swap(struct student s[],int n)
// {
//     struct student temp;
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=0;j<n-i-1;j++)
//         {
//             if(s[j].cgpa<s[j].cgpa)
//             {
//                 temp=s[j];
//                 s[j]=s[j+1];
//                 s[j+1]=temp;
//             }
//         }
//     }
// }
// int main()
// {
//     int n;
//     printf("How many Students? : ");
//     scanf("%d",&n);
//     struct student s[n];
//     for(int i=0;i<n;i++)
//     {
//         printf("Enter name of the student : ");
//         scanf("%s",s[i].name);
//         printf("Enter Student ID : ");
//         scanf("%d",&s[i].ID);
//         printf("Ënter Student's CGPA : ");
//         scanf("%f",&s[i].cgpa);
//     }
//     swap(s,n);
//     for(int i=0;i<n;i++)
//     {
//         printf("Name : %s ,ID: %d CGPA : %f\n",s[i].name,s[i].ID,s[i].cgpa);
//     }
// }

// #include<stdio.h>
// typedef struct
// {
//     char name[10];
//     int ID;
//     float cgpa;
// }student;

// void swap(student s[],int n)
// {
//     student temp;
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=0;j<n-i-1;j++)
//         {
//             if(s[j].cgpa<s[j+1].cgpa)
//             {
//                 temp=s[j];
//                 s[j]=s[j+1];
//                 s[j+1]=temp;
//             }
//         }
//     }
// }
// int main()
// {
//     int n;
//     printf("How many Students? : ");
//     scanf("%d",&n);
//     student s[n];
//     for(int i=0;i<n;i++)
//     {
//         printf("Enter name of the student : ");
//         scanf("%s",s[i].name);
//         printf("Enter Student ID : ");
//         scanf("%d",&s[i].ID);
//         printf("Ënter Student's CGPA : ");
//         scanf("%f",&s[i].cgpa);
//     }
//     swap(s,n);
//     for(int i=0;i<n;i++)
//     {
//         printf("Name : %s ,ID: %d CGPA : %.2f\n",s[i].name,s[i].ID,s[i].cgpa);
//     }
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     FILE *fp=fopen("sample.txt","r+");
//     int n;
//     scanf("%d",&n);
//     fprintf(fp,"%d\n",n);
//     char str[n][100];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%s",str[i]);
//     }
//     for(int i=0;i<n;i++)
//     {
//         fprintf(fp,"%s\n",str[i]);
//     }
//     for(int i=0;i<n-i;i++)
//     {
//         for(int j=0;j<n-i-1;j++)
//         {
//             if(strcmp(str[j],str[j+1])>0)
//             {
//                 char temp[10];
//                 strcpy(temp,str[j]);
//                 strcpy(str[j],str[j+1]);
//                 strcpy(str[j+1],temp);
//             }
//         }
//     }
//     fseek(fp,0,SEEK_END);
//     for(int i=0;i<n;i++)
//     {
//         fprintf(fp,"\n%s\n",str[i]);
//     }
// }

// #include<stdio.h>
// int main()
// {
//     char str[100];
//     int num=1234;
//     int i=0,j=0;
//     int temp=num;
//     while(temp!=0)
//     {
//         str[i++]=temp%10+'0';
//         temp/=10;
//     }
//     str[i]='\0';
//     i--;
//     while(j<i)
//     {
//         char c=str[j];
//         str[j]=str[i];
//         str[i]=c;
//         j++;
//         i--;
//     }
//     printf("%s",str);
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     //char target=':';
//     char *str="12:130:45:1";
//     //for(int i=0;i<strlen(str);i++)
//     //{
//       //  if(str[i]==target)printf("found at %dnd  position\n",i+1);
//     //}
//     char *q=str;
//     while(q=strchr(q,':'))
//     {
//         if(q)
//         {
//             printf("Found at %d position\n",q-str);
//             q++;
//         }
//     }
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char *const target="bc";
//     char *str="abcdbce";
//     for(int i=0;i<strlen(str);i++)
//     {
//         for(int j=i+1;j<strlen(str);j++)
//         {
//             char temp=str[i+j];
//             if(strcmp(temp,target)==0)
//             {
//                 printf("found at %d position",i);
//             }
//         }
//     }
// }
// #include<stdio.h>
// int main()
// {
//     char str[]="abcdeabed";
//     char target[]="ab";
//     int len1=0;
//     while(str[len1]!='\0')
//     {
//         len1++;
//     }
//     int len2=0;
//     while(target[len2]!='\0')
//     {
//         len2++;
//     }
//     int found;
//     for(int i=0;i<len1;i++)
//     {
//         int found=1;
//         for(int j=0;j<len2;j++)
//         {
//             if(str[i+j]!=target[j])
//             {
//                 found=0;
//                 break;
//             }
//         }
//         if(found)
//         printf("found at %d position ",i);
//     }
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char str[]="I love my country Bangladesh";
//     char *p=strtok(str," ");
//     while(p)
//     {
//         printf("%s\n",p);
//         p=strtok(NULL," ");
//     }
// }

// #include<stdio.h>
// #include<string.h>
// #include<math.h>
// int main()
// {
//     char str[100];
//     scanf("%s",str);
//     int len=strlen(str);
//     int dec=0;
//     for(int i=0;i<len;i++)
//     {
//         if(str[i]=='A')dec+=10*(pow(16,len-i-1));
//         else if(str[i]=='B')dec+=11*(pow(16,len-i-1));
//         else if(str[i]=='C')dec+=12*(pow(16,len-i-1));
//         else if(str[i]=='D')dec+=13*(pow(16,len-i-1));
//         else if(str[i]=='E')dec+=14*(pow(16,len-i-1));
//         else if(str[i]=='F')dec+=15*(pow(16,len-i-1));
//         else dec+=(str[i]-'0')*(pow(16,len-i-1));
//     }
//     printf("Decimal : %d\n",dec);
//     int temp=dec;
//     char oct[100];
//     int j=0;
//     while(temp)
//     {
//         oct[j++]=temp%8+'0';
//         temp/=8;
//     }
//     strrev(oct);
//     printf("Octal : %s",oct);
// }

// #include<stdio.h>
// int main()
// {
//     int n;
//     printf("Enter decimal number : ");
//     scanf("%d",&n);
//     char hex[100];
//     int temp=n;
//     int i=0;
//     while(temp)
//     {
//         if(temp%16==10)
//         {
//             hex[i++]='A';
//             temp/=16;
//         }
//         else if(temp%16==11)
//         {
//             hex[i++]='B';
//             temp/=16;
//         }
//         else if(temp%16==12)
//         {
//             hex[i++]='C';
//             temp/=16;
//         }
//         else if(temp%16==13)
//         {
//             hex[i++]='D';
//             temp/=16;
//         }
//         else if(temp%16==14)
//         {
//             hex[i++]='E';
//             temp/=16;
//         }
//         else if(temp%16==15)
//         {
//             hex[i++]='F';
//             temp/=16;
//         }
//         else
//         {
//             hex[i++]=temp%16+'0';
//             temp/=16;
//         }
//     }
//     hex[i]='\0';
//     int len=0;
//     while(hex[len]!='\0')
//     {
//         len++;
//     }
//     for(int i=0;i<len/2;i++)
//     {
//         char temp=hex[i];
//         hex[i]=hex[len-1-i];
//         hex[len-1-i]=temp;
//     }
//     printf("%s",hex);
// }

// #include<stdio.h>
// int main()
// {
//     int n;
//     printf("Enter decimal number : ");
//     scanf("%d",&n);
//     char hex[100];
//     int temp=n;
//     int i=0;
//     while(temp)
//     {
//         if(temp%16==10)
//         {
//             hex[i++]='A';
//             temp/=16;
//         }
//         else if(temp%16==11)
//         {
//             hex[i++]='B';
//             temp/=16;
//         }
//         else if(temp%16==12)
//         {
//             hex[i++]='C';
//             temp/=16;
//         }
//         else if(temp%16==13)
//         {
//             hex[i++]='D';
//             temp/=16;
//         }
//         else if(temp%16==14)
//         {
//             hex[i++]='E';
//             temp/=16;
//         }
//         else if(temp%16==15)
//         {
//             hex[i++]='F';
//             temp/=16;
//         }
//         else
//         {
//             hex[i++]=temp%16+'0';
//             temp/=16;
//         }
//     }
//     hex[i]='\0';
//     int len=0;
//     while(hex[len]!='\0')
//     {
//         len++;
//     }
//     for(int i=0;i<len/2;i++)
//     {
//         char temp=hex[i];
//         hex[i]=hex[len-1-i];
//         hex[len-1-i]=temp;
//     }
//     printf("%s",hex);
// }

// #include<stdio.h>
// int main()
// {
//     char str[]="aaa";
//     char exp[]="aa";
//     int count=0;
//     for(int i=0;i<3;i++)
//     {
//         int found=1;
//         for(int j=0;j<2;j++)
//         {
//             if(str[i+j]!=exp[j])
//             {
//                 found=0;
//                 break;
//             }
//         }
//         if(found)
//             {
//                 printf("found at %d position\n",i);
//                 count++;
//             }
//     }
//     printf("Found %d times ",count);
// }

/////// Command Line Argument ///////

// #include<stdio.h>
// int main(int argc,char *argv[])
// {
//     printf("Arguments number are %d\n",argc);
//     for(int i=0;i<argc;i++)
//     {
//         printf("Arguments number %d is : %s\n",i,argv[i]);
//     }
// }

// #include<stdio.h>
// int main(int argc,const char *argv[])
// {
//     FILE *fp;
//     fp=fopen(argv[1],"r");
//     if(fp==NULL)
//     {
//         fprintf(stderr,"File not found");
//         return 1;
//     }
//     int num=0;
//     int sum=0;
//     while(1)
//     {
//         int i=fscanf(fp,"%d",&num);
//         if(i==EOF)break;
//         if(num%2!=0)
//         {
//             sum+=num;
//         }
//     }
//     printf("%d",sum);
// }

// #include<stdio.h>
// int main()
// {
//     int n;
//     char c;
//     scanf("%d %c",&n,&c);
//     char x=c-'A';
//     x=(x-n%26+26)%26+'A';
//     printf("%c",x);
// }

// #include<stdio.h>
// int main()
// {
//     int a,b,c;
//     scanf("%d%d%d",&a,&b,&c);
//     int max=0;
//     int smax=0;
//     if(a>b)
//     {
//         max=a;
//         smax=b;
//     }
//     else
//     {
//         max=b;
//         smax=a;
//     }
//     if(c>max)
//     {
//         smax=max;
//         max=c;
//     }
//     else if(c>smax && c<max)
//     {
//         smax=c;
//     }
//     printf("Maximun number is : %d\nSecend Maximum number is : %d",max,smax);
// }

// #include<stdio.h>
// int main()
// {
//     int y;
//     scanf("%d",&y);
//     int i=(((y%400)==0)) || ((y%100!=0) && ((y%4)==0));
    
//     if(i){
//         printf("Leap year");
//     }
//     else printf("Not Leap year");
// }

// #include<stdio.h>
// int main()
// {
//     int max,smax;
//     int a,b,c;
//     scanf("%d%d%d",&a,&b,&c);
//     max=((a>b && a>c)?a:((b>c && b>a)?b:c));
//     printf("%d",max);
// }

// #include<stdio.h>
// int gcd(int a,int b)
// {
//     while(b!=0)
//     {
//         int c=a%b;
//         a=b;
//         b=c;
//     }
//     return a;
// }
// int main()
// {
//     int a,b;
//     scanf("%d%d",&a,&b);
//     int gcdr=gcd(a,b);
//     printf("%d",gcd);
// }

// #include<stdio.h>
// int main()
// {
//     int a=6,b=12;
//     int min=(a<b)?a:b;int max=(a>b)?a:b;
//     int gcd=0;
//     for(int i=2;i<=min;i++)
//     {
//         if(a%i==0 && b%i==0)
//         {
//             gcd=i;
//         }
//     }
//     printf("gcd is : %d\n",gcd);
//     int lcm=(a>b)?a:b;
//     while(1)
//     {
//         if(lcm%a==0 && lcm%b==0)break;
//         lcm++;
//     }
//     printf("%d",lcm);
// }

// #include<stdio.h>
// int main()
// {
//     int arr[]={3,6,4,8,9,15,5};
//     int max=arr[0];
//     int smax=arr[1];
//     if(smax>max)
//     {
//         int t=max;
//         max=smax;
//         smax=t;
//     }
//     for(int i=2;i<7;i++)
//     {
//         if(arr[i]>max)
//         {
//             int t=max;
//             max=arr[i];
//             smax=t;
//         }
//         else if(arr[i]<max && arr[i]>smax)
//         {
//             smax=arr[i];
//         }
//     }
//     printf("Max element %d\nSecond Max element %d",max,smax);
// }

// #include<stdio.h>
// int main()
// {
//     int d=0;
//     int a[]={5,7,3,6,4,5,6,7,8};
//     for(int i=0;i<9;i++)
//     {
//         for(int j=0;j<i;j++)
//         {
//             if(a[i]==a[j]) d=1;
//         }
//         if(!d)
//         printf("%d ",a[i]);
//     }
// }

// #include<stdio.h>
// #include<stdlib.h>

// union restype
// {
//     char name[50];
//     int mark;
//     float cgpa;
// };
// enum tagtype
// {
//     MARK,CGPA
// };
// struct student
// {
//     int roll;
//     enum tagtype tag;
//     union restype result;
// };

// int main()
// {
//     struct student a={130,MARK,{.mark=86}};
//     union restype b;
// }

// #include<stdio.h>
// #include<stdlib.h>
// struct student
// {
//     char name[10];
//     int roll;
//     float cgpa;
// };
// int main()
// {
//     struct student *a=(struct student*)malloc(sizeof(struct student));
// }


//----------Bitwise----------//

// #include<stdio.h>
// int setbit(int x,int p)
// {
//     unsigned int m;
//     m=1<<p;
//     return x|m;
// }
// int setBits(int x,int p,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         x=setbit(x,p-i);
//     }
//     return x;
// }

// #include <stdio.h>
// #include <string.h>

// char *strtoks(char *str, const char *delims)
// {
//     static char *gstr;
//     if (str != NULL)
//         gstr = str; // initialize only on first call

//     if (gstr == NULL  || *gstr == '\0') 
//         return NULL;

//     char *start = gstr;

//     while (*gstr && !strchr(delims, *gstr))
//         gstr++;

//     if (*gstr)
//     {
//         *gstr = '\0'; 
//         gstr++;       
//     }

//     return start;
// }

// int main()
// {
//     char str[] = "..You,live.in;Dhaka.Right!";
//     char delim[]={'.',' ',';','!',','};
//     char *token = strtoks(str, delim); 

//     while (token != NULL)
//     {   if(*token!='\0')
//         printf("%s\n", token);
//         token = strtoks(NULL,delim);
//     }
//     return 0;
// }

// #include<stdio.h>
// #include<string.h>

// char *strtoks(char *s,const char *delim)
// {
//     static char *gstr;
//     if(s!=NULL)gstr=s;
//     if(gstr==NULL || *gstr=='\0')return NULL;
//     char *start=gstr;
//     while(*gstr && !(strchr(delim,*gstr)))gstr++;
//     if(*gstr)
//     {
//         *gstr='\0';
//         gstr++;
//     }
//     return start;
// }
// int main()
// {
//     char str[]="You live;in.Bangleshdesh right?";
//     char delim[]={'.',' ',';','\0'};
//     char *t=strtoks(str,delim);
//     while(t)
//     {
//         printf("%s\n",t);
//         t=strtoks(NULL,delim);
//     }
//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// union restype{int mark;float cgpa;};
// struct persontype
// {
//     unsigned char bloodgroup:2;
//     unsigned char rhfactor:1;
// };
// enum tagtype{MARK,CGPA};
// char *tagnames[2]={"MARK","CGPA"};
// enum blood{A,B,AB,O};
// char *blood[4]={"A","B","AB","O"};
// enum rh{poistive,negative};
// char *rh[2]={"+","-"};
// struct student
// {
//     char *name;
//     int roll;
//     union restype result;
//     struct persontype person;
//     enum tagtype tag;
// };
// int findcode(char *s,char **str,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(strcmp(s,str[i])==0)return i;
//     }
//     return 0;
// }
// void getstruct(struct student *s)
// {
//     s->name=(char*)malloc(31*sizeof(char));
//     printf("\nEnter student's name : ");
//     scanf("%s",s->name);
//     printf("\nEnter roll number : ");
//     scanf("%d",&s->roll);
//     char str[10];
//     printf("\nEnter mark system : ");
//     scanf("%s",str);
//     s->tag=findcode(str,tagnames,2);
//     if(s->tag==MARK){
//         printf("Enter the mark for the student : ");
//         scanf("%d",&s->result.mark);
//     }
//     else
//     {
//         printf("Enter the cgpa for the student : ");
//         scanf("%f",&s->result.cgpa);
//     }
//     char bloods[10];
//     printf("\nEnter the bloodgroup : ");
//     scanf("%s",bloods);
//     s->person.bloodgroup=findcode(bloods,blood,4);
//     char rhfactor[10];
//     printf("\nEnter rh factor");
//     scanf("%s",rhfactor);
//     s->person.rhfactor=findcode(rhfactor,rh,2);
// }
// void initstruct(struct student *t)
// {
//         t->name=(char*)malloc(31*sizeof(char));
// }
// void copy(struct student *a,struct student *b)
// {
//     strcpy(a->name,b->name);
//     a->roll=b->roll;
//     if(a->tag==MARK)a->result.mark=b->result.mark;
//     else a->result.cgpa=b->result.cgpa;
//     a->person.bloodgroup=b->person.bloodgroup;
//     a->person.rhfactor=b->person.rhfactor;
// }
// void freStruct(struct student* a){
//     free(a->name);
// }
// void printstruct(struct student a)
// {
//     printf("\nRoll %d",a.roll);
//     if(a.tag==MARK)
//     printf(" Mark: %d",a.result.mark);
//     else printf(" CGPA: %.2f",a.result.cgpa);
//     printf(" Bloodgroup : %s%s",blood[a.person.bloodgroup],rh[a.person.rhfactor]);
// }
// int main()
// {
//     int n;
//     printf("How many students are there? : ");
//     scanf("%d",&n);
//     struct student a[n];
//     for(int i=0;i<3;i++)
//     {
//         initstruct(&a[i]);
//         getstruct(&a[i]);
//     }
//     for(int i=0;i<n;i++)
//     {
//         printstruct(a[i]);
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(a[j].roll<a[i].roll)
//             {
//                 struct student t;
//                 initstruct(&t);
//                 copy(&t,&a[i]);
//                 copy(&a[i],&a[j]);
//                 copy(&a[j],&t);
//                 freStruct(&t);
//             }
//         }
//     }
//     for (int i=0;i<n;i++){
//         printstruct(a[i]);
//     }
//     for (int i=0;i<n;i++){
//         freStruct(&a[i]);
//     }
//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     int u=0,sa=0,sd=0;
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j]>=arr[i])
//             sa=1;
//             else sa=0;
//             if(arr[j]<=arr[i])
//             sd=1;
//             else sd=0;
//         }
//     }
//     if(sa==1)printf("Sorted and A");
//     else if(sd==1)printf("Sorted and D");
//     else printf("U");
// }

// #include<stdio.h>
// int main(){
//     int n;
//     scanf("%d",&n);
//     int arr[n];
//     int isAsc=1,isDec=1;
//     for(int i=0;i<n;i++)scanf("%d",&arr[i]);
//     for(int i=0;i<n-1;i++)
//     {
//         if(arr[i]>=arr[i+1])isAsc=0;
//         if(arr[i]<=arr[i+1])isDec=0;
//     }
//     if(isAsc)printf("Sorted and A");
//     else if(isDec)printf("Unsorted and D");
//     else printf("U");
// }

// #include<stdio.h>
// int main()
// {
//     int x=20,y=10,z=0;
//     int a=x && !y||z;
//     int b=x++*-y+!z;
//     printf("%d\n%d",a,b);
// }

// #include<stdio.h>
// int main()
// {
//     int i;
//     scanf("%d",&i);
//     if(++i)
//     {
//         int i=50;
//         printf("%d\n",i++);
//     }
//     printf("%d\n",i);
// 
// }

// #include<stdio.h>
// int calculateHindex(int C[],int N)
// {
//     //int arr[]={9,5,4,2,1};
//     int h=0;
//     for(int i=0;i<N;i++)
//     {
//         if(C[i]>(i+1))h=i+1;
//     }
//     return h;
// }
// int main()
// {
//     int arr[]={9,5,4,2,1};
//     int result=calculateHindex(arr,5);
//     printf("%d",result);
// }

// #include<stdio.h>
// struct student
// {
//     char name[30];
//     int roll;
//     float cgpa;
// };
// int main()
// {
//     struct student a;
//     int x=sizeof(a);
//     printf("%d",x);
// }

// #include<stdio.h>
// int main()
// {
//     int n,m; //n->row,m->column
//     scanf("%d%d",&n,&m);
//     int array[n][m];
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             scanf("%d",&array[i][j]);
//         }
//     }
//     int total;
//     int max;
//     for(int i=0;i<n;i++)
//     {
//         total=0;
//         for(int j=0;j<m;j++)
//         {
//             total+=array[i][j];
//         }
//         printf("Total number for student %d is %d\n",i+1,total);
//     }
//     for(int i=0;i<n;i++)
//     {
//         max=array[0][i];
//         for(int j=0;j<m;j++)
//         {
//             if(array[j][i]>max)max=array[j][i];
//         }
//         printf("Maximum number for subject %d is %d\n",i+1,max);
//     }
// }

// #include<stdio.h>
// int main()
// {
//     int n,x;
//     printf("Degree? : ");
//     scanf("%d",&n);
//     printf("Enter value of X : ");
//     scanf("%d",&x);
//     int arr[n+1];
//     printf("Enter the coefficients : ");
//     for(int i=0;i<(n+1);i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     float sum=arr[n];
//     for(int i=n-1;i>=0;i--)
//     {
//         sum=sum*x+arr[i];
//     }
//     printf("%f",sum);
// }

// #include<stdio.h>
// void insert(int a[],int e,int idx,int N)
// {
//     for(int i=N;i>idx;i--)
//     {
//         a[i]=a[i-1];
//     }
//     a[idx]=e;
// }

// #include<stdio.h>

// int *square(int x)
// {
//     int result=x*x;
//     return &result;
// }
// int main()
// {
//     int a=10;
//     int *p;
//     p=sqaure(a);
//     printf("%d",*p);
//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int m,r,c;
//     scanf("%d%d%d",&m,&r,&c);
//     int ***array;
//     array=(int***)malloc(m*sizeof(int**));
//     for(int i=0;i<m;i++)
//     {
//         *(array+i)=(int**)malloc(r*sizeof(int*));
//         for(int j=0;j<r;j++)
//         {
//             *(*(array+i)+j)=(int*)malloc(c*sizeof(int));
//         }
//     }
// }

// #include<stdio.h>
// int countMinBits(int n)
// {
//     int count=0;
//     while(n>0)
//     {
//         count++;
//         n>>=1;
//     }
//     return count;
// }
// int findTrailingZeros(int n)
// {
//     int count=0;
//     unsigned m=1;
//     while(1)
//     {
//         if(!(n&m))
//         {
//             count++;
//             n>>=1;
//         }
//         else break;
//     }
//     return count;
// }
// int allRepeated(int x)
// {
//     int d1,d2;
//     while(x!=0)
//     {
//         d1=x%10;
//         d2=x%100;
//         if(d1^d2)return 0;
//         else x/=100;
//     }
//     return 1;
// }
