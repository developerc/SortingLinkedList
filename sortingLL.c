#include <stdio.h>
#include <stdlib.h>

typedef struct workers {
 int age;
 char * name;
 struct workers * next;
} empl;

int findCount(empl * head);
empl * compareAge(empl * head, int count);
void printNodes(empl * head, int count);

void main(){
 int count;
 empl * head = NULL;
 empl * emp1 = (empl *) malloc(sizeof(empl));
 head = emp1;
 emp1->age = 40;
 emp1->name = "Donald";
 empl * emp2 = (empl *) malloc(sizeof(empl));
 emp2->age = 21;
 emp2->name = "Tom";
  emp1->next = emp2;
 empl * emp3 = (empl *) malloc(sizeof(empl));
 emp3->age = 22;
 emp3->name = "Bob";
  emp2->next = emp3;
 empl * emp4 = (empl *) malloc(sizeof(empl));
 emp4->age = 23;
 emp4->name = "Jerry";
  emp3->next = emp4;
 empl * emp5 = (empl *) malloc(sizeof(empl));
 emp5->age = 24;
 emp5->name = "Genry";
  emp4->next = emp5;
 empl * emp6 = (empl *) malloc(sizeof(empl));
 emp6->age = 25;
 emp6->name = "Jack";
  emp5->next = emp6;
  emp6->next = NULL;
 count = findCount(emp1);
 printf("count = %d\n", count);
 head = compareAge(head, count);
 printNodes(head, count);
 free(emp6);
 free(emp5);
 free(emp4);
 free(emp3);
 free(emp2);
 free(emp1);
}

void printNodes(empl * head, int count){
 printf("Printing list nodes:\n");
 empl * current = head;
 for(int i=0; i<count; i++){
  printf("age = %d, name = %s\n", current->age, current->name);
  current = current->next;
 }
}


empl * compareAge(empl * head, int count){
 empl * current = NULL;
 empl * begin = NULL;
 empl * first = head;
 empl * second = first->next;
 for(int k=count; k>1; k--){
 //first compare
 if(first->age < second->age){
         first->next = second->next;
         second->next = first;
         begin = second;
 } else {
         begin = first;
 }
 current = begin;
 //next compare
 for(int i=2; i<k; i++){
  first = current->next;
  second = first->next;
  if(first->age < second->age){
         first->next = second->next;
         second->next = first;
         current->next = second;
  }
  current = current->next;
 }
 first = begin;
 second = first->next;
 }

 return begin;
}

int findCount(empl * head){
 empl * current = head;
 int count = 0;
 while (current != NULL){
  count += 1;
  printf("age = %d, name = %s\n", current->age, current->name);
  current = current->next;
 }
 return count;
}
