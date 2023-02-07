#pragma once
#include "CoreMinimal.h"
#include "ERPGModInputTags.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_SetModBlackboardValue.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_SetModBlackboardValue : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ERPGModInputTags Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
public:
    URPGTriggerEffect_SetModBlackboardValue();
};

