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
        foreach (Individu *ind, liste_individu) {
            int val=ind->skill();
            if (val<seuil_a_atteindre){
                ind->mutate();
            }
        generationNb++;
        //qDebug()<<"generationNb : "<<generationNb<<endl;
        }
    }
}

void Population::evolutionnaryProcess()
{
    //qDebug()<<"on rentre dans le evo";

    //-je cherche à faire muter un individu si il est nul

    //-récupérer les ratios:


    int index =-1;
    float plusNul = 1;
    int indexPlusNul = 10;
    foreach (Individu *ind,liste_individu) {
        index++;
        //qDebug()<<"index "<<index<<endl;
        ind->Ratio();
        //qDebug()<<"ratio "<<ind->Ratio()<<endl;
        //-créer une mémoire pour retrouver l'ID à muter

        ratios[index]=ind->Ratio();

    }
    //-récuperer le ratio le plus faible et l'index

    for (int i=0; i<=index; i++){
        if (ratios[i]<plusNul || ratios[i]==plusNul)
        {
            plusNul=ratios[i];
            indexPlusNul=i;
        }
    }
    qDebug()<<endl<<"ID le plus nul et son ratio: "<<indexPlusNul+1<<" . "<<plusNul<<endl;

    if(plusNul < 0.5){
        liste_individu.at(indexPlusNul)->mutate();
        liste_individu.at(indexPlusNul)->evaluate();
        qDebug()<<"ici est censé afficher l'individu ayant muté"<<endl;
        liste_individu.at(indexPlusNul)->toString();
        }
}





















