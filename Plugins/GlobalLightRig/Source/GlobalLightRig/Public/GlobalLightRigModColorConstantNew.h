#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EGlobalLightRigModLinearColorType.h"
#include "EGlobalLightRigModParam.h"
#include "GlobalLightRigModColorBase.h"
#include "GlobalLightRigModColorConstantNew.generated.h"

class UGlobalLightRigModOption;

UCLASS(Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModColorConstantNew : public UGlobalLightRigModColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModParam Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModLinearColorType ColorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGlobalLightRigModOption*> Modifiers;
    
    UGlobalLightRigModColorConstantNew();
};

