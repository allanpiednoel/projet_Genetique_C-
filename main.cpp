#include "parametres.h"
#include <QList>
#include <QDebug>

int main()
{
    Parameters::details();

    //initialisation de chaques entitées
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

    population_1.evaluate();
    population_2.evaluate();

    // recherche du meilleur
    std::sort(population_1.liste_individu.begin(), population_1.liste_individu.end(), Individu::betterSkillThan);
    std::sort(population_2.liste_individu.begin(), population_2.liste_individu.end(), Individu::betterSkillThan);

    cout<<endl<<"-listes triees :"<<endl<<"population 1 : "<<endl;
    cout<<population_1.tooString()<<endl;
    cout<<"population 2 : "<<endl;
    cout<<population_2.tooString()<<endl<<endl;

    //skill median

     cout<<"-skill med pop_1: "<<population_1.skillmedian()<<endl;
     cout<<"-skill med pop_2: "<<population_2.skillmedian()<<endl;

     if (population_1.skillmedian()-population_2.skillmedian()!=0||population_1.skillmedian()<Parameters::skillMoyen)
     {
         //big mutate

         cout<<endl<<"-bigmutate pop_1: "<<endl;
         population_1.BigMutate(Parameters::skillMoyen);
         cout<<population_1.tooString()<<endl;
         cout<<"-bigmutate pop_2: "<<endl;
         population_2.BigMutate(Parameters::skillMoyen);
         cout<<population_2.tooString()<<endl;
     }
     //affichage du skill median
     cout<<endl<<"-skill population 1: "<<population_1.skillmedian()<<endl;
     cout<<"-skill population 2: "<<population_2.skillmedian()<<endl<<endl;

     std::sort(population_1.liste_individu.begin(), population_1.liste_individu.end(), Individu::betterSkillThan);
     std::sort(population_2.liste_individu.begin(), population_2.liste_individu.end(), Individu::betterSkillThan);


     //nombre de chance de mutations effectué total, puis de chaque individu
     cout<<"nombre de mutation effectuees: "<<endl<<"-pop_1 : "<<population_1.generationNb<<endl;
     cout<<"    chaque membres ont eu une chance de muter "<<population_1.generationNb/(NbIndividus)<<" fois"<<endl<<endl;
     cout<<"-pop_2 : "<<population_2.generationNb<<endl;
     cout<<"    chaque membres ont eu une chance de muter "<<population_2.generationNb/(NbIndividus)<<" fois"<<endl<<endl;

     //récupération de l'alpha et suppression dans sa famille (il a une classe pour lui tout seul)
     alpha_1.liste_individu.append(population_1.liste_individu.at(0));
     alpha_2.liste_individu.append(population_2.liste_individu.at(0));

     population_1.liste_individu.removeFirst();
     population_2.liste_individu.removeFirst();


     //affichage des stats des alphas
     cout<<"-alphas :"<<endl<<"meilleur de la famille 1: "<<endl<<alpha_1.tooString();
     cout<<"il a mute "<<alpha_1.liste_individu.at(0)->generNB<<" fois"<<endl;
     cout<<"et est issu de la generation "<<alpha_1.liste_individu.at(0)->generID<<endl<<endl<<endl;
     cout<<"meilleur de la famille 2: "<<endl<<alpha_2.tooString();
     cout<<"il a mute "<<alpha_2.liste_individu.at(0)->generNB<<" fois"<<endl;
     cout<<"et est issu de la generation "<<alpha_2.liste_individu.at(0)->generID<<endl<<endl<<endl;

    //tournoi

    for(int i=0; i<NbIndividus-1;i++){
     b.tournoi(i,&population_1, &population_2);}

    cout<<endl<<"scores famille 1 : V/D  ratio"<<endl;

    //triage et affichage en fonction de l'ID

    std::sort(population_1.liste_individu.begin(), population_1.liste_individu.end(), Individu::betterIDThan);
    std::sort(population_2.liste_individu.begin(), population_2.liste_individu.end(), Individu::betterIDThan);

    foreach(Individu *ind, population_1.liste_individu){
        cout<<"Individu num "<<ind->genome[0]<<": "<<ind->getVictoire()<<"/"<<ind->getDefaite()<<"     "<<ind->Ratio()<<endl;
    }

    cout<<endl<<"scores famille 2 : V/D  ratio"<<endl;

    foreach(Individu *ind, population_2.liste_individu){
        cout<<"Individu num "<<ind->genome[0]<<": "<<ind->getVictoire()<<"/"<<ind->getDefaite()<<"     "<<ind->Ratio()<<endl;
    }
   //récupère l'individu le plus nul et lui donne une chance de muter 1 fois
   b.launchEvo(&population_1, &population_2);

   //combat des deux alphas+affichage du vainceur
   b.AlphaVsAlpha(&population_1, &population_2, &alpha_1, &alpha_2);

}
