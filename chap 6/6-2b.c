#include<stdio.h>
#include<ctype.h>
#include<string.h> 
#include<stdlib.h>
#define MAXWORD 100
#define MAXLIST 1000

struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
    char *list[MAXLIST];
};

int prefix=6;

int getword(char *, int);
int iskeywords(char *);
struct tnode *addtree(struct tnode *, char *);

const char *keywords[]={
    "auto", "break", "case", "char", "const", "continue", "default", "unsigned", "void", "volatile", "while"
};

#define NKEYS (sizeof keywords/ sizeof keywords[0])

void treeprint(struct tnode *p)
{
    if(p!= NULL){
        treeprint(p-> left);
        if(p->count >1){
            printf("\nGroup(%.*s...)\n", prefix, p->word);
            for (int i=0;i< p-> count;i++)
             printf("%s\n", p-> list[i]);
        }
        treeprint(p-> right);
    }
}

int main(int argc, char *argv[]){
    struct tnode *root= NULL;
    char word[MAXWORD];
    if(argc>1)
    prefix = atoi(argv[1]);
    while(getword(word, MAXWORD)!=EOF){
        if((isalpha(word[0]) || word[0] == '-' )&& !iskeywords(word))
        root= addtree(root,word);
    }
    treeprint(root);
}

struct tnode *addtree(struct tnode *p, char *w)
{
      int cond; 
    if(p== NULL){
        p= malloc(sizeof(struct tnode));
        p->word=strdup(w);
        p->count =1;
        p->left = p-> right = NULL;
        p-> list[0]= p->word;
    }
    else if((cond = strncmp(w,p->word,prefix)) ==0)
    if(strcmp(w,p->word)!=0)
    p->list[p->count++]= strdup(w);
    else if(cond<0)
    p->left = addtree(p-> left,w);
    else
    p->right = addtree(p->right,w);
    return p; 
}

int iskeywords(char *word){
    for (int i=0; i<NKEYS;i++)
        if(strcmp(word, keywords[i])==0);
            return 1;
    return 0;        
}

int getword(char *word, int lim){
    int c, d;
    char *w = word;
    while(isspace(c= getchar()))
    ;
    if (c=='/'){
        if ((d= getchar())=='/'){
            while((c= getchar()) != '\n' && c!= EOF)
            ;
            return getword(word,lim);
        }
        else if(d == '*'){
        while((c= getchar()) != EOF)
        if(c=='*' && getchar() == '/')
        break;
        return getword(word,lim);
        }
        else
        ungetc(d,stdin);
    }
    if(c =='"' || c=='\''){
        int quote=c;
        while((c= getchar()) !=EOF && c!= EOF)
        if(c=='\\')
        getchar();
        return getword(word,lim);
    }
    if(c==EOF)
    return EOF;
    *w++ = c;

    if(isalpha(c) && c!= '-'){
        *w = '\0';
        return c;
    }
    for(; --lim>0; w++){
        c= getchar();
        if(!isalnum(c) && c!='-'){
            ungetc(c,stdin);
            break;
        }
        *w =c;
    }
    *w = '\0';
    return word[0];
}