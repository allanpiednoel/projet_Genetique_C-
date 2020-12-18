#ifndef INDIVIDU_H
#define INDIVIDU_H
#include <QDebug>
#include <QString>
#include <QList>
#define TAILLE_GENOME 6
#include "parametres.h"

//ici sont regroupés les éléments relatifs à 1 seul individu

class Individu
{
private:
    //variables de victoires/defaites/ratios propre à chaque Individu
    int victoire;
    int defaite;
    float ratio;

public:
    //récupération du nombre de mutation aboutie et derniere mutation en date
    int generNB=0;
    int generID=0;

    //skill (Fitness = 100 - m_skill)
    int m_skill=-1;

    //genome
    int genome[TAILLE_GENOME];

    Individu(int id,int a, int f, int p, int i, int r);
    Individu(Individu *papa);

    bool mutate();//donne une chance de muter 1 fois

    void evaluate();//calcul le skill

    void death();//mort

    static bool betterSkillThan(Individu *i1, Individu *i2);//permet de trier la liste par skill

    static bool betterIDThan(Individu *i1, Individu *i2);//tri la liste par ID

    QString toString();//affiche l'individu sur le terminal, avec son génome

    //setter du genome
    enum GENE_type {ID,AGILITE,FORCE,PRECISION,INTELLIGENCE,RESISTANCE};
    int id() const;
    int agilite() const;
    int force() const;
    int precision() const;
    int intelligence() const;
    int resistance() const;

    //incrémentation des victoire & les defaites
    void incr_victoires(){victoire ++;}
    void incr_defaites(){defaite ++;}
    float Ratio();

    //getters skill, victoires & defaites
    int skill() const;
    int getVictoire() const;
    int getDefaite() const;

    //getter/setter du ratio V/D
    float getRatio() const;
    void SetRatio(float value);
};

#endif // INDIVIDU_H
