/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  split_helper(in, odds, evens);
  in = NULL;




}





void split_helper(Node*& in, Node*& odds, Node*& evens)
{
  if (in == NULL) 
  { 
    if (evens != NULL) evens->next = NULL; 
    if (odds != NULL) odds->next = NULL;
    return; 
  }

  if (in->value % 2 == 0)
  {
    if (evens == NULL) { 
      evens = in; 
      return split_helper(in->next, odds, evens); 
    }
    else { 
      evens->next = in; 
      return split_helper(in->next, odds, evens->next); 
    }
  }
  else
  {
    if (odds == NULL) { 
      odds = in;
      return split_helper(in->next, odds, evens); 
    }
    else { 
      odds->next = in; 
      return split_helper(in->next, odds->next, evens); 
    }
  }


}

// WRITE YOUR CODE HERE