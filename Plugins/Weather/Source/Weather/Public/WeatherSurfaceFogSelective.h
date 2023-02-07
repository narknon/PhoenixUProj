#pragma once
#include "CoreMinimal.h"
#include "WeatherSurfaceFogBase.h"
#include "WeatherSurfaceFogSelective.generated.h"

class USceneComponent;

UCLASS(Blueprintable)
class WEATHER_API AWeatherSurfaceFogSelective : public AWeatherSurfaceFogBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* OnlyShowHide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyShowHideIncludeChildren;
    
    AWeatherSurfaceFogSelective();
    UFUNCTION(BlueprintCallable)
    void SetComponentToShowHide(USceneComponent* SceneComponent, bool bIncludeChildren);
    
};

