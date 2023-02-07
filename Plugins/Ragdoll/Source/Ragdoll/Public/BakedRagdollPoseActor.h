#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "BakedRagdollPoseActor.generated.h"

class UBakedRagdollPoseComponent;
class USkeletalMeshComponent;

UCLASS(Blueprintable, NotPlaceable)
class ABakedRagdollPoseActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBakedRagdollPoseComponent* BakedPoseComponent;
    
protected:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> SkelMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* ActorConstrainedToUs;
    
public:
    ABakedRagdollPoseActor();
protected:
    UFUNCTION(BlueprintCallable)
    void HandleOnActorHit(AActor* SelfActor, AActor* OtherActor, FVector ImpulseNormal, const FHitResult& HitReslt);
    
};

