#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXWORD 100
#define HASHSIZE 101

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval=0;
    while(*s)
    hashval = *s++ + 31 * hashval;
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
struct  nlist *install (char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if((np = lookup(name)) == NULL){
        np= (struct nlist *) malloc(sizeof (*np));
        if(np == NULL || (np-> name = strdup(name)) == NULL)
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

int main(){
    int c;
    char word[MAXWORD];
    int i;
    struct nlist *np;
    while((c= getchar()) !=EOF){
        if(c == '#'){
            scanf("%s" , word);
            if(strcmp(word, "define") == 0){
                char name[MAXWORD], defn[MAXWORD];
                scanf("%s %s", name, defn);
                install (name, defn);
                // skip rest of line
                while ((c=getchar())!= '\n' && c!=EOF)
                ;
            }
            continue;
        }
        if(isalpha(c)){
            i=0;
            word[i++]=c;
            while(isalnum(c= getchar()))
            word[i++]= c;
            word[i]= '\0';
            ungetc(c,stdin);
            if((np= lookup(word)) != NULL)
            printf("%s", np->defn);
            else
            printf("%s", word);
        }
        else{
            putchar(c);
        }
    }
}