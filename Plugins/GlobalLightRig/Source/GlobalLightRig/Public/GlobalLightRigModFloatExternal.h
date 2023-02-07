#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModColorConversionType.h"
#include "EGlobalLightRigModParam.h"
#include "GlobalLightRigModFloatBase.h"
#include "GlobalLightRigModFloatExternal.generated.h"

class UGlobalLightRigModOption;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModFloatExternal : public UGlobalLightRigModFloatBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModParam Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGlobalLightRigModOption*> Modifiers;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModColorConversionType ColorConversion;
    
    UGlobalLightRigModFloatExternal();
};

