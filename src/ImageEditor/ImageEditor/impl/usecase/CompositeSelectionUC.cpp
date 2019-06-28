#include <stdafx.h>
#include "CompositeSelectionUC.h"

using namespace SelectionUsecase;

int EditorSM::isThisACompositeState(EditorModel state)
{
    if (state.stateID == SelectionAppState::STATE_SELECTION)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

EditorModel EditorSM::getNextValues(EditorModel currentState, GlobalMsg input, double& output)
{
    SelectionAppState stateID = currentState.stateID;
    SelectionAppMsg msgID = input.msgID;
    EditorModel newSTT = currentState;

    if (stateID == SelectionAppState::STATE_NORMAL)
    {
        if (msgID == SelectionAppMsg::MSG_TOOLBAR_SELECT)
        {
            newSTT.stateID = SelectionAppState::STATE_SELECTION;
        }
    }
    else if (stateID == SelectionAppState::STATE_PENCIL)
    {
        if (msgID == SelectionAppMsg::MSG_TOOLBAR_SELECT)
        {
			// 
            // newSTT.stateID == 
			// 
        }
    }

    return newSTT;
}

SelectionModel SelectionSM::getNextValues(SelectionModel currentState, GlobalMsg input, double& output)
{
    SelectionAppState stateID = currentState.stateID;
    SelectionAppMsg msgID = input.msgID;

    SelectionModel newSTT = currentState;

    if (msgID == SelectionAppMsg::MSG_SELECTION_MOUSE_CLICK)
    {
        newSTT.selectionShape ++;
    }

    return newSTT;
}