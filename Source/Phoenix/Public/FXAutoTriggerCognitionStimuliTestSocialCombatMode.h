#pragma once
#include "CoreMinimal.h"
#include "ESocialCombatMode.h"
#include "FXAutoTriggerCognitionStimuliTest.h"
#include "FXAutoTriggerCognitionStimuliTestSocialCombatMode.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerCognitionStimuliTestSocialCombatMode : public UFXAutoTriggerCognitionStimuliTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESocialCombatMode SocialCombatMode;
    
    UFXAutoTriggerCognitionStimuliTestSocialCombatMode();
};

