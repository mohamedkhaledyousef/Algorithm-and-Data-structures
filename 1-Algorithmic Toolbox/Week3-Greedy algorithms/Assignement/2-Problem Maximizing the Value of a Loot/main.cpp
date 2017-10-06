#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//to get index of max value per unit
int getMaxIndex (vector<int> weights, vector<int> values)
    {
    int maxI = 0;
    double maxValuePerUnit = 0;

    for (int i = 0; i<weights.size(); ++i)
        {
        if (weights[i] != 0 && (double)values[i]/weights[i] > maxValuePerUnit)
            {
            maxValuePerUnit = (double)values[i]/weights[i];
            maxI = i;
            }
        }

    return maxI;        //this index contain the index of max value per unit ..for example1 : maxI=2 which 120 30 that equal to 4$
    }

double getOptimalValue(int capacityW, vector<int> weights, vector<int> values)
    {
    double value = 0.0;

    for (int i=0 ;i<weights.size(); ++i)
        {
        if (capacityW == 0)     //if the knapsack is full return value that it contain
            return value;
                                                                //Tracing on example 1
        int index = getMaxIndex(weights, values);               //to get max value per unit after first unit ...Now index = 2 which contain 120 30 that equal to 4
        int a= min(capacityW, weights[index]);                  //take the minimum between (50,30) =>30 ...a = 30
        value += a * (double)values[index]/weights[index];      //value = 0+(30*(120/30))= 120
        weights[index] -= a;                                    //weights = 30-30 = 0
        capacityW -= a;                                         //capacityW = 50-30=20
                                                                //----------------------------
                                                                //in second loop
                                                                //capacityW = 20 .. capacityW !=0
                                                                //to get max value per unit after first unit ...Now index = 0 which contain 60 20 that equal to 3
                                                                //take the minimum between (20,20) =>20 ...a = 20
                                                                //value = 120+(20*(60/20))= 120+60=180
                                                                //weights = 30-20 = 10
                                                                //capacityW = 20-20=0
                                                                //----------------------------
                                                                //in third loop
                                                                //capacityW = 0 .. capacityW ==0 ...True =>return value = 180
                                                                //------------------------------------------------------------------

        }

    return value;
    }


int main()
    {
    int n,capacityW;
    cin >>n>>capacityW;

    vector<int> values(n);
    vector<int> weights(n);

    for (int i = 0; i<n; ++i)
        {
        cin >> values[i] >> weights[i];
        }

    double optimalValue = getOptimalValue(capacityW, weights, values);

    cout <<fixed<<setprecision(4)<<optimalValue <<endl;

    return 0;
}


/*
The first line of the input contains the number n of items
and the capacity w of a knapsack.
n   w

The next n lines define the values and weights of the items
-example1
    3 50
    60 20
    100 50
    120 30
    knapsack capacity is 50

Solution
            item		1	      2 	     3
			value		60$	      100$       120
			weight		20  	  50         30
                        3$/unit	  2$/unit    4$/unit

			total: 280$
            knapsack capacity is 20+50+30=100

------------------------------------------
	(1)lets have some optimal solution...
        -sort the value/weight
            item		1	      2 	     3
			value		100$	  60$       120
			weight		50  	  20         30
                        2$/unit	  3$/unit    4$/unit

			total: 280$
            knapsack capacity is 20+50+30=100

        -first solution ..we take the second item and the third item into the bag.
            item		1	      2 	     3
			value		100$	  60$       120
			weight		50  	  20         30
                        2$/unit	  3$/unit    4$/unit

			total: 180$
            knapsack capacity is 20+30=50

		-second solution ... lets suppose in this optimal solution we dont use as much as possiable of the best item with the heighest value per unit of weight
		-then take some item which we used in this solution
            item		2
			value		100$
			weight		50
                        2$/unit

			total: 100$
            knapsack capacity is 50

		-and separate its usage into 2 parts,one part of the same size of how much we have of the best item (here's 2)and the second part is every thing else

            item        2           2
			value		100/2$      100/2$
			weight		25          25
                        2$/unit     2$/unit

			total: 100$
            knapsack capacity is 50

		-then we can substitute or replace the first part with the best item

            item        3           2
			value		120$        100/2=50$
			weight		20          25
                        5$/unit     2$/unit

			total: 170$
            knapsack capacity is 20+25=45

		-then we add 5 kg from item 1 to fill the knapsack

            item        3           2	        1
			value		120$        100/2=50$   10$
			weight		20          25          5
                        5$/unit     2$/unit     2$/unit

			total: 180$
            Now,knapsack capacity is 20+25+5=50

------------------------------------------------------------------------
example2
            item              1
			value		      500$
			weight		      30
            value per unit    500/30 = 16.6667 $/unit

			total: 500$
            knapsack capacity is 10

Solution
-what do this means by as much as possiable?
	-either use the whole item,if it fits into the knapsack
	-or if the capacity of the knapsack is less than how much we have of this item,then just fill the whole knapsack only with this item

            item              1
			value		      500$
			weight		      30
            value per unit    500/30 = 16.666666666 $/unit

			total: 500/30 = 16.6667$
            knapsack capacity is 10


    */

/*
My Bad first code

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    int n,w,sumMoney=0,weights=0;

    vector<int> value(n);
    vector<int> weight(n);
    vector<int> valPerUnit(n);

    cin >>n>>w;

    for (int i=0; i<n ; ++i)
    {
        cin >>value[i]>>weight[i];
        valPerUnit[i]= value[i]/weight[i];

    }

    weights = weight[0];
    for (int i=0; i<n ; ++i)
    {
        if (weights <= w)
            {
                sumMoney = sumMoney + value[i];
                weights += weight[i+1];

            }

    }
    cout <<fixed<<setprecision(4)<<sumMoney<<endl;


    */
