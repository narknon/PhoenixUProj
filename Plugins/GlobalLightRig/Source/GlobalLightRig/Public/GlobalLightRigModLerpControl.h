#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EGlobalLightRigModParam.h"
#include "GlobalLightRigModLerpControl.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModLerpControl : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModParam Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UGlobalLightRigModLerpControl();
};

