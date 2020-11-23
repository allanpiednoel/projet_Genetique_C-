#include <QTextStream>
#include "parametres.h"



Population::Population()
{

}

void Population::evaluate()
{
    foreach (Individu *ind, liste_individu) {
        ind->evaluate();
    }
}

QString Population::tooString()
{
    QString res;
    QTextStream buf(&res);
    foreach (Individu *ind, liste_individu) {
        buf<<ind->toString()<<endl;
    }
    return res;
}

int Population::skillmedian()
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
{
    generationNb =0;

    while(skillmedian()<seuil_a_atteindre&&generationNb<Parameters::generationsMaxNb)
    {
        foreach (Individu *ind, liste_individu)
        {
            if (ind->skill()<seuil_a_atteindre)ind->mutate();


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
    int memID =0;

    for (int i=0; i<=index; i++)
    {

        if (Defaites[i]>plusNul)
        {
            plusNul=Defaites[i];
            ratio_pn=ratios[i];
            indexPlusNul=ID[i];

        }
    }

    memID=indexPlusNul;
    cout<<endl<<"ID le plus nul et son ratio: "<<indexPlusNul<<" . "<<ratio_pn<<endl;

    int valID =0;

    foreach(Individu *ind, liste_individu)
    {

        if(valID != ind->genome[0]&&plusNul==ind->getDefaite()&&ind->genome[0]==indexPlusNul)
        {
            indexPlusNul=ind->genome[0]-1;
            break;
        }
        valID++;
    }
    if(ratio_pn < 0.5)
    {
        cout<<liste_individu.at(indexPlusNul)->toString();
        liste_individu.at(indexPlusNul)->mutate();
        liste_individu.at(indexPlusNul)->evaluate();
        cout<<liste_individu.at(indexPlusNul)->toString();
    }
}
