#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "AIPerformTaskVO.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskVO : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOrientToPlayer;
    
    UAIPerformTaskVO();
};

