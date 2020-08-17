#include "treeBst.h"

treeBst::treeBst() /**costruttore di default della classe treeBst**/
{
    root=NULL; /**impostiamo il nodo root a NULL**/
}
/**il metodo sottostante non fa altro che inserire il nodo passato come input, currNode**/
void treeBst::insertNodeBst(nodeBst *head,nodeBst *currNode)
{
    if(root==NULL) /**se la radice non e' ancora stata impostata ad un valore**/
    {
        root=currNode; /**impostiamo root a currNode, in questo modo la inizializziamo e creiamo la radice dell'albero**/
        root->setFather(NULL); /**settiamo poi il padre della radice a NULL**/
    }
else /**Se invece la radice è già stata impostata**/
    {
        /**di seguito vi sono i controlli che rispettano le proprietà dell'albero binario di ricerca quindi..**/
        if(currNode->getFrequency()<=head->getFrequency()) /**se la frequenza del nodo che si vuole inserire è minore o uguale alla frequenza della testa**/
        {                                                   /**inseriamo tale nodo a sinistra facendo ulteriori controlli**/
            if(head->getSonSx()==NULL) /**se la testa non ha figli alla sua sinistra, allora inseriamo questo nodo immediatamente alla sua sinistra**/
            {
                currNode->setFather(head); /**impostiamo quindi il padre del nodo corrente**/
                head->setSonSx(currNode); /**e lo settiamo alla sinistra della testa**/
            }
            else /**altrimenti, e cioè se la testa alla sua sinistra ha dei nodi**/
                insertNodeBst(head->getSonSx(),currNode); /**richiamiamo il metodo scendendo a sinistra dell'albero**/

        }

        else /**se invece..**/
        {
            if(currNode->getFrequency()>head->getFrequency()) /**la frequenza del nodo che si vuole inserire è maggiore della frequenza della testa**/
        {                                                      /**inseriamo tale nodo a destra facendo ulteriori controlli**/
            {
                if(head->getSonDx()==NULL) /**se la testa alla sua destra non ha figli, allora inseriamo questo nodo immediatamente alla sua destra**/
                {
                     currNode->setFather(head); /**impostiamo quindi il padre del nodo corrente**/
                      head->setSonDx(currNode);/**e lo settiamo alla destra della testa**/
                }
                else /**altrimenti, e cioè se la testa alla sua destra ha dei nodi**/
                    insertNodeBst(head->getSonDx(),currNode);/**richiamiamo il metodo scendendo a destra dell'albero**/

        }
    }
}
}
}

/**Il metodo sottostante implementa la visita inorder, quindi prima si visita il sottoalbero sinistro, poi la radice e
poi il sottoalbero destro dell'albero**/
void treeBst::visit(nodeBst *head)
{
    if(head!=NULL)
    {
        visit(head->getSonSx());
        cout<<"Element: "<<head->getElement()<<endl<<endl;
        cout<<"Frequency: "<<head->getFrequency()<<endl<<endl;
        visit(head->getSonDx());
    }
}

/**metodo che implementa la ricerca del minimo all'interno dell'albero sfruttando la proprietà dell'albero
di ricerca e cioè, sapendo che a sinistra si troverà sempre un numero inferiore rispetto alla radice ed infatti
scendiamo a sinistra dell'albero fino alle foglie, arrivati alle foglie ritorniamo il nodo trovato che equivale al minimo**/
nodeBst *treeBst::treeMinimum(nodeBst *currNode)
{
    if(currNode->getSonSx()==NULL) /**se sono una foglia**/
     return currNode; /**ritorno il nodo**/

    else /**altrimenti**/
        return treeMinimum(currNode->getSonSx()); /**scendo sempre più a sinistra dell'albero**/
}

/**Metodo che implementa la ricerca dell'albero binario richiamando un metodo privato**/
nodeBst *treeBst::searchBst(unsigned char element) /**come input tale metodo prende un unsigned char, quindi prendiamo da input l'elemento che serve cercare**/
{
    int frequency=1;
    nodeBst *found=NULL;
    nodeBst *currentNode=new nodeBst(element,frequency); /**creiamo un nodo con le caratteristiche utili per trovare ciò che cerchiamo**/
    searchPrivate(currentNode,root,found); /**richiamo del metodo privato searchPrivate che ha come input il nodo che si vuole cercare, la radice, e found
                                            un nodo passato per riferimento in cui memorizziamo il nodo trovato**/
    return found;
}
/**Il metodo sottostante, sfruttando le proprietà dell'albero binario di ricerca, mette in pratica la ricerca dell'albero binario**/
void treeBst::searchPrivate(nodeBst *currNode,nodeBst *head,nodeBst* &found)
{
    if(head!=NULL)
    {
        if(head->getElement()==currNode->getElement()) /**Se ho trovato l'elemento**/
        found=head; /**salvo il nodo trovato in found**/
    else
        {
            searchPrivate(currNode,head->getSonSx(),found); /**richiamo il metodo searchPrivate sul sottoalbero sinistro**/
            searchPrivate(currNode,head->getSonDx(),found); /**richiamo il metodo searchPrivate sul sottoalbero destro**/
        }
    }
}
/**Il metodo sottostante ricerca il successore di un nodo passato in input all'interno dell'albero servendosi del metodo per la ricerca del minimo
Se il nodo passato ha un figlio destro allora il successore sarà il minimo del sottoalbero destro di quel nodo.
Se il nodo non ha un figlio destro ed io sono figlio sinistro allora il successore è mio padre**/

nodeBst *treeBst::treeSuccessor(nodeBst *currNode)
{
      nodeBst *y;
        if(currNode->getSonDx()!=NULL)
            return treeMinimum(currNode->getSonDx());

y=currNode->getFather();

   while((y!= NULL) && currNode == y->getSonDx()) /**fin quando mio padre non è null e il nodo corrente è il figlio destro del nodo y**/
    {
        currNode = y; /**aggiorno il nodo corrente**/
        y = y->getFather(); /**aggiorno y**/
    }

return y;
}
/**Il metodo sottostante elimina il nodo passato per input dall'albero binario di ricerca distinguendo tre casi:
1) Se il nodo corrente non ha figli si elimina il nodo
2) Se il nodo corrente ha un figlio si attacca questo figlio alla radice del nodo corrente e si passa ad eliminare il nodocorrente
3) Se il nodo corrente ha entrambi i figli, si trova il successore,si elimina il successore attaccando il figlio del successore al suo padre**/
void treeBst::elimNodeBst(nodeBst *elimNode)
{
    nodeBst *y,*x;


    if(elimNode->getSonDx()==NULL || elimNode->getSonSx()==NULL) /**se il nodo ha un solo figlio o non ha figli**/
       {
            y=elimNode; /**memorizzo il nodo da eliminare del nodo y**/
        }

        else
            y=treeSuccessor(elimNode); /**negli altri casi, quindi quando ha entrambi i figli, memorizzo il successore del nodo da eliminare nel nodo y**/

    if(y->getSonSx()!=NULL) /**se il nodo y ha il figlio sinistro**/
        x=y->getSonSx(); /**memorizzo il figlio sinistro nel nodo x**/

    else /**se il nodo y invece ha il figlio destro**/
        x=y->getSonDx(); /**memorizzo il figlio destro nel nodo x**/

       if(x!=NULL) /**verifico che il nodo sia diverso da null per impostare il padre**/
        x->setFather(y->getFather());


    if(y->getFather()==NULL) /**se il padre del nodo y è null, allora aggiorno la radice**/
        root=x;

    else if(y==y->getFather()->getSonSx()) /**se invece sono il figlio sinistro di y**/
            y->getFather()->setSonSx(x); /**x diventa mio padre**/

        else  /**se invece sono il figlio destro di y**/
                y->getFather()->setSonDx(x);/**x diventa mio padre**/
if(y!=elimNode) /**Se y è diverso dal nodo da cancellare**/
        elimNode->setElement(y->getElement()); /**Copio i dati di y nel nodo da cancellare**/

delete y; /**Dealloco y**/
}
/** Tale metodo implementa l'estrazione del minimo utilizzando i metodi per la ricerca del minimo e per l'eliminazione**/
nodeBst *treeBst::extractMin()
{
    nodeBst *minim;

    minim=treeMinimum(root); /**cerco il minimo all'interno dell'albero partendo dalla radice**/

    if(minim==NULL) /**se non c'è un minimo**/
        return NULL; /**ritorna null**/
    else
    {
        nodeBst *currMinim=new nodeBst(); /**creo un oggetto currMinim utilizzando il costruttore della classe nodeBst**/
    /**setto le impostazioni dell'oggetto appena creato con i valori del minimo precedentemente cercato**/
        currMinim->setElement(minim->getElement());
        currMinim->setFrequency(minim->getFrequency());
        currMinim->setFather(minim->getFather());
        currMinim->setSonSx(minim->getSonSx());
        currMinim->setSonDx(minim->getSonDx());
        currMinim->setSonSxHuffman(minim->getSonSxHuffman());
        currMinim->setSonDxHuffman(minim->getSonDxHuffman());
        elimNodeBst(minim); /**elimino il nodo all'interno dell'albero binario di ricerca**/
        return currMinim; /**e ritorno l'oggetto currMinim**/
    }
}
/**Il metodo sottostante calcola la dimensione dell'albero; Tale dimensione viene calcolata contando il numero dei nodi dell'albero**/
int treeBst::sizeTreeBst(nodeBst *head)
{
    if(head==NULL)
        return 0;
    else
         return (1+sizeTreeBst(head->getSonSx())+ sizeTreeBst(head->getSonDx()));
}


