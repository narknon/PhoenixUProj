#pragma once
#include "CoreMinimal.h"
#include "MunitionType_Hitbox.h"
#include "MunitionType_AttackHitbox.generated.h"

UCLASS(Blueprintable)
class AMunitionType_AttackHitbox : public AMunitionType_Hitbox {
    GENERATED_BODY()
public:
    AMunitionType_AttackHitbox(const FObjectInitializer& ObjectInitializer);
};

