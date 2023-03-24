#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "TransfigurationPreviewEffect.generated.h"

UCLASS(Blueprintable)
class ATransfigurationPreviewEffect : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool CanPlaceObject;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* TargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* TargetActorCopy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector ObjectExtent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector ObjectCenter;
    
public:
    ATransfigurationPreviewEffect(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TickVFX(float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable)
    void OnTargetActorDestroyed(AActor* InDestroyedActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BeginVFX();
    
};

