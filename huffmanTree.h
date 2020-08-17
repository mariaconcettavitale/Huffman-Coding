#ifndef HUFFMANTREE_H_INCLUDED
#define HUFFMANTREE_H_INCLUDED
#include "header.h"
#include "nodeBst.h"
#include "priorityQueue.h"
class huffmanTree
{
private:
        nodeBst *rootHuffman; /**dichiarazione della radice dell'albero di huffman**/
public:
        huffmanTree(){rootHuffman=NULL;} /**costruttore di default**/
        ~huffmanTree(); /**distruttore**/
        nodeBst *getRootHuffman(){return rootHuffman;} /**metodo che restituisce la radice dell'albero di huffman**/
        void buildHuffman(priorityQueue *queueMinPriority); /**metodo per la costruzione dell'albero di huffman che riceve in input la coda di priorità**/
        void visitPreorder(nodeBst *rootHuffman); /**metodo per la visita dell'albero**/
};


#endif // HUFFMANTREE_H_INCLUDED
