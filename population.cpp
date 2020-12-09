#include <QTextStream>
#include "parametres.h"



Population::Population()
{

}

void Population::evaluate()//reprise de la fonction evaluate de l'individu
{
    foreach (Individu *ind, liste_individu) {
        ind->evaluate();
    }
}

QString Population::tooString()//utilisation de la fonction tostring de l'individu
                               //pour afficher la famille entiere
{
    QString res;
    QTextStream buf(&res);
    foreach (Individu *ind, liste_individu) {
        buf<<ind->toString()<<endl;
    }
    return res;
}

int Population::skillmedian()//calcul du skill median de chaque famille
{
    int skillmed =0;
    foreach (Individu *ind, liste_individu) {
        ind->evaluate();
        skillmed += ind->skill();

    }
    skillmed = skillmed/NbIndividus;
    return skillmed;
}


void Population::BigMutate(int seuil_a_atteindre)
{   //essaie de faire muter tous les individus d'une famille
    //jusqu'au seuil_a_atteindre

    //tant que le skill median < seuil_a_atteindre & on est en dessous du nombre de génération max :
    while(skillmedian()<seuil_a_atteindre&&generationNb<Parameters::generationsMaxNb)
    {
        //pour chaque individu,
        foreach (Individu *ind, liste_individu)
        {
            //si le skill de l'individu < au seuil a atteindre: alors on essaie de muter
            if (ind->skill()<seuil_a_atteindre)ind->mutate();
            //si il y a eu mutation: on récupère le numéro de la generation
            if(ind->mutate())ind->generID = generationNb/NbIndividus;

        generationNb++;
        }
    }
}

void Population::evolutionnaryProcess()
{
    //-je cherche à faire muter un individu si il est nul

    //-récupérer les ratios:


    int index =liste_individu.at(0)->genome[0]-1;//dans le cas ou l'alpha est le premier (0)-> index out of range sur les listes/enums
    int plusNul = 0;
    float ratio_pn = 1;
    int indexPlusNul = 10;

    foreach (Individu *ind,liste_individu)
    {
        index++;
        //-créer une mémoire pour retrouver l'ID à muter
        Defaites[index]=ind->getDefaite();
        ratios[index]=ind->Ratio();
        ID[index]=ind->genome[0];

    }
    //-récuperer le ratio le plus faible et l'index

    for (int i=0; i<=index; i++)
    {

        if (Defaites[i]>plusNul)
        {
            plusNul=Defaites[i];
            ratio_pn=ratios[i];
            indexPlusNul=ID[i];

        }
    }
    cout<<endl<<"ID le plus nul et son ratio: "<<indexPlusNul<<" . "<<ratio_pn<<endl;

    int valID =0;
    // correction de l'équart de 1 entre IndexPlusNul et l'ID réel
    foreach(Individu *ind, liste_individu)
    {

        if(valID != ind->genome[0]&&plusNul==ind->getDefaite()&&ind->genome[0]==indexPlusNul)
        {
            indexPlusNul=ind->genome[0]-1;
            break;
        }
        valID++;
    }
    //si il a un faible ratio:
    if(ratio_pn < 0.5)
    {
        cout<<liste_individu.at(indexPlusNul)->toString();//on affiche
        liste_individu.at(indexPlusNul)->mutate();//on essaie de muter
        liste_individu.at(indexPlusNul)->evaluate();//on recalcul le skill
        cout<<"tentative de mutation:"<<endl;
        cout<<liste_individu.at(indexPlusNul)->toString();//on affiche a nouveau
    }
}
