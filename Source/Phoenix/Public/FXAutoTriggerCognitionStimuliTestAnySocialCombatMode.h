#pragma once
#include "CoreMinimal.h"
#include "ESocialCombatMode.h"
#include "FXAutoTriggerCognitionStimuliTest.h"
#include "FXAutoTriggerCognitionStimuliTestAnySocialCombatMode.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerCognitionStimuliTestAnySocialCombatMode : public UFXAutoTriggerCognitionStimuliTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ESocialCombatMode> SocialCombatModes;
    
    UFXAutoTriggerCognitionStimuliTestAnySocialCombatMode();
};

