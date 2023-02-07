#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModColorConversionType.h"
#include "EGlobalLightRigModParam.h"
#include "GlobalLightRigModFloatBase.h"
#include "GlobalLightRigWorldModDriverName.h"
#include "GlobalLightRigModFloatCurveNew.generated.h"

class UCurveFloat;
class UGlobalLightRigModOption;

UCLASS(Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModFloatCurveNew : public UGlobalLightRigModFloatBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModParam Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightRigWorldModDriverName Source;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGlobalLightRigModOption*> Modifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModColorConversionType ColorConversion;
    
    UGlobalLightRigModFloatCurveNew();
};

