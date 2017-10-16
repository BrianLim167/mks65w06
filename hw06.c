#include <stdio.h>
#include <stdlib.h>
#include "hw06.h"

void print_list(struct node *list){
  printf("%d ", list->i);
  if ( list->next == NULL ) printf("\n");
  else print_list( list->next );
}

struct node * insert_front(struct node *list, int n){
  struct node *front = (struct node *) malloc(sizeof(struct node));
  front->next = list;
  front->i = n;
  return front;
}

struct node * free_list(struct node *list){
  while ( list != NULL ){
    struct node *q = list;
    list = list->next;
    free( q );
  }
  return list;
}

int main(){
  struct node *f = (struct node*) malloc(sizeof(struct node));

  f->i = 6;

  print_list(f);
  
  f = insert_front(f,3);
  f = insert_front(f,2);

  print_list(f);

  f = free_list(f);
  
  //print_list(f);
  
}
