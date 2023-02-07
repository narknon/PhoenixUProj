#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "Templates/SubclassOf.h"
#include "ablCentaurSpawnMunitionTask.generated.h"

class AActor;
class AMunitionType_Base;

UCLASS(Blueprintable, EditInlineNew)
class UablCentaurSpawnMunitionTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> EquipArrowClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> MunitionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ArrowSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MunitionSocketOffsetX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BlackboardTargetActorKeyName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTrackTargetLocation;
    
    UablCentaurSpawnMunitionTask();
};

