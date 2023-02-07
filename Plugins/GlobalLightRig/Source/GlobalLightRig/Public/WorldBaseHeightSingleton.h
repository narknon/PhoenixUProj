#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldBaseHeights.h"
#include "WorldBaseHeightsTracker.h"
#include "WorldBaseHeightSingleton.generated.h"

class AActor;
class UExponentialHeightFogComponent;
class USceneComponent;
class UVolumetricCloudsComponent;
class UWorld;

UCLASS(Blueprintable, Transient)
class GLOBALLIGHTRIG_API UWorldBaseHeightSingleton : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldBaseHeights Base;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldBaseHeightsTracker Offsets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldBaseHeights Final;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 UpdateDisable;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorld* OwningWorld;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UExponentialHeightFogComponent> SetFogComponent;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UVolumetricCloudsComponent> SetCloudsComponent;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> SetAtmosphereComponent;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UExponentialHeightFogComponent> CachedFogComponent;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UVolumetricCloudsComponent> CachedCloudsComponent;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> CachedAtmosphereComponent;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> BaseOverrides;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> BaseHeightObjects;
    
public:
    UWorldBaseHeightSingleton();
};

