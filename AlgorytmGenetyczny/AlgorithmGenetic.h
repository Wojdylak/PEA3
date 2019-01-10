#ifndef ALGORITHMGENETIC_H
#define ALGORITHMGENETIC_H

#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <chrono>

#include "MatrixCost.h"


class AlgorithmGenetic
{
    int numberVertices;
    const MatrixCost &matrix;
    int sizePopulation;
    double rateCrossover, rateMutation;
    std::vector<Path> population;
    int numberOfTournamentIndividual; 
    
    // clean vector and set numberVertices
    void initialization();
    void setSizePopulation(int size);
    void setRateCrossover(double rate);
    void setRateMutation(double rate);
    double getRandomFromZeroToOne();
    
    // using variable population
    void initalizationPopulation();
    void calculateFitnessPopulation();
    int calculateCostPath(std::vector<int> &path);
    Path getTheFittestIndividual();
    Path selectOneIndividualByTournamentMethod();
    
    Path doCrossoverPMX(std::vector<int> &firstParent, std::vector<int> &secondParent);
    void doMutationSwap(Path &individual);
    
    // using variable numberVerticles
    const Path generateGreedyPath(int firstVertex);
    const Path generateRandomPath();
    
    void getTwoRandomNumberFromRange(int &first, int &second, int range);
    
public:
//    AlgorithmGenetic();
    AlgorithmGenetic(const MatrixCost &orginalMatrix) : matrix(orginalMatrix) {};
    ~AlgorithmGenetic();

    Path search(int sizePopulation, double rateCrossover, double rateMutation, int time);

};

#endif // ALGORITHMGENETIC_H
