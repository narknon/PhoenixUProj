#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapRulesObjects.h"
#include "MaterialSwapObjectTagRules.generated.h"

USTRUCT(BlueprintType)
struct FMaterialSwapObjectTagRules {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesObjects Rule;
    
    MATERIALPERMUTER_API FMaterialSwapObjectTagRules();
};

