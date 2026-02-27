// delete same character from s2 to s1
#include<stdio.h>
#define MAX 100
int squeeze(char str1[],char str2[]);


int squeeze(char str1[],char str2[]){
    int i,j,k;
    
    for (k=0; str2[k]!='\0'; ++k){
        for (i=j=0;str1[i]!='\0';++i){
            
            if (str1[i]!=str2[k])
            {
                str1[j++]=str1[i];
            }
        }
        str1[j]='\0';
        
    }
}

// int main(){
//     char str1[MAX]= "abcd";
//     char str2[MAX]= "bgjtsci";

//     squeeze(str1,str2);
//     printf("new str1 :%s\n", str1);
// }




// user input
int main(){
    char str1[100];
    char str2[100];
    printf("str1: ");
    scanf("%s", str1);
   
    printf("str1: ");
    scanf("%s", str2);
    
    squeeze(str1,str2); 
    printf("diff char in str1 from str2: %s", str1);
    
}


