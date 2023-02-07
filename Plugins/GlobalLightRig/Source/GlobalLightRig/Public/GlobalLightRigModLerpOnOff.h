#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigModLerpBinary.h"
#include "GlobalLightRigModLerpOnOff.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModLerpOnOff : public UGlobalLightRigModLerpBinary {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Cutoff;
    
    UGlobalLightRigModLerpOnOff();
};

