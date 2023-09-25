#include <iostream>

using namespace std;

int main() { 
 int dgt, scl, i, a; 
 cin >> dgt; 
 cin >> scl; 
 
 if (dgt < 0 || dgt > 9){ 
  printf("digit must be 0~9"); 
 } 
 else if(scl < 3 || scl > 10){ 
  printf("scale must be 3~10"); 
 } 
 else{ 
  if (dgt == 0){ 
   printf(" "); 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
   printf(" \n"); 
   for(a=0; a<scl; a++){ 
    for(i=0; i<scl; i++){ 
     printf("*"); 
     for(i=0; i<scl; i++){ 
     printf(" "); 
     } 
     printf("*\n"); 
    } 
   } 
   printf(" "); 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
   printf(" "); 
  } 
  if(dgt == 1){ 
   for(i=0; i<scl; i++){ 
    printf("*\n"); 
   } 
  } 
  if(dgt == 2){ 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
   printf(" \n"); 
   for(i=0; i<scl; i++){ 
    for(a=0; a<scl; a++){ 
     printf(" "); 
    } 
    printf("*\n"); 
   } 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
   printf("\n"); 
   for(i=2; i<scl; i++){ 
    printf("*\n"); 
   } 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
  } 
  if(dgt == 3){ 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
   printf(" \n"); 
   for(a=0; a<scl; a++){ 
    for(i=0; i<scl; i++){ 
     printf(" "); 
    } 
    printf("*\n"); 
   } 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
   printf(" \n"); 
   for(a=0; a<scl; a++){ 
    for(i=0; i<scl; i++){ 
     printf(" "); 
    } 
    printf("*\n"); 
   } 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
  } 
  if(dgt == 4){ 
   for(i=1; i<scl; i++){ 
    printf("*"); 
    for(a=2; a<scl; a++){ 
     printf(" "); 
    } 
    printf("*\n"); 
   } 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
   printf("\n"); 
   for(i=1; i<scl; i++){ 
    for(a=1; a<scl; a++){ 
     printf(" "); 
    } 
    printf("*\n"); 
   } 
  } 
  if(dgt == 5){ 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
   printf("\n"); 
   for(a=2; a<scl; a++){ 
    printf("*\n"); 
   } 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
   printf("\n"); 
   for(a=2; a<scl; a++){ 
    for(i=1; i<scl; i++){ 
     printf(" "); 
    } 
    printf("*\n"); 
   } 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
  } 
  if(dgt == 6){ 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
   for(i=2; i<scl; i++){ 
    printf("\n*"); 
   } 
    
   printf("\n"); 
   for(i=0; i<scl; i++){ 
   printf("*"); 
   } 
   for(a=2; a<scl; a++){ 
    printf("\n*"); 
    for(i=2; i<scl; i++){ 
    printf(" "); 
    } 
    printf("*"); 
   } 
   printf("\n"); 
   for(i=0; i<scl; i++){ 
    printf("*"); 
   } 
  } 
  if(dgt == 7){ 
   for(i=0; i < scl; i++){ 
    printf("*"); 
   } 
   printf("\n"); 
   for(a=1; a < scl; a++){ 
    for(i=1; i < scl; i++){ 
     printf(" "); 
    } 
    printf("*\n"); 
   } 
  } 
  if(dgt == 8){ 
   printf(" "); 
   for(i=0; i < scl; i++){ 
    printf("*"); 
   } 
   printf(" \n"); 
   for(a=0; a < scl; a++){ 
    printf("*"); 
    for(i=0; i < scl; i++){ 
     printf(" "); 
    } 
    printf("*\n"); 
   } 
   printf(" "); 
   for(i=0; i < scl; i++){ 
    printf("*"); 
   } 
   printf(" \n"); 
   for(a=0; a < scl; a++){ 
    printf("*"); 
    for(i=0; i < scl; i++){ 
     printf(" "); 
    } 
    printf("*\n"); 
   } 
   printf(" "); 
   for(i=0; i < scl; i++){ 
    printf("*"); 
   } 
   printf(" "); 
  } 
  if(dgt == 9){ 
   printf(" "); 
   for(i=0; i < scl; i++){ 
    printf("*"); 
   } 
   printf(" \n"); 
   for(a=0; a < scl; a++){ 
    printf("*"); 
    for(i=0; i < scl; i++){ 
     printf(" "); 
    } 
    printf("*\n"); 
   } 
   printf(" "); 
   for(i=0; i < scl; i++){ 
    printf("*"); 
   } 
   printf(" \n"); 
   for(a=0; a < scl; a++){ 
     
    for(i= -1; i < scl; i++){ 
     printf(" "); 
    } 
    printf("*\n"); 
   } 
     
  } 
 } 
 return 0; 
}
