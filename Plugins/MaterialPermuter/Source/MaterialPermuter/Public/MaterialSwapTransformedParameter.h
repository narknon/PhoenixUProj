#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ETransformedParameterSource.h"
#include "MaterialSwapCachedTransformSourceBone.h"
#include "MaterialSwapCachedTransformSourceComponent.h"
#include "MaterialSwapTransformedParameter.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapTransformedParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TransformSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETransformedParameterSource TransformType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapCachedTransformSourceBone CachedBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapCachedTransformSourceComponent CachedComponent;
    
    FMaterialSwapTransformedParameter();
};

