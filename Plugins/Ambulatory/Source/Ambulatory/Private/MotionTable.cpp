#include "MotionTable.h"

bool UMotionTable::HasStateTransition(FName InStartState, FName InEndState) const {
    return false;
}

bool UMotionTable::HasEventTransition(FName InEventName, FName InStartState) const {
    return false;
}

FName UMotionTable::GetVariationStateNameFromAnimation(const FString& InAnimationName) const {
    return NAME_None;
}

float UMotionTable::GetTravelDistanceToState(float InTimeToReachState, FName InEndState, FName InStartState, float InCycleTime) const {
    return 0.0f;
}

float UMotionTable::GetTravelDistanceToEvent(float InTimeToReachEvent, FName InEventName, FName InStartState, float InCycleTime) const {
    return 0.0f;
}

float UMotionTable::GetTimeToReachEventBefore(float InTimeToReachEvent, FName InEventName, FName InStartState, float InCycleTime) const {
    return 0.0f;
}

float UMotionTable::GetTimeToReachEvent(FName InEventName, FName InStartState, float InCycleTime) const {
    return 0.0f;
}

float UMotionTable::GetTimeToReachEndStateBefore(float InTimeToReachEndState, FName InEndState, FName InStartState, float InCycleTime) const {
    return 0.0f;
}

float UMotionTable::GetTimeToReachEndState(FName InEndState, FName InStartState, float InCycleTime) const {
    return 0.0f;
}

float UMotionTable::GetStateTransitionTravelDistance(FName InStartState, FName InEndState) const {
    return 0.0f;
}

float UMotionTable::GetStateTransitionDuration(FName InStartState, FName InEndState) const {
    return 0.0f;
}

FName UMotionTable::GetStateNameFromAlias(const FString& InAliasedStateName) const {
    return NAME_None;
}

FName UMotionTable::GetStateContainingEvent(FName InEventName, FName InStartState) const {
    return NAME_None;
}

float UMotionTable::GetNearestTimeToReachEvent(float InTimeToReachEvent, FName InEventName, FName InStartState, float InCycleTime) const {
    return 0.0f;
}

float UMotionTable::GetNearestTimeToReachEndState(float InTimeToReachEndState, FName InEndState, FName InStartState, float InCycleTime) const {
    return 0.0f;
}

float UMotionTable::GetEventTransitionTravelDistance(FName InEventName, FName InStartState) const {
    return 0.0f;
}

float UMotionTable::GetEventFollowThroughTravelDistance(FName InEventName, FName InStartState) const {
    return 0.0f;
}

float UMotionTable::GetEventFollowThroughDuration(FName InEventName, FName InStartState) const {
    return 0.0f;
}

float UMotionTable::GetEventCycleTime(FName InEventName, FName InStartState) const {
    return 0.0f;
}

bool UMotionTable::AliasHasVariations(const FString& InAliasedStateName) const {
    return false;
}

UMotionTable::UMotionTable() {
}

