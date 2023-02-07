#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerCognitionStimuliTest.h"
#include "FXAutoTriggerCognitionStimuliTestNot.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerCognitionStimuliTestNot : public UFXAutoTriggerCognitionStimuliTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerCognitionStimuliTest* Test;
    
    UFXAutoTriggerCognitionStimuliTestNot();
};

