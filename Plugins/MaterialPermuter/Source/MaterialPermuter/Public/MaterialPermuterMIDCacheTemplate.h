#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MaterialPermuterMIDCacheTemplate.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FMaterialPermuterMIDCacheTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* Template;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime Touched;
    
    MATERIALPERMUTER_API FMaterialPermuterMIDCacheTemplate();
};

