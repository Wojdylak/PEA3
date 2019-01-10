#include "AlgorithmGenetic.h"


AlgorithmGenetic::~AlgorithmGenetic()
{
}

void AlgorithmGenetic::initialization()
{
    std::vector<Path>().swap(population);
    
    numberVertices = matrix.getNumberVertices();
}

void AlgorithmGenetic::setSizePopulation(int size)
{
    sizePopulation = size;
}

void AlgorithmGenetic::setRateCrossover(double rate)
{
    rateCrossover = rate;
}

void AlgorithmGenetic::setRateMutation(double rate)
{
    rateMutation = rate;
}

double AlgorithmGenetic::getRandomFromZeroToOne()
{
    return ((double)rand() / (double)RAND_MAX);
}

void AlgorithmGenetic::initalizationPopulation()
{
    population.resize(sizePopulation);
    population[0] = generateGreedyPath(rand() % numberVertices);
    for (int i = 1; i < sizePopulation; i++)
        population[i] = generateRandomPath();
}

void AlgorithmGenetic::calculateFitnessPopulation()
{
    for (auto& el : population)
        el.cost = calculateCostPath(el.path);
}

int AlgorithmGenetic::calculateCostPath(std::vector<int> &currentPath)
{
    int cost = 0;
    for (size_t i=0; i < currentPath.size() - 1; i++)
    {
        cost += matrix.getCost(currentPath[i], currentPath[i+1]);
    }
    cost += matrix.getCost(currentPath[currentPath.size() - 1], currentPath[0]);
    
    return cost;
}

Path AlgorithmGenetic::getTheFittestIndividual()
{
    int cost = population[0].cost;
    Path fittest = population[0];
    for (auto el : population)
    {
        if (el.cost < cost)
        {
            cost = el.cost;
            fittest = el;
        }
    }
    

    return fittest;
}

Path AlgorithmGenetic::selectOneIndividualByTournamentMethod()
{
    Path bestIndividual;
    Path temporaryIndividual;
    bool flagIsRandomNumber; // nazwa do zmiany
    int randomNumber;
    std::vector<int> listRandomNumbers;
    
    // choose the first individual
    randomNumber = rand() % sizePopulation;
    listRandomNumbers.push_back(randomNumber);
    bestIndividual = population[randomNumber];

    for (int i = 0; i < (numberOfTournamentIndividual) - 1; i++)
    {
        do
        {
            flagIsRandomNumber = false;
            randomNumber = rand() % sizePopulation;
            for (auto el : listRandomNumbers)
                if (el == randomNumber)
                {
                    flagIsRandomNumber = true;
                    break;
                }
        } while (flagIsRandomNumber);
        listRandomNumbers.push_back(randomNumber);
        temporaryIndividual = population[randomNumber];
        
        if (temporaryIndividual.cost < bestIndividual.cost)
            bestIndividual = temporaryIndividual;
    }
    return bestIndividual;
}

Path AlgorithmGenetic::doCrossoverPMX(std::vector<int> &firstParent, std::vector<int> &secondParent)
{
    int smallerNumberOfRange;
    int biggerNumberOfRange;
    std::vector<int> child(numberVertices, -1);
    std::vector<int>::iterator iteratorVector;
    int tmpCounter;
    int tmpNumber;
    
    getTwoRandomNumberFromRange(smallerNumberOfRange, biggerNumberOfRange, numberVertices);
    
    // copy parent vertices to child from range
    // copy[first, last) why +1
    std::copy(&firstParent[smallerNumberOfRange], &firstParent[biggerNumberOfRange] + 1, &child[smallerNumberOfRange]);
    
    for (int i = smallerNumberOfRange; i <= biggerNumberOfRange; i++)
    {
        iteratorVector = std::find(child.begin(), child.end(), secondParent[i]);
        
        // if it isn't in vector
        if (iteratorVector == child.end())
        {
            // take number from first parent from the same pace
            // and looking for position this number in second parent
            tmpCounter = i;
            do
            {
                tmpNumber = firstParent[tmpCounter];
                for (tmpCounter=0; tmpCounter<numberVertices; tmpCounter++)
                    if (tmpNumber == secondParent[tmpCounter])
                        break;
                
            } while (child[tmpCounter] != -1);
            
            child[tmpCounter] = secondParent[i];
        }
    }
    
    // fill the rest of numbers
    tmpCounter=0;
    while (tmpCounter < numberVertices)
    {
        // find number that child doesn't have
        while (tmpCounter < numberVertices && (std::find(child.begin(), child.end(), secondParent[tmpCounter]) != child.end())) tmpCounter++;
        
        // find empty space and place it there
        iteratorVector = std::find(child.begin(), child.end(), -1);
        if (iteratorVector != child.end())
            *iteratorVector = secondParent[tmpCounter];
    }
    
    return {-1, std::move(child)};
}

void AlgorithmGenetic::doMutationSwap(Path &individual)
{
    int firstRandomNumber;
    int secondRandomNumber;
    
    firstRandomNumber = rand() % numberVertices;
    do
    {
        secondRandomNumber = rand() % numberVertices;
    } while (firstRandomNumber == secondRandomNumber);
    
    std::swap(individual.path[firstRandomNumber], individual.path[secondRandomNumber]);
}

const Path AlgorithmGenetic::generateGreedyPath(int firstVertex)
{
    std::vector<int> path(numberVertices);
    bool visitedVertices[numberVertices] {false};
    int valueOfMinimumCost;
    int numberOfMinimumVertex;
    int tmpValueCost;
    
    path[0] = firstVertex;
    visitedVertices[firstVertex] = true;
    
    for (int i = 1; i < numberVertices; i++)
    {
        valueOfMinimumCost = INT_MAX;
        numberOfMinimumVertex = 0;
        
        for (int j = 0; j < numberVertices; j++)
        {
            // visited or to itself
            if (visitedVertices[j] || path[i-1] == j)
                continue;
                
            tmpValueCost = matrix.getCost(path[i-1], j);
            if (tmpValueCost < valueOfMinimumCost)
            {
                valueOfMinimumCost = tmpValueCost;
                numberOfMinimumVertex = j;
            }
        }
        
        visitedVertices[numberOfMinimumVertex] = true;
        path[i] = numberOfMinimumVertex;
        
    }
    return {-1, std::move(path)};
}

const Path AlgorithmGenetic::generateRandomPath()
{
    std::vector<int> path;
    for (int i = 0; i < numberVertices; i++) path.push_back(i);
    std::random_shuffle(path.begin(), path.end());
    
    return {-1, std::move(path)};
}

void AlgorithmGenetic::getTwoRandomNumberFromRange(int &first, int &second, int range)
{
    first = rand() % range;
    do{
        second = rand() % range;
    } while (first == second); 
    
    if (second < first)
        std::swap(first, second);
}

Path AlgorithmGenetic::search(int sizePopulation, double rateCrossover, double rateMutation, int time)
{
    // time
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime; 
    double currentTime;
    int counterTimeTest = 0;
    int lastShowBestCost= 0;
    
    std::vector<Path> newPopulation;
    Path firstParent;
    Path secondParent;
    Path child;
    Path bestPath;
    
    numberOfTournamentIndividual = sizePopulation / 3;

    setSizePopulation(sizePopulation);
    setRateCrossover(rateCrossover);
    setRateMutation(rateMutation);
    initialization();
    initalizationPopulation();
    calculateFitnessPopulation();
    
    bestPath = getTheFittestIndividual();
    
    startTime = std::chrono::steady_clock::now();
    do
    {
        // incubator for the best
        child = getTheFittestIndividual();
        newPopulation.push_back(child);
        
        // create new poopulation
        while (newPopulation.size() < sizePopulation)
        {
            firstParent = selectOneIndividualByTournamentMethod();
            secondParent = selectOneIndividualByTournamentMethod();
            child = doCrossoverPMX(firstParent.path, secondParent.path);
            if (getRandomFromZeroToOne() < rateCrossover)
                newPopulation.push_back(child);
        }
        
        // mutation
        for (auto &el : newPopulation)
            if (getRandomFromZeroToOne() < rateMutation)
                doMutationSwap(el);
        
        // replace old with new one
        population.swap(newPopulation);
        std::vector<Path>().swap(newPopulation);
    
        calculateFitnessPopulation();
        child = getTheFittestIndividual();
        if (child.cost < bestPath.cost)
            bestPath = child;
    
        endTime = std::chrono::steady_clock::now();
        currentTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
        
        if (currentTime >= counterTimeTest)
        {
            if (lastShowBestCost != bestPath.cost)
            {
                std::cout<<currentTime<<" sek. wynik: "<<bestPath.cost<<std::endl;
                lastShowBestCost = bestPath.cost;
            }
            counterTimeTest++;
        }
        
    } while (currentTime < time);
    


    return std::move(bestPath);
}