#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTargetTypeLocation.h"
#include "AblAbilityTask.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "ablAttackHitboxTask.generated.h"

class AMunitionType_Hitbox;
class UInteractionArchitectAsset;

UCLASS(Blueprintable, EditInlineNew)
class UablAttackHitboxTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Hitbox> MunitionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MunitionImpactType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MunitionTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* MunitionDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAblAbilityTargetTypeLocation HitboxLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttachToSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNotifyParrySystem;
    
public:
    UablAttackHitboxTask();
};

