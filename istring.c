#ifndef ISTRING_C
#define ISTRING_C

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "istring.h"
#include "istring_newH.h"

char *istring_mk(const char* str){
  if(str != NULL){
    size_t iLength = strlen(str);
    Istring newIstring = malloc(sizeof(_istring) + (sizeof(char) * (iLength + 1)));
    if(newIstring == NULL){
      return NULL;
    }
    else {
      newIstring->length = iLength;
      strcpy(newIstring->string, str);
        
      return newIstring->string;
    }
  }
  else return NULL;
}


void istring_rm(char *str){
  if(str != NULL){
    free(START(str));
  }
}

char *istring_to_string(const char *str){
  if(str == NULL){
    return NULL;
  }
  else {
    char *cString = malloc(strlen(str)+1);
    if(cString == NULL){
      return NULL;
    }
    strcpy(cString,str);
    cString[strlen(str)+1] = '\0';
    return cString;
  }
}

 void checkChars(char *str){
   char *cursor = str;
   int temp = *cursor;
   while(!(temp <= 31 && temp >= 0)){
     temp = *cursor;
     cursor = cursor + 1;
   }
   *(char*)cursor = '\0';
   return;
 }


size_t istrfixlen(char *s){
  checkChars(s);
  if(strlen(s) != START(s)->length){
    START(s)->length = strlen(s); 
  }
  return (size_t)strlen(s);
}

void fillChars(char *cString, int cLength, int oldLength){
  char *repeatChar = cString + cLength - 1;
  char *startChar = cString + cLength + 1;
  while(oldLength >= cLength){
    *startChar = *repeatChar;
    startChar = startChar + 1;
  }
  return;
}

char* istrslen(char *s, size_t length){
  if(strlen(s) < (int)length){
    char *newIstring = istring_mk(s);
    free(s);
    return STRING(newIstring);
  }
  else{
    int oldLength = strlen(s) + 1;
    START(s)->length = (int)length;
    fillChars(s, (int)length, oldLength);
    return s; 
  }
}


char *istrchr(const char *s, int c){
  return strchr(s, c);
}
char *istrrchr(const char *s, int c){
  return strrchr(s, c);
}
int istrcmp(const char *s1, const char *s2){
  return strcmp(s1,s2);
}
int istrncmp(const char *s1, const char *s2, size_t n){
  return strncmp(s1,s2,(int)n);
}
size_t istrlen(const char *s){
  return (int)(START(s)->length);
}

char *istrcpy(char *dst, const char *src){
  Istring iStr = (Istring) dst;
  size_t length = 0;
  
  while(src[length] != '\0'){
    iStr->string[length] = src[length];
    length++;
  }
  iStr->string[length] = '\0';
  iStr->length = length;

  return STRING(dst);
}

char *istrncpy(char *dst, const char *src, size_t n){
  Istring iStr = (Istring) dst;
  size_t length = 0;

  while(length < n){
    iStr->string[length] = src[length];
    length++;
  }
  iStr->string[length] = '\0';
  iStr->length = (int)n;
  return dst;
}
char *istrcat(char *dst, const char *src){
  int sizeDst = strlen(dst);
  int sizeSrc = strlen(src);

  Istring iStr = (Istring)dst;
  for(int i = sizeDst; i >= 0; i--){
    iStr->string[i] = dst[i];
  }

  for(int length = 0; length <= sizeSrc;length++){
    iStr->string[sizeDst+length] = src[length];
  }
  
  iStr->string[sizeDst+sizeSrc+1] = '\0';
  
  iStr->length= sizeDst+sizeSrc;
  return dst;
}
char *istrncat(char *dst, const char *src, size_t n){
  int sizeDst = strlen(dst);

  Istring iStr = (Istring)dst;
  for(int i = sizeDst; i >= 0; i--){
    iStr->string[i] = dst[i];
  }
  
  for(int length = 0; length < n;length++){
    iStr->string[sizeDst+length] = src[length];
  }
  
  iStr->string[sizeDst+n+2] = '\0';
  
  iStr->length= sizeDst+n;

  return dst;

}

#endif
