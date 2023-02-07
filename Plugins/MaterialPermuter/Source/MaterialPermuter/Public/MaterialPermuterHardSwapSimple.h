#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterHardSwapBase.h"
#include "MaterialPermuterHardSwapSimple.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterHardSwapSimple : public FMaterialPermuterHardSwapBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeChildren;
    
    FMaterialPermuterHardSwapSimple();
};

