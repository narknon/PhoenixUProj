#pragma once
#include "CoreMinimal.h"
#include "ActorSpawner.h"
#include "ESpawnCameraActorType.h"
#include "Templates/SubclassOf.h"
#include "Spawn_CameraActor.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USpawn_CameraActor : public UActorSpawner {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpawnCameraActorType CameraType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFixedAspectRatio;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> StackCameraClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> DefaultCameraClass;
    
public:
    USpawn_CameraActor();
};

