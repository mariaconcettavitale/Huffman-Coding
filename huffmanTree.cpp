#include "huffmanTree.h"
/**metodo della classe huffmanTree che crea l'albero di huffman prendendo in input la coda di priorità**/

void huffmanTree::buildHuffman(priorityQueue *codeMinPriority)
{
    nodeBst *x;
    nodeBst *y;
    int size=codeMinPriority->sizeQueue();
        for(int i=0;i<size-1;i++)
        {
            x=codeMinPriority->extractMinQueue(); /**estraggo un minimo utilizzando il metodo extractMinQueue**/
            y=codeMinPriority->extractMinQueue(); /**estraggo un minimo utilizzando il metodo extractMinQueue**/
            nodeBst *z=new nodeBst(x,y); /**creo un nodo utilizzando il costruttore che prende in input i due minimi precedentemente estratti**/
            x->setFather(z); /**setto il padre del primo minimo**/
            y->setFather(z); /**setto il padre del secondo minimo**/
            int frequency=x->getFrequency()+y->getFrequency(); /**imposto la frequenza**/
            z->setFrequency(frequency);  /**inserisco la frequenza precedentemente calcolata al nodo z**/
            z->setElement('*'); /**imposto l'elemento con un carattere qualsiasi**/
            codeMinPriority->insertPriorityQueueBst(z); /**inserisco il nodo creato nella coda**/
          }
rootHuffman=codeMinPriority->extractMinQueue();  /**estraggo l'ultimo minimo e lo assegno alla radice dell'albero**/

}
/**implementazione della visita preorder dell'albero che consiste nel visitare prima la radice, poi il sottoalbero sinistro e
poi il sottoalbero destro**/
void huffmanTree::visitPreorder(nodeBst *head)
{
    if(head!=NULL)
    {
        cout<<"Element: "<<head->getElement()<<endl<<endl;
        cout<<"Frequency: "<<head->getFrequency()<<endl<<endl;
        visitPreorder(head->getSonSxHuffman());
        visitPreorder(head->getSonDxHuffman());
    }
}

