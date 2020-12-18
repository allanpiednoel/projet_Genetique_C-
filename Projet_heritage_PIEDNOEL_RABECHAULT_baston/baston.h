#ifndef BASTON_H
#define BASTON_H
#include "parametres.h"



// ici est référencé les fonctions relatives aux duels

class baston
{
public:
    baston();
    bool match_nul(Individu * ind1 , Individu * ind2); // retourne True si match nul ( ecart de skill < marge_match_nul)

    int match (Individu * ind1,Individu * ind2); // utilise match_nul comme condition, retourne 1 si * ind1 est gagnant
                                                 //et 2 si * ind2 gagnant

    void tournoi (int indice_p1,Population *p1, Population *p2); //faire combattre un individu d'une famille avec chaques inds de la famille adverse
                                                                 //pour chaques membres de la famille, les faire se battre avec l'individu indice_p1
                                                                 //attribution des victoires et des défaites de chaques individu

    void launchEvo(Population *p1, Population *p2);//sers juste à éxécuter evolutionnaryProcess

    int AlphaVsAlpha(Population *p1, Population *p2, Population *alf1, Population *alf2); //fait se battre les deux alphas, et calcul la moyenne de
                                                                                           //chaque familles au cas ou le combat est nul.
                                                                                           //determine le vainceur de la bataille

    void slatra(int indice_p1,Population *p1, Population *p2);//tournoi final si combat alpha-> matche nul. ici, les perdants meurent
};

#endif // BASTON_H
