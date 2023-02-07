#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapScalarParameter.generated.h"

USTRUCT(BlueprintType)
struct FMaterialSwapScalarParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    MATERIALPERMUTER_API FMaterialSwapScalarParameter();
};

