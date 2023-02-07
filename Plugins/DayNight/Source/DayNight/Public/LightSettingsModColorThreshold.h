#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ELightRigCurveLinearColorType.h"
#include "LightSettingsModColorBase.h"
#include "LightSettingsModColorThreshold.generated.h"

class ULightSettingsModThreshold;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModColorThreshold : public ULightSettingsModColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULightSettingsModThreshold* Threshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ColorAbove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ColorBelow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightRigCurveLinearColorType ColorType;
    
    ULightSettingsModColorThreshold();
};

