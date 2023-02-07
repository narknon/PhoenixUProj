#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigWorldModDriverName.h"
#include "GlobalLightingCustomBlendableNameScalar.h"
#include "GlobalLightingCustomBlendablesValue.h"
#include "GlobalLightingCustomBlendablesValueScalarCurve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingCustomBlendablesValueScalarCurve : public UGlobalLightingCustomBlendablesValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightingCustomBlendableNameScalar Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightRigWorldModDriverName Source;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    UGlobalLightingCustomBlendablesValueScalarCurve();
};

