#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "EBrewingState.h"
#include "RecipeIngredient.h"
#include "BrewingSiteState.generated.h"

UCLASS(Blueprintable)
class UBrewingSiteState : public UObject {
    GENERATED_BODY()
public:
    UBrewingSiteState();
    UFUNCTION(BlueprintCallable)
    void InstantlyCompleteBrewing();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetUncollectedYield() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRecipeYield() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FRecipeIngredient> GetRecipeIngredients() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetPotionID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetOutputItemID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsInSanctuary() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHasInventorySpaceToCollectPotion(FName CollectorID, int32& OutYieldLeft) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTimespan GetBrewingTimeRemaining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EBrewingState GetBrewingState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBrewingProgressRatio() const;
    
};

