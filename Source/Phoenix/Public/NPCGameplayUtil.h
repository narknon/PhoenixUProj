#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "NPCGameplayUtil.generated.h"

class USkeletalMeshComponent;

UCLASS(Blueprintable)
class UNPCGameplayUtil : public UObject {
    GENERATED_BODY()
public:
    UNPCGameplayUtil();
    UFUNCTION(BlueprintCallable)
    static void SetLinearDampeningAcrossPhysicsBodies(const USkeletalMeshComponent* SkeletalMeshComp, const float LinearDampening);
    
    UFUNCTION(BlueprintCallable)
    static void AddImpulseSpread(const USkeletalMeshComponent* SkeletalMeshComp, const FVector Velocity, const bool bVelocityChange);
    
};

