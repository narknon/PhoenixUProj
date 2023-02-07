#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModLinearColorType.h"
#include "EGlobalLightRigModParam.h"
#include "GlobalLightRigModColorBase.h"
#include "GlobalLightRigWorldModDriverName.h"
#include "GlobalLightRigModColorCurveNew.generated.h"

class UCurveLinearColor;
class UGlobalLightRigModOption;

UCLASS(Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModColorCurveNew : public UGlobalLightRigModColorBase {
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGlobalLightRigModOption*> Modifiers;
    
    UGlobalLightRigModColorCurveNew();
};

