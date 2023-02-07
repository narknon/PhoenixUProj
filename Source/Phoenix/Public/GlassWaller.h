#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "AI/Navigation/NavigationTypes.h"
#include "GlassWaller.generated.h"

class UInstancedStaticMeshComponent;
class USplineComponent;

UCLASS(Blueprintable)
class AGlassWaller : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* InstancedStaticMeshComponent;
    
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENavDataGatheringMode NavigationGeometryGatheringMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableWhenPlayerMounted;
    
    AGlassWaller();
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WithEditor();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetMobility(EComponentMobility::Type InMobility);
    
};

