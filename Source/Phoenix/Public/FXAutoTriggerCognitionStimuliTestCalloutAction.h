#pragma once
#include "CoreMinimal.h"
#include "ECalloutActions.h"
#include "FXAutoTriggerCognitionStimuliTest.h"
#include "FXAutoTriggerCognitionStimuliTestCalloutAction.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerCognitionStimuliTestCalloutAction : public UFXAutoTriggerCognitionStimuliTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECalloutActions CalloutAction;
    
    UFXAutoTriggerCognitionStimuliTestCalloutAction();
};

