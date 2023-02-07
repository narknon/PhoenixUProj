#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MaterialPermuterKey.h"
#include "WeatherStormState.h"
#include "WeatherSurfaceCharacterFXState.h"
#include "WeatherStorm.generated.h"

class AActor;
class AFullScreenWeatherDecalActor;
class AWeatherAnimationBlueprint;
class AWeatherCoverageBlueprint;
class UMaterialPermuterLoadingBundle;
class UMaterialSwapSphereSelectionComponent;
class UWeatherSurfaceDataAsset;

UCLASS(Blueprintable, Transient)
class WEATHER_API UWeatherStorm : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> ParentActor;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> StormOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWeatherSurfaceDataAsset* SurfaceData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeatherStormState StormState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFullScreenWeatherDecalActor* WeatherDecal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AWeatherAnimationBlueprint* WeatherAnimationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AWeatherCoverageBlueprint* WeatherCoverageActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMaterialSwapSphereSelectionComponent* WeatherSwapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMaterialPermuterLoadingBundle* CharacterFXLoadingBundle;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FWeatherSurfaceCharacterFXState> CharacterFX;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialPermuterKey WeatherGroupKey;
    
public:
    UWeatherStorm();
};

