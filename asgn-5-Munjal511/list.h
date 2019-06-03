#ifndef LIST_H
#define LIST_H


typedef struct node {
    Data data;
    struct node * next;
    struct node * prev;
}Node;


typedef struct list {
    
    Node * head;
    Node * tail;
	
	void (*insert)(struct list *, int,Data Data);
	void (*remove)(struct list *, int);
	Data * (*read)(struct list *, int);
	void (*delete)(struct list *);

}List;


List * newList();
void insertData(List * l, int i, Data d);
void removeData(List * l, int i);
Data * readData(List * l, int i);
void deleteList(List * l);

#endif