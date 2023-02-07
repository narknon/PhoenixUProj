#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModColorConversionType.h"
#include "EGlobalLightRigModParam.h"
#include "GlobalLightRigModFloatBase.h"
#include "GlobalLightRigModFloatConstantNew.generated.h"

class UGlobalLightRigModOption;

UCLASS(Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModFloatConstantNew : public UGlobalLightRigModFloatBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModParam Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGlobalLightRigModOption*> Modifiers;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModColorConversionType ColorConversion;
    
    UGlobalLightRigModFloatConstantNew();
};

