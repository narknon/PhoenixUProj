#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapActorTagRules.h"
#include "MaterialSwapActorTypeRules.h"
#include "MaterialSwapObjectRules.h"
#include "MaterialSwapActorRules.generated.h"

USTRUCT(BlueprintType)
struct FMaterialSwapActorRules {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapObjectRules ObjectFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapActorTypeRules TypeFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapActorTagRules TagFilter;
    
    MATERIALPERMUTER_API FMaterialSwapActorRules();
};

