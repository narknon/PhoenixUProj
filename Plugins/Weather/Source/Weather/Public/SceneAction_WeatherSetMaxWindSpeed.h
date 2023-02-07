#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherGeneric.h"
#include "SceneAction_WeatherSetMaxWindSpeed.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_WeatherSetMaxWindSpeed : public USceneAction_WeatherGeneric {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxWindSpeed;
    
    USceneAction_WeatherSetMaxWindSpeed();
};

