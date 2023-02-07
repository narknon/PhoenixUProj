#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EablEnemy_DragonMobilityType.h"
#include "ablDragonMobilityTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablDragonMobilityTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EablEnemy_DragonMobilityType MobilityType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistFromTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightAboveTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveSpeed;
    
public:
    UablDragonMobilityTask();
};

