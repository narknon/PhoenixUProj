#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MaterialPermuterKey.h"
#include "MaterialPermuterKeyProperty.h"
#include "MaterialPermuterKeyBlueprintLibrary.generated.h"

UCLASS(Blueprintable)
class MATERIALPERMUTER_API UMaterialPermuterKeyBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMaterialPermuterKeyBlueprintLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MaterialPermuterKeySplit(FMaterialPermuterKey Key, FName& Group, FName& SubType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MaterialPermuterKeyIsValid(FMaterialPermuterKey Key, bool& bValid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MaterialPermuterKeyDropdownSplit(FMaterialPermuterKeyProperty KeyDropdown, FName& Group, FName& SubType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MaterialPermuterKeyDropdownIsValid(FMaterialPermuterKeyProperty KeyDropdown, bool& bValid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString MakeMaterialPermuterKeyHashString(FMaterialPermuterKey Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName MakeMaterialPermuterKeyHash(FMaterialPermuterKey Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialPermuterKey MakeMaterialPermuterKeyFromKeyDropdown(FMaterialPermuterKeyProperty KeyDropdown);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialPermuterKey MakeMaterialPermuterKeyFromGroupSubType(FName Group, FName SubType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString MakeMaterialPermuterKeyDropdownHashString(FMaterialPermuterKeyProperty KeyDropdown);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName MakeMaterialPermuterKeyDropdownHash(FMaterialPermuterKeyProperty KeyDropdown);
    
};

