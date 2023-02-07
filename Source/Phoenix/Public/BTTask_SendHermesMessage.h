#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_SendHermesMessage.generated.h"

UCLASS(Blueprintable)
class UBTTask_SendHermesMessage : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MessageName;
    
    UBTTask_SendHermesMessage();
};

