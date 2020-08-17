#include "priorityQueue.h"

priorityQueue::priorityQueue() /**costruttore di default della classe priority queue**/
{
    treeQueue=new treeBst(); /**alloco memoria per l'alberoBsT**/
}

void priorityQueue::insertPriorityQueueBst(nodeBst *insertNode) /**metodo che inserisce i nodi nella coda**/
{
    insertPriorityQueuePrivate(insertNode);
}

void priorityQueue::insertPriorityQueuePrivate(nodeBst *insertNode)
{
    treeQueue->insertNodeBst(treeQueue->getRoot(),insertNode); /**richiamo del metodo dell'albero di ricerca per inserire il nodo**/

}

void priorityQueue::printQueue() /**metodo pubblico per stampare la coda di priorità**/
{
    treeQueue->visit(treeQueue->getRoot()); /**richiamo del metodo per la stampa dell'albero di ricerca**/
}

nodeBst *priorityQueue::extractMinQueue() /**metodo pubblico che richiama il metodo privato per l'operazione di estrazione del minimo**/
{
     return extractMinTree(); /**richiamo del metodo privato per l'estrazione dell'albero**/
}

void priorityQueue::increaseKey(unsigned char element) /**tale metodo servirà per incrementare il valore della frequenza nel caso
                                                    in cui si rilevino elementi uguali, altrimenti creiamo e inseriamo semplicemente quell'elemento all'interno della priorityQueue**/
{
    increaseKeyPrivate(element);   /**richiamo del metodo increaseKey però privato**/
}

nodeBst *priorityQueue::extractMinTree() /**metodo privato che richiama il metodo dell'albero per l'estrazione**/
{
    return treeQueue->extractMin();
}
/**Nel metodo sottostante non facciamo altro che prendere un elemento da input e cercare all'interno dell'albero
quell'elemento, se tale elemento è presente allora salviamo la sua frequenza, lo eliminiamo e ricreamo il nodo
con la frequenza aggiornata, se invece esso è null quindi non è stato trovato, semplicemente lo inseriamo nella coda**/
void priorityQueue::increaseKeyPrivate(unsigned char element)
{
   int frequency=1;
    nodeBst *searchElement=NULL;
    searchElement=treeQueue->searchBst(element);

    if(treeQueue->getRoot()!=NULL)
    {
        if(searchElement!=NULL)
        {
             frequency=searchElement->getFrequency(); /**salviamo la frequenza dell'elemento trovato**/
             treeQueue->elimNodeBst(searchElement); /**lo eliminiamo mediante il emtodo elimNodeBst dell'albero di ricerca**/
             searchElement=new nodeBst(element,1); /**creiamo un nodo inizializzandolo ai valori indicati**/
             frequency=frequency+1; /**aumentiamo la frequenza di uno**/
             searchElement->setFrequency(frequency); /**impostiamo la frequenza**/
            insertPriorityQueueBst(searchElement); /**inseriamo il nodo creato**/
        }
        else /**se quindi non è stato trovato**/
        {

            searchElement=new nodeBst(element,1); /**creiamo il nodo mediante costruttore**/
            insertPriorityQueueBst(searchElement); /**e lo inseriamo**/
        }
    }
    else /**se invece la radice è null dell'albero**/
    {

            searchElement=new nodeBst(element,1);  /**allora inseriamo semplicemente il nodo**/
            insertPriorityQueueBst(searchElement);
    }
}
/**il metodo sottostante non fa altro che calcolare il size della coda, quindi ci rifacciamo al size dell'albero **/
int priorityQueue::sizeQueue()
{
    int somma=sizeTree(); /**richiamo del metodo per il calcolo del size dell'albero privato**/
    return somma;
}

int priorityQueue::sizeTree()
{
        int sommaTree=0;
        sommaTree=treeQueue->sizeTreeBst(treeQueue->getRoot());  /**richiamo del metodo sizeTreeBst dll'oggetto treeQueue che ha
                                                                    come input la radice dell'albero**/
        return sommaTree;
}


