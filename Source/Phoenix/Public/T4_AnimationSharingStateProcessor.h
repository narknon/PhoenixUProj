#pragma once
#include "CoreMinimal.h"
#include "AnimationSharingTypes.h"
#include "EFacialAnimType.h"
#include "T4_AnimationSharingStateProcessor.generated.h"

class AActor;

UCLASS(Blueprintable)
class UT4_AnimationSharingStateProcessor : public UAnimationSharingStateProcessor {
    GENERATED_BODY()
public:
    UT4_AnimationSharingStateProcessor();
    UFUNCTION(BlueprintCallable)
    void UpdateT4State(int32& OutState, AActor* InActor, uint8 CurrentState, uint8 OnDemandState, bool& bShouldProcess);
    
    UFUNCTION(BlueprintCallable)
    void ProcessActorState_Implementation(int32& OutState, AActor* InActor, uint8 CurrentState, uint8 OnDemandState, bool& bShouldProcess);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetUsesEyeMouthAnims(uint8 InCurrentState, bool& bOutUsesEyeAnims, bool& bOutUsesMouthAnims);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    EFacialAnimType GetFacialAnimType(uint8 InCurrentState);
    
};

