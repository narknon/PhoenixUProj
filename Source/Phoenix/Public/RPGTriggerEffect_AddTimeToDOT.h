#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_AddTimeToDOT.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_AddTimeToDOT : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SpellNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DurationToAdd;
    
public:
    URPGTriggerEffect_AddTimeToDOT();
};

