#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MaterialParameterSetter.h"
#include "MultiFXWrapper.h"
#include "EnemyCorruptionData.generated.h"

UCLASS(Blueprintable)
class UEnemyCorruptionData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialParameterSetter> CorruptionStartMaterialFXs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFXWrapper CorruptionFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialParameterSetter> CorruptionStopMaterialFXs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFXWrapper CorruptionStopParticalFX;
    
    UEnemyCorruptionData();
};

