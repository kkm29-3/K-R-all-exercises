// cross referncer that prints of all words
#include<stdio.h>
#include<ctype.h>
#include<string.h> 
#include<stdlib.h>
#define MAXWORD 100
#define MAXLIST 1000
#define MAXNODES 100

struct tnode *addtree(struct tnode*, char *);
struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
// void treeprint (struct node *p);
void tree_to_array(struct tnode *);

int getword(char *, int);
struct tnode *node_array[MAXNODES];
int node_count=0;
int compare(const void *a, const void *b){
    struct tnode *x= *(struct tnode **)a;
    struct tnode *y= *(struct tnode **)b;
    return y->count - x->count;
}

void tree_to_array(struct tnode *p){
    if (p!=NULL){
        tree_to_array (p->left);
        node_array[node_count++]=p;
        tree_to_array(p->right);
    }
}

//addtree: add a node with w at or below p
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if(p==NULL){
        p=malloc(sizeof (struct tnode));
        p->word = strdup(w);
        p->count =1;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0)
    p->count++;
    else if(cond <0)
    p-> left = addtree(p-> left, w);
    else 
    p->right = addtree(p-> right, w);
    return p;
}


//get next word
int getword(char *word, int lim){
  int c;
  char *w= word;
  while(isspace(c=getchar()))
  ;
  if(c!= EOF)
  *w++ =c;
  if(!isalpha(c))
  {
    *w = '\0';
    return c;
  }for(; --lim >0; w++)
  if(!isalnum (*w = getchar())){
    ungetc(*w, stdin);
    break;
  }
  *w = '\0';
  return word[0];
}

// word frequency count
int main()
{
    struct tnode *root= NULL;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF)
    if(isalpha(word[0]))
    root = addtree(root, word);
    tree_to_array(root);
    qsort(node_array, node_count, sizeof(struct tnode*), compare);
    for (int i=0; i<node_count; i++)
    printf("%4d %s\n", node_array[i]-> count,node_array[i]->word);
    return 0;
}

//  this is a test this is only a test