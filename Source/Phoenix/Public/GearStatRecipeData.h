#pragma once
#include "CoreMinimal.h"
#include "GearStatType.h"
#include "RecipeIngredient.h"
#include "GearStatRecipeData.generated.h"

USTRUCT(BlueprintType)
struct FGearStatRecipeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<GearStatType> StatType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Upgrade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRecipeIngredient> Ingredients;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasAllIngredients;
    
    PHOENIX_API FGearStatRecipeData();
};

