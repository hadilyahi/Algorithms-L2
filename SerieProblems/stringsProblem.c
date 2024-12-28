//  STRINGS
#include<stdio.h>
 int main(){
     // problem 1 : Write a program to take a string as input and display its length
     char str[100];
     int i=0;
        printf("Enter the string : ");
         fgets(str, sizeof(str), stdin);
        while(str[i]!='\0' && str[i] != '\n'){
            i++;
        }
        printf("The length of the string is : %d",i);
////////////////////////////////////////////////////////
// problem 2 : Write a program to concatenate two strings. 
    char str1[100],str2[100]; 
    int i=0,j=0;
    printf("Enter the first string : ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string : ");
    fgets(str2, sizeof(str2), stdin);
    while(str1[i]!='\0' && str1[i] != '\n'){
        i++;}
    while(str2[j]!='\0' && str2[j] != '\n'){    
        str1[i]=str2[j];
        i++;
        j++; }
    str1[i]='\0';
    printf("The concatenated string is : %s",str1);
    //////////////////////////////////////////////////////
    // problem 3 :Write a program to check if a string is a palindrome.
     char str[100];
        int i=0,j=0;
        printf("Enter the string : ");
        fgets(str, sizeof(str), stdin);
        while(str[i]!='\0' && str[i] != '\n'){
            i++;
        }   
        i--;
        while(j<i){
            if(str[j]!=str[i]){
                printf("The string is not a palindrome");
                return 0;
            }
            j++;
            i--;
        }
        printf("The string is a palindrome");
    ///////////////////////////////////////////////////
    // problem 4 : Write a program to count the number of vowels and consonants in a string.
     char str[100];
        int i=0,v=0,c=0;
        printf("Enter the string : ");
        fgets(str, sizeof(str), stdin);
        while(str[i]!='\0' && str[i] != '\n'){
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
                v++;
            }
            else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
                c++;
            }
            i++;
        }
        printf("The number of vowels is : %d \n The number of consonants is : %d",v,c); 
////////////////////////////////////////////////////////
// problem 5 : Write a program to find the frequency of each character in a string.
    char str[100], ch;
      int count = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter the character to find: ");
    scanf("%c", &ch);
    for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ch) {
        count++;
    }
    }
    printf("The character '%c' appears %d times.\n", ch, count);

     return 0; 
     }