#include "MultiFX2Manager.h"

class AActor;
class UMultiFX2Asset;
class UObject;

void UMultiFX2Manager::UpdateFX() {
}

FMultiFX2Handle UMultiFX2Manager::SpawnFXAsset(const UMultiFX2Asset* FXAsset, UObject* Target, AActor* Instigator, FVector Location, FRotator Rotation, FName AttachPointName) {
    return FMultiFX2Handle{};
}

FMultiFX2Handle UMultiFX2Manager::SpawnFXArray(const TArray<FMultiFX2Var>& Var, UObject* Target, AActor* Instigator, FVector Location, FRotator Rotation, FName AttachPointName) {
    return FMultiFX2Handle{};
}

FMultiFX2Handle UMultiFX2Manager::SpawnFX(const FMultiFX2Var& Var, UObject* Target, AActor* Instigator, FVector Location, FRotator Rotation, FName AttachPointName) {
    return FMultiFX2Handle{};
}

void UMultiFX2Manager::SetRotation(const FMultiFX2Handle& InHandle, const FRotator& InRotation) {
}

void UMultiFX2Manager::SetLocation(const FMultiFX2Handle& InHandle, const FVector& InLocation) {
}

void UMultiFX2Manager::SetFootprintLifetimeScale(float Scale) {
}

void UMultiFX2Manager::SetCustomTimeDilation(const FMultiFX2Handle& InHandle, float Dilation) {
}

bool UMultiFX2Manager::IsLooping(const FMultiFX2Handle& InHandle) {
    return false;
}

bool UMultiFX2Manager::IsActive(const FMultiFX2Handle& InHandle) {
    return false;
}

void UMultiFX2Manager::DestroyFXHandle(const FMultiFX2Handle& InHandle, bool bImmediate) {
}

UMultiFX2Manager::UMultiFX2Manager() {
}

