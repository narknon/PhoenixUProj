#include "VendorManager.h"

class UVendorManager;

void UVendorManager::ReloadVendorStock(FName VendorID) {
}

void UVendorManager::RefreshVendorStockIfNeeded(FName Vendor) {
}

void UVendorManager::RefreshVendorStock(FName Vendor) {
}

void UVendorManager::LoadVendorBroomPreviewActorClass(const FName BroomID) {
}

TArray<FUnavailableIconInfo> UVendorManager::GetUnavailableVendorItems(FName VendorID) {
    return TArray<FUnavailableIconInfo>();
}

UVendorManager* UVendorManager::Get() {
    return NULL;
}

TArray<FVendorInfo> UVendorManager::BP_GetVendorsSellingItem(FName ItemId) {
    return TArray<FVendorInfo>();
}

UVendorManager::UVendorManager() {
}

