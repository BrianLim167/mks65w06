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
  struct node a;
  struct node b;
  struct node c;

  a.next = &b;
  b.next = &c;
  c.next = NULL;

  a.i = 4;
  b.i = 5;
  c.i = 6;

  print_list(&a);

  struct node *f;
  
  f = insert_front(&a,3);

  print_list(f);

  free_list(f);
  
  print_list(f);
  
}
