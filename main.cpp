#include "huffman.h"

int main()
{

    string fileName,fileNameEnc,fileNameDecod; /**da input vengono acquisiste le stringhe che conterranno i nomi dei file e il file che verrà aperto**/

    cout<<"Algoritmo di compressione di Huffman di Vitale Maria Concetta"<<endl<<endl;
    cout<<"I formati accettati sono:"<<"\n.txt\n.bmp\n.wav"<<endl<<endl;

    cout << "Quale file vuoi aprire?";
    cin >> fileName;
    cout<<endl;
    int dim=fileName.size(); /**acquisiamo la dimensione della stringa che contiene il file da aprire e verifichiamo se
                            il formato è compreso tra quelli dell'algoritmo**/

    while(fileName.compare(dim-3,3,"txt")!=0 && fileName.compare(dim-3,3,"bmp")!=0 && fileName.compare(dim-3,3,"wav")!=0)
    {
        cout<<"Formato non accettato!Quale file vuoi aprire?";
        cin >> fileName;
    }

    cout << "Scegliere il nome del file di encod che verra' creato: "; /**acquisiamo da input i nomi dei file dell'encoder e del decoder**/
    cin >> fileNameEnc;
    cout << "Scegliere il nome del file di decod che verra' creato: ";
    cin >> fileNameDecod;
    cout<<endl<<endl;


    huffman *huffTest=new huffman(fileName,fileNameEnc,fileNameDecod); /**costruiamo l'oggetto huffTest inizializzandolo tramite costruttore passando i file appena acquisiti**/
    cout<<"Inizio fase di encoding "<<endl<<endl;
    huffTest->encoder(); /**richiamo del metodo encoder contenuto nella classe huffman tramite l'oggetto creato**/
    cout<<"Inizio fase di decoding "<<endl<<endl;
    huffTest->decoder();  /**richiamo del metodo encoder contenuto nella classe huffman tramite l'oggetto creato**/


return 0;
}
