#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModLinearColorType.h"
#include "EGlobalLightRigModParam.h"
#include "EGlobalLightRigModType.h"
#include "EGlobalLightRigProbeMode.h"
#include "GlobalLightRigModColorBase.h"
#include "GlobalLightRigWorldModDriverName.h"
#include "GlobalLightRigModColorCurve.generated.h"

class UCurveLinearColor;

UCLASS(Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModColorCurve : public UGlobalLightRigModColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModParam Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightRigWorldModDriverName Source;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveLinearColor* Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModLinearColorType ColorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModType Type;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigProbeMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UGlobalLightRigModColorCurve();
};

