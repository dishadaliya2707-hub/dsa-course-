#include <stdio.h>
#include <string.h>

int main(){

//char greeting[] = {'D' , 'I' , 'S' , 'H' , 'A' , '\0' };
//char greeting[3] = {'D' , 'I' , 'S' , 'H' , 'A' , '\0' };
char greeting[50] = "DISHA";

//char greeting[10];
//printf("Enter a string: \n");
//scanf("%s" , greeting);

for (int i = 0; i<9; i++){
    printf("%c" , greeting[i]);
}

printf("\n Greeting message : %s\n", greeting );

char str[] = ",How are you?";
strcat(greeting, str);

printf("\n Greeting message: %s\n", greeting );
return 0;
}