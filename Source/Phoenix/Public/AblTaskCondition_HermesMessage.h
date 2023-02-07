#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblTaskCondition_HermesMessage.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblTaskCondition_HermesMessage : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HermesMessageName;
    
    UAblTaskCondition_HermesMessage();
};

