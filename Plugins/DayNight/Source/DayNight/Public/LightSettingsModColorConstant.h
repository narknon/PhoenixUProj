#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ELightRigCurveLinearColorType.h"
#include "LightSettingsModColorBase.h"
#include "LightSettingsModColorConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModColorConstant : public ULightSettingsModColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightRigCurveLinearColorType ColorType;
    
    ULightSettingsModColorConstant();
};

