#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModColorConversionType.h"
#include "EGlobalLightRigModParam.h"
#include "EGlobalLightRigModType.h"
#include "EGlobalLightRigProbeMode.h"
#include "GlobalLightRigModFloatBase.h"
#include "GlobalLightRigModFloatConstant.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModFloatConstant : public UGlobalLightRigModFloatBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModParam Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModColorConversionType ColorConversion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModType Type;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigProbeMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UGlobalLightRigModFloatConstant();
};

