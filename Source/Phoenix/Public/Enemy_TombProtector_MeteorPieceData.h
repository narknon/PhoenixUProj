#pragma once
#include "CoreMinimal.h"
#include "Enemy_TombProtector_MeteorPieceData.generated.h"

class AEnemyAIWeapon;

USTRUCT(BlueprintType)
struct FEnemy_TombProtector_MeteorPieceData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AEnemyAIWeapon> MeteorPtr;
    
    PHOENIX_API FEnemy_TombProtector_MeteorPieceData();
};

