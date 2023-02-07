#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigWorldModDriverName.h"
#include "GlobalLightingCustomBlendableNameLinearColor.h"
#include "GlobalLightingCustomBlendablesValue.h"
#include "GlobalLightingCustomBlendablesValueLinearColorCurve.generated.h"

class UCurveLinearColor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingCustomBlendablesValueLinearColorCurve : public UGlobalLightingCustomBlendablesValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightingCustomBlendableNameLinearColor Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightRigWorldModDriverName Source;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveLinearColor* Curve;
    
    UGlobalLightingCustomBlendablesValueLinearColorCurve();
};

