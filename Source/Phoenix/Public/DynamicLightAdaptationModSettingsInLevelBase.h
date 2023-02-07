#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesLevelName.h"
#include "DynamicLightAdaptationModSettingsInterface.h"
#include "ELightAdapatationEVModOp.h"
#include "DynamicLightAdaptationModSettingsInLevelBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UDynamicLightAdaptationModSettingsInLevelBase : public UDynamicLightAdaptationModSettingsInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesLevelName LevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSearchFullLevelNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightAdapatationEVModOp ModOp;
    
    UDynamicLightAdaptationModSettingsInLevelBase();
};

