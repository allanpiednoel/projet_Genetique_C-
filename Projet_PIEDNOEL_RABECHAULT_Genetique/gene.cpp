#include "gene.h"
#include "individu.h"
#include "parametres.h"



Gene::Gene(Gene &g) : indiv(g.indiv)
{

}

Gene::Gene(Gene *_ind) : indiv(_ind)
{

}
