#include<stdio.h>
int expand(char s1[],char s2[]);
int expand(char s1[],char s2[])
{
   int i=0;
   int j=0; //i index of s1 & j index of s2
   while(s1[i]!='\0'){
    if (s1[i]=='-'&& i>0 && (s1[i+1]!='\0' &&
        (
            s1[i-1]>='a' && s1[i-1]<= 'z'&&
            s1[i+1]>='a' && s1[i+1]<= 'z')||
           ( s1[i-1]>='A' && s1[i-1]<= 'Z'&&
            s1[i+1]>='A' && s1[i+1]<= 'Z')||
            (s1[i-1]>='0' && s1[i-1]<= '9'&&
            s1[i+1]>='0' && s1[i+1]<= '9')
        )
    ){
        char c;
        for(c=s1[i-1]+1; c<=s1[i+1];++c)
            s2[j++]=c;
            ++i;
    }

    else{
        s2[j++] = s1[i];
    }
    ++i;
    }
    s2[j]='\0';
}

//test
int main(){
    char s1[]="a-z0-7";
    char s2[100];
    expand(s1,s2);
    printf("original: %s\n",s1);
    printf("expand: %s",s2);

}