#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingCustomBlendableNameLinearColor.h"
#include "GlobalLightingCustomBlendablesValue.h"
#include "GlobalLightingCustomBlendablesValueLinearColorDesaturate.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingCustomBlendablesValueLinearColorDesaturate : public UGlobalLightingCustomBlendablesValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightingCustomBlendableNameLinearColor Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Desaturate;
    
    UGlobalLightingCustomBlendablesValueLinearColorDesaturate();
};

