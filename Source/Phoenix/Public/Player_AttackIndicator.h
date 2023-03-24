#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MultiFX2Handle.h"
#include "Player_AttackIndicator.generated.h"

class UMultiFX2_Base;

UCLASS(Abstract, Blueprintable)
class APlayer_AttackIndicator : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> ParryableBeamFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> UnblockableBeamFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> PerfectParryBeamFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBeamGoesAttackerToTarget;
    
    APlayer_AttackIndicator(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePerfectParry(FMultiFX2Handle InParraybleFX2Handle, FMultiFX2Handle InPerfectParryFX2Handle);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveIndicatorStop(bool bIsParryIndicator, bool bIsUnblockableIndicator, FMultiFX2Handle InFX2Handle);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveIndicatorStart(bool bIsParryIndicator, bool bIsUnblockableIndicator, FMultiFX2Handle InFX2Handle, const float InEstimatedTime);
    
};

