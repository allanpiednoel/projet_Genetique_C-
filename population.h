#ifndef POPULATION_H
#define POPULATION_H
#include <QList>
#include "parametres.h"
#include <QString>
#define NbIndividus 10


class Population
{

public:

    //récupération du nombre de mutation aboutie et derniere mutation en date de chaque famille
    int generationNb=0;
    int generationID;

    //Tableaux pour comparaisons
    float Defaites[NbIndividus];
    float ratios[NbIndividus];
    float ID[NbIndividus];

    Population();


    QList <Individu *>liste_individu;//liste dans laquelle sera répertoriée chaque individus

    void evaluate();//calcul du skill

    QString tooString();//affiche toute la famille

    int skillmedian();//calcul du skill median de la famille

    void BigMutate(int seuil_a_atteindre);//essaie de faire muter tous les individus d'une famille
                                          //jusqu'au seuil_a_atteindre

    void evolutionnaryProcess();//récupère le plus nul de chaque famille et tente de le faire
                                //muter qu'une fois

};

/**/

#endif // POPULATION_H
