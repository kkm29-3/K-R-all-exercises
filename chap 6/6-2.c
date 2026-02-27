#include<stdio.h>
#include<ctype.h>
#include<string.h> 
#include<stdlib.h>
#define MAXWORD 100
int prefixlen=6;
struct wordlist{
    char *word;
    struct wordlist *next;
};

struct tnode{
    char *prefix;
    struct wordlist *list;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *, int);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *p);
struct tnode *talloc();
struct wordlist *walloc();
char *my_strdup(char *);

int main(int argc, char *argv[])
{
    struct tnode *root = NULL;
    char word[MAXWORD];
    if(argc > 1)
        prefixlen= atoi(argv[1]);
    
    while(getword(word,MAXWORD) != EOF)
        if(isalpha(word[0]))
            root= addtree(root,word);
    treeprint(root);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w){
    int cond;
    char pref[MAXWORD];
    strncpy(pref, w , prefixlen);
    pref[prefixlen]='\0';
    if(p== NULL){
        p=talloc();
        p-> prefix= my_strdup(pref);
        p->list = walloc();
        p->list -> word= my_strdup(w);
        p->list -> next = NULL;
        p->left = p-> right = NULL;
    }

    else if((cond= strcmp(pref, p-> prefix)) ==0){
        struct wordlist *wl = p->list;
        while (wl->next != NULL)
        wl = wl ->next;
        wl -> next = walloc();
        wl-> next -> word= my_strdup(w);
        wl->next -> next = NULL;
    }
    else if(cond<0)
        p->left = addtree (p->left, w);
    else
        p->right = addtree(p-> right, w);
    return p;
}

void treeprint(struct tnode *p)
{
    struct wordlist *w;
    if(p!= NULL){
        treeprint(p-> left);
        if(p->list && p->list -> next){
            printf("\nprefix\" %s:\n", p->prefix);
            for(w= p->list; w!= NULL; w= w->next)
                printf("%s\n", w->word);
        }
        treeprint(p-> right);
    }
}

struct tnode *talloc(){
    return(struct tnode *)malloc(sizeof(struct tnode));
}

struct wordlist *walloc(){
    return(struct wordlist *)malloc(sizeof(struct wordlist));
}

char *my_strdup(char* s){
    char *p= malloc(strlen(s)+1);
    if(p)
        strcpy(p,s);
    return p;
}

int getword(char *word, int lim){
    int c;
    char *w = word;
    while(isspace(c= getchar()))
    ;
    if (c=='/'){
        int d= getchar();
        if (d== '/'){
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
    if(c =='"'){
        while((c= getchar()) !='"' && c!= EOF)
        ;
        return getword(word,lim);
    }

    if(!isalpha(c) && c!= '_')
        return c;
        *w++ =c;
    
    while(--lim >0){
        c= getchar();
        if(!isalnum(c) && c!='_'){
            ungetc(c,stdin);
            break;
        }
        *w++ =c;
    }
    *w = '\0';
    return word[0];
}

// int computesum
// int computetotal
// int computeavg
// int computess
// int computessumk