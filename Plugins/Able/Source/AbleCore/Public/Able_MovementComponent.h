#pragma once
#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Able_MovementComponent.generated.h"

class AActor;
class URootMotionModifier;
class URootMotionModifierProperties;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABLECORE_API UAble_MovementComponent : public UCharacterMovementComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URootMotionModifier*> RootMotionModifierArray;
    
public:
    UAble_MovementComponent();
    UFUNCTION(BlueprintCallable)
    void RemoveRootMotionModifier(URootMotionModifierProperties* InRootMotionModifierProperties);
    
    UFUNCTION(BlueprintCallable)
    URootMotionModifier* AddRootMotionModifier(URootMotionModifierProperties* InRootMotionModifierProperties, AActor* Instigator, float Duration);
    
};

