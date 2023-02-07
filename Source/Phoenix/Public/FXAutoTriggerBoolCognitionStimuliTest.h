#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerBoolCognitionStimuliTest.generated.h"

class UFXAutoTriggerCognitionStimuliTest;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolCognitionStimuliTest : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerCognitionStimuliTest* Test;
    
    UFXAutoTriggerBoolCognitionStimuliTest();
};

