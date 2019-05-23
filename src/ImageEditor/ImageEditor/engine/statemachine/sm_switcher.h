#pragma once

#include "sm.h"
#include <vector>

template<typename  T_S, typename T_I, typename T_O>
class  SMSwitcher : public MITSM<T_S, T_I, T_O>
{
private:
    std::vector<MITSM<T_S, T_I, T_O>* >  _vSwitcher;
    int _index_Active;

protected:    
    MITSM<T_S, T_I, T_O>* _getSwitcher(int index)
    {
        if (index >=0 && index < _vSwitcher.size())
        {
            return _vSwitcher[index];
        }
        else 
        {
            return NULL;
        }
    }

    MITSM<T_S, T_I, T_O>* _activeMachine()
    {
        if (_index_Active >= 0 && _index_Active < _vSwitcher.size())
        {
            return _vSwitcher[_index_Active];
        }
        else
        {
            return NULL;
        }
    }

    void _setActiveMachine(int newIndex)
    {
        if (newIndex >= 0 && newIndex < _vSwitcher.size())
        {
            _index_Active = newIndex;
        }
        else 
        {
            _index_Active = -1;
        }
    }
public:
    SMSwitcher()    
    {
        _index_Active = -1;
        _vSwitcher.clear();
    }

    int addSwitcher(MITSM<T_S, T_I, T_O>* pSM, bool isActive = true )
    {
        _vSwitcher.push_back(pSM);

        if (isActive)
        {
            _index_Active = _vSwitcher.size() - 1;
        }

		return 0;
    }

    virtual int navigation(T_S currentState, T_I incomingMsg, int& processedIndex) = 0;   // Return 0 if success; else fail. processIndex is the index of submachine which would process the incomingMsg

    virtual T_O step(T_I msg)
    {
        T_O output;
        T_S state_origin = myState();
        int index_Switcher = 0;
        actionWhenIncomingMsg(myState(), msg);

        if (navigation(myState(), msg, index_Switcher) == 0) // Success
        {
            T_S sub_old_state;
            T_S sub_new_state;
            
            sub_old_state = _vSwitcher[index_Switcher]->myState();
            output =  _vSwitcher[index_Switcher]->step(msg);
            sub_new_state = _vSwitcher[index_Switcher]->myState();

            T_I i;

            T_S state = myState();
            if (isSubStateChangeEffectMyState(msg, sub_old_state,sub_new_state, output, state))
            {
                setStateVal(state);
            }
        }
        else
        {
            // Ignore
            // throw  "Invalid";
        }

        actionAfterProcessState(state_origin, myState(), msg, output);
		return T_O();
    }

    virtual T_S getNextValues(T_S currentState, T_I input, T_O& output)
    {
        int index_Switcher;
        if (navigation(myState(), input, index_Switcher) == 0) // Success
        {
            return  _vSwitcher[index_Switcher]->getNextValues(currentState, input, output);
        }
        else
        {
            throw "Invalid";
        }
    }

    // Return false if it does not effects, my_state_now would hold new state information
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