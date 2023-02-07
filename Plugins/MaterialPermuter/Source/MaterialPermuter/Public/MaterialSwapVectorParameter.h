#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MaterialSwapVectorParameter.generated.h"

USTRUCT(BlueprintType)
struct FMaterialSwapVectorParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Value;
    
    MATERIALPERMUTER_API FMaterialSwapVectorParameter();
};

