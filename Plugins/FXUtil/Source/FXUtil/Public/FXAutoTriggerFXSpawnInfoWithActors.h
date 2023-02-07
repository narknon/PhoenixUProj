#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerFXSpawnInfo.h"
#include "FXAutoTriggerFXSpawnInfoWithActors.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FFXAutoTriggerFXSpawnInfoWithActors : public FFXAutoTriggerFXSpawnInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Instigator;
    
    FXUTIL_API FFXAutoTriggerFXSpawnInfoWithActors();
};

