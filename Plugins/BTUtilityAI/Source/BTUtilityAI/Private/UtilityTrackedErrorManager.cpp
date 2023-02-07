#include "UtilityTrackedErrorManager.h"

class AActor;
class UUtilityTrackedErrorManager;

void UUtilityTrackedErrorManager::ResetError_Type(const AActor* InOwner, EUtilityTrackedErrorType InType) {
}

void UUtilityTrackedErrorManager::ResetError_NameType(const AActor* InOwner, FName InName, EUtilityTrackedErrorType InType) {
}

void UUtilityTrackedErrorManager::ResetError_NameAccessory(const AActor* InOwner, FName InName, const AActor* InAccessory) {
}

void UUtilityTrackedErrorManager::ResetError_Name(const AActor* InOwner, FName InName) {
}

void UUtilityTrackedErrorManager::ResetError_AccessoryType(const AActor* InOwner, const AActor* InAccessory, EUtilityTrackedErrorType InType) {
}

void UUtilityTrackedErrorManager::ResetError_Accessory(const AActor* InOwner, const AActor* InAccessory) {
}

void UUtilityTrackedErrorManager::ResetError(const AActor* InOwner, FName InName, const AActor* InAccessory, EUtilityTrackedErrorType InType) {
}

void UUtilityTrackedErrorManager::ReportError(const AActor* InOwner, FName InName, const AActor* InAccessory, EUtilityTrackedErrorType InType, float InTimeToReset) {
}

bool UUtilityTrackedErrorManager::IsReportedError_Type(const AActor* InOwner, EUtilityTrackedErrorType InType) const {
    return false;
}

bool UUtilityTrackedErrorManager::IsReportedError_NameType(const AActor* InOwner, FName InName, EUtilityTrackedErrorType InType) const {
    return false;
}

bool UUtilityTrackedErrorManager::IsReportedError_NameAccessory(const AActor* InOwner, FName InName, const AActor* InAccessory) const {
    return false;
}

bool UUtilityTrackedErrorManager::IsReportedError_Name(const AActor* InOwner, FName InName) const {
    return false;
}

bool UUtilityTrackedErrorManager::IsReportedError_AccessoryType(const AActor* InOwner, const AActor* InAccessory, EUtilityTrackedErrorType InType) const {
    return false;
}

bool UUtilityTrackedErrorManager::IsReportedError_Accessory(const AActor* InOwner, const AActor* InAccessory) const {
    return false;
}

bool UUtilityTrackedErrorManager::IsReportedError(const AActor* InOwner, FName InName, const AActor* InAccessory, EUtilityTrackedErrorType InType) const {
    return false;
}

bool UUtilityTrackedErrorManager::GetAccessories_Type(const AActor* InOwner, EUtilityTrackedErrorType InType, TSet<AActor*>& OutAccessories) const {
    return false;
}

bool UUtilityTrackedErrorManager::GetAccessories_NameType(const AActor* InOwner, FName InName, EUtilityTrackedErrorType InType, TSet<AActor*>& OutAccessories) const {
    return false;
}

UUtilityTrackedErrorManager* UUtilityTrackedErrorManager::Get() {
    return NULL;
}

UUtilityTrackedErrorManager::UUtilityTrackedErrorManager() {
}

