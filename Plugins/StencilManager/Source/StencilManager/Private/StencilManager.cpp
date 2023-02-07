#include "StencilManager.h"

class AActor;
class AStencilManagerSingleton;
class UObject;
class UPrimitiveComponent;

void UStencilManager::UnlockForStencil(UObject* WorldContextObject, UObject* LockOwner, UPrimitiveComponent* Component, bool& bSuccess, bool bRestore) {
}

void UStencilManager::UnlockAllForStencil(UObject* WorldContextObject, UObject* LockOwner, bool& bSuccess, bool bRestore) {
}

bool UStencilManager::StencilGroupEnabled(UObject* WorldContextObject, FName Group) {
    return false;
}

bool UStencilManager::StencilEnabled(UObject* WorldContextObject) {
    return false;
}

void UStencilManager::SetStencilValueRenderCustomDepth(UPrimitiveComponent* PrimitiveComponent, FStencilValueRenderCustomDepth StencilValueRenderCustomDepth) {
}

void UStencilManager::SetStencilValueAndRenderCustomDepth(UPrimitiveComponent* PrimitiveComponent, int32 StencilValue, bool bRenderCustomDepth) {
}

void UStencilManager::SetStencilValue(UPrimitiveComponent* PrimitiveComponent, int32 StencilValue) {
}

void UStencilManager::SetStencilEffect(AActor* InTarget, FName StencilEffect, bool bFlag) {
}

void UStencilManager::SetStencil(AActor* InTarget, uint8 StencilValue, bool bFlag) {
}

void UStencilManager::SetRenderCustomDepth(UPrimitiveComponent* PrimitiveComponent, bool bRenderCustomDepth) {
}

void UStencilManager::SetActorStencilValueRenderCustomDepth(AActor* Actor, FStencilValueRenderCustomDepth StencilValueRenderCustomDepth) {
}

void UStencilManager::SetActorStencilValueAndRenderCustomDepth(AActor* Actor, int32 StencilValue, bool bRenderCustomDepth) {
}

void UStencilManager::SetActorStencilValue(AActor* Actor, int32 StencilValue) {
}

void UStencilManager::SetActorRenderCustomDepth(AActor* Actor, bool bRenderCustomDepth) {
}

void UStencilManager::LockOwnerForStencil(UObject* WorldContextObject, UPrimitiveComponent* Component, UObject*& Owner) {
}

void UStencilManager::LockForStencil(UObject* WorldContextObject, UObject* LockOwner, UPrimitiveComponent* Component, int32 StencilValue, bool& bSuccess, bool bRenderCustomDepth) {
}

void UStencilManager::LockAllForStencil(UObject* WorldContextObject, UObject* LockOwner, AActor* Actor, int32 StencilValue, bool& bSuccess, bool bRenderCustomDepth) {
}

void UStencilManager::IsLockedForStencil(UObject* WorldContextObject, UPrimitiveComponent* Component, bool& bLocked) {
}

AStencilManagerSingleton* UStencilManager::GetStencilManager(const UObject* WorldContextObject) {
    return NULL;
}

void UStencilManager::GetCurrentStencilEffect(AActor* InTarget, FName& StencilEffect) {
}

void UStencilManager::EnableStencilGroups(UObject* WorldContextObject, TArray<FName> Groups, bool bEnable) {
}

void UStencilManager::EnableStencilGroup(UObject* WorldContextObject, FName Group, bool bEnable) {
}

void UStencilManager::EnableStencil(UObject* WorldContextObject, bool bEnable) {
}

void UStencilManager::DisableStencilGroups(UObject* WorldContextObject, TArray<FName> Groups) {
}

void UStencilManager::DisableStencilGroup(UObject* WorldContextObject, FName Group) {
}

UStencilManager::UStencilManager() {
}

