#pragma once
#include "CoreMinimal.h"
#include "RecipeIngredientDefinition.generated.h"

USTRUCT(BlueprintType)
struct FRecipeIngredientDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IngredientName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Quantity;
    
    PHOENIX_API FRecipeIngredientDefinition();
};

