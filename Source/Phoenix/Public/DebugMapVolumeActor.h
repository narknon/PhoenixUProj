#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugMapVolumeActor.generated.h"

class UDebugMapVolumeComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Blueprintable)
class ADebugMapVolumeActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString VolumeId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* VolumeDynamicMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* VolumeMaterial;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugMapVolumeComponent* DebugVolumeComponent;
    
public:
    ADebugMapVolumeActor(const FObjectInitializer& ObjectInitializer);
};

