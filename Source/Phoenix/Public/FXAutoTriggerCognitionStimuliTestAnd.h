#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerCognitionStimuliTest.h"
#include "FXAutoTriggerCognitionStimuliTestAnd.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerCognitionStimuliTestAnd : public UFXAutoTriggerCognitionStimuliTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerCognitionStimuliTest*> Tests;
    
    UFXAutoTriggerCognitionStimuliTestAnd();
};

