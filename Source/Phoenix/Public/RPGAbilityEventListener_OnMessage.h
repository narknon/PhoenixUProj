#pragma once
#include "CoreMinimal.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityEventListener_OnMessage.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnMessage : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString HermesMessage;
    
public:
    URPGAbilityEventListener_OnMessage();
};

