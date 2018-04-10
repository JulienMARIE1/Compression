#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;



/* @param decimal     : valeur a transformer en binaire.
 * @param rep_binaire : chaine binaire recuperer
 * @brief             : fonction qui decompose la valeur decimal passe en
 *                      parametre pour avoir la decompostion binaire
 */
void decbin(int decimal, char rep_binaire[])
{
  if(decimal > 255){
    printf("Trop grand");
    return ;
  }
  else{
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


/* @param nomFichier  : nom du fichier où recuperer les caracteres
 * @return            : chaine de caracteres, recuperer du fichier
 * @brief             : Lit le fichier passe en parametre et recupere les
 *                      caractere 1 par 1 pour les renvoyer sous forme
 *                      de chaine de caracteres
 */

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

/* @param nomFichier  : Chaine de caractere à traiter
 * @brief             : calcul la fréquence et le nombre d'apparition
 *                      de chaque caractere dans la chaine
 */
void etudeStatistique (const string & chaine){
	cout << "********************" << "Etude statistique des octets" << "********************" << endl;
	vector <double> frequence (255, 0);
	vector <int> apparition (255, 0);
	char octet [8];

  // nombre d'apparition
	for (int i = 0; i < chaine.size(); ++i){
		++apparition[chaine[i]];
	}
	cout << "les fréquences sont : " << endl;
  // frequence
  for (int i = 0; i < chaine.size(); ++i){
		frequence[chaine[i]] = (double) apparition[chaine[i]] / (double) chaine.size();
		decbin((int)(chaine[i]), octet); // recupere la chaine de caractere des bits

		cout << "caractere : " << chaine[i] << " Octet : " << octet << " nombre apparition : "
			 << apparition[chaine[i]] << " frequence :" << frequence [chaine[i]] << endl;
	}
}

/* @param nomFichier  : nom du fichier où recuperer les caracteres
 * @brief             : Ecrit dans les fichiers 1 bit sur 2, de chaque caracteres
 *                      pour cela j'applique a chaque caractere une masque, suivant
 *                      les bits vouluent
 *
 */
void modificationBitsUnBitSurDeux (const string & chaine){
	ofstream fichier1 ("fic1.txt", ofstream::out);
	ofstream fichier2 ("fic2.txt", ofstream::out);
  int offset1 = 170; // 10101010
  int offset2 = 85; //  01010101
  char octet [8];
  char newChar;

	for (int i = 0; i < chaine.size(); ++i){
    decbin((int)(chaine[i]), octet);
    cout << "char   " <<octet << endl;

    newChar = (int)chaine[i] & offset1;
    decbin(newChar, octet);
    cout << "offset " << octet << endl;
    fichier1 << newChar;

    newChar = (int)chaine[i] & offset2;
    decbin((int)chaine[i] & offset2, octet);
    cout << "offset " << octet << endl;
    fichier2 << newChar;
  }

  fichier1.close();
  fichier2.close();
}

/* @param nomFichier  : nom du fichier où recuperer les caracteres
 * @brief             : Ecrit dans les fichiers soit les 4 bits
 *                      de poids fort soit de poids faible, de chaque caracteres
 *                      pour cela j'applique a chaque caractere une masque, suivant
 *                      les bits vouluent
 *
 */
void modificationBitsPoidFaibleFort (const string & chaine){
	ofstream fichier1 ("fic1.txt", ofstream::out);
	ofstream fichier2 ("fic2.txt", ofstream::out);
	int offset1 = 240; // 11110000
	int offset2 = 15; // 00001111
	char octet [8];
	char newChar;

	for (int i = 0; i < chaine.size(); ++i){
		decbin((int)(chaine[i]), octet);
		cout << "char   " <<octet << endl;

		newChar = (int)chaine[i] & offset1;
		decbin(newChar, octet);
		cout << "offset " << octet << endl;
		fichier1 << newChar;

		newChar = (int)chaine[i] & offset2;
		decbin((int)chaine[i] & offset2, octet);
		cout << "offset " << octet << endl;
		fichier2 << newChar;
  }

  fichier1.close();
  fichier2.close();
}

int main (int argc, char * argv[]){
	string chaine (lectureFichier(argv[1]));
	etudeStatistique(chaine);
	//modificationBitsUnBitSurDeux(chaine);
  modificationBitsPoidFaibleFort(chaine);
}
