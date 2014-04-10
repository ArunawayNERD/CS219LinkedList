#ifndef JP_LIST_H //JP is incase there already is LIST_H somewhere 
#define JP_LIST_H

/*
 * John Pigott
 * CS219
 * List Homework
 * 3/31/14
 */

struct node
{
    node():data(0), nxt_nd(0){};
    node(int nd_data):data(nd_data), nxt_nd(0){};
    node(node *nxt_node):data(0), nxt_nd(nxt_node){};
    node(int nd_data, node *nxt_node):data(nd_data), nxt_nd(nxt_node){};
   
    int data;
    node *nxt_nd;
};

class list
{
    public:
        list();
        void push_head(int);
        void push_tail(int);
        int pop_head(); //removes the head node and returns it
        int pop_tail(); //removes the tail node and returns it
        int size();
        void display_all();
 
    private:
        node *head;
        node *tail; 
};
#endif 
