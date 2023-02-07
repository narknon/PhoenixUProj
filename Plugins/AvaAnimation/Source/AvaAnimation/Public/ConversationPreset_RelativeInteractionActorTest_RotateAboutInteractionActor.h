#pragma once
#include "CoreMinimal.h"
#include "ConversationPreset_RelativeInteractionActorTest.h"
#include "ConversationPreset_RelativeInteractionActorTest_RotateAboutInteractionActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UConversationPreset_RelativeInteractionActorTest_RotateAboutInteractionActor : public UConversationPreset_RelativeInteractionActorTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CheckAngleStep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StartRotationToAvatar;
    
    UConversationPreset_RelativeInteractionActorTest_RotateAboutInteractionActor();
};

