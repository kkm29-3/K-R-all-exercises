// keyword counting program
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stddef.h>
#include<stdlib.h>
#define NKEYS (sizeof keytab/ sizeof keytab)

#define MAXWORD 100
struct key{
    char *word;
    int count;
}keytab[]= {"auto", 0, "break" , 0,"case", 0, "char", 0, "const", 0, "continue", 0, "default",0, "unsigned", 0};


int getword(char *, int);
int binsearch (char *, struct key *, int);
int main()
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        if ((n = binsearch (word, keytab, NKEYS)) >= 0)
        keytab[n].count++;
        // else(!isalpha())
        for(n=0; n< NKEYS; n++)
        if(keytab[n].count >0)
        printf("%4d %s\n", keytab[n].count, keytab[n].word);
        return 0;
    }  
}
//binsearch
int binsearch(char *word, struct key tab[], int n){
    int cond;
    int low,high,mid;

    low=0;
    high= n-1;
    while(low <= high){
        mid= (low+high) /2;
        if((cond = strcmp(word, tab[mid].word)) <0)
        high = mid -1;
        else if(cond >0)
        low = mid +1;
        else
        return mid;
    }
    return -1;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

int getch(void){
    return (bufp>0) ? buf[--bufp]: getchar();
}

void ungetch(int c){
    if(bufp>= BUFSIZE)
    printf("ungetch: too many chacters \n");
    else
    buf[bufp++]=c;
}

//get next word
int getword(char *word, int lim){
    int c, d;
    char *w = word;
    //skip whitespace
    while(isspace (c= getch()))
    ;
    if(c== EOF){
        return EOF; 

    //preprocessor    
    if(c == '#'){
        while((c= getch()) != '\n' && c!= EOF)
        ;
        return getword(word,lim);
    }

    //string constants
    if(c == '"'){
        while((c= getch()) != '"' && c!= EOF)
        if(c== '\\')
        getch();
        return getword(word,lim);
    }
    //character constant
    if(c == '\''){
        while((c= getch()) != '\'' && c!= EOF)
        if(c == '\\')
        getch();
        return getword(word,lim);
    }

    //comment
    if(c=='/'){
        d=getch();
        if(d=='/')
         while((c= getch()) != '\n' && c!= EOF)
        ;
        return getword(word,lim);
    }

        else if(d == '*'){
        while((c=getch()) != EOF){
            if(c == '*' && (d= getch()) == '/')
            ungetch(d);
            break;
        }
        return getword(word,lim);
    }
    else ungetch(d);
    }
    *w++ =c;
    for(; --lim>0; w++){
        c=getch();
        if(!isalnum(c) && c!='-'){
            ungetch(c);
            break;
        }
        *w=c;
    }
    *w='\0';
    return word[0];
    // for(; --lim > 0; w++)
    // if(!isalpha(c) &&c!='-'){
    //     *w = '\0';
    //     return c;
    // }
    // for(; --lim>0; w++){
    //     c=getch();
    //     if(!isalnum(*w = getch())){
    //         ungetch(*w);
    //         break;
    //     }
    // }
    // *w = '\0';
    // return word[0];

}


// int getop(char s[])
// {
//     int i,c;
//     while((s[0]= c= getch()) == ' '|| c=='\t')
//     ;
//     s[1]='\0';
//     if(isdigit(c) && c!='.')
//     return c;
//     i=0;
//     if(isdigit(c))
//     while(isdigit(s[++i] = c= getch()))
//     ;
//     s[i]= '\0';
//     if(c!= EOF)
//     ungetch(c);
//     return c;
// }
