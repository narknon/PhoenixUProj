#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Enemy_AttackExtraData.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UEnemy_AttackExtraData : public UObject {
    GENERATED_BODY()
public:
    UEnemy_AttackExtraData();
};

