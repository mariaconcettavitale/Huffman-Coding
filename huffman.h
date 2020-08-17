#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED
#include "header.h"
#include "nodeBst.h"
#include "priorityQueue.h"
#include "huffmanTree.h"
class huffman
{
private:
    priorityQueue *queueMinPriority; /**dichiarazione della coda di priorità che userà l'algoritmo per creare l'albero di huffman**/
    huffmanTree *treeHuffman; /**dichiarazione dell'albero di huffman**/
    int offset; /**variabile utilizzata per calcolare l'offset**/
    char *buffer; /**array utilizzato per salvare i caratteri dal file che si vuole aprire**/
    long sizeF; /**Dimensione che verrà utilizzata per allocare memoria per l'array**/
    long dimBuffComp; /**variabile per calcolare il tasso di compressione**/
    string fileNameIn; /**stringa che contiene il nome del file input**/
    string fileNameEnc;/**stringa che contiene il nome del file encoder**/
    string fileNameDec;/**stringa che contiene il nome del file decoder**/
    void buildHuffmanTree(); /**metodo che costrutire l'albero di huffman**/
    void buildBitsHuffman(nodeBst *head,unsigned char ch,string *bitsHuffman,string bit); /**metodo che costruisce la stringa di bit di Huffman**/

public:
        huffman(string fileNameIn,string fileNameEnc,string fileNameDec); /**costruttore con parametri**/
       ~huffman(); /**distruttore**/
       void encoder(); /**metodo encoder**/
       void decoder(); /**metodo decoder**/
};

#endif // HUFFMAN_H_INCLUDED
