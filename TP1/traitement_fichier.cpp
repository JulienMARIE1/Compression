#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void decbin(int decimal, char rep_binaire[])
{
    if(decimal > 255)
    {
        printf("Trop grand");
        return ;
    }
    else
    {
		int i;
    	for(i = 7; i >= 0; --i){	
			if(decimal >= pow(2, i)){
			    rep_binaire[i] = '1';
			    decimal -= pow(2, i);
			}
			else{
			     rep_binaire[i] = '0';
			}
		}
    }
}
string lectureFichier (const char* nomFichier){
	
	cout << "********************" << "Affichage du texte en claire" << "********************" << endl;
	ifstream fichier (nomFichier, ifstream::in);
	string chaineRecupere;
	string tmp;
	if (fichier.is_open()){
		while ( getline (fichier, tmp) ){
			cout << tmp << endl;
			chaineRecupere += tmp; 
		}
		 fichier.close();
	} else {
		cout << "le fichier n'a pas pu être ouvert " << endl;
	}
	return chaineRecupere;

}

void etudeStatistique (const string & chaine){
	cout << "********************" << "Etude statistique des octets" << "********************" << endl;
	vector <double> frequence (255, 0);
	vector <int> apparition (255, 0);
	char octet [8];
	
	for (int i = 0; i < chaine.size(); ++i){
		++apparition[chaine[i]];
	}
	cout << "les fréquences sont : " << endl;
	for (int i = 0; i < chaine.size(); ++i){
		frequence[chaine[i]] = (double) apparition[chaine[i]] / (double) chaine.size();
		decbin((int)(chaine[i]), octet);

		cout << "caractere : " << chaine[i] << " Octet : " << octet << " nombre apparition : "
			 << apparition[chaine[i]] << " frequence :" << frequence [chaine[i]] << endl;
	}	
}

void modificationBitsUnBitSurDeux (const string & chaine){
	ofstream fichier1 ("fic1.txt", ofstream::out);
	ofstream fichier2 ("fic2.txt", ofstream::out);
	
	for (int i = 0 )
}

int main (int argc, char * argv[]){
	string chaine (lectureFichier(argv[1]));	
	etudeStatistique(chaine);
	
}
