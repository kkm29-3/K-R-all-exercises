#include<stdio.h>
int htoi (const char s[]){
   int i=0;
   int value=0;
   int digit;

   //condition direct on 0x or oX
   if (s[0]=='0' && (s[1]== 'x'|| s[1]=='X')){
      i=2;
   }

   for (i=0; s[i]!= '\0';++i){
      if (s[i]>='0' && s[i]<='9')
         digit = s[i]- '0';
         
         else if (s[i]>='a' && s[i]<='f')
         digit = s[i]-'a'+ 10;

         else if (s[i]>='A' && s[i]<='F')
         digit = s[i]-'A'+ 10;   

      else 
      break;
      value = 16 * value+ digit;
   }
   
   return value;
}


// int main(){
//    int c;
//    scanf("htoi: ");
//    printf("htoi:",c);
// }

int main(){
   printf("htoi: %d\n",htoi("FF"));
}