#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerCognitionStimuliTest.h"
#include "FXAutoTriggerCognitionStimuliTestHasSense.generated.h"

class UAISense_CogGroup;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerCognitionStimuliTestHasSense : public UFXAutoTriggerCognitionStimuliTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UAISense_CogGroup> Sense;
    
    UFXAutoTriggerCognitionStimuliTestHasSense();
};

