#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_CreatureAttackImpact.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UAnimNotify_CreatureAttackImpact : public UAnimNotify {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
public:
    UAnimNotify_CreatureAttackImpact();
};

