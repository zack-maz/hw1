#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "split.h"

using namespace std;

int main()
{
    Node* odds = NULL;
    Node* evens = NULL;


    Node* in = NULL;
    int newVal = 0;
    int preVal = 100;
    for (int i = 30; i > 0; i--)
    {
      newVal = rand() % 5 + 1;
      //cout << "NEWVAL: " << newVal << endl;
      Node* n = new Node(preVal - newVal, in);
      //Node* n = new Node(i, in);
      in = n;
      cout << in->value << endl;
      preVal -= newVal;
    }


    split(in, odds, evens);




    cout << "------" << endl;
    Node* fill = odds;
    Node* temp = NULL;
    cout << fill->value << endl;
    while (fill->next != NULL)
    {
      temp = fill->next;
      cout << fill->next->value << endl;
      delete fill;
      fill = temp;
    }
    if (fill != NULL) delete fill;

    cout << "------" << endl;
    fill = evens;
    temp = NULL;
    cout << fill->value << endl;
    while (fill->next != NULL)
    {
      temp = fill->next;
      cout << fill->next->value << endl;
      delete fill;
      fill = temp;
    }
    if (fill != NULL) delete fill;

    cout << "------" << endl;
    fill = in;
    if (fill == NULL)
    {
      cout << "IN NULL" << endl;
    }
    
}