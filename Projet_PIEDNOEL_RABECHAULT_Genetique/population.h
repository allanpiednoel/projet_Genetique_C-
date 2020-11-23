#ifndef POPULATION_H
#define POPULATION_H
#include <QList>
#include "parametres.h"
#include <QString>
#define NbIndividus 1000


class Population
{
private:
//    int victoire=0;
//    int defaite=0;

public:
    int generationNb=0;
    float Defaites[NbIndividus];
    float ratios[NbIndividus];
    float ID[NbIndividus];
    Population();
    QList <Individu *>liste_individu;
    void evaluate();
    QString tooString();
    int skillmedian();
    void BigMutate(int seuil_a_atteindre);
    void evolutionnaryProcess();


};

/**/

#endif // POPULATION_H
