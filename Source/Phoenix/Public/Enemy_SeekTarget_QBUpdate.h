#pragma once
#include "CoreMinimal.h"
#include "Enemy_QBUpdate.h"
#include "Enemy_SeekTarget_QBUpdate.generated.h"

UCLASS(Blueprintable)
class UEnemy_SeekTarget_QBUpdate : public UEnemy_QBUpdate {
    GENERATED_BODY()
public:
    UEnemy_SeekTarget_QBUpdate();
};

