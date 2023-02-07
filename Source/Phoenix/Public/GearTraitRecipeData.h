#pragma once
#include "CoreMinimal.h"
#include "GearTraitRecipeDefinition.h"
#include "RecipeIngredient.h"
#include "GearTraitRecipeData.generated.h"

USTRUCT(BlueprintType)
struct FGearTraitRecipeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearTraitRecipeDefinition RecipeDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUnlocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasAllIngredients;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRecipeIngredient> Ingredients;
    
    PHOENIX_API FGearTraitRecipeData();
};

