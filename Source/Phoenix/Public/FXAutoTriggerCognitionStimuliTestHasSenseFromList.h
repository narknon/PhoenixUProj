#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerCognitionStimuliTest.h"
#include "FXAutoTriggerCognitionStimuliTestHasSenseFromList.generated.h"

class UAISense_CogGroup;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerCognitionStimuliTestHasSenseFromList : public UFXAutoTriggerCognitionStimuliTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<UAISense_CogGroup>> Senses;
    
    UFXAutoTriggerCognitionStimuliTestHasSenseFromList();
};

