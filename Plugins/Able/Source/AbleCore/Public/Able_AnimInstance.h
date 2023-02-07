#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_AnimInstance.h"
#include "UObject/NoExportTypes.h"
#include "Able_AnimInstance_Interface.h"
#include "Able_AnimInstance.generated.h"

class UAblAbilityComponent;
class UAblAnimationModifier;
class UAnimSequence;

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAble_AnimInstance : public UAnimationArchitect_AnimInstance, public IAble_AnimInstance_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UAnimSequence*, float> MapSequenceToPhaseVote;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InIdle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblAnimationModifier*> AnimationModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DesiredWorldDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LastDesiredWorldDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredWorldSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RateMultiplierOverride;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FixedYawRemaining;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FixedYawOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FixedYawSampleTime;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAblAbilityComponent* AbleAbilityComponent;
    
public:
    UAble_AnimInstance();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_LastDesiredWorldDirection(FVector InWorldDirection);
    
    UFUNCTION(BlueprintCallable)
    void Set_FixedYaw(const float InFixedYawRemaining, const float InFixedYawOffset, const float SampleTime);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_DesiredWorldSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_DesiredWorldDirection(FVector InWorldDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_LastDesiredWorldDirection(FVector& OutWorldDirection);
    
    UFUNCTION(BlueprintCallable)
    void Get_FixedYawSampleTime(float& OutFixedYawSampleTime);
    
    UFUNCTION(BlueprintCallable)
    void Get_FixedYawRemaining(float& OutFixedYawRemaining);
    
    UFUNCTION(BlueprintCallable)
    void Get_FixedYawOffset(float& OutFixedYawOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_DesiredWorldSpeed(float& OutSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_DesiredWorldDirection(FVector& OutWorldDirection);
    
    
    // Fix for true pure virtual functions not being implemented
};

