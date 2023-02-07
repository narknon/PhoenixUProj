#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CustomizableCharacterShimHelper.generated.h"

UCLASS(Blueprintable)
class UCustomizableCharacterShimHelper : public UObject {
    GENERATED_BODY()
public:
    UCustomizableCharacterShimHelper();
    UFUNCTION(BlueprintCallable)
    static bool SetCharacterLookOverride(FName CharacterID, FName CharacterIdOverride);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveCharacterLookOverride(FName CharacterID);
    
    UFUNCTION(BlueprintCallable)
    static FName GetCharacterLookOverride(FName CharacterID);
    
};

