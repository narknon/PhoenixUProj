#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "MultiFX2Handle.h"
#include "DisillusionmentData.h"
#include "StateEffectComponent.h"
#include "DisillusionmentComponent.generated.h"

class AActor;
class ACharacter;
class UMaterialSwap;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDisillusionmentComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDisillusionmentData DisillusionmentData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* SightDetectionSphereActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<AActor*, AActor*> SightDetectionActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> FullyAwareActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MinSightAngleDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMultiFX2Handle FX2Handle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialSwap* MaterialSwap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> TaggedActors;
    
    UDisillusionmentComponent();
    UFUNCTION(BlueprintCallable)
    static void RemoveDisillusionmentFromActor(const AActor* Actor, bool bEvenIfCloak);
    
    UFUNCTION(BlueprintCallable)
    void PerceptionDoneHandler(AActor* Actor, bool bSuccess, bool bReturnControl);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OwnerMovementModeChanged(ACharacter* Character, TEnumAsByte<EMovementMode> PrevMovementMode, uint8 PreviousCustomMode);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnActorEndOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnActorBeginOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    static bool IsActorDisillusionedByCloak(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool IsActorDisillusioned(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    float GetVisibilityPercentage();
    
};

