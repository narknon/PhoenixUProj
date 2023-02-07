#pragma once
#include "CoreMinimal.h"
#include "ERPGModInputTags.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_ModifyModBlackboardValue.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_ModifyModBlackboardValue : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ERPGModInputTags Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ModificationValue;
    
public:
    URPGTriggerEffect_ModifyModBlackboardValue();
};

