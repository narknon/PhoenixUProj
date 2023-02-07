#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterHardSwapBase.h"
#include "MaterialSwapRules.h"
#include "MaterialPermuterHardSwapRules.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterHardSwapRules : public FMaterialPermuterHardSwapBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules Rules;
    
    FMaterialPermuterHardSwapRules();
};

