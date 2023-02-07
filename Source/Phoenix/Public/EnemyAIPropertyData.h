#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EEEnemyAISizeCategory.h"
#include "EnemyAIPropertyData.generated.h"

class UEnemyAIPathCheckPropertyData;

UCLASS(Blueprintable)
class UEnemyAIPropertyData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEEnemyAISizeCategory m_sizeCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RotationRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FleeFixedDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyAIPathCheckPropertyData* PathCheckPtr;
    
    UEnemyAIPropertyData();
};

