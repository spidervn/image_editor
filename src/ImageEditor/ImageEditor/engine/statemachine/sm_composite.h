#pragma once

#include "sm.h"
#include <vector>
#include <map>
#include <iterator>		// Back-inserter

template<typename T_S,typename T_I,typename T_O>
class SMComposite : public MITSM<T_S, T_I, T_O>
{
public:
    SMComposite(std::vector<MITSM<T_S, T_I, T_O>* > vComposite)
    {
        _vComposite.clear();
        std::copy(vComposite.begin(), vComposite.end(), std::back_inserter(_vComposite));
    }

    SMComposite(int arr[], int n)
    {
        _vComposite.clear();
        // std::copy(vComposite.begin(), vComposite.end(), std::back_inserter(_vComposite));
    }

    const MITSM<T_S, T_I, T_O>* getSubMachine(int nIndex)
    {
        if (nIndex >= 0 && nIndex < _vComposite.size())
        {
            return _vComposite[nIndex];
        }
        else 
        {
            return NULL;
        }
    }

    virtual int isThisACompositeState(T_S state) = 0;    // Return -1: if state is in main machine; 
                                                            // Else: return the vector index of composite-machine

	/*
    T_O step(T_I input)
    {
        T_O output;
        T_O outputSub;

        T_S originState = this->myState();
        this->actionWhenIncomingMsg(originState, input);

        T_S newState = this->getNextValues(originState, input, output);
        int index = isThisACompositeState(newState);

        // Entering Sub-Machine (composited-machine)
        if (index >= 0 && index < _vComposite.size())
        {
            MITSM<T_S, T_I, T_O>* pSubMachine = _vComposite[index]  ;
            // pSubMachine->getNextValues( pSubMachine->myState(), input, output); // Let sub-machine process the input and get Output            
			output = pSubMachine->step(input);
		}
        
        this->state = newState;
        this->actionAfterProcessState(originState, newState, input, output);

        return output;
    }
	*/

	T_O step(T_I input)
    {
        T_O output;
        T_O outputSub;

        T_S originState = this->myState();
        T_S newState;
        this->actionWhenIncomingMsg(originState, input);

		int index = isThisACompositeState(originState);
        // Entering Sub-Machine (composited-machine)
        if (index >= 0 && index < _vComposite.size())
        {
            MITSM<T_S, T_I, T_O>* pSubMachine = _vComposite[index]  ;
            // pSubMachine->getNextValues( pSubMachine->myState(), input, output); // Let sub-machine process the input and get Output            
			T_I inputSub = input;

            preProcessMsg_ToSubMachine(originState, inputSub);
            outputSub = pSubMachine->step(inputSub);

            newState = this->getNextValues(originState, input, output);
            output = outputSub;
		}
		else 
		{
			newState = this->getNextValues(originState, input, output);
		}
        
        this->state = newState;
        this->actionAfterProcessState(originState, newState, input, output);

        return output;
    }

    // Return true if the Input changes
    virtual bool preProcessMsg_ToSubMachine(T_S currentState, T_I& msg )
    {
        return false;
    }
private:
    std::vector<MITSM<T_S, T_I, T_O>* > _vComposite;
};