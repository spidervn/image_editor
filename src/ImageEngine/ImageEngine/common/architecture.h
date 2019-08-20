#ifndef IMAGEENGINE_COMMON_ARCHITECTURE_STRUCT_H_
#define IMAGEENGINE_COMMON_ARCHITECTURE_STRUCT_H_

/* 
 * Connector Builder - for Composition.
 * Composite = [a, c, b]
 *  a: From
 *  b: To
 *  c: connector
 * 
 * Definition:
 *      Modelling struct
 *      View the Modelling
 *      Sync the modelling to Real hardware.
 * 
 * 
 */

template<class T> 
struct Connector
{
    T a;
    T b;

    Connector(T a1, T b1)
    {
        a = a1;
        b = b1;
    }

    void define()
    {
        
    }
};

/*
 * Skeleton Builder
 *  A skeleton is a framework which lies between Developer and operating System. 
 *  The short term of Skeleton Builder is SB. 
 *  The purpose of Skeleton Builder is:
 *      - They created one Skeleton for a specified purpose.
 */


#endif