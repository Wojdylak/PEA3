#include <iostream>
#include <ctime>

#include <vector>
#include <algorithm>
#include <fstream>

#include "MatrixCost.h"
#include "AlgorithmGenetic.h"
#include "MyFunctions.h"

using namespace std;

void MyMenu();

int main()
{
    srand(time(NULL));

    MyMenu();
    
	return 0;
}


void MyMenu()
{
    MatrixCost * matrix = nullptr;
    matrix = new MatrixCost();
    
    AlgorithmGenetic genetyczny(*matrix);

    Path path;
    int kryteriumStop = 60;
    int sizePopulation = 10;
    double rateCrossover = 0.8;
    double rateMutation = 0.01;

    int inNumber;
    char choice;
    bool loop1;
    string filePath;
    
    cout<<INTRO<<endl;
    
    loop1 = true;
    while (loop1)
    {
        cout<<MAIN_MENU;
        cout<<"3("<<kryteriumStop<<"),4("<<sizePopulation<<"),5("<<rateMutation<<"),6("<<rateCrossover<<")"<<endl;
        cout<<"Wybierz: ";
        
        //get choice
        choice = getchar();
        
        switch (choice)
        {
            case '1':
            {
                cout<< "Podaj sciezke: ";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin>>filePath;
                if (matrix->loadFile(&filePath[0]))
                    cout<<"Wczytano poprawnie"<<endl;
                else
                    cout<<"Error"<<endl;
                break;
            } // end case 1
            case '2':
            {
                if (matrix->isGood())
                {
                    matrix->show();
                }
                else
                    cout<<"Nie ma macierzy "<<endl;
                break;
            } // end case 2
            case '3':
            {
                cout << "Podaj ile sekund: ";
                cin >> inNumber;
                kryteriumStop = inNumber;
                break;
            } // end case 3
            case '4':
            {
                cout << "Podaj wielkosc populacji: ";
                cin >> inNumber;
                sizePopulation = inNumber;
                break;
            } // end case 4
            case '5':
            {
                cout << "Podaj wspolczynik mutacji: ";
                cin >> inNumber;
                rateMutation = inNumber;
                break;
            } // end case 5
            case '6':
            {
                cout << "Podaj wspolczynik krzyzowania: ";
                cin >> inNumber;
                rateCrossover = inNumber;
                break;
            } // end case 6
            case '7':
            {
                if (matrix->isGood())
                {
                    path = genetyczny.search(sizePopulation, rateCrossover, rateMutation, kryteriumStop);
                    cout<<"Koszt: "<<path.cost<<endl;
                }
                else
                    cout<<"Nie ma macierzy "<<endl;
                break;
            } // end case 7
            case '0':
                loop1 = false;
            break;
            
            default:
                break;
        } // end switch
        
        cout<<endl<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    } // end loop1
}
