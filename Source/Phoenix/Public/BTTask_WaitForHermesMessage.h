#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_WaitForHermesMessage.generated.h"

UCLASS(Blueprintable)
class UBTTask_WaitForHermesMessage : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MessageName;
    
    UBTTask_WaitForHermesMessage();
};

