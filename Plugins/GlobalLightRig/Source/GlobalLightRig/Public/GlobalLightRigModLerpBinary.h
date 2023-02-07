#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigModLerpControl.h"
#include "GlobalLightRigModLerpBinary.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModLerpBinary : public UGlobalLightRigModLerpControl {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvert;
    
    UGlobalLightRigModLerpBinary();
};

