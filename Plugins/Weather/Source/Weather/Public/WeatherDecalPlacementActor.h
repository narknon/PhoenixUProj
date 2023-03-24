#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeatherDecalPlacementActor.generated.h"

UCLASS(Blueprintable)
class WEATHER_API AWeatherDecalPlacementActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> DecalTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    AWeatherDecalPlacementActor(const FObjectInitializer& ObjectInitializer);
};

