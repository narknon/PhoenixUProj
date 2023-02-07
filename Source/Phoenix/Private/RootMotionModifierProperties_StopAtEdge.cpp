#include "RootMotionModifierProperties_StopAtEdge.h"

URootMotionModifierProperties_StopAtEdge::URootMotionModifierProperties_StopAtEdge() {
    this->TraceStartUp = 10.00f;
    this->TraceEndDown = -110.00f;
    this->DesiredDistanceFromEdge = 50.00f;
    this->bDebug = false;
}

