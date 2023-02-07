#pragma once
#include "CoreMinimal.h"
#include "Enemy_InstanceQBUpdateData.h"
#include "Enemy_SeekTarget_InstanceQBUpdateData.generated.h"

UCLASS(Blueprintable)
class UEnemy_SeekTarget_InstanceQBUpdateData : public UEnemy_InstanceQBUpdateData {
    GENERATED_BODY()
public:
    UEnemy_SeekTarget_InstanceQBUpdateData();
};

