#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ESurfaceFogType.h"
#include "WeatherSurfaceFogBase.generated.h"

UCLASS(Abstract, Blueprintable)
class WEATHER_API AWeatherSurfaceFogBase : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SupportedFogTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ESurfaceFogType ShowingFogType;
    
    AWeatherSurfaceFogBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RecalculateBounds();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowSurfaceFog(ESurfaceFogType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHideSurfaceFog();
    
};

