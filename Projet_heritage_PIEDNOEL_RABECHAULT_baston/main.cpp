#include "parametres.h"
#include <QList>
#include <QDebug>

int main()
{
    Parameters::details();

    //initialisation de chaques entitées
    baston b;
    Population famille_1;
    Population famille_2;
    Population alpha_1;
    Population alpha_2;

    //remplissage des familles en fonction du nombre d'individus voulus

    famille_1.init();
    famille_2.init();


    //evaluation de la liste non triée

    famille_1.evaluate();
    famille_2.evaluate();

    // recherche du meilleur

    std::sort(famille_1.liste_individu.begin(), famille_1.liste_individu.end(), Individu::betterSkillThan);
    std::sort(famille_2.liste_individu.begin(), famille_2.liste_individu.end(), Individu::betterSkillThan);

    cout<<endl<<"-listes triees par points de skill :"<<endl<<"famille 1 : "<<endl;
    cout<<famille_1.tooString()<<endl;
    cout<<"famille 2 : "<<endl;
    cout<<famille_2.tooString()<<endl<<endl;

    //skill median

     cout<<"-skill med famille 1: "<<famille_1.skillmedian()<<endl;
     cout<<"-skill med famille 2: "<<famille_2.skillmedian()<<endl<<endl;
     cout<<"premier tournoi"<<endl<<endl;

     //premier tournoi avant mutation

     for(int i=0; i<NbIndividus;i++){
      b.tournoi(i,&famille_1, &famille_2);}


     //triage de la liste par ID, pour une meilleure recherche ultérieure (verification des valeurs)

     std::sort(famille_1.liste_individu.begin(), famille_1.liste_individu.end(), Individu::betterIDThan);
     std::sort(famille_2.liste_individu.begin(), famille_2.liste_individu.end(), Individu::betterIDThan);

     //affichage du score de chacun

     cout<<endl<<"scores famille 1 : V/D  ratio"<<endl;

     foreach(Individu *ind, famille_1.liste_individu){
         cout<<"Individu num "<<ind->genome[0]<<": "<<ind->getVictoire()<<"/"<<ind->getDefaite()<<"     "<<ind->Ratio()<<endl;
     }

     cout<<endl<<"scores famille 2 : V/D  ratio"<<endl;

     foreach(Individu *ind, famille_2.liste_individu){
         cout<<"Individu num "<<ind->genome[0]<<": "<<ind->getVictoire()<<"/"<<ind->getDefaite()<<"     "<<ind->Ratio()<<endl;
     }

     //faire evoluer les individus jusqu'une valeure limite (parameters::skillMoyen) pour les familles

     if (famille_1.skillmedian()-famille_2.skillmedian()!=0||famille_1.skillmedian()<Parameters::skillMoyen)
     {
         //big mutate pop 1
         cout<<"liste triee par id:"<<endl<<endl;
         cout<<endl<<"-mutation famille 1 jusqu'a "<<Parameters::skillMoyen<<" : "<<endl<<endl;
         famille_1.BigMutate(Parameters::skillMoyen);//on  fait évoluer la famille jusqu'a un certain skill moyen
         famille_1.evaluate();// on recalcul le skill
         cout<<famille_1.tooString()<<endl;//on l'affiche en sortie
     }
     if (famille_1.skillmedian()-famille_2.skillmedian()!=0||famille_2.skillmedian()<Parameters::skillMoyen)
     {
         //big mutate pop 2
         cout<<"-mutation famille 2 jusqu'a "<<Parameters::skillMoyen<<" : "<<endl<<endl;
         famille_2.BigMutate(Parameters::skillMoyen);
         famille_2.evaluate();
         cout<<famille_2.tooString()<<endl;


     }


     //affichage du skill median


     cout<<endl<<"-skill famille 1: "<<famille_1.skillmedian()<<endl;
     cout<<"-skill famille 2: "<<famille_2.skillmedian()<<endl<<endl;

     //nombre de chance de mutations effectué total, puis de chaque individu
     cout<<"nombre de mutation effectuees: "<<endl<<"-famille 1 : "<<famille_1.generationNb<<endl;
     cout<<"    Il y a eu "<<famille_1.generationNb/(NbIndividus)<<" generations dans la famille 1"<<endl<<endl;
     cout<<"-famille 2 : "<<famille_2.generationNb<<endl;
     cout<<"    Il y a eu "<<famille_2.generationNb/(NbIndividus)<<" generations dans la famille 2"<<endl<<endl;

     //triage de la liste par point de skill pour la recherche de l'alpha

     std::sort(famille_1.liste_individu.begin(), famille_1.liste_individu.end(), Individu::betterSkillThan);
     std::sort(famille_2.liste_individu.begin(), famille_2.liste_individu.end(), Individu::betterSkillThan);

     //récupération de l'alpha et suppression dans sa famille (il a une classe pour lui tout seul)
     alpha_1.liste_individu.append(famille_1.liste_individu.at(0));
     alpha_2.liste_individu.append(famille_2.liste_individu.at(0));

     famille_1.liste_individu.removeFirst();
     famille_2.liste_individu.removeFirst();

     //affichage des stats des alphas
     cout<<"-alphas :"<<endl<<"meilleur de la famille 1: "<<endl<<alpha_1.tooString();
     if(alpha_1.liste_individu.at(0)->generNB==0)
        {
         cout<<"il n'as pas mute"<<endl<<endl;
        }
     else
        {
         cout<<"il a mute "<<alpha_1.liste_individu.at(0)->generNB<<" fois"<<endl;
         cout<<"et est issu de la generation "<<alpha_1.liste_individu.at(0)->generID<<endl<<endl<<endl;
        }

        cout<<"meilleur de la famille 2: "<<endl<<alpha_2.tooString();

     if(alpha_2.liste_individu.at(0)->generNB==0)
        {
         cout<<"il n'as pas mute"<<endl<<endl;
        }
     else
        {
        cout<<"il a mute "<<alpha_2.liste_individu.at(0)->generNB<<" fois"<<endl;
        cout<<"et est issu de la generation "<<alpha_2.liste_individu.at(0)->generID<<endl<<endl<<endl;
        }

    //tournoi

    for(int i=0; i<NbIndividus-1;i++){
        b.tournoi(i,&famille_1, &famille_2);}

    cout<<endl<<"scores famille 1 : V/D  ratio"<<endl;

    //triage et affichage en fonction de l'ID

    std::sort(famille_1.liste_individu.begin(), famille_1.liste_individu.end(), Individu::betterIDThan);
    std::sort(famille_2.liste_individu.begin(), famille_2.liste_individu.end(), Individu::betterIDThan);

    foreach(Individu *ind, famille_1.liste_individu){
        cout<<"Individu num "<<ind->genome[0]<<": "<<ind->getVictoire()<<"/"<<ind->getDefaite()<<"     "<<ind->Ratio()<<endl;
    }

    cout<<endl<<"scores famille 2 : V/D  ratio"<<endl;

    foreach(Individu *ind, famille_2.liste_individu){
        cout<<"Individu num "<<ind->genome[0]<<": "<<ind->getVictoire()<<"/"<<ind->getDefaite()<<"     "<<ind->Ratio()<<endl;
    }
   //récupère l'individu le plus nul et lui donne une chance de muter 1 fois
   b.launchEvo(&famille_1, &famille_2);

   //combat des deux alphas+affichage du vainceur
   //si match nul, on fait un dernier combat a mort entre les familles, ceux ayant le plus de survivants l'emporte
if(b.AlphaVsAlpha(&famille_1, &famille_2, &alpha_1, &alpha_2)==2){
   for(int i=0; i<NbIndividus-1;i++){
    b.slatra(i,&famille_1, &famille_2);}

   for(int i=NbIndividus-2; i>=0;i--){//ici si l'id est < 0, on supprime l'individu (death())
       //qDebug()<<"suppr indiv"<<i;
       if(famille_1.liste_individu.at(i)->id()<0){
        famille_1.liste_individu.removeAt(i);
       }
   }

   for(int i=NbIndividus-2; i>=0;i--){
       if(famille_2.liste_individu.at(i)->id()<0){
        famille_2.liste_individu.removeAt(i);
       }
}
    cout<<endl<<"survivants famille 1:"<<endl<<famille_1.tooString()<<endl;
    cout<<endl<<"survivants famille 2:"<<endl<<famille_2.tooString()<<endl;

    //compter le nombre de survivants
    if(famille_1.liste_individu.count()>famille_2.liste_individu.count())
    {
        cout<<"la famille 1 est gagnant de cette guerre, ils ont plus de survivants ("<<famille_1.liste_individu.count()<<")"<<endl;
    }
    else if ((famille_1.liste_individu.count()<famille_2.liste_individu.count())){
        cout<<"la famille 2 est gagnant de cette guerre, ils ont plus de survivants ("<<famille_2.liste_individu.count()<<")"<<endl;
    }
    else if ((famille_1.liste_individu.count()==famille_2.liste_individu.count())){
        cout<<endl<<"aucune des familles gagnantes! leur ecart de puissance est trop serre"<<endl;
    }

}
}
