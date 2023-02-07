#pragma once
#include "CoreMinimal.h"
#include "CustomizableActor.h"
#include "StationInteractor_Interface.h"
#include "Templates/SubclassOf.h"
#include "Tier4_Actor.generated.h"

class AActor;
class AStation;
class AVisibilityMeshActor;
class UCapsuleComponent;
class UPhxAnimationSharingSetup;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ATier4_Actor : public ACustomizableActor, public IStationInteractor_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPhxAnimationSharingSetup> AnimSharingSetup;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* Collision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AVisibilityMeshActor* VisibilityMesh;
    
public:
    ATier4_Actor();
    UFUNCTION(BlueprintCallable)
    bool TeleportToStation(const AStation* InStation, const int32 InConnectionIndex);
    
    UFUNCTION(BlueprintCallable)
    void SetManagedStackVisibilityMesh(UStaticMeshComponent* InVisibilityMesh);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCharacterLoadComplete(AActor* inTheActor);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnBeginActorOverlap(AActor* SelfActor, AActor* OtherActor);
    
    
    // Fix for true pure virtual functions not being implemented
};

