#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsInterface.h"
#include "ELightAdapatationModOp.h"
#include "ELightAdapatationProperty.h"
#include "DynamicLightAdaptationModSettingsVariableBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UDynamicLightAdaptationModSettingsVariableBase : public UDynamicLightAdaptationModSettingsInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightAdapatationProperty ModProperty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightAdapatationModOp ModOp;
    
    UDynamicLightAdaptationModSettingsVariableBase();
};

