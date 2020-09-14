// A program that reads a string and writes it with each character on a line and then writes the string inverted, 
// also with one character on each line. And redo the process N number of times. The user enters the value of N.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Function that reads a string of any length, dynamically reallocating the string size
char *inputString(FILE* fp, size_t size){
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}
// Driver function
int main ()
{
    char *a;
    int i,j,t;
    printf("Enter the string:\n");
    a = inputString(stdin, 10);
    t=strlen(a); // get the number of characters in the string
    int l;
    printf("Enter the number of repetitions:\n");
    scanf("%i", &l);  
    if (l<1) l=1;
   for(j=1;j<l+1;j++)
   {
      // write the string with each character on a line
      for(i=0;i<t;i++) printf("%c\n", a[i]); 
      // write the inverted string with each character on a line
      for(i=t-1;i>=0;i--) printf("%c\n", a[i]);
   }
  return 0;
}

