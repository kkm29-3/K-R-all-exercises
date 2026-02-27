#include<stdio.h>
#include<ctype.h>
#include<string.h> 
#include<stdlib.h>
#define MAXWORD 100
#define NOISECOUNT 100
#define MAXLINES 100
struct linelist{int lines[MAXLINES]; int count;};

// struct wordlist *walloc();

struct wordlist{
    char *word;
    struct wordlist *next;
};


struct tnode{
    char *word;
    // int count;
    struct wordlist *list;
    struct linelist l1;
    struct tnode *left;
    struct tnode *right;
};

char *noise[NOISECOUNT]={"the", "and", "is", "of", "a"};

//functions
int getword(char *, int);
int isnoise(char *);
struct tnode *addtree(struct tnode *, char *,int );
void treeprint(struct tnode *);
struct tnode *talloc(void);
char *strdup_(char *);
int linemo=1;

// word frequency count
int main()
{
    struct tnode *root= NULL;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]) && !isnoise(word))
            root = addtree(root,word, linemo);
    treeprint(root);
        return 0;
}

//addtree: add a node with w at or below p
struct tnode *addtree(struct tnode *p, char *w,int line)
{
    int cond;
    if(p==NULL)
    {
        p=talloc();
        p->word = strdup_(w);
        p->l1.lines[0]= line;
        p->l1.count = 1;
        // p->list[0]= p->word;
        p->left = p-> right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0)
        // struct wordlist *wl = p->list;
        if(p-> l1.lines[p->l1.count-1] != line)
            p->l1.lines[p-> l1.count++]= line;
    else if(cond <0)
         p-> left = addtree(p-> left, w,line);
    else 
        p->right = addtree(p-> right, w,line);
    return p;
}

struct wordlist *walloc(){
    return(struct wordlist *)malloc(sizeof(struct wordlist));
}


//treeprint: sorted order of tree at each node
void treeprint(struct tnode *p)
{
    int i;
    // struct wordlist *w;
    if(p!= NULL){
            treeprint(p-> left);
            printf("%15s:", p->word);
       for(i=0; i< p-> l1.count; i++)
            printf("%d", p->l1.lines[i]);
            printf("\n");
       treeprint(p->right);
    }
}

// noise function
int isnoise(char *w){
    for(int i=0; i< NOISECOUNT; i++)
        if(strcmp(w,noise[i])==0)
         return 1;
    return 0;    

}

//talloc: make a tnode
struct tnode *talloc(void){
    return (struct tnode *) malloc (sizeof(struct tnode));
}

//make a duplicate of s
char *strdup_(char *s)
{
    char *p;
    p= (char *) malloc(strlen(s)+1);
    if(p!= NULL)
    strcpy(p,s); 
    return p;
}

//get next word
int getword(char *word, int lim){
    int c;
    char *w= word;
    while((c=getchar()) == ' ' || c== '\t')
    ;
    if(c=='\n')
        linemo++;
    if(c!= EOF)
        *w++ = c;
    if(!isalpha(c)){
        *w='\0';
        return c;
    }
    for(; --lim >0; w++)
        if(!isalnum(*w= getchar())){
            ungetc(*w, stdin);
            break;
    }
    *w = '\0';
    return word[0];
}