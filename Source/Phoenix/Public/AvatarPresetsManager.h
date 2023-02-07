#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharacterLoadCompleteDynamicDelegateDelegate.h"
#include "EGenderEnum.h"
#include "AvatarPresetManagerDelegateDelegate.h"
#include "EAvatarPresetType.h"
#include "AvatarPresetsManager.generated.h"

class AActor;
class UAvatarPresetDefinition;
class UAvatarPresetsManager;
class UCustomizableCharacterComponent;

UCLASS(Blueprintable)
class PHOENIX_API UAvatarPresetsManager : public UObject {
    GENERATED_BODY()
public:
    UAvatarPresetsManager();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EAvatarPresetType StringToPresetType(const FString& PresetType);
    
    UFUNCTION(BlueprintCallable)
    static bool SetPlayerGenderRig(EGenderEnum NewGenderRig);
    
    UFUNCTION(BlueprintCallable)
    static bool SaveAvatarLook(FName RegistryId, const TMap<EAvatarPresetType, TSoftObjectPtr<UAvatarPresetDefinition>>& AvatarPresetDefinitions);
    
    UFUNCTION(BlueprintCallable)
    static void ReleaseAllAvatarPresets();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString PresetTypeToString(EAvatarPresetType PresetType);
    
    UFUNCTION(BlueprintCallable)
    static bool LoadPreset(UCustomizableCharacterComponent* CCC, EAvatarPresetType PresetType, FName PresetName, const FCharacterLoadCompleteDynamicDelegate& OnCharacterLoadComplete, bool& IsLoading, const bool bForceSync);
    
    UFUNCTION(BlueprintCallable)
    static void LoadLookFromArrays(AActor* Actor, EGenderEnum Gender, TArray<FName> AvatarPresetIDs, TArray<FName> GearAppearanceIDs, const FString& GearTags, const FCharacterLoadCompleteDynamicDelegate& CharacterLoadComplete, FName HouseIDOverride);
    
    UFUNCTION(BlueprintCallable)
    static bool LoadFullBodyPreset(UCustomizableCharacterComponent* CCC, FName PresetName, const FCharacterLoadCompleteDynamicDelegate& OnCharacterLoadComplete, const bool bForceSync, const bool bShowDefaultAvatarGear);
    
    UFUNCTION(BlueprintCallable)
    static bool LoadAvatarPresetDefinitionsFromSaveGameDB(AActor* Actor, TMap<EAvatarPresetType, TSoftObjectPtr<UAvatarPresetDefinition>>& OutPresetNames, EGenderEnum& OutGender);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void LoadAllAvatarPresets(const UObject* InWorldContextObject, FAvatarPresetManagerDelegate DelegateToCall, const TArray<FName>& AdditionalGearAppearanceIDs);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FString> GetPresetTypes();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetPresetsOfType(EGenderEnum Gender, EAvatarPresetType PresetType, bool bIncludeHidden);
    
    UFUNCTION(BlueprintCallable)
    static EGenderEnum GetPlayerGenderRig();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetFullBodyPresetNames(EGenderEnum Gender, bool bIncludeHidden);
    
    UFUNCTION(BlueprintCallable)
    static bool GetFullbodyPreset(FName FullBodyPresetName, EGenderEnum& OutGender, TMap<EAvatarPresetType, TSoftObjectPtr<UAvatarPresetDefinition>>& OutPresets);
    
    UFUNCTION(BlueprintCallable)
    static bool GetFullBodyAvatarPresetNames(FName FullBodyPresetName, EGenderEnum& OutGender, TMap<EAvatarPresetType, FName>& OutPresetNames);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TMap<EAvatarPresetType, FName> GetAvatarPresetNames(const TMap<EAvatarPresetType, TSoftObjectPtr<UAvatarPresetDefinition>>& AvatarPresetDefinitions);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetAvatarPresetName(TSoftObjectPtr<UAvatarPresetDefinition> AvatarPresetDefinition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSoftObjectPtr<UAvatarPresetDefinition> GetAvatarPresetDefinition(FName PresetName);
    
    UFUNCTION(BlueprintCallable)
    static UAvatarPresetsManager* Get();
    
};

