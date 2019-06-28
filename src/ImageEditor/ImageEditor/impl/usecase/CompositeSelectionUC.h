#pragma once

#include "engine/statemachine/sm.h"
#include "engine/statemachine/sm_composite.h"

namespace SelectionUsecase
{

enum SelectionAppState
{
    STATE_NORMAL,
    STATE_SELECTION,
    STATE_PENCIL
};

enum SelectionAppMsg
{
    MSG_TOOLBAR_SELECT,
    MSG_TOOLBAR_PENCIL,
    MSG_SELECTION_MOUSE_CLICK,
    MSG_SELECTION_MOUSE_DOUBLE_CLICK
};

struct GlobalMsg
{
    SelectionAppMsg msgID;
};

struct EditorModel
{
    SelectionAppState stateID;
};

struct SelectionModel
{
    SelectionAppState stateID;
    int selectionShape;
};

class EditorSM: public SMComposite<EditorModel, GlobalMsg, double>
{
public:
    virtual int isThisACompositeState(EditorModel state);
    virtual EditorModel getNextValues(EditorModel currentState, GlobalMsg input, double& output);
};

class SelectionSM: public MITSM<SelectionModel, GlobalMsg, double>
{
public:
    SelectionModel getNextValues(SelectionModel currentState, GlobalMsg input, double& output);
};

}