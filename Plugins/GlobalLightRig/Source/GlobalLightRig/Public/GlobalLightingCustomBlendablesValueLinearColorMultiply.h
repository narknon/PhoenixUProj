#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingCustomBlendableNameLinearColor.h"
#include "GlobalLightingCustomBlendablesValue.h"
#include "GlobalLightingCustomBlendablesValueLinearColorMultiply.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingCustomBlendablesValueLinearColorMultiply : public UGlobalLightingCustomBlendablesValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightingCustomBlendableNameLinearColor Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Intensity;
    
    UGlobalLightingCustomBlendablesValueLinearColorMultiply();
};

