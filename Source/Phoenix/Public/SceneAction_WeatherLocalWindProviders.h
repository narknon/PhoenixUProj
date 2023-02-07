#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherLocalWind.h"
#include "SceneAction_WeatherLocalWindProviders.generated.h"

class UFloatProvider;
class UVectorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_WeatherLocalWindProviders : public USceneAction_WeatherLocalWind {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVectorProvider* Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* Speed;
    
    USceneAction_WeatherLocalWindProviders();
};

