#include "nodeBst.h"

nodeBst::nodeBst() ///costruttore di default della classe nodeBst
{
    left=NULL;
    right=NULL;
    father=NULL;
    leftHuffman=NULL;
    rightHuffman=NULL;
}

nodeBst::nodeBst(unsigned char elem,int freq) ///costruttore della classe nodeBst che prende come input un carattere ed un intero
{
     element=elem; ///inizializzo la variabile element privata ad elem che è da input
    frequency=freq; ///inizializzo la variabile frequency privata a freq che è da input
    left=NULL;      ///setto i puntatori a null
    right=NULL;
    father=NULL;
    leftHuffman=NULL;
    rightHuffman=NULL;
}

nodeBst::nodeBst(nodeBst *leftHuffman,nodeBst *rightHuffman) ///costruttore della classe nodeBst che prende come input due nodi indicanti i figli di huffman
{
    left=NULL;
    right=NULL;
    this->leftHuffman=leftHuffman;
    this->rightHuffman=rightHuffman;
}



