#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GearItemID.h"
#include "GearManagerFunctionLibrary.generated.h"

UCLASS(Blueprintable)
class UGearManagerFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UGearManagerFunctionLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool NotEqual_GearItemIDGearItemID(const FGearItemID& arg1, const FGearItemID& arg);
    
    UFUNCTION(BlueprintCallable)
    static bool IsValid(const FGearItemID& GearItemID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool EqualEqual_GearItemIDGearItemID(const FGearItemID& arg1, const FGearItemID& arg2);
    
};

