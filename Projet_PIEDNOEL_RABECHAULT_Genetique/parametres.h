#ifndef PARAMETERS_H
#define PARAMETERS_H
#include "individu.h"
#include "myrandom.h"
#include <QString>
#include <QMap>
#include "population.h"
//#include "ratio.h"
#include "baston.h"
#include "../shared/qstd.h"
using namespace qstd;



class Parameters {
public:
    static void details();
    static int individualsNb;
    static int generationsMaxNb;
    static int skillMoyen;
    static int marge_match_nul;

    static int initialGenesNb;
    static int minFitness;
    static int mutationNB ;
    static int indiv_fam_1;
    static int indiv_fam_2;
    //QList<Individu *> population_1;
    //QList<Individu *> population_2;
    static double mutationRate;
    static double mutationAddRate;
    static double mutationDeleteRate;
    static double crossoverRate;
    Parameters *ptr;
    static MyRandom *randomGenerator;
    static int debug;
    static void print(QString txt, int d);
    static float Abs(float val);
};




#endif // PARAMETERS_H
