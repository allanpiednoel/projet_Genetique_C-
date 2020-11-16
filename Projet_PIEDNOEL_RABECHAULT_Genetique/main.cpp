#include "../shared/qstd.h"
using namespace qstd;
#include "parametres.h"
#include <QList>
#include <QDebug>

//IDEE
//a l'initialisation, utiliser big mutate pour avoir un combat serré entre les 2 familles
//ensuite utiliser evoProcess pour determiner le vainceur

//-au bout de tant de mutation, les indivs meurent si ils sont perdants

int main()
{
    Parameters::details();
    baston b;
    Population population_1;
    Population population_2;

    // remplissage

    for (int i=0; i<NbIndividus;i++)
   {
    //attribution aléatoire des genes ( entre 0 et 100 )
    int agilite = Parameters::randomGenerator->get(100);
    int force = Parameters::randomGenerator->get(100);
    int precision = Parameters::randomGenerator->get(100);
    int intelligence = Parameters::randomGenerator->get(100);
    int resistance =Parameters::randomGenerator->get(100) ;


    population_1.liste_individu.append(new Individu(agilite,force,precision,intelligence,resistance));
    }

    // remplissage

    for (int i=0; i<NbIndividus;i++)
   {
    //attribution aléatoire des genes ( entre 0 et 100 )
    int agilite = Parameters::randomGenerator->get(100);
    int force = Parameters::randomGenerator->get(100);
    int precision = Parameters::randomGenerator->get(100);
    int intelligence = Parameters::randomGenerator->get(100);
    int resistance =Parameters::randomGenerator->get(100) ;



    population_2.liste_individu.append(new Individu(agilite,force,precision,intelligence,resistance));
    }

    //affichage de la liste non triée

    //cout<<"listes non triees :"<<endl<<"population 1 : "<<endl;
    population_1.evaluate();
   // cout<<population_1.tooString()<<endl;
    population_2.evaluate();
   // cout<<"population 2 : "<<endl;
   // cout<<population_2.tooString()<<endl;

    // recherche du meilleur
    std::sort(population_1.liste_individu.begin(), population_1.liste_individu.end(), Individu::betterSkillThan);
    std::sort(population_2.liste_individu.begin(), population_2.liste_individu.end(), Individu::betterSkillThan);


    cout<<endl<<"-listes triees :"<<endl<<"population 1 : "<<endl;
    cout<<population_1.tooString()<<endl;
    cout<<"population 2 : "<<endl;
    cout<<population_2.tooString()<<endl<<endl;

    //test skill median

     cout<<"-skill med pop_1: "<<population_1.skillmedian()<<endl;
     cout<<"-skill med pop_2: "<<population_2.skillmedian()<<endl;

     if (population_1.skillmedian()-population_2.skillmedian()!=0)
     {
         //big mutate
         cout<<endl<<"***big mutate fait evoluer tout le monde jusqu'a ce que la famille soit level :"<<Parameters::skillMoyen<<".***"<<endl<<endl;
         cout<<"-bigmutate pop_1: "<<endl;
         population_1.BigMutate(Parameters::skillMoyen);
         cout<<population_1.tooString()<<endl;
         cout<<"-bigmutate pop_2: "<<endl;
         population_2.BigMutate(Parameters::skillMoyen);
         cout<<population_2.tooString()<<endl;
     }
     cout<<endl<<"-skill population 1: "<<population_1.skillmedian()<<endl;
     cout<<"-skill population 2: "<<population_2.skillmedian()<<endl<<endl;

     //std::sort(population_1.liste_individu.begin(), population_1.liste_individu.end(), Individu::betterSkillThan);
     //std::sort(population_2.liste_individu.begin(), population_2.liste_individu.end(), Individu::betterSkillThan);


    /* cout<<"-listes des individus :"<<endl<<"population 1 : "<<endl;
     cout<<population_1.tooString()<<endl;
     cout<<"population 2 : "<<endl;
     cout<<population_2.tooString()<<endl<<endl;*/

     cout<<"nombre de mutation effectuees: "<<endl<<"-pop_1 : "<<population_1.generationNb<<endl;
     cout<<"-pop_2 : "<<population_2.generationNb<<endl;

    //test tournoi
    int i_1=1;
    int i_2=1;
    for(int i=0; i<NbIndividus;i++){
     b.tournoi(i,&population_1, &population_2);}

    cout<<endl<<"scores famille 1 : V/D  ratio"<<endl;

    foreach(Individu *ind, population_1.liste_individu){
        cout<<"Individu num "<<i_1<<": "<<ind->getVictoire()<<"/"<<ind->getDefaite()<<"     "<<ind->Ratio()<<endl;
        i_1++;
    }

    cout<<endl<<"scores famille 2 : V/D  ratio"<<endl;

    foreach(Individu *ind, population_2.liste_individu){
        cout<<"Individu num "<<i_2<<": "<<ind->getVictoire()<<"/"<<ind->getDefaite()<<"     "<<ind->Ratio()<<endl;
        i_2++;
    }



    b.launchEvo(&population_1, &population_2);

    //réaffichage de liste_individu pour test mutation issu du tournoi

   /* cout<<"population 1 : "<<endl;
    cout<<population_1.tooString()<<endl;
    cout<<"population 2 : "<<endl;
    cout<<population_2.tooString()<<endl;*/


    /*foreach (Individu *ind, population_1.liste_individu) {
        ind->
    }*/

   /*



     //test nb generations

     cout<<"test skillmedian population 1: "<<population_1.skillmedian()<<endl;
     cout<<"test skillmedian population 2: "<<population_2.skillmedian()<<endl;
     cout<<"nombre de generations pop_1 : "<<population_1.generationNb<<endl;
     cout<<"nombre de generations pop_2 : "<<population_2.generationNb<<endl;

     cout <<"test evo : "<<endl;*/


/*ap

    foreach (Individu *ind, Parameters::population_1) {
        qDebug()<<"avant mutation";
        cout<<ind->toString()<<endl;
        ind->mutate();
        ind->evaluate();
        qDebug()<<"apres mutation";
        cout<<ind->toString()<<endl;}
   // cout<<endl<<Individu::ptr;*/
}
