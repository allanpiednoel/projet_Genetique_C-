#ifndef GENE_H
#define GENE_H
#include <QString>
class Gene
{
private:
    Gene *indiv;
public:
    Gene *ptr;
    QString toString();
    Gene(Gene &g);
    Gene(Gene *_ind);
};

#endif // GENE_H
