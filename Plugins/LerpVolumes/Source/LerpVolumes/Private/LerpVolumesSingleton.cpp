#include "LerpVolumesSingleton.h"

class UObject;

void ALerpVolumesSingleton::LerpVolumesSetWorldVectorDefault(UObject* WorldContextObject, FName VariableName, FVector VariableValue) {
}

void ALerpVolumesSingleton::LerpVolumesSetWorldUnitDirectionDefault(UObject* WorldContextObject, FName VariableName, FVector VariableValue) {
}

void ALerpVolumesSingleton::LerpVolumesSetWorldTagDefaultName(UObject* WorldContextObject, FName VariableName, FName VariableValue) {
}

void ALerpVolumesSingleton::LerpVolumesSetWorldTagDefault(UObject* WorldContextObject, FName VariableName, const FString& VariableValue) {
}

void ALerpVolumesSingleton::LerpVolumesSetWorldScalarDefault(UObject* WorldContextObject, FName VariableName, float VariableValue) {
}

void ALerpVolumesSingleton::LerpVolumesSetWorldIntegerDefault(UObject* WorldContextObject, FName VariableName, int32 VariableValue) {
}

void ALerpVolumesSingleton::LerpVolumesSetWorldColorDefault(UObject* WorldContextObject, FName VariableName, FLinearColor VariableValue) {
}

void ALerpVolumesSingleton::LerpVolumesIsWorldVector(UObject* WorldContextObject, FName VariableName, bool& bExists) {
}

void ALerpVolumesSingleton::LerpVolumesIsWorldUnitDirection(UObject* WorldContextObject, FName VariableName, bool& bExists) {
}

void ALerpVolumesSingleton::LerpVolumesIsWorldTag(UObject* WorldContextObject, FName VariableName, bool& bExists) {
}

void ALerpVolumesSingleton::LerpVolumesIsWorldScalar(UObject* WorldContextObject, FName VariableName, bool& bExists) {
}

void ALerpVolumesSingleton::LerpVolumesIsWorldInteger(UObject* WorldContextObject, FName VariableName, bool& bExists) {
}

void ALerpVolumesSingleton::LerpVolumesIsWorldColor(UObject* WorldContextObject, FName VariableName, bool& bExists) {
}

bool ALerpVolumesSingleton::LerpVolumesGetWorldVector(UObject* WorldContextObject, FName VariableName, FVector& VariableValue) {
    return false;
}

bool ALerpVolumesSingleton::LerpVolumesGetWorldUnitDirection(UObject* WorldContextObject, FName VariableName, FVector& VariableValue) {
    return false;
}

void ALerpVolumesSingleton::LerpVolumesGetWorldType(UObject* WorldContextObject, FName VariableName, ELerpVolumesInterpolantType& VariableType) {
}

bool ALerpVolumesSingleton::LerpVolumesGetWorldTag(UObject* WorldContextObject, FName VariableName, FString& VariableValue, ELerpVolumesGetTagValueMode ValueMode) {
    return false;
}

bool ALerpVolumesSingleton::LerpVolumesGetWorldScalar(UObject* WorldContextObject, FName VariableName, float& VariableValue) {
    return false;
}

bool ALerpVolumesSingleton::LerpVolumesGetWorldInteger(UObject* WorldContextObject, FName VariableName, int32& VariableValue) {
    return false;
}

bool ALerpVolumesSingleton::LerpVolumesGetWorldColor(UObject* WorldContextObject, FName VariableName, FLinearColor& VariableValue) {
    return false;
}

bool ALerpVolumesSingleton::LerpVolumesGetVectorAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, FVector& VariableValue) {
    return false;
}

bool ALerpVolumesSingleton::LerpVolumesGetUnitDirectionAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, FVector& VariableValue) {
    return false;
}

bool ALerpVolumesSingleton::LerpVolumesGetTagAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, FString& VariableValue, ELerpVolumesGetTagValueMode ValueMode) {
    return false;
}

bool ALerpVolumesSingleton::LerpVolumesGetScalarAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, float& VariableValue) {
    return false;
}

bool ALerpVolumesSingleton::LerpVolumesGetIntegerAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, int32& VariableValue) {
    return false;
}

bool ALerpVolumesSingleton::LerpVolumesGetColorAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, FLinearColor& VariableValue) {
    return false;
}

ALerpVolumesSingleton::ALerpVolumesSingleton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Priority = 0.00f;
    this->bLastLocalStateValid = false;
}

