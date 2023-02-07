#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EGlobalLightRigModLinearColorType.h"
#include "EGlobalLightRigModParam.h"
#include "EGlobalLightRigModType.h"
#include "EGlobalLightRigProbeMode.h"
#include "GlobalLightRigModColorBase.h"
#include "GlobalLightRigModColorConstant.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModColorConstant : public UGlobalLightRigModColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModParam Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModLinearColorType ColorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModType Type;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigProbeMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UGlobalLightRigModColorConstant();
};

