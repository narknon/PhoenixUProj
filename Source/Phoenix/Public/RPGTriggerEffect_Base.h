#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RPGTriggerEffect_Base.generated.h"

class URPGCondition;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class URPGTriggerEffect_Base : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URPGCondition*> Conditions;
    
    URPGTriggerEffect_Base();
};

