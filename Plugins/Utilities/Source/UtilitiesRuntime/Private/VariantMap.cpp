#include "VariantMap.h"

class UObject;
class UVariantMap;

bool UVariantMap::VariantExists_FromHandle(FVariantMapHandle VarMapHandle, FName Name) {
    return false;
}

bool UVariantMap::VariantExists(FName Name) {
    return false;
}

UVariantMap* UVariantMap::RetrieveVariantMap(FVariantMapHandle VarMapHandle) {
    return NULL;
}

FName UVariantMap::GetVariantName_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FName DefaultValue, bool& bFound) {
    return NAME_None;
}

FName UVariantMap::GetVariantName(FName Name, FName DefaultValue, bool& bFound) {
    return NAME_None;
}

int32 UVariantMap::GetVariantInt32_FromHandle(FVariantMapHandle VarMapHandle, FName Name, int32 DefaultValue, bool& bFound) {
    return 0;
}

int32 UVariantMap::GetVariantInt32(FName Name, int32 DefaultValue, bool& bFound) {
    return 0;
}

FVector UVariantMap::GetVariantFVector_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FVector DefaultValue, bool& bFound) {
    return FVector{};
}

FVector2D UVariantMap::GetVariantFVector2D_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FVector2D DefaultValue, bool& bFound) {
    return FVector2D{};
}

FVector2D UVariantMap::GetVariantFVector2D(FName Name, FVector2D DefaultValue, bool& bFound) {
    return FVector2D{};
}

FVector UVariantMap::GetVariantFVector(FName Name, FVector DefaultValue, bool& bFound) {
    return FVector{};
}

FTransform UVariantMap::GetVariantFTransform_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FTransform DefaultValue, bool& bFound) {
    return FTransform{};
}

FTransform UVariantMap::GetVariantFTransform(FName Name, FTransform DefaultValue, bool& bFound) {
    return FTransform{};
}

FString UVariantMap::GetVariantFString_FromHandle(FVariantMapHandle VarMapHandle, FName Name, const FString& DefaultValue, bool& bFound) {
    return TEXT("");
}

FString UVariantMap::GetVariantFString(FName Name, const FString& DefaultValue, bool& bFound) {
    return TEXT("");
}

FRotator UVariantMap::GetVariantFRotator_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FRotator DefaultValue, bool& bFound) {
    return FRotator{};
}

FRotator UVariantMap::GetVariantFRotator(FName Name, FRotator DefaultValue, bool& bFound) {
    return FRotator{};
}

float UVariantMap::GetVariantFloat_FromHandle(FVariantMapHandle VarMapHandle, FName Name, float DefaultValue, bool& bFound) {
    return 0.0f;
}

float UVariantMap::GetVariantFloat(FName Name, float DefaultValue, bool& bFound) {
    return 0.0f;
}

bool UVariantMap::GetVariantBool_FromHandle(FVariantMapHandle VarMapHandle, FName Name, bool DefaultValue, bool& bFound) {
    return false;
}

bool UVariantMap::GetVariantBool(FName Name, bool DefaultValue, bool& bFound) {
    return false;
}

FVariantMapHandle UVariantMap::GetHandle_FromObject(UObject* InObject) {
    return FVariantMapHandle{};
}

FVariantMapHandle UVariantMap::GetHandle() {
    return FVariantMapHandle{};
}

FVariantMapHandle UVariantMap::DuplicateVariantMap(FVariantMapHandle VarMapHandle, bool bDestroy) {
    return FVariantMapHandle{};
}

FVariantMapHandle UVariantMap::DestroyVariantMap(FVariantMapHandle VarMapHandle) {
    return FVariantMapHandle{};
}

FVariantMapHandle UVariantMap::CreateVariantMap() {
    return FVariantMapHandle{};
}

void UVariantMap::AddVariantName_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FName Value) {
}

void UVariantMap::AddVariantName(FName Name, FName Value) {
}

void UVariantMap::AddVariantInt32_FromHandle(FVariantMapHandle VarMapHandle, FName Name, int32 Value) {
}

void UVariantMap::AddVariantInt32(FName Name, int32 Value) {
}

void UVariantMap::AddVariantFVector_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FVector Value) {
}

void UVariantMap::AddVariantFVector2D_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FVector2D Value) {
}

void UVariantMap::AddVariantFVector2D(FName Name, FVector2D Value) {
}

void UVariantMap::AddVariantFVector(FName Name, FVector Value) {
}

void UVariantMap::AddVariantFTransform_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FTransform Value) {
}

void UVariantMap::AddVariantFTransform(FName Name, FTransform Value) {
}

void UVariantMap::AddVariantFString_FromHandle(FVariantMapHandle VarMapHandle, FName Name, const FString& Value) {
}

void UVariantMap::AddVariantFString(FName Name, const FString& Value) {
}

void UVariantMap::AddVariantFRotator_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FRotator Value) {
}

void UVariantMap::AddVariantFRotator(FName Name, FRotator Value) {
}

void UVariantMap::AddVariantFloat_FromHandle(FVariantMapHandle VarMapHandle, FName Name, float Value) {
}

void UVariantMap::AddVariantFloat(FName Name, float Value) {
}

void UVariantMap::AddVariantBool_FromHandle(FVariantMapHandle VarMapHandle, FName Name, bool Value) {
}

void UVariantMap::AddVariantBool(FName Name, bool Value) {
}

void UVariantMap::AbsorbVariantMap_FromHandle(FVariantMapHandle MasterVarMapHandle, FVariantMapHandle VarMapHandleToAbsorb) {
}

void UVariantMap::AbsorbVariantMap(UVariantMap* VarMapHandleToAbsorb) {
}

UVariantMap::UVariantMap() {
}

