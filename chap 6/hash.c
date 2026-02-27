#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

//hash: form hash value for string s
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval= *s +31 *hashval;
    return hashval % HASHSIZE;
}

int main(){
    unsigned hashval;
    char *hashval =" hello";
    printf("%u", hashval->hashtab);
}