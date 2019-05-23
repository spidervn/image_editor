#pragma once

#include "sm.h"
#include <vector>

template<typename  T_S, typename T_I, typename T_O>
class SMBroadcast : public MITSM<T_S, T_I, T_O>
{
private:
    std::vector<MITSM<T_S,T_I,T_O>*> _vSub;

public:
    SMBroadcast()
    {
        _vSub.clear();
    }

    virtual ~SMBroadcast()
    {}

    virtual bool filter(T_I incoming_Msg, int subMachineIndex) = 0;    // return true if you want subMachineIndex process this Message

    const MITSM<T_S, T_I, T_O>* getSubMachine(int nIndex)
    {
        if (nIndex >= 0 && nIndex < _vSub.size())
        {
            return _vSub[nIndex];
        }
        else
        {
            return NULL;
        }
    }

    virtual int addSubMachine(MITSM<T_S, T_I, T_O>* pSM)
    {
        _vSub.push_back(pSM);
        return 0;
    }

    virtual T_O step(T_I msg)
    {
        int index_Switcher = 0;
        T_O o;
        actionWhenIncomingMsg(myState(), msg);

        for(int i = 0; i < _vSub.size(); i++)
        {
            if (filter(msg, i))
            {
				// 
				// Finish all results
				// 
                o = _vSub[i]->step(msg);
            }
        }
        
        actionAfterProcessState(myState(), myState(), msg, o);
        // Output of the last results
        return o;
    }

	virtual int step(T_I msg, std::vector<T_O>& vout)
    {
        int index_Switcher = 0;
        T_O o;

		vout.clear();
        for(int i = 0; i < _vSub.size(); i++)
        {
            if (filter(msg, i))
            {
				// 
				// Finish all results
				// 
                T_S sub_OldState = _vSub[i]->myState();
                o = _vSub[i]->step(msg);
				vout.push_back(o);

                T_S state = myState();
                if (isSubStateChangeEffectMyState(
                    msg, 
                    sub_OldState,
                    _vSub[i]->myState(),
                    o,
                    state))
                {
                    setStateVal(state);
                }
            }
        }
        
        return 0;
    }

    virtual T_S getNextValues(T_S currentState, T_I input, T_O& output)
    {
        //Do not Need
        return currentState;
    }

    // Return true 
    virtual bool isSubStateChangeEffectMyState(
        T_I msg,
        T_S subMachineOldState,
        T_S subMachineNewState,
        T_O subMachineOutput,
        T_S& my_state_now)
    {
        return false;
    };
};
