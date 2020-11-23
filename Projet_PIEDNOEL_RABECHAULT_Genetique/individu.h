#ifndef INDIVIDU_H
#define INDIVIDU_H
#include <QDebug>
#include <QString>
#include <QList>
#define TAILLE_GENOME 6
#include "parametres.h"
class Individu
{
private:
   // int m_skill;
    int victoire;
    int defaite;
    float ratio;
public:

    int m_skill;
    void mutate();
    Individu(int id,int a, int f, int p, int i, int r);
    Individu(Individu *papa);
    void evaluate();
    static bool lessSkillThan(Individu *i1, Individu *i2);
    static bool betterSkillThan(Individu *i1, Individu *i2);
    static bool betterIDThan(Individu *i1, Individu *i2);

    QString toString();
    int genome[TAILLE_GENOME];

    enum GENE_type {ID,AGILITE,FORCE,PRECISION,INTELLIGENCE,RESISTANCE};
    int id() const;
    int agilite() const;
    int force() const;
    int precision() const;
    int intelligence() const;
    int resistance() const;
    void incr_victoires(){victoire ++;/*qDebug()<<"victoire : "<<victoire<<endl;*/}//qDebug()<<"victoire : "<<victoire<<endl;
    void incr_defaites(){defaite ++;/*qDebug()<<"defaites : "<<defaite<<endl;*/}
    float Ratio();


    int skill() const;
    int getVictoire() const;
    int getDefaite() const;

    float getRatio() const;
    void SetRatio(float value);
};

#endif // INDIVIDU_H
