#include "parametres.h"
#include "qstd.h"
using namespace qstd;
//QList <Individu *> Parameters::population_1;
//QList <Individu *> Parameters::population_2;
int Parameters::individualsNb =NbIndividus;
int Parameters::marge_match_nul=5;
int Parameters::generationsMaxNb = 100;
int Parameters::skillMoyen = 60;
//int ratio=0;
int Parameters::initialGenesNb = 0;
int Parameters::minFitness = 0;
int Parameters::mutationNB = 0;

double Parameters::mutationRate = 0.1;
double Parameters::mutationAddRate = 0.2;
double Parameters::mutationDeleteRate = 0.1;
double Parameters::crossoverRate = 0.6;

int Parameters::indiv_fam_1;
int Parameters::indiv_fam_2;
// ******************************************************
// TODO : modifier la graine :
// - 0 : non aléatoire pour debug
// - rien : aléatoire
// ******************************************************
MyRandom *Parameters::randomGenerator=new MyRandom();//30//10(match nul alpha)

int Parameters::debug = 1;

/*void Parameters::affichage()
{

        // affichage *1
        cout<<endl;
        foreach (Individu *ind, Parameters::population_1) {
            cout<<ind->toString()<<endl;
        }
        // calcul des puissances *2
        foreach (Individu *ind, Parameters::population_2) {
            ind->evaluate();
        }

        // affichage *2
        cout<<endl;
        foreach (Individu *ind, Parameters::population_2) {
            cout<<ind->toString()<<endl;
        }
}

void Parameters::print(QString txt, int d)
{
    if(d<debug)
        cout<<txt<<endl;
}
*/

void Parameters::details()
{
    cout<<endl<<"-2 familles sont generes avec des genes aleatoires entre 0 et 100."<<endl<<endl;
    cout<<"-On calcul leur skill avec la moyenne de la somme de leurs genes."<<endl;
    cout<<"****/Le skill est l'inverse du fitness/***"<<endl;
    cout<<"puis la moyenne de la famille."<<endl<<endl;
    cout<<"-Si l'ecart de puissance n'est pas nul,"<<endl;
    cout<<"on fait muter chaque individu de chaque famille jusqu'a"<<endl;
    cout<<"une moyenne max de "<<Parameters::skillMoyen<<"."<<endl<<endl;
    cout<<"-Mais chaque famille ne peux evoluer que "<<Parameters::generationsMaxNb<<" fois."<<endl<<endl;
    cout<<endl<<"-apres ceci, on fait combattre chaque membre en duel,"<<endl;
    cout<<"si leur ecart de skill est superieur a "<<Parameters::marge_match_nul<<", l'un des deux l'emporte"<<endl;
    cout<<"sinon, il y a match nul."<<endl;
    cout<<endl<<"-A l'issue, on calcul et on recupere le ratio de chaque individu."<<endl;
    cout<<"-L'individu le plus nul a une chance de muter"<<endl<<endl<<endl;
}

float Parameters::Abs(float val)
{
    if (val<0)return -val;
    else return val;
}
