#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EGlobalLightRigModParam.h"
#include "ELightRigCurveParam.h"
#include "LightSettingsLerpControl.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API ULightSettingsLerpControl : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModParam ModParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightRigCurveParam Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ULightSettingsLerpControl();
};

