#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "BaseStateComponent.h"
#include "EnemyStateData.h"
#include "EnemyStateComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemyStateComponent : public UBaseStateComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyStateData EnemyStateData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo TeamAsset;
    
public:
    UEnemyStateComponent();
};

