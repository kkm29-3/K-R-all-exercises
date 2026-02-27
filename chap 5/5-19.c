#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};
int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name [MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
void dirdcl(void);
void dcl(void);

void dcl(void){
    int ns;
    for(ns = 0; gettoken() == '*';ns++)
    ;
    dirdcl();
    while (ns-- >0)
    strcat(out, "pointer to");
}


void dirdcl(void){
    int type;

    if(tokentype == '('){
        dcl();
        // gettoken();
        if (tokentype !=')')
        printf("error: missing)\n");
    }
    else if(tokentype == NAME)
    strcpy(name,token);
    else
    printf("error: expected name or (dcl)void\n");
    while((type= gettoken())== PARENS || type == BRACKETS)
    if(type == PARENS)
    strcat(out, "function returning");
    else{
        strcat(out,"array");
        strcat(out,token);
        strcat(out,"of");
    }
}

int gettoken(void){
    int c,getch();
    void ungetch(int);
    char *p = token;

    while((c=getch()) == ' '|| c=='\t')
    ;
    if(c=='('){
        if((c=getch()) == ')'){
            strcpy(token, "()");
            return tokentype= PARENS;
        }
        else{
            ungetch(c);
            return tokentype = '(';
        }
    } else if(c=='['){
        for(*p++ = c; (*p++ = getch()) !=']' ;)
        ;
        *p = '\0';
        return tokentype = BRACKETS;

    } else if(isalpha(c)){
        for (*p++ = c; isalnum(c=getch());)
        *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }else
    return tokentype= c;
}
//undcl with reduntant parenthesis
int main()
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() !=EOF)
    {
        strcpy (out,token);

        while((type= gettoken())!= '\n'){
            if(type ==PARENS|| type == BRACKETS){
                strcat (out,token);
            }
            else if(type== '*'){

                if(out[0]=='(' || out[0] == '[')
                sprintf(temp, "(*%s)", out);
                else
                sprintf(temp, " *%s", out);
                strcpy(out,temp);
            }

            else if(type == NAME){
                sprintf(temp, "%s  %s",token, out);
                strcpy(out,temp);
            }

            else
            printf("invalid input at %s\n", token);
           
        }
    }
    printf("%s\n",out);
}