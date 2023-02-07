#include "MaterialPermuterKeyBlueprintLibrary.h"

void UMaterialPermuterKeyBlueprintLibrary::MaterialPermuterKeySplit(FMaterialPermuterKey Key, FName& Group, FName& SubType) {
}

void UMaterialPermuterKeyBlueprintLibrary::MaterialPermuterKeyIsValid(FMaterialPermuterKey Key, bool& bValid) {
}

void UMaterialPermuterKeyBlueprintLibrary::MaterialPermuterKeyDropdownSplit(FMaterialPermuterKeyProperty KeyDropdown, FName& Group, FName& SubType) {
}

void UMaterialPermuterKeyBlueprintLibrary::MaterialPermuterKeyDropdownIsValid(FMaterialPermuterKeyProperty KeyDropdown, bool& bValid) {
}

FString UMaterialPermuterKeyBlueprintLibrary::MakeMaterialPermuterKeyHashString(FMaterialPermuterKey Key) {
    return TEXT("");
}

FName UMaterialPermuterKeyBlueprintLibrary::MakeMaterialPermuterKeyHash(FMaterialPermuterKey Key) {
    return NAME_None;
}

FMaterialPermuterKey UMaterialPermuterKeyBlueprintLibrary::MakeMaterialPermuterKeyFromKeyDropdown(FMaterialPermuterKeyProperty KeyDropdown) {
    return FMaterialPermuterKey{};
}

FMaterialPermuterKey UMaterialPermuterKeyBlueprintLibrary::MakeMaterialPermuterKeyFromGroupSubType(FName Group, FName SubType) {
    return FMaterialPermuterKey{};
}

FString UMaterialPermuterKeyBlueprintLibrary::MakeMaterialPermuterKeyDropdownHashString(FMaterialPermuterKeyProperty KeyDropdown) {
    return TEXT("");
}

FName UMaterialPermuterKeyBlueprintLibrary::MakeMaterialPermuterKeyDropdownHash(FMaterialPermuterKeyProperty KeyDropdown) {
    return NAME_None;
}

UMaterialPermuterKeyBlueprintLibrary::UMaterialPermuterKeyBlueprintLibrary() {
}

