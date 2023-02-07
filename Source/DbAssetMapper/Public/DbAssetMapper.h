#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "DbSingleColumnInfo.h"
#include "DbAssetActorSpawnFinishedDelegate.h"
#include "DbAssetMapper.generated.h"

class AActor;
class UDbAssetMapper;

UCLASS(Blueprintable)
class DBASSETMAPPER_API UDbAssetMapper : public UObject {
    GENERATED_BODY()
public:
    UDbAssetMapper();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AActor* SpawnAssetFromDbIdForAutomation(const UObject* WorldContextObject, const FTransform& InTransform, const FString& InItemName, int32 inParentUID, int32 inOverrideUID, bool bSpawnOnlyShell);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SpawnAssetFromDbIdAsync(const UObject* WorldContextObject, const FTransform& InTransform, const FString& InItemName, bool bSpawnOnlyShell, const FDbAssetActorSpawnFinished& FinishDelegate);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AActor* SpawnAssetFromDbId(const UObject* WorldContextObject, const FTransform& InTransform, const FString& InItemName, bool bSpawnOnlyShell);
    
    UFUNCTION(BlueprintCallable)
    static bool SetTableColumnInfo(UPARAM(Ref) FDbSingleColumnInfo& inDbColInfo, FDbSingleColumnInfo& outDbColInfo, const FString& inTableName, const FString& inColumnName, bool inEmpty, bool inAddNone);
    
    UFUNCTION(BlueprintCallable)
    static bool IsValidRegistryID(const FString& inRegistryName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSubtypeID(const FName& RegistryId);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSkeletonTypeID(const FName& RegistryId);
    
    UFUNCTION(BlueprintCallable)
    static FString GetRegistryTypeID(const FName& inTypeName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetRegistryTypeDef(const FName& RegistryId);
    
    UFUNCTION(BlueprintCallable)
    static TSoftObjectPtr<UObject> GetItemSpawnAssetFromDbId(const FString& InItemName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetEmoteVoiceID(const FName& RegistryId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UDbAssetMapper* GetDbAssetMapper();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FString> GetAllRegistryTypeIDs();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FString> GetAllRegistrySubtypeIDs(const FString& RegistryTypeID);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FString> GetAllRegistryIDsOfType(const FString& SubtypeID);
    
    UFUNCTION(BlueprintCallable)
    static FName GetAdditionalVoiceID(const FName& RegistryId);
    
};

