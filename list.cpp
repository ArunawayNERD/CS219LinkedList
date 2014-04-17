/*
 * John Pigott
 * CS219
 * List Homework
 * 4/1/14
 */
#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

int main()
{
    list my_list;

    srand(time(0));    

    cout << "Size: " <<  my_list.size() << endl << endl;
    for(int i = 0; i < 100; i++)
    {
        my_list.push_head(rand() % 100);
    }

    my_list.display_all();

    cout << "\nSize: " << my_list.size() << endl;
    return 0;
}

// consturcter with initializer list causes issues.
// i.e. head doesnt actully point to tail;
/*list::list():tail(new node), head(new node(tail))
  {
    cout << "Head: " << head << endl; 
    cout << "Tail: " << tail << endl; 
    cout << "AfterHead: " << head->nxt_nd <<endl << endl;
  };
*/

//using the method body instead of the init list works perfectly though
list::list()
{
    tail = new node;
    head = new node(tail);
}

void list::push_head(int nw_data)
{
    head->nxt_nd = new node(nw_data, head->nxt_nd);  
}

void list::push_tail(int nw_data)
{
    int length = size();

    node *crt_ptr = head;
    for(int i = 0; i < length; i++)
    {
        if(crt_ptr->nxt_nd != 0)
        {
            crt_ptr = crt_ptr->nxt_nd;
        }
    }
    
    crt_ptr->nxt_nd = new node(nw_data, crt_ptr->nxt_nd);
}

int list::pop_head()
{
    node *old_head = head->nxt_nd;
    int head_data = head->nxt_nd->data;
    
    head->nxt_nd = head->nxt_nd->nxt_nd;
    
    delete old_head;
    old_head = 0;

    return head_data;
}

int list::pop_tail()
{
    int tail_data;
    node *old_tail;
    node *crt_ptr;
    int length = size();

    crt_ptr = head;
    
    //goes to second to last node
    for(int i = 0; i < (length-1); i++)
    {
        if(crt_ptr->nxt_nd != 0)
        {
            crt_ptr = crt_ptr->nxt_nd;
        }
     }
    old_tail = crt_ptr->nxt_nd;
    tail_data = crt_ptr->nxt_nd->data;
    
    crt_ptr->nxt_nd = tail;

    delete old_tail;
    old_tail = 0;

    return tail_data;
}

int list::size()
{
    int size = 0;
    node *crt_ptr; //pointer to current node

    if(head->nxt_nd == tail || head->nxt_nd == 0)
    {
        return 0;
    }
    crt_ptr = head->nxt_nd;
      
    while(crt_ptr != tail)
    {
        if(crt_ptr->nxt_nd != 0)
        {
            crt_ptr = crt_ptr->nxt_nd; //advance to the next node then loop
        }
        
        size += 1;
    }

    return size;
}

void list::display_all()
{
    node *crt_ptr = head->nxt_nd;
    int length = size();

    for(int i = 0; i < length; i++)
    {
        if(crt_ptr != 0)
            cout << "Node " << (i+1) << ": " << crt_ptr->data << endl;
        
        //check if the list ends even though size didnt report it
        if(crt_ptr->nxt_nd == 0)
            break;

        crt_ptr = crt_ptr->nxt_nd;
    } 
}   
