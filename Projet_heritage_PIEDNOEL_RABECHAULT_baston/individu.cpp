#include <QTextStream>
#include "parametres.h"
#include <QDebug>


int Individu::id() const
{
    return genome[ID];
}

int Individu::agilite() const
{
    return genome[AGILITE];
}

int Individu::force() const
{
    return genome[FORCE];
}

int Individu::precision() const
{
    return genome[PRECISION];
}

int Individu::intelligence() const
{
    return genome[INTELLIGENCE];
}

int Individu::resistance() const
{
    return genome[RESISTANCE];
}
//generationNb
float Individu::Ratio()//calcul du ratio
{
    ratio =-1;
    if(victoire==0)ratio=0;
    if(defaite==0&&victoire>0)ratio=victoire;
    ratio=(float)(victoire)/(float)(defaite+victoire);
    SetRatio(ratio);
    //qDebug()<<"ratio: "<<ratio<<endl;
    return ratio;
}

//getters
int Individu::skill() const
{
    return m_skill;
}

int Individu::getVictoire() const
{
    return victoire;
}

int Individu::getDefaite() const
{
    return defaite;
}


float Individu::getRatio() const
{
    return ratio;
}

void Individu::SetRatio(float value)
{
    ratio=value;
}



bool Individu::mutate()//return faux si la mutation a échouée
{
   //on choisi au hasard l'index du gêne a muter
    int index = (Parameters::randomGenerator->get(1000))%TAILLE_GENOME;
    //on choisi deux valeurs aléatoire
    int val= Parameters::randomGenerator->get(100); // future valeure du gêne muté
 int val2= Parameters::randomGenerator->get(100); //determine si la mutation a échouée ou non

 //si la mutation est régréssive || tentative de mutation échouée : retourne faux

 if (val<genome[index]||(val2*Parameters::mutationRate)<TAILLE_GENOME)return false;

 else if(index!=0){
    genome[index]= val; //attribution de la nouvelle valeure du gêne muté
    generNB++;// incrémentation du nombre de mutations reussies
 }
 return true;


}

Individu::Individu(int id,int a, int f, int p, int i, int r) //permet d'initialiser un individu
{
    victoire = 0;
    defaite = 0;
    genome[ID]=id;
    genome[AGILITE]=a;
    genome[FORCE]=f;
    genome[PRECISION]=p;
    genome[INTELLIGENCE]=i;
    genome[RESISTANCE]=r;
    m_skill=-1;

}
//fonction pour dupliquer un individu, non utilisée
Individu::Individu(Individu *papa)

{
    victoire = 0;
    defaite = 0;
    for (int i=1; i<TAILLE_GENOME; i++){
        genome[i]=papa->genome[i];
    }
    mutate();
}
//calcul le skill (moyenne de tout les gênes)
void Individu::evaluate()
{
    m_skill=0;
    for (int i=1; i<TAILLE_GENOME; i++){
        m_skill+=genome[i];
    }
    m_skill = m_skill/(TAILLE_GENOME-1); //m_skill -> moyenne car widget: lcp de 2 chiffres

}

void Individu::death()//dans le main, apres le slatra, si id < 0 : suppression dans la liste
{
    genome[ID]=-1;
}

bool Individu::betterSkillThan(Individu *i1, Individu *i2)
{
    return i1->m_skill > i2->m_skill;
}

bool Individu::betterIDThan(Individu *i1, Individu *i2)
{
    return i1->genome[0] < i2->genome[0];
}



QString Individu::toString() {//affiche  un individu
    QString res;
    QTextStream buf(&res);
    buf<<m_skill<<" : [id="<<genome[ID]<<" ; ag="<<genome[AGILITE]<<" ; fo="<<genome[FORCE]<<" ; pre="<<genome[PRECISION]<<" ; int="<<genome[INTELLIGENCE]<<" ; res="<<genome[RESISTANCE]<<"]"<<endl;
    return res;
}
