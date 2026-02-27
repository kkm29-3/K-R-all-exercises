#include<stdio.h>
// #include<string.h>
void reverse(char s[]){
    int i,j;
    char c;
    for(i=0,j=0;s[j]!='\0';++j)
    ;
    --j;

while(i<j){
    c=s[i];
    s[i]=s[j];
    s[j]=c;
    ++i;
    --j;
}
}

void itoa(int n,char s[],int width){
    int i,sign;
    sign=n;
    if(n<0)
    n=-n;
i=0;
do{
    s[i++]=n%10 +'0';

}
while((n/=10)>0);
if(sign<0)
s[i++]='-';

while (i<width)
s[i++]=' ';
s[i]='\0';
reverse(s);
}

// int main(){
//     char s[100]; 
//     int number,width;
//     printf("enter an integer:");
//     scanf("%d",&number);

//     printf("enter max width:");
//     scanf("%d",&width);

//     itoa(number,s,width);
//     printf("number: %d\n",number);
//     printf("string with %d %s\n",width,s);

// }


int main(){
    char s[100];
    int number= -12345;
    int width =10;

    itoa(number,s,width);
    printf("number : %d\n",number);
    printf("str with width %d:%s\n",width,s);
    
}

