#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayProperty_Float.h"
#include "Moddable.h"
#include "BrewingRecipe.h"
#include "BrewingManager.generated.h"

class UBrewingSiteState;

UCLASS(Blueprintable)
class UBrewingManager : public UObject, public IModdable {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float BrewTimeMultiplier;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, UBrewingSiteState*> ActiveBrewingSiteStates;
    
public:
    UBrewingManager();
    UFUNCTION(BlueprintCallable, Exec)
    void UnlockAllPotionRecipes();
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBrewTimeMultiplier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetBrewingUICategories() const;
    
    UFUNCTION(BlueprintCallable)
    void GetBrewingRecipes(TArray<FBrewingRecipe>& AvailableRecipes, TArray<FBrewingRecipe>& LockedRecipes);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GetAllPotions(int32 AmountToGrant);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GetAllPotionIngredients(int32 AmountToGrant);
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UBrewingManager* BP_Get();
    
public:
    UFUNCTION(BlueprintCallable)
    static bool AreOwnedIngredientsEnough(const FBrewingRecipe& BrewingRecipe);
    
    
    // Fix for true pure virtual functions not being implemented
};

