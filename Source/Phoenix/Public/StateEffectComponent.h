#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateEffectComponentEndEffectDelegate.h"
#include "StateEffectComponent.generated.h"

class AActor;
class ASpellTool;
class UMultiFX2_Base;
class UObjectStateInfo;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UStateEffectComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateEffectComponentEndEffect OnEndEffect;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectStateInfo* ObjectStateInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Instigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASpellTool* SpellTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> endFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> BreakoutFX;
    
public:
    UStateEffectComponent();
    UFUNCTION(BlueprintCallable)
    void SetDuration(float InDuration);
    
    UFUNCTION(BlueprintCallable)
    void ResetDuration();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRemainingTime() const;
    
    UFUNCTION(BlueprintCallable)
    void EndEffect();
    
};

