#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXWORD 100
#define BUFSIZE 100

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];
char buf[BUFSIZE];
int bufp =0;


// make a duplicate of s
char *strdup_(char *s)
{
    char *p=malloc(strlen(s)+1);;
    if(p)
        strcpy (p,s); 
    return p;
}


int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch : too many characters\n");
    else
        buf[bufp++] = c;
}

//hash: form hash value for string s
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval= *s +31 *hashval;
    return hashval % HASHSIZE;
}

//lookup: look for s in hashtab
struct nlist *lookup (char *s)
{
    struct nlist *np;
    for(np= hashtab[hash(s)]; np != NULL ; np= np->next)
        if(strcmp(s, np-> name) == 0)
            return np;
    return NULL;
}

//install: put (name,defn) in hashtab
struct  nlist *install (char *name,char *defn)
{
    struct nlist *np;
    unsigned hashval;
    np= (struct nlist *) malloc(sizeof (*np));
    if(np == NULL || (np-> name = strdup(name)) == NULL){
         return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }   
    else
        free((void * ) np->defn);
    if((np->defn = strdup (defn)) == NULL)
        return NULL;
    return np;
}

int getword(char *word, int lim){
    int c,getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace (c= getch()))
    ;
    if(c!= EOF)
    *w++ = c;
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for(; --lim > 0; w++)
    if(!isalnum(*w = getch())){
        ungetch(*w);
        break;
    }
    *w = '\0';
    return word[0];
}

// main program to remove #define
int main(){
    char word[MAXWORD];
    char name[MAXWORD];
    char defn[MAXWORD];

    while(getword(word, MAXWORD) !=EOF){
        if(strcmp(word, "#define") ==0){
            getword(name, MAXWORD);
            getword(defn, MAXWORD);
            install(name, defn);
        }else{
            struct nlist *np= lookup(word);
            if(np)
            printf("%s\n", np->defn);
            else
            printf("%s\n", word);
        }
    }
}