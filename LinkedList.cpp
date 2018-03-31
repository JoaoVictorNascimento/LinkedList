#include <iostream>

using namespace std;

struct Node {
    int e;
    Node* next;
};

struct LinkedList {
    Node* first;
};

LinkedList* listCreate(){
    LinkedList* l = new LinkedList;
    l->first = NULL;
    return l;
}

void listPrint(LinkedList* l){
    Node* p = l->first;
    cout << "LinkedList [";
    while(p!=NULL){
        cout << p->e << " ";
        p = p->next;
    }
    cout << "]" << endl;
}

//Exercicio 1

bool listEmpty(LinkedList* l){
    if(l->first == NULL){
        return true;
    }
    else{
        return false;
    }
}

//Exercicio 2

int listSize(LinkedList* l){
    int cout = 0;
    Node* node =  l->first;

    while(node!=NULL){
        cout++;
        node = node->next;
    }
    return cout;
}

//Exercicio 3

Node* listFind(LinkedList* l, int e){
    Node* node =  l->first;

    while(node!=NULL){
        if(node->e == e){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

//Exercicio 4

void listInserFirst(LinkedList* l, int e) {
    Node* node = new Node;
    node->e = e;
    node->next = l->first;
    l->first = node;
}

void listInsertLast(LinkedList* l, int e){
    if(l->first == NULL){
        listInserFirst(l,e);
    }
    else{
        Node* p = l->first;

        while(p->next != NULL){
            p = p->next;
        }
        Node* node = new Node;
            node-> e = e;
            node->next = NULL;
            p->next = node;
    }
}

//Exercicio 5

void listRemoveLast(LinkedList* l){
    Node* node =  l->first;

    while(node!=NULL){
        if(node->next->next == NULL){
            delete node->next;
            node->next = NULL;
        }
        node = node->next;
    }
}

//Exercicio 6

void listInsertSorted(LinkedList* l,int e){
    Node* p = l->first;
    Node* prev = NULL;

    while((p!=NULL)&&(e>p->e)) {
        prev = p;
        p = p->next;
    }

    Node* node = new Node;
    node->e= e;
    node->next = p;
    if(prev!=NULL){
        prev->next = node;
    }
    else{
        l->first = node;
    }
}

//Exercicio 7

void listRemove(LinkedList* l, int e){
    Node* p =  l->first;
    Node* p_next = p->next;

    while(p_next!=NULL){
        if(p_next->e == e){
            if(p_next->next==NULL){
                delete p_next;
                p->next = NULL;
                p->e = NULL;
            }
            else{
                p->next = p->next->next;
                delete p_next;
            }
        }
        p = p->next;
    }
}

//Exercicio 8

bool listEquals(LinkedList* l1, LinkedList*l2){
    Node* i = l1->first;
    Node* j = l2->first;

    int count1 = 0, count2 = 0;

    while(i!=NULL){
        count1++;
        i = i->next;
    }

    while(j!=NULL){
        count2++;
        j = j->next;
    }

    if(count1 != count2){
        return false;
    }

    else{
       i = l1->first;
       j = l2->first;

       while((i!=NULL)&&(j!=NULL)){
            if(i->e != j->e){
                return false;
            }
            i = i->next;
            j = j->next;
        }
    return true;
    }
}
    //Exercicio 9

    bool listCheckSorted(LinkedList* l){
        Node* prev = l->first;
        Node* p = prev->next;

        while(p->next !=NULL){
            if(prev->e < p->e){
                return false;
            }
            prev = p;
            p = p->next;
        }
        return true;
    }

    //Exercicio 10

    void listInsertAll(LinkedList* l, int v[], int n){
        int i = 0;
        while(i<n){
            listInsertLast(l,v[i]);
            i++;
        }
    }

    //Exercicio 11

    LinkedList* listClone(LinkedList* l) {
        LinkedList* aux = listCreate();

        Node* p = l->first;
        Node* p_aux = l->first;

        while(p != NULL){
            listInsertLast(aux,p->e);
            p = p->next;
            p_aux = p_aux->next;
        }


        return aux;
    }

    //Exercicio 12

    LinkedList* listConcat(LinkedList* l, LinkedList* l1){
        LinkedList* l2 = listCreate();
        l2 = listClone(l);

        Node* p = l1->first;
        while(p != NULL){
            listInsertLast(l2,p->e);
            p = p->next;
        }
        return l2;
    }

    //Exercicio 13

    LinkedList* listMerge(LinkedList* l1, LinkedList* l2){
        LinkedList* merge = listCreate();
        Node* p_l1 = l1->first;
        Node* p_l2 = l2->first;

        while(p_l1 != NULL){
            listInsertSorted(merge,p_l1->e);
            p_l1 = p_l1->next;
        }

        while(p_l2 != NULL){
            listInsertSorted(merge,p_l2->e);
            p_l2 = p_l2->next;
        }

        return merge;
    }

    //Exercicio 14

    void listPrintR(Node* p){
        if(p == NULL){
            return;
        }
        else{
            cout<< p->e << " ";
            listPrintR(p->next);
        }
    }

    //Exercicio 15
    void listPrintRR(Node* p){
        if(p == NULL){
            return;
        }
        else{
            listPrintRR(p->next);
            cout << p->e << " ";

        }
    }

    //Exercicio 16
    void listFindR(Node* p, int e){
        if(p == NULL){
            cout << "O elemento não esta na lista";
        }

        else if(p->e == e){
            cout << "O elemento esta na lista";
        }

        else{
          listFindR(p->next,e);
        }
    }





int main()
{

    LinkedList* l = listCreate();
    listInsertSorted(l,1);
    listInsertSorted(l,2);
    listInsertSorted(l,3);


    listPrintRR(l->first);

    //listPrint(l);
    return 0;
}
