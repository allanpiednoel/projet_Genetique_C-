#ifndef POPULATION_H
#define POPULATION_H
#include <QList>
#include "parametres.h"
#include <QString>
#define NbIndividus 5


class Population
{
private:
//    int victoire=0;
//    int defaite=0;

public:
    int generationNb;
    float ratios[NbIndividus];
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
