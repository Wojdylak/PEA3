#include <iostream>
#include <ctime>

//#include <vector>
//#include <algorithm>

#include "MatrixCost.h"
#include "AlgorithmGenetic.h"

using namespace std;

int main()
{
    srand(time(NULL));

    
    MatrixCost *obj;
    obj = new MatrixCost();
    
    AlgorithmGenetic genetyczny(*obj);
    PathWithResult route;
    if (obj->loadFile("tsp_17.txt"))
    {
        //obj->show();
        
        route = genetyczny.search(20, 0.8, 0.01, 10);
        cout<<route.path.cost<<endl<<endl;
        
        for( auto el : route.result)
            cout<<el<<" ";
        cout<<endl;
        
    }
    
    
	return 0;
}
