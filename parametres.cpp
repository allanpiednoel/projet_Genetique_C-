#include "parametres.h"
#include "qstd.h"
using namespace qstd;

//paramètres modifiables du programme
int Parameters::individualsNb =NbIndividus;
int Parameters::marge_match_nul=5;
int Parameters::generationsMaxNb = 100;
int Parameters::skillMoyen = 60;

double Parameters::mutationRate = 0.1;

// ******************************************************
// TODO : modifier la graine :
// - 0 : non aléatoire pour debug
// - rien : aléatoire
// ******************************************************
MyRandom *Parameters::randomGenerator=new MyRandom();//30//10(match nul alpha)

void Parameters::details()
{
    cout<<endl<<"-2 familles sont generes avec des genes aleatoires entre 0 et 100."<<endl<<endl;
    cout<<"-On calcul leur skill avec la moyenne de la somme de leurs genes."<<endl;
    cout<<"****/Le skill est l'inverse du fitness/***"<<endl;
    cout<<"puis la moyenne de la famille."<<endl<<endl;
    cout<<"-Si l'ecart de puissance n'est pas nul,"<<endl;
    cout<<"on fait muter chaque individu de chaque famille jusqu'une"<<endl;
    cout<<"moyenne max de "<<Parameters::skillMoyen<<"."<<endl<<endl;
    cout<<"-Mais chaque famille n'a que "<<Parameters::generationsMaxNb<<" chances de muter au total."<<endl<<endl;
    cout<<endl<<"-apres ceci, on fait combattre chaque membre en duel,"<<endl;
    cout<<"si leur ecart de skill est superieur a "<<Parameters::marge_match_nul<<", l'un des deux l'emporte"<<endl;
    cout<<"sinon, il y a match nul."<<endl;
    cout<<endl<<"-A l'issue, on calcul et on recupere le ratio de chaque individu."<<endl;
    cout<<"-L'individu le plus nul a une chance de muter"<<endl<<endl;
    cout<<"-Puis enfin nous faisont combattre les deux alphas dans les "<<endl<<"memes conditions de combat."<<endl;
    cout<<"-Si il y a match nul, on compare les ratios familiaux pour"<<endl<<"determiner le vainceur."<<endl<<endl;
}

float Parameters::Abs(float val)
{
    if (val<0)return -val;
    else return val;
}
