#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShadowSprint.generated.h"

class UCapsuleComponent;
class UShadowSprintMovementComponent;

UCLASS(Blueprintable)
class AShadowSprint : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActiveScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScaleIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShadowSprintMovementComponent* MovementComponent;
    
    AShadowSprint(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetScaleInfo(bool bInScaleIn, float InActiveScale);
    
    UFUNCTION(BlueprintCallable)
    UCapsuleComponent* GetCapsuleComponent();
    
};

