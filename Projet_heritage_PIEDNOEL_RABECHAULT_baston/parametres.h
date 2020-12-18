#ifndef PARAMETERS_H
#define PARAMETERS_H
#include "individu.h"
#include "myrandom.h"
#include <QString>
#include <QMap>
#include <QDebug>
#include <QList>
#include "population.h"
#include "baston.h"
#include "../shared/qstd.h"

//Paramètres relatif à l'evénement, que l'on peut modifier
//contient aussi tout les #includes

using namespace qstd;

class Parameters {
public:
    static void details();// texte affiché au début du programme, rappelles les conditions et résume le tournoi
    static int individualsNb;//nombre d'individus dans une famille
    static int generationsMaxNb;//nombre de mutations max possibles
    static int skillMoyen;//limite de skill moyen de chaque famille (commune aux 2)
    static int marge_match_nul;
    static double mutationRate;//
    static MyRandom *randomGenerator;
    static float Abs(float val);
};

#endif // PARAMETERS_H
