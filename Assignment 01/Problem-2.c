#include <stdio.h>
int main() 
{
  int age;
  int isCitizen;
  printf("Enter your age");
  scanf("%d",&age);
  printf("Are you citizen? (If you are then Enter 1 otherwise enter 0):");
  scanf("%d", &isCitizen);
  if (age >= 18) {
  printf("Old enough to vote.\n");

  if (isCitizen==1) {
    printf("And you are a citizen, so you can vote!\n");
  } else {
    printf("But you must be a citizen to vote.\n");
  } 
} else {
  printf("Not old enough to vote.\n");
  return 0;
}
