#include<stdio.h>
// #define in 1
// #define out 0
int main()
{
 int c;

//  state= out;
//  nw=nc=nl=0;
 while((c= getchar())!=EOF){
   if (c=='\t'){
      putchar('\\');
      putchar('t');
   }

   else if (c=='\b'){
      putchar('\\');
      putchar('b');
   }

   else if(c=='\\'){
      putchar('\\');
      putchar('\\');

   }

   else{
      if (c!='\t'){
         if (c!='\b'){
            if(c!='\\'){
               putchar(c);
            }
         }
      }
   }

 }
}

 
   //  ++nc;
   //  if (c=='\n')
   //  ++nl;
   //  if(c==' '|| c=='\n'||c=='\t')
   // //    state= out;
   // // else if (state==out){
   // //  state= in;
   //  ++nw;
   //   }
   //  printf("%d%d%d\n", nw,nl,nc);
// }

// }