#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsInterface.h"
#include "ELightAdapatationEVModOp.h"
#include "ELightAdapatationEVProperty.h"
#include "DynamicLightAdaptationModSettingsEVExpression.generated.h"

class UExposureExpressionsExposureValue;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UDynamicLightAdaptationModSettingsEVExpression : public UDynamicLightAdaptationModSettingsInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightAdapatationEVProperty ModProperty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightAdapatationEVModOp ModOp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* Expression;
    
    UDynamicLightAdaptationModSettingsEVExpression();
};

