#ifndef NODEBST_H_INCLUDED
#define NODEBST_H_INCLUDED
#include "header.h"
class nodeBst
{
private:
    unsigned char element;
    int frequency;
    nodeBst *left;
    nodeBst *right;
    nodeBst *father;
    nodeBst *leftHuffman;
    nodeBst *rightHuffman;

public:
     nodeBst(); ///costruttore di default
     nodeBst(unsigned char elem,int freq); ///costruttore con parametri
     nodeBst(nodeBst *leftHuff,nodeBst *rightHuff); ///costruttore che inizializza i nodi di huffman
     ~nodeBst(){}; ///distruttore
     unsigned char getElement(){return element;} ///metodo che ritorna l'elemento
     int getFrequency(){return frequency;} ///metodo che ritorna la frequenza
     nodeBst *getSonSx(){return left;} ///metodo che ritorna il figlio sinistro
     nodeBst *getSonDx(){return  right;} ///metodo che ritorna il figlio destro
     nodeBst *getFather(){return father;} ///metodo che ritorna il padre del nodo
     nodeBst *getSonSxHuffman(){return leftHuffman;} ///metodo che ritorna il figlio sinistro di huffman
     nodeBst *getSonDxHuffman(){return  rightHuffman;} ///metodo che ritorna il figlio destro di huffman
     void setElement(unsigned char elem){element=elem;} ///metodo che setta l'elemento
     void setFrequency(int freq){frequency=freq;} ///metodo che setta la frequenza
     void setFather(nodeBst *externFather){father=externFather;} ///metodo che setta il padre
     void setSonSx(nodeBst *sx){left=sx;} ///metodo che setta il figlio sinistro
     void setSonDx(nodeBst *dx){right=dx;} ///metodo che setta il figlio destro
     void setSonSxHuffman(nodeBst *sxHuff){leftHuffman=sxHuff;} ///metodo che setta il figlio sinistro di huffman
     void setSonDxHuffman(nodeBst *dxHuff){rightHuffman=dxHuff;} ///metodo che setta il figlio destro di huffman
};


#endif // NODEBST_H_INCLUDED
