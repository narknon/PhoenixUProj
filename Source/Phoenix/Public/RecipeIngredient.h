#pragma once
#include "CoreMinimal.h"
#include "RecipeIngredientDefinition.h"
#include "RecipeIngredient.generated.h"

USTRUCT(BlueprintType)
struct FRecipeIngredient {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecipeIngredientDefinition RecipeDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentlyOwnedQuantity;
    
    PHOENIX_API FRecipeIngredient();
};

