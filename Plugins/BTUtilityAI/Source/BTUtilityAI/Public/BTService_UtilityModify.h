#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_UtilityModify.generated.h"

UCLASS(Blueprintable)
class BTUTILITYAI_API UBTService_UtilityModify : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPauseUtilityEvaulation;
    
    UBTService_UtilityModify();
};

