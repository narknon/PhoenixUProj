#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackExtraData.h"
#include "ActivateDOV_AttackExtraData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UActivateDOV_AttackExtraData : public UEnemy_AttackExtraData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistanceSquared;
    
    UActivateDOV_AttackExtraData();
};

