#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED
#include "header.h"
#include "nodeBst.h"
#include "treeBst.h"
class priorityQueue
{
private:
        treeBst *treeQueue; /**dichiarazione dell'albero**/
        nodeBst *extractMinTree(); /**metodo privato dell'estrazione del minimo dell'albero**/
        void increaseKeyPrivate(unsigned char elem);  /**metodo privato per l'incremento della frequenza**/
        void insertPriorityQueuePrivate(nodeBst *insertNode);/**metodo privato che implementa l'inserimento del nodo**/
        int sizeTree(); /**metodo privato che ritorna la dimensione dell'albero**/
public:
       priorityQueue(); /**costruttore di default**/
      ~priorityQueue(){}; /**distruttore**/
       void insertPriorityQueueBst(nodeBst *insertNode); /**metodo che implementa l'inserimento del nodo**/
       nodeBst *extractMinQueue(); /**metodo che implementa l'estrazione del minimo**/
       int sizeQueue(); /**metodo che ritorna la dimensione dell'albero**/
       void increaseKey(unsigned char elem); /**metodo che implemena l'incremento della frequenza**/
       void printQueue(); /**metodo che stampa la coda**/

};

#endif // PRIORITYQUEUE_H_INCLUDED
