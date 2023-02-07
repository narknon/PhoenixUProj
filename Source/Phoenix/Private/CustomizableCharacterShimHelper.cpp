#include "CustomizableCharacterShimHelper.h"

bool UCustomizableCharacterShimHelper::SetCharacterLookOverride(FName CharacterID, FName CharacterIdOverride) {
    return false;
}

bool UCustomizableCharacterShimHelper::RemoveCharacterLookOverride(FName CharacterID) {
    return false;
}

FName UCustomizableCharacterShimHelper::GetCharacterLookOverride(FName CharacterID) {
    return NAME_None;
}

UCustomizableCharacterShimHelper::UCustomizableCharacterShimHelper() {
}

