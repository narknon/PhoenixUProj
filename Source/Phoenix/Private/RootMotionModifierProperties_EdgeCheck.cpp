#include "RootMotionModifierProperties_EdgeCheck.h"

URootMotionModifierProperties_EdgeCheck::URootMotionModifierProperties_EdgeCheck() {
    this->DetectMaxDistance = 1000.00f;
    this->ComputeEdgeAtThreshhold = 25.00f;
    this->TraceRadius = 3.00f;
    this->bDebugDraw = false;
    this->SafeDistanceFromEdge = 25.00f;
    this->EdgeOffsetSpeed = 80.00f;
}

