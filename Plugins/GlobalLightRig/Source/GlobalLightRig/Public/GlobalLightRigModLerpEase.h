#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModLerpEasingType.h"
#include "GlobalLightRigModLerpControl.h"
#include "GlobalLightRigModLerpEase.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModLerpEase : public UGlobalLightRigModLerpControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightRigModLerpEasingType Easing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendExp;
    
    UGlobalLightRigModLerpEase();
};

