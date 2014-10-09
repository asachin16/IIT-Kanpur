#include <stdio.h>
#include<string.h>

char *xyz()
{
   char str[32];
   strcpy(str,"Hello there!");
   return str;
}

int main()
{
  printf("%s",xyz());
}
