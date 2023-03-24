#pragma once
#include "CoreMinimal.h"
#include "SpellTool.h"
#include "ReparoSpellTool.generated.h"

class UActorComponent;
class UMultiFX2_Base;
class UObject;

UCLASS(Blueprintable)
class AReparoSpellTool : public ASpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FailedFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> EndFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyHitTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetQueryCapsuleRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetQueryCapsuleOffsetX;
    
    AReparoSpellTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ReparoExpired();
    
    UFUNCTION(BlueprintCallable)
    void ReparoCancel(const UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    static void DisableReparoAOE(bool Disable);
    
    UFUNCTION(BlueprintCallable)
    void ARepairComplete(UActorComponent* Comp);
    
};

