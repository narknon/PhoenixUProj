#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_GenerateFocus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_GenerateFocus : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FocusAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AmountIsFullFocusBars;
    
public:
    URPGTriggerEffect_GenerateFocus();
};

