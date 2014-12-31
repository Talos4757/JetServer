/*
 * Utility.h
 *
 *  Created on: Dec 26, 2014
 *      Author: matan
 */

#ifndef JETSERVER_UTILITY_H_
#define JETSERVER_UTILITY_H_

#include <iostream>
#include <stdio.h>

using namespace std;


enum TargetType
{
        //MUST be ordered by in game points value (best target is last)
        NA = 0,
        LowGoalR,
        LowGoalL,
        HighGoalR,
        HighGoalL,
        Truss,
        HotGoal
};

#define TARGETSIZE (sizeof(int) + 3*sizeof(double))
class Target
{
  //ALL numbers should be relative to the driving pivot!
  public:
    TargetType type;
    double distance; 
    double h_angle;
    double v_angle;
};


#endif /* JETSERVER_UTILITY_H_ */
