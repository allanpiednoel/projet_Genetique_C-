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
    Population alpha_1;
    Population alpha_2;
    // remplissage

    for (int i=0; i<NbIndividus;i++)
   {
    //attribution aléatoire des genes ( entre 0 et 100 )
    int agilite = Parameters::randomGenerator->get(100);
    int force = Parameters::randomGenerator->get(100);
    int precision = Parameters::randomGenerator->get(100);
    int intelligence = Parameters::randomGenerator->get(100);
    int resistance =Parameters::randomGenerator->get(100) ;


    population_1.liste_individu.append(new Individu(i,agilite,force,precision,intelligence,resistance));
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



    population_2.liste_individu.append(new Individu(i,agilite,force,precision,intelligence,resistance));
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

     if (population_1.skillmedian()-population_2.skillmedian()!=0||population_1.skillmedian()<Parameters::skillMoyen)
     {
         //big mutate
         //cout<<endl<<"***big mutate fait evoluer tout le monde jusqu'a ce que la famille soit level :"<<Parameters::skillMoyen<<".***"<<endl<<endl;
         cout<<endl<<"-bigmutate pop_1: "<<endl;
         population_1.BigMutate(Parameters::skillMoyen);
         cout<<population_1.tooString()<<endl;
         cout<<"-bigmutate pop_2: "<<endl;
         population_2.BigMutate(Parameters::skillMoyen);
         cout<<population_2.tooString()<<endl;
     }
     cout<<endl<<"-skill population 1: "<<population_1.skillmedian()<<endl;
     cout<<"-skill population 2: "<<population_2.skillmedian()<<endl<<endl;

     std::sort(population_1.liste_individu.begin(), population_1.liste_individu.end(), Individu::betterSkillThan);
     std::sort(population_2.liste_individu.begin(), population_2.liste_individu.end(), Individu::betterSkillThan);


    /* cout<<"-listes des individus :"<<endl<<"population 1 : "<<endl;
     cout<<population_1.tooString()<<endl;
     cout<<"population 2 : "<<endl;
     cout<<population_2.tooString()<<endl<<endl;*/

     cout<<"nombre de mutation effectuees: "<<endl<<"-pop_1 : "<<population_1.generationNb<<endl;
     cout<<"    chaque membres ont eu une chance de muter "<<population_1.generationNb/(NbIndividus)<<" fois"<<endl<<endl;
     cout<<"-pop_2 : "<<population_2.generationNb<<endl;
     cout<<"    chaque membres ont eu une chance de muter "<<population_2.generationNb/(NbIndividus)<<" fois"<<endl<<endl;

     alpha_1.liste_individu.append(population_1.liste_individu.at(0));
     alpha_2.liste_individu.append(population_2.liste_individu.at(0));

     population_1.liste_individu.removeFirst();
     population_2.liste_individu.removeFirst();

     cout<<"-alphas :"<<endl<<"meilleur de la famille 1: "<<endl<<alpha_1.tooString()<<endl;
     cout<<"meilleur de la famille 2: "<<endl<<alpha_2.tooString()<<endl;


    //test tournoi
    int i_1=1;
    int i_2=1;
    for(int i=0; i<NbIndividus-1;i++){
     b.tournoi(i,&population_1, &population_2);}

    cout<<endl<<"scores famille 1 : V/D  ratio"<<endl;

    //triage en fonction de l'ID

    std::sort(population_1.liste_individu.begin(), population_1.liste_individu.end(), Individu::betterIDThan);
    std::sort(population_2.liste_individu.begin(), population_2.liste_individu.end(), Individu::betterIDThan);
    //cout<<population_1.tooString()<<endl;
    //cout<<population_2.tooString()<<endl;

    foreach(Individu *ind, population_1.liste_individu){
        cout<<"Individu num "<<ind->genome[0]<<": "<<ind->getVictoire()<<"/"<<ind->getDefaite()<<"     "<<ind->Ratio()<<endl;
        i_1++;
    }

    cout<<endl<<"scores famille 2 : V/D  ratio"<<endl;

    foreach(Individu *ind, population_2.liste_individu){
        cout<<"Individu num "<<ind->genome[0]<<": "<<ind->getVictoire()<<"/"<<ind->getDefaite()<<"     "<<ind->Ratio()<<endl;
        i_2++;
    }


    //TODO:
    //recuperer l'alpha, ne pas le faire muter, (puis faire alpha vs alpha, il ne se bat qu'avec l'autre )
   cout<<endl<<"lancement evo"<<endl<<endl;
   b.launchEvo(&population_1, &population_2);
   b.AlphaVsAlpha(&population_1, &population_2, &alpha_1, &alpha_2);

}
