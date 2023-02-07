#pragma once
#include "CoreMinimal.h"
#include "ELerpEasingType.h"
#include "LightDirectionLerpControl.h"
#include "LightDirectionEase.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightDirectionEase : public ULightDirectionLerpControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELerpEasingType Easing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendExp;
    
    ULightDirectionEase();
};

