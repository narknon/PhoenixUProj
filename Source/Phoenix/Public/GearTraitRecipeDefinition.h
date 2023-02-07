#pragma once
#include "CoreMinimal.h"
#include "RecipeIngredientDefinition.h"
#include "GearTraitRecipeDefinition.generated.h"

USTRUCT(BlueprintType)
struct FGearTraitRecipeDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TraitID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LockId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRecipeIngredientDefinition> Ingredients;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RarityTier;
    
    PHOENIX_API FGearTraitRecipeDefinition();
};

