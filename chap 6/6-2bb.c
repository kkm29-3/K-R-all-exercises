//binary tree using structure, alphabetical order 
#include<stdio.h>
#include<ctype.h>
#include<string.h> 
#include<stdlib.h>
#define MAXWORD 100
#define MAXLIST 1000

int prefix=6;
struct tnode *addtree(struct tnode *, char *);
char *list[MAXLIST];
int count;
void treeprint (struct tnode *p);
int getword(char *, int);
int iskeywords(char *);

const char *keywords[]={
    "auto", "break", "case", "char", "const", "continue", "default", "unsigned", "void", "volatile", "while"
};

struct key{
    char *word;
    int count;
}keytab[]= {"auto", 0, "break" , 0,"case", 0, "char", 0, "const", 0, "continue", 0, "default",0, "unsigned", 0};

#define NKEYS (sizeof keytab/ sizeof keytab[0])

int iskeyword(char *word){
    for (int i=0; i<NKEYS;i++)
        if(strcmp(word, keywords[i])==0);
            return  1;
    return 0;        
}

// //make a duplicate of s
// char *strdup(char *s){
//     char *p;
//     p=(char *) malloc(strlen(s) + 1);
//     if(p!= NULL)
//     strcpy(p,s);
//     return p;
// }

int main(int argc, char *argv[]){
    struct tnode *root= NULL;
    char word[MAXWORD];
    if(argc>1)
    prefix = atoi(argv[1]);
    while(getword(word, MAXWORD)!=EOF){
        if((isalpha(word[0]) || word[0] == '-' )&& !iskeyword(word))
        root= addtree(root,word);
    }
    treeprint(root);
}

// char *strdup(char *s);
int getword(char *word, int lim);
struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *talloc(void);

struct tnode *addtree(struct tnode *p, char *w)
{
      int cond;

    if(p== NULL){
        p= talloc();
        p->word=strdup(w);
        p->count =1;
        p->left = p-> right = NULL;
    }
    else if((cond = strcmp(w,p->word)) ==0)
    p->count++;
    else if(cond<0)
    p->left = addtree (p-> left,w);
    else
    p->right = addtree(p->right,w);
    return p; 
}

// treeprint: sorted order of tree at each node
void treeprint (struct tnode *p)
{
    if(p!= NULL){
        treeprint(p-> left);
        if(p->count >1){
            printf("\nGroup(%.*s...)\n", prefix, p->word);
            for (int i=0;i< p-> count;i++)
             printf("%s\n", p-> left[i]);
        }
        treeprint(p-> right);
    }
}

//make  a tnode
struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

//struct list_node{
//     int iskeyword(char *word){
//         for (int i=0; i<NKEYS; i++)
//         if(strcmp(word, keyword[1]) == 0)
//         return i;
//         return 0;
//     }
// }

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

int getword(char *word, int lim){
    int c, d;
    char *w = word;
    while(isspace (c= getch()))
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
    if(!isalpha(c)){
        *w = '\0';
        // return c;
    }
    for(; --lim>0; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

