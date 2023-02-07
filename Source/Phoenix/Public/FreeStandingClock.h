#pragma once
#include "CoreMinimal.h"
#include "TransfigurationObjectBase.h"
#include "FreeStandingClock.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class AFreeStandingClock : public ATransfigurationObjectBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* HandsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* HourHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* MinuteHand;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HandRotateDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHandsLookAtPlayer;
    
public:
    AFreeStandingClock();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnClockChime();
    
    UFUNCTION(BlueprintCallable)
    void DoClockTick();
    
};

