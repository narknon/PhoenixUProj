#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "OdcFlags.h"
#include "BTService_Creature_ModifyAreaFlags.generated.h"

UCLASS(Blueprintable)
class UBTService_Creature_ModifyAreaFlags : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReplace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlags AreaUsageFlags;
    
    UBTService_Creature_ModifyAreaFlags();
};

