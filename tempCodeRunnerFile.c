#include<stdio.h>
int main()
{
    int n;
    printf("Enter decimal number : ");
    scanf("%d",&n);
    char hex[100];
    int temp=n;
    int i=0;
    while(temp)
    {
        if(temp%16==10)
        {
            hex[i++]='A';
            temp/=16;
        }
        else if(temp%16==11)
        {
            hex[i++]='B';
            temp/=16;
        }
        else if(temp%16==12)
        {
            hex[i++]='C';
            temp/=16;
        }
        else if(temp%16==13)
        {
            hex[i++]='D';
            temp/=16;
        }
        else if(temp%16==14)
        {
            hex[i++]='E';
            temp/=16;
        }
        else if(temp%16==15)
        {
            hex[i++]='F';
            temp/=16;
        }
        else
        {
            hex[i++]=temp%16+'0';
            temp/=16;
        }
    }
    hex[i]='\0';
    int len=0;
    while(hex[len]!='\0')
    {
        len++;
    }
    for(int i=0;i<len/2;i++)
    {
        char temp=hex[i];
        hex[i]=hex[len-1-i];
        hex[len-1-i]=temp;
    }
    printf("%s",hex);
}