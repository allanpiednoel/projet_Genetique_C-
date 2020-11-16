#include "parametres.h"
#include <QDebug>
#include <QList>


baston::baston()
{
}

bool baston::match_nul(Individu *ind1, Individu *ind2)
// pour utiliser ces deux fonctions, if(better=false && less ==false){match nul}; else beter == true: i1 gagne;
//si c'est vrai, ind1 gagne

{
   if ((ind1->m_skill-ind2->m_skill)>(-Parameters::marge_match_nul)&&(ind1->m_skill-ind2->m_skill<Parameters::marge_match_nul)){
       //qDebug()<<"match nul";
   return true;}
   //qDebug()<<"pas match nul";
   return false;
}

int baston::match(Individu *ind1, Individu *ind2)
{int vainqueur =0;
    if (match_nul(ind1,ind2)==false)
    {

        if(ind1->m_skill>ind2->m_skill){
            vainqueur = 1;
        }
        else if (ind1->m_skill<ind2->m_skill){
            vainqueur = 2;
        }
    }
    return vainqueur;
}

void baston::tournoi(int indice_p1,Population *p1, Population *p2)
{//faire combattre un individu d'une famille avec chaques inds de la famille adverse

    //pour chaques membres de la famille, les faire se battre avec l'individu
    foreach (Individu *ind,p2->liste_individu) {
        int vainqueur=match(p1->liste_individu.at(indice_p1),ind);

        //conditions d'attribution des stats
        if (vainqueur==1){
            p1->liste_individu.at(indice_p1)->incr_victoires();

            ind->incr_defaites();
        }
        else if (vainqueur ==2) {
            p1->liste_individu.at(indice_p1)->incr_defaites();
            ind->incr_victoires();
        }

    }
    //qDebug()<<endl<<"victoires | defaites assayant: "<<p1->liste_individu.at(indice_p1)->getVictoire()<<" : "
   // <<p1->liste_individu.at(indice_p1)->getDefaite()<<endl;

}

void baston::launchEvo(Population *p1, Population *p2)
{
    p1->evolutionnaryProcess();
    p2->evolutionnaryProcess();
}
