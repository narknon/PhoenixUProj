#pragma once
#include "CoreMinimal.h"
#include "SceneAction_AnimatedLightControllerComponent.h"
#include "SceneAction_DayNightLightControllerComponent.generated.h"

class USceneActionDayNightLightControllerSettings;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_DayNightLightControllerComponent : public USceneAction_AnimatedLightControllerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneActionDayNightLightControllerSettings* Settings;
    
    USceneAction_DayNightLightControllerComponent();
};

