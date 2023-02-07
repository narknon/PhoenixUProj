#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_Crime.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_Crime : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SeverityLevel;
    
public:
    URPGTriggerEffect_Crime();
};

