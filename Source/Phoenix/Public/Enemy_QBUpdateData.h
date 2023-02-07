#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Enemy_QBUpdateData.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, Config=Game)
class UEnemy_QBUpdateData : public UObject {
    GENERATED_BODY()
public:
    UEnemy_QBUpdateData();
};

