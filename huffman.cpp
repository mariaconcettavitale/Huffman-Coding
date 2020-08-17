#include "huffman.h"
using namespace std;

huffman::huffman(string fileNameIn,string fileNameEnc,string fileNameDec) /**costruttore della classe huffman**/
{
     ifstream fileTextIn; /**dichiarazione dell'oggetto fileTextIn**/
     unsigned char ch=0;
     this->fileNameIn=fileNameIn; /**salvo le stringhe tramite le variabili private dichiarate nella classe per un successivo utilizzo di esse per i file creati nella fase di encoder e decoder**/
     this->fileNameEnc=fileNameEnc;
     this->fileNameDec=fileNameDec;

   fileTextIn.open(fileNameIn.c_str(),ios::in|ios::binary|ios::ate); /**utilizzo del metodo open per aprire il file di input in modalita'
                                                                      lettura.L'apertura è in binario e inoltre ci posizioniamo alla fine del file con
                                                                     l'utilizzo di ios::ate **/
   if(!fileTextIn) /**verifichiamo che non ci siano problemi nel momento dell'apertura del file**/
    {
        cout<<"ERROR OPEN FILE INPUT "<<endl; /**in tal caso stampiamo un messaggio di errore**/
        exit(0);
    }

        sizeF = fileTextIn.tellg();  /** utilizziamo il metodo tellg che ci restituisce la posizione del file, e visto che ci siamo posizionati alla fine
                                        avremo il size del file**/
        fileTextIn.seekg (0, ios::beg); /**in seguito, ci riposizioniamo all'inzio del file per poter procedere ad una corretta lettura di esso**/
        int i=0;
        buffer = new char[sizeF]; /**creamo poi un array di dimensione sizeF**/
    fileTextIn.read(buffer,sizeF); /**leggiamo i caratteri dal file e li memorizziamo nel buffer appena creato**/
    fileTextIn.close(); /**dopodichè chiudiamo il file**/
    queueMinPriority=new priorityQueue(); /**allochiamo memoria per l'oggetto queueMinPriority tramite il costruttore della classe priorityQueue**/

        /**di seguito, fin quando non raggiungiamo la fine del buffer,iniziamo a creare la coda di priorita' tramite il metodo increaseKey**/
cout<<"Costruzione coda minima di priorita' "<<endl<<endl;
while(i<sizeF)
    {
            ch=buffer[i];
            queueMinPriority->increaseKey(ch);
            i++;
    }
cout<<"Costruzione albero di Huffman "<<endl<<endl;
buildHuffmanTree(); /**richiamo del  metodo buildHuffmanTree**/
}
/**questo metodo, dopo aver allocato memoria per l'oggetto treeHuffman tramite il costruttore della classe huffmanTree
passa alla costruzione dell'albero di huffman mediante il metodo buildHuffman che ha come input la coda di priorità precedentemente
inizializzata**/
void huffman::buildHuffmanTree()
{
    treeHuffman=new huffmanTree();
    treeHuffman->buildHuffman(queueMinPriority);
}
/**Il metodo encoder codificherà il file passato precedentemente come input**/
void huffman::encoder()
{
     ofstream fileTextEnc; /**dichiarazione dell'oggetto fileTextEnc**/
     string bitsHuffman="";/**Stringa mediante cui costruiremo la stringa di bit**/
     string format; /**stringa utilizzata per aggiungere il formato alla stringa mediante l'operazione di concatenazione di stringhe**/
     vector <unsigned char> bufToComp; /**buffer utilizzato per poter memorizzare i caratteri**/
     unsigned  char ch=0;
     unsigned char letter=0;
     int j=0;
     float tasComp=0.0; /**variabile tramite cui calcoleremo il tasso di compressione del file**/

     format=".and"; /**formato della codifica**/
     fileNameEnc.append(format); /**mediante l'uso del metodo append aggiungiamo il formato al nome scelto per il file di codifica**/
     fileTextEnc.open(fileNameEnc.c_str(),ios::out|ios::binary); /**apertura del file di codifica in modalità binaria mediante l'uso del metodo open**/

    if(!fileTextEnc) /**controlliamo che non ci siano stati problemi con lìapertura del file**/
    {
        cout<<"ERROR OPEN FILE ENCODER"<<endl;
        exit(0);
    }

long i=0;
/**passo poi alla costruzione della stringa dei bit di huffman prendendo il carattere dal buffer precedentemente inizializzato mediante l'apertura
del file di input e passando poi il carattere memorizzato al metodo buildBitsHuffman che cotruirà la stringa di bit passata per riferimento al metodo**/
while(i<sizeF)
  {
        letter=buffer[i];
        buildBitsHuffman(treeHuffman->getRootHuffman(),letter,&bitsHuffman,"");
        i++;
  }

 j=0;
 /**Estrazione dalla stringa creato dei bit**/
while(!bitsHuffman.empty())
{
   string subHuffman=""; /**utilizziamo una sottostringa per estrarre otto bit alla volta**/
   subHuffman=bitsHuffman.substr(0,8); /**tramite il metodo estraiamo una stringa che va dalla posizione 0 alla posizione 8**/

   if(subHuffman.size()!=8) /**ci accertiamo di aver estratto esattamente otto caratteri per non aver problemi nella trasformazione dai bit al char**/
      {
          offset=8-subHuffman.size()%8; /**ci calcoliamo offset per poter capite quanti zeri bisogna aggiungere**/
           for(int i=0;i<offset;i++) /**e aggiungiamo numero offset di zeri per poter raggiungere size 8**/
            bitsHuffman+='0';

            subHuffman=bitsHuffman.substr(0,8); /**Dopodiche' estraiamo gli 8 bit raggiunti**/
      }
     bitsHuffman.erase(0,8); /**Cancelliamo di volta in volta i bit estratti**/
   /**tramite le operazioni sottostanti passiamo , tramite operatori bitwise, alla trasformazione dei bit in byte,**/
    while(subHuffman[j]!=0)
    {
            unsigned char temp=1;
            if(subHuffman[j]=='1')
            {
                temp<<=(7-j);
                ch|=temp;
            }

        j++;
    }
    bufToComp.push_back(ch); /**dopodichè salviamo il byte nel buffer bufToComp**/

    j=0;
   ch=0;
   }

dimBuffComp =(bufToComp.size()*8-(offset+1)); /**Trasformazione in bit per calcolare successivamente il tasso di compressione**/

int sizeBuf=bufToComp.size();

for(long i=0;i<sizeBuf;i++)
     fileTextEnc.put(bufToComp[i]); /**scriviamo sul file , tale file infatti è stato aperto in modalità scrittura**/

     fileTextEnc.close(); /**chiudiamo il file**/

 tasComp=(float)dimBuffComp/(sizeF*8); /**calcolo il tasso di compressione trasformando in bit**/
            cout<<"Il file aperto "<<fileNameIn<<" e' stato compresso con un tasso di compressione del " << ((1-tasComp)*100) << "% " << endl<<endl;

}
/**tale metodo costruisce la stringa di bit. Come input abbiamo la testa dell'albero, il carattere acquisito dal buffer, la stringa
che verrò costruita passata come riferimento e la stringa bit che servirà solo per aggiungere '0' o '1'**/
void huffman::buildBitsHuffman(nodeBst *head,unsigned char ch,string *bitsHuffman,string bit)
{
    if(head!=NULL)
{
    /**se hai trovato l'elemento nell'albero ed è una foglia**/
    if(head->getElement()==ch && !head->getSonSxHuffman() && !head->getSonDxHuffman())
    {
        *bitsHuffman+=bit; /**concatena alla stringa bitsHuffman il bit memorizzato**/
    }
    else
    {
        buildBitsHuffman(head->getSonSxHuffman(),ch,bitsHuffman,bit+'0'); /**se vado a sinistra bit avrà valore '0'**/
        buildBitsHuffman(head->getSonDxHuffman(),ch,bitsHuffman,bit+'1'); /**se vado a destra bit avrà valore '1'**/
    }
}
}
/**metodo decoder: con questo metodo decodifichiamo il file encoder precedentemente creato**/
void huffman::decoder()
{

 ifstream fileTextEnc; /**oggetto fileTextEnc per riaprire il file encoder**/
 ofstream fileTextDec; /**oggetto fileTextDec per aprire il file decoder con il nome precedentemente dato**/
 string format; /**stringa utilizzata per aggiungere il formato alla stringa mediante l'operazione di concatenazione di stringhe**/
 unsigned char letter=0;
 unsigned char ch=0;
 delete(buffer); /**liberiamo memoria per buffer poichè non servirà più**/
 vector<unsigned char> bits;
 long h=0;

   fileTextEnc.open(fileNameEnc.c_str(),ios::in|ios::binary|ios::ate); /**utilizzo del metodo open per aprire il file encoder in modalita'
                                                                      lettura.L'apertura è in binario e inoltre ci posizioniamo alla fine del file con
                                                                     l'utilizzo di ios::ate*/
  if(!fileTextEnc) /**controlliamo che non si siano verificati problemi con l'apertura**/
    {
        cout<<"ERROR OPEN FILE ENCODER"<<endl;
        exit(0);
    }

    sizeF = fileTextEnc.tellg(); /** utilizziamo il metodo tellg che ci restituisce la posizione del file, e visto che ci siamo posizionati alla fine
                                        avremo il size del file**/
    fileTextEnc.seekg (0, ios::beg); /**in seguito, ci riposizioniamo all'inzio del file per poter procedere ad una corretta lettura di esso**/

    char *bufferT=new char[sizeF];  /**creamo poi un array di dimensione sizeF**/
    fileTextEnc.read(bufferT, sizeF);/**read dal file dei dati compressi nel buffer**/
    fileTextEnc.close();  /**chiudiamo il file**/

    int dim=fileNameIn.size();
/**verifica del formato del file dato in input per impostare il formato corretto del file di decodifica**/
        if (fileNameIn.compare(dim-3,3,"txt")==0)
            format=".txt";
        if (fileNameIn.compare(dim-3,3,"bmp")==0)
            format=".bmp";
        if (fileNameIn.compare(dim-3,3,"wav")==0)
            format=".wav";

    fileNameDec.append(format); /**dopodichè concateno il formato prima selezionato alla stringa che contiene il nome**/
    fileTextDec.open(fileNameDec.c_str(),ios::out|ios::binary); /**apro il file di decodifica in binario, in modalità scrittura**/

if(!fileTextDec) /**controllo che sia andato tutto bene nell'operazione di apertura**/
    {
        cout<<"ERROR OPEN FILE DECODER"<<endl;
        exit(0);
    }

nodeBst *temp = treeHuffman->getRootHuffman(); /**salvo la radice in un nodo temporaneo**/

 for(long i=0;i<sizeF;i++) /**scorro il tutto il bufferT**/
 {
     letter=bufferT[i]; /**prendo il singolo carattere dal bufferT**/
     for(int j=7;j>=0;j--)
     {
         if(h<=dimBuffComp) /**mi assicuro che non venga sforata la dimensione**/
         {
            ch = (letter>>j) & 1; /**ricrea byte con operatore bitwise per trasferirli uno alla volta**/

            if(ch) /**se è uno vado a destra**/
                temp = temp->getSonDxHuffman();
            else /**se è zero vado a sinistra**/
                temp = temp->getSonSxHuffman();

            if(!temp->getSonSxHuffman() && !temp->getSonDxHuffman())  /**se sono arrivata alla foglia**/
            {
                bits.push_back(temp->getElement());  /**inserisco l'elemento all'interno del vector bits**/
                temp = treeHuffman->getRootHuffman(); /**ricomincio dalla testa dell'albero di Huffman, quindi reimposto temp**/
            }
            h++;
        }
        else
            continue;

     }
 }
int sizeBits=bits.size();
for(long i=0;i<sizeBits;i++)
    fileTextDec.put(bits[i]); /**Inserisco nel file gli elementi memorizzati in bits**/

    cout<<"Il file decoder "<<fileNameDec<<" e' stato creato!"<<endl<<endl;
 fileTextDec.close();
}
