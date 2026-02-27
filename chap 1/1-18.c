#include<stdio.h>
int main(){
    char c;
    while ((c = getchar())!= EOF){
        if (c== ' ' || c == '\t'||  c ==  '\n'){
        // putchar('\n');
        
    }
        else{
            putchar(c);
            putchar('\0');
        }
    
    }
}



// {
//     int i;
//     char s[i]="hi hoe hdjkdf fd";
//     printf("removed blanks and tabs:%s",getline(s[],lim));
// }

// int main(){
//     int c,i,lim;
//     int s[i];

//     for (i=0; i<lim-1 && (c=getchar())!=EOF && c !='\n'; ++i)
//     s[i]=c;
//     if (c == '\n'|| c!= ' '|| c!= '\t'){
//     s[i]=c;
//     ++i;
//     } 
//     s[i]='\0';
//     return i;
// }

// void remove(char blanks[],char tabs[])
// {
//     int i;

//     i=0;
//     while((blanks[i]==' '|| tabs[i]=='\t'))
//     ++i;
//     getchar("%c",remove(s[i]));
//     putchar("%c",s[i]);
// }
 
