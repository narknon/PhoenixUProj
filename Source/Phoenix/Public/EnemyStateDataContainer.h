#pragma once
#include "CoreMinimal.h"
#include "EnemyStateData.h"
#include "ObjectStateDataContainerBase.h"
#include "EnemyStateDataContainer.generated.h"

UCLASS(Blueprintable, NonTransient)
class UEnemyStateDataContainer : public UObjectStateDataContainerBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyStateData Data;
    
    UEnemyStateDataContainer();
};

