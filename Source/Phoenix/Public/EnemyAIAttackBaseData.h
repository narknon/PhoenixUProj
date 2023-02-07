#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnemyAIAttackDistData.h"
#include "EnemyAIAttackDistTableDataContainer.h"
#include "EnemyAIAttackBaseData.generated.h"

UCLASS(Blueprintable)
class UEnemyAIAttackBaseData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxMoveAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideMobilityMoveThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveDistThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveDistThresholdNoMansLandScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveDistThresholdNoMansLandScaleCloser;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemyAIAttackDistTableDataContainer> ApproachDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyAIAttackDistData AttackData;
    
    UEnemyAIAttackBaseData();
};

