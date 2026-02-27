#include<stdio.h>
#include<string.h>
#include<ctype.h>

int numeric = 0;
int reverse= 0;
#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS,QUALIFIERS};
int tokentype;
char token[MAXTOKEN];
char name [MAXTOKEN];
char datatype[MAXTOKEN];
int gettoken(void);
char out[1000];
void dcl(void);
void dirdcl(void);

void dcl(void){
   int ns=0;
   while (tokentype == '*' || tokentype == QUALIFIERS)
   {
    if(tokentype == '*')
    ns++;
    else{
    strcat(out, " ");
    strcat(out, token);   
    
    }
    gettoken();
   }
    
   dirdcl();
   while (ns -- >0)
   strcat(out, "pointer to");
}


void dirdcl(void){
    int type;

    if(tokentype == '('){
        dcl();
        if (tokentype !=')')
        printf("error: missing)\n");
    }

    else if(tokentype == NAME)
    strcpy(name,token);

    else
    printf("error: expected name or (dcl)void\n");

    while((type= gettoken())== PARENS || type == BRACKETS || type== '(' ){
        if(type == PARENS){
            strcat(out, "function returning");
        }
        else if(type == BRACKETS){
            strcat(out, "function returning");
        }
        else if(type == '('){
             strcat(out, "function expecting");
        }

        if(tokentype != ')')
        {
        while(1){
            dcl();
            if(tokentype == ')')
            break;
            strcat(out, ",");
            gettoken();
        }
     }
     strcat(out, "returning");
    }
}

int gettoken(void){
    int c;
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
        if(!strcmp (token, "const") || !strcmp (token, "volatile") || !strcmp (token, "unsigned") || !strcmp (token, "signed") || !strcmp (token, "short") || !strcmp (token, "long") )

        return tokentype = QUALIFIERS;
        return tokentype = NAME;
    }
    else
    token[0]= c;
    token[1]= '\0';
    return tokentype= c;
}

int main(){
   
    while (gettoken() != EOF){
        strcpy (datatype, token);
        out[0]= '\0';
        dcl();
        if(tokentype != '\n')
        printf("syntax error\n");
        printf("%s: %s %s\n", name,out, datatype);
    }
}

#define ALLOCSIZE 1000
static char allocbuf[ALLOCSIZE];
static char *allocp= allocbuf;

char *alloc (int n)
{
    if(allocbuf+ ALLOCSIZE - allocp >= n){
        allocp +=n;
        return allocp -n;

    }else 
    return 0;
}