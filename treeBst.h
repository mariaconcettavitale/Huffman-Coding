#ifndef TREEBST_H_INCLUDED
#define TREEBST_H_INCLUDED
#include "header.h"
#include "nodeBst.h"

class treeBst
{
private:

        nodeBst *root; ///Dichiarazione radice dell'albero
        nodeBst *treeMinimum(nodeBst *minim); ///metodo privato estrazione del minimo
        void searchPrivate(nodeBst *currNode,nodeBst *head,nodeBst *&found); /**metodo privato per la ricerca all'interno dell'albero**/
public:
        treeBst(); ///costruttore di default
        ~treeBst(){}; ///distruttore
        void insertNodeBst(nodeBst *head,nodeBst *currNode); ///metodo per l'inserimento di un nodo
        void visit(nodeBst *head); ///metodo per la visita dell'albero
        nodeBst *getRoot(){return root;} ///metodo che ritorna la radice
        nodeBst *treeSuccessor(nodeBst *currNode); ///metodo per trovare il successore di un nodo
        void elimNodeBst(nodeBst *elimNode); ///metodo per eliminare un nodo
        nodeBst *searchBst(unsigned char element); ///metodo pubblico per la ricerca
        nodeBst *extractMin(); ///metodo pubblico per l'estrazione del minimo
        int sizeTreeBst(nodeBst *head); ///metodo per calcolare le dimensioni dell'albero
};


#endif // TREEBST_H_INCLUDED
