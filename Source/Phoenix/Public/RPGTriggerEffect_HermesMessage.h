#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_HermesMessage.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_HermesMessage : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString HermesMessage;
    
public:
    URPGTriggerEffect_HermesMessage();
};

