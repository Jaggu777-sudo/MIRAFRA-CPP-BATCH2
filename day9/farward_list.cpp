#include <iostream>
using namespace std;

class ForwardList
{
public:
    int data;
    ForwardList *next;
    ForwardList *head;

    ForwardList(int val)
    {
        data = val;
        next = NULL;
    }

    void addBegin(int val)
    {
        ForwardList *new_node = new ForwardList(val);
        new_node->next = head;
        head = n;
    }

    void addEnd(int val)
    {
        ForwardList *new_node = new ForwardList(val);
        if (!head)
        {
            head = new_node;
            return;
        }
        ForwardList *t = head;
        while (t->next)
            t = t->next;
        t->next = new_node;
    }

    void addMiddle(int val, int pos)
    {
        if (pos <= 0 || !head)
        {
            addBegin(val);
            return;
        }
        ForwardList *t = head;
        for (int i = 1; i < pos && t->next; i++)
            t = t->next;
        ForwardList *n = new ForwardList(val);
        n->next = t->next;
        t->next = n;
    }

    void deleteBegin()
    {
        if (!head)
            return;
        ForwardList *t = head;
        head = head->next;
        delete t;
    }

    void deleteEnd()
    {
        if (!head)
            return;
        if (!head->next)
        {
            delete head;
            head = NULL;
            return;
        }
        ForwardList *t = head;
        while (t->next->next)
            t = t->next;
        delete t->next;
        t->next = NULL;
    }

    void deleteMiddle(int pos)
    {
        if (pos <= 0 || !head || !head->next)
        {
            deleteBegin();
            return;
        }
        ForwardList *t = head;
        for (int i = 1; i < pos && t->next->next; i++)
            t = t->next;
        ForwardList *d = t->next;
        t->next = d->next;
        delete d;
    }

    int count()
    {
        int c = 0;
        ForwardList *t = head;
        while (t)
        {
            c++;
            t = t->next;
        }
        return c;
    }

    void print()
    {
        ForwardList *t = head;
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }

    void reverse()
    {
        ForwardList *p = NULL, *c = head, *n = NULL;
        while (c)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        head = p;
    }
};


int main()
{
    ForwardList list(0);

    list.addBegin(10);
    list.addEnd(20);
    list.addEnd(30);
    list.addMiddle(15, 1);
    list.print();

    list.deleteBegin();
    list.deleteEnd();
    list.print();

    list.addEnd(40);
    list.addEnd(50);
    list.print();

    list.reverse();
    list.print();

    cout << list.count() << endl;

    return 0;
}
