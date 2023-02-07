#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "Enemy_ApparateActorData.h"
#include "Enemy_SplineSpawnActorData.h"
#include "EnemyAIStateInterface.generated.h"

class AEnemy_ApparateActor;
class AEnemy_SplineSpawnActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UEnemyAIStateInterface : public UInterface {
    GENERATED_BODY()
};

class IEnemyAIStateInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AEnemy_SplineSpawnActor* SpawnSplineSpawnActor(FTransform SpawnTransform, const FEnemy_SplineSpawnActorData& Data);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AEnemy_ApparateActor* SpawnApparateActor(FTransform SpawnTransform, const FEnemy_ApparateActorData& Data);
    
};

