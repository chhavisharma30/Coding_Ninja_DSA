/*Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.*/

#include<iostream>
#include<stdio.h>
using namespace std;

int checkstring(char *t){
 if(*t==NULL){
  return 1;
 }
 char *c=t;
 if(*t=='a'){
  if(*(c+1)=='a'){
   
  return checkstring(t+1);
  }
  else if(*(c+1)=='b'){
   return checkstring(t+1);
  }
  if(*(c+1)==NULL){
   
   return 1;
  }
  else{
   return 0;
  }
 }
 else if(*t=='b'){
  if(*(c+1)=='b'&&*(c+2)=='a'){
   return checkstring(t+2);
  }
  else if(*(c+1)=='b'&&*(c+2)==NULL){
   return 1;
  }
  else{
   return 0;
  }
  
 }
 
}

main(){
 
 char s[100];
 cin>>s;
 char *t;
 t=s;
 if(*t=='a'){
  t=t++;
  
  
  if(checkstring(t)){
   cout<<"valid substring";
  }
  else{
   cout<<"Not a valid substring";
  }
  
 }
 else{
  cout<<"Not a valid substring";
 }
 
 
 
}