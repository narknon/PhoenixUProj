#pragma once
#include "CoreMinimal.h"
#include "Enemy_QBUpdateData.h"
#include "Enemy_Reposition_QBUpdateData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnemy_Reposition_QBUpdateData : public UEnemy_QBUpdateData {
    GENERATED_BODY()
public:
    UEnemy_Reposition_QBUpdateData();
};

