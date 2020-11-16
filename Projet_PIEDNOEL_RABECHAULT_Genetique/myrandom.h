#ifndef MYRANDOM_H
#define MYRANDOM_H

/*! \class MyRandom
 * \brief classe permettant de récupérer des nombres aléatoires
 */
class MyRandom
{
public:
    /*! \brief Constructeur
     * \param seed (int) : graine de l'initialisateur de nombres aléatoires
     */
    MyRandom(int seed=-1);
    /*! \brief méthode permettant de récupérer un entier aléatoire
     * \param max (int) : nombre maximum exclu
     * \return (int) : le nombre aléatoire entre 0 et max-1
     */
    int get(int max);
    /*! \brief méthode retournant un nombre réel aléatoire entre 0 et 1
     */
    double getFloat();
};

#endif // MYRANDOM_H
