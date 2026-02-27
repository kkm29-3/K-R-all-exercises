#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN 100
enum {NAME, PARENS, BRACKETS};
int tokentype;
char token[MAXTOKEN];
char name [MAXTOKEN];
char datatype[MAXTOKEN];
int gettoken(void);
char out[1000];
void skip_to_eol();
void dcl(void);
void dirdcl();

int main(){
   
    while (gettoken() != EOF){
        int  error=0;
        strcpy (out, " ");
        if(tokentype != NAME){

            printf("syntax error\n");
    
            skip_to_eol;
            continue;
        }

        strcpy(datatype, token);
        dcl();
        if(!error){
            if(tokentype!= '\n')
                printf("syntax error/n");
            else
            printf("%s: %s %s\n", name,out, datatype);
        }
    }
}

void skip_to_eol(){
    int c;
    while((c=getchar())!= '\n' && c!=EOF)
    ;
}

int gettoken(void){
    int c;
    // void ungetch(int);
    char *p = token;

    while((c=getchar()) == ' '|| c=='\t')
    ;
    if(c=='('){
        if((c=getchar()) == ')'){
            strcpy(token, "()");
            return tokentype= PARENS;
        }
        else{
            ungetc(c,stdin);
            token[0]= '(';
            token[1]= '\0';
            return tokentype = '(';
        }
    } else if(c=='['){
        for(*p++ = c; (*p++ = getchar()) !=']' ;)
        ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if(isalpha(c)){
        for (*p++ = c; isalnum(c=getchar());)
        *p++ = c;
        *p = '\0';
        ungetc(c,stdin);
        return tokentype = NAME;
    }else
    token[0]= c;
    token[1]= '\0';
    return tokentype= c;
}

void dcl(void){
    int ns;
    for(ns = 0; gettoken() == '*';)
    ns++;
    dirdcl();
    while (ns-- >0)
    strcat(out, "pointer to");
}

void dirdcl(){
    int type;

    if(tokentype == '('){
        // gettoken();
        dcl();
        if (tokentype !=')')
        printf("error: missing)\n");
    }
    else if(tokentype == NAME)
    strcpy(name,token);
    else
    printf("error: expected name or (dcl)void\n");
    while((type= gettoken())== PARENS || BRACKETS)
    if(type == PARENS)
    strcat(out, "function returning");
    else{
        strcat(out,"array");
        strcat(out,token);
        strcat(out,"of");
    }
}
