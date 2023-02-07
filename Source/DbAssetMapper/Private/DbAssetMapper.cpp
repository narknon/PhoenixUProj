#include "DbAssetMapper.h"

class AActor;
class UDbAssetMapper;
class UObject;

AActor* UDbAssetMapper::SpawnAssetFromDbIdForAutomation(const UObject* WorldContextObject, const FTransform& InTransform, const FString& InItemName, int32 inParentUID, int32 inOverrideUID, bool bSpawnOnlyShell) {
    return NULL;
}

bool UDbAssetMapper::SpawnAssetFromDbIdAsync(const UObject* WorldContextObject, const FTransform& InTransform, const FString& InItemName, bool bSpawnOnlyShell, const FDbAssetActorSpawnFinished& FinishDelegate) {
    return false;
}

AActor* UDbAssetMapper::SpawnAssetFromDbId(const UObject* WorldContextObject, const FTransform& InTransform, const FString& InItemName, bool bSpawnOnlyShell) {
    return NULL;
}

bool UDbAssetMapper::SetTableColumnInfo(FDbSingleColumnInfo& inDbColInfo, FDbSingleColumnInfo& outDbColInfo, const FString& inTableName, const FString& inColumnName, bool inEmpty, bool inAddNone) {
    return false;
}

bool UDbAssetMapper::IsValidRegistryID(const FString& inRegistryName) {
    return false;
}

FName UDbAssetMapper::GetSubtypeID(const FName& RegistryId) {
    return NAME_None;
}

FName UDbAssetMapper::GetSkeletonTypeID(const FName& RegistryId) {
    return NAME_None;
}

FString UDbAssetMapper::GetRegistryTypeID(const FName& inTypeName) {
    return TEXT("");
}

FName UDbAssetMapper::GetRegistryTypeDef(const FName& RegistryId) {
    return NAME_None;
}

TSoftObjectPtr<UObject> UDbAssetMapper::GetItemSpawnAssetFromDbId(const FString& InItemName) {
    return NULL;
}

FName UDbAssetMapper::GetEmoteVoiceID(const FName& RegistryId) {
    return NAME_None;
}

UDbAssetMapper* UDbAssetMapper::GetDbAssetMapper() {
    return NULL;
}

TArray<FString> UDbAssetMapper::GetAllRegistryTypeIDs() {
    return TArray<FString>();
}

TArray<FString> UDbAssetMapper::GetAllRegistrySubtypeIDs(const FString& RegistryTypeID) {
    return TArray<FString>();
}

TArray<FString> UDbAssetMapper::GetAllRegistryIDsOfType(const FString& SubtypeID) {
    return TArray<FString>();
}

FName UDbAssetMapper::GetAdditionalVoiceID(const FName& RegistryId) {
    return NAME_None;
}

UDbAssetMapper::UDbAssetMapper() {
}

