#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapRulesObjectMatchMode.h"
#include "EMaterialSwapRulesObjects.h"
#include "MaterialSwapObjectRules.generated.h"

USTRUCT(BlueprintType)
struct FMaterialSwapObjectRules {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesObjects Rule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Objects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapRulesObjectMatchMode MatchMode;
    
    MATERIALPERMUTER_API FMaterialSwapObjectRules();
};

