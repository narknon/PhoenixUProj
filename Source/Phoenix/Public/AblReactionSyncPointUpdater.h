#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AblAvaMotionWarpSyncPointUpdater.h"
#include "EReactionLocationSyncPointType.h"
#include "EReactionRotationSyncPointType.h"
#include "AblReactionSyncPointUpdater.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblReactionSyncPointUpdater : public UAblAvaMotionWarpSyncPointUpdater {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EReactionLocationSyncPointType LocationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EReactionRotationSyncPointType RotationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LocationOffset;
    
public:
    UAblReactionSyncPointUpdater();
};

