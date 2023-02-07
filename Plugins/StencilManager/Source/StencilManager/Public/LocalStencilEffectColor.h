#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocalStencilEffectMaterialParameter.h"
#include "LocalStencilEffectColor.generated.h"

USTRUCT(BlueprintType)
struct FLocalStencilEffectColor : public FLocalStencilEffectMaterialParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    STENCILMANAGER_API FLocalStencilEffectColor();
};

