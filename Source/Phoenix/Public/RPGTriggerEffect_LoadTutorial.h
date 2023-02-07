#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_LoadTutorial.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_LoadTutorial : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TutorialName;
    
public:
    URPGTriggerEffect_LoadTutorial();
};

