#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ECreatureStance.h"
#include "PropOwl_AnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UPropOwl_AnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureStance DesiredStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureStance InitStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ReactToSpell;
    
    UPropOwl_AnimInstance();
};

