#include "EnvironmentalGlobalsSingleton.h"

class UObject;

void AEnvironmentalGlobalsSingleton::GetEnvironmentalGlobals(UObject* WorldContextObject, FEnvironmentalGlobals& EnvironmentalGlobals) {
}

void AEnvironmentalGlobalsSingleton::EnvironmentalGlobalsSetExtraVector(UObject* WorldContextObject, FName Name, FVector Value, bool& bSuccess) {
}

void AEnvironmentalGlobalsSingleton::EnvironmentalGlobalsSetExtraScalar(UObject* WorldContextObject, FName Name, float Value, bool& bSuccess) {
}

void AEnvironmentalGlobalsSingleton::EnvironmentalGlobalsSetExtraColor(UObject* WorldContextObject, FName Name, FLinearColor Value, bool& bSuccess) {
}

void AEnvironmentalGlobalsSingleton::EnvironmentalGlobalsGetSeason(UObject* WorldContextObject, FEnvironmentalGlobalsSeason& Season, bool bAllowOverrides) {
}

void AEnvironmentalGlobalsSingleton::EnvironmentalGlobalsGetExtraVector(UObject* WorldContextObject, FName Name, FVector& Value, bool& bExists) {
}

void AEnvironmentalGlobalsSingleton::EnvironmentalGlobalsGetExtraScalar(UObject* WorldContextObject, FName Name, float& Value, bool& bExists) {
}

void AEnvironmentalGlobalsSingleton::EnvironmentalGlobalsGetExtraColor(UObject* WorldContextObject, FName Name, FLinearColor& Value, bool& bExists) {
}

AEnvironmentalGlobalsSingleton::AEnvironmentalGlobalsSingleton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bDirty = false;
    this->bDiscontinuity = true;
}

