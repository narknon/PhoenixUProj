#pragma once
#include "CoreMinimal.h"
#include "ECalloutActions.h"
#include "FXAutoTriggerCognitionStimuliTest.h"
#include "FXAutoTriggerCognitionStimuliTestAnyCalloutAction.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerCognitionStimuliTestAnyCalloutAction : public UFXAutoTriggerCognitionStimuliTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ECalloutActions> CalloutActions;
    
    UFXAutoTriggerCognitionStimuliTestAnyCalloutAction();
};

