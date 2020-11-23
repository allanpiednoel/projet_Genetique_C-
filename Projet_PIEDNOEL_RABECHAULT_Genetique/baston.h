#ifndef BASTON_H
#define BASTON_H
#include "parametres.h"
#include <QList>
#include "population.h"
class baston
{
public:
    baston();
    bool match_nul(Individu * ind1 , Individu * ind2);
    int match (Individu * ind1,Individu * ind2);
    void tournoi (int indice_p1,Population *p1, Population *p2);
    void launchEvo(Population *p1, Population *p2);
    void AlphaVsAlpha(Population *p1, Population *p2, Population *alf1, Population *alf2);
};

#endif // BASTON_H
