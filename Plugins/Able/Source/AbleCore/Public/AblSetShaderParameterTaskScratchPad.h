#pragma once
#include "CoreMinimal.h"
#include "AlphaBlend.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblSetShaderParameterTaskScratchPad.generated.h"

class UAblSetParameterValue;
class UMaterialInstanceDynamic;

UCLASS(Blueprintable, NonTransient)
class UAblSetShaderParameterTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> DynamicMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblSetParameterValue*> PreviousValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAlphaBlend BlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAlphaBlend BlendOut;
    
    UAblSetShaderParameterTaskScratchPad();
};

