#include "AvatarPresetsManager.h"

class AActor;
class UAvatarPresetDefinition;
class UAvatarPresetsManager;
class UCustomizableCharacterComponent;
class UObject;

EAvatarPresetType UAvatarPresetsManager::StringToPresetType(const FString& PresetType) {
    return EAvatarPresetType::EYEBROWCOLOR;
}

bool UAvatarPresetsManager::SetPlayerGenderRig(EGenderEnum NewGenderRig) {
    return false;
}

bool UAvatarPresetsManager::SaveAvatarLook(FName RegistryId, const TMap<EAvatarPresetType, TSoftObjectPtr<UAvatarPresetDefinition>>& AvatarPresetDefinitions) {
    return false;
}

void UAvatarPresetsManager::ReleaseAllAvatarPresets() {
}

FString UAvatarPresetsManager::PresetTypeToString(EAvatarPresetType PresetType) {
    return TEXT("");
}

bool UAvatarPresetsManager::LoadPreset(UCustomizableCharacterComponent* CCC, EAvatarPresetType PresetType, FName PresetName, const FCharacterLoadCompleteDynamicDelegate& OnCharacterLoadComplete, bool& IsLoading, const bool bForceSync) {
    return false;
}

void UAvatarPresetsManager::LoadLookFromArrays(AActor* Actor, EGenderEnum Gender, TArray<FName> AvatarPresetIDs, TArray<FName> GearAppearanceIDs, const FString& GearTags, const FCharacterLoadCompleteDynamicDelegate& CharacterLoadComplete, FName HouseIDOverride) {
}

bool UAvatarPresetsManager::LoadFullBodyPreset(UCustomizableCharacterComponent* CCC, FName PresetName, const FCharacterLoadCompleteDynamicDelegate& OnCharacterLoadComplete, const bool bForceSync, const bool bShowDefaultAvatarGear) {
    return false;
}

bool UAvatarPresetsManager::LoadAvatarPresetDefinitionsFromSaveGameDB(AActor* Actor, TMap<EAvatarPresetType, TSoftObjectPtr<UAvatarPresetDefinition>>& OutPresetNames, EGenderEnum& OutGender) {
    return false;
}

void UAvatarPresetsManager::LoadAllAvatarPresets(const UObject* InWorldContextObject, FAvatarPresetManagerDelegate DelegateToCall, const TArray<FName>& AdditionalGearAppearanceIDs) {
}

TArray<FString> UAvatarPresetsManager::GetPresetTypes() {
    return TArray<FString>();
}

TArray<FName> UAvatarPresetsManager::GetPresetsOfType(EGenderEnum Gender, EAvatarPresetType PresetType, bool bIncludeHidden) {
    return TArray<FName>();
}

EGenderEnum UAvatarPresetsManager::GetPlayerGenderRig() {
    return EGenderEnum::GENDER_MALE;
}

TArray<FName> UAvatarPresetsManager::GetFullBodyPresetNames(EGenderEnum Gender, bool bIncludeHidden) {
    return TArray<FName>();
}

bool UAvatarPresetsManager::GetFullbodyPreset(FName FullBodyPresetName, EGenderEnum& OutGender, TMap<EAvatarPresetType, TSoftObjectPtr<UAvatarPresetDefinition>>& OutPresets) {
    return false;
}

bool UAvatarPresetsManager::GetFullBodyAvatarPresetNames(FName FullBodyPresetName, EGenderEnum& OutGender, TMap<EAvatarPresetType, FName>& OutPresetNames) {
    return false;
}

TMap<EAvatarPresetType, FName> UAvatarPresetsManager::GetAvatarPresetNames(const TMap<EAvatarPresetType, TSoftObjectPtr<UAvatarPresetDefinition>>& AvatarPresetDefinitions) {
    return TMap<EAvatarPresetType, FName>();
}

FName UAvatarPresetsManager::GetAvatarPresetName(TSoftObjectPtr<UAvatarPresetDefinition> AvatarPresetDefinition) {
    return NAME_None;
}

TSoftObjectPtr<UAvatarPresetDefinition> UAvatarPresetsManager::GetAvatarPresetDefinition(FName PresetName) {
    return NULL;
}

UAvatarPresetsManager* UAvatarPresetsManager::Get() {
    return NULL;
}

UAvatarPresetsManager::UAvatarPresetsManager() {
}

