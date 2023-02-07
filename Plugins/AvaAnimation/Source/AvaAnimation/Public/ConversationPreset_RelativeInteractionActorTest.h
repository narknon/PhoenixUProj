#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConversationPreset_RelativeInteractionActorTest.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UConversationPreset_RelativeInteractionActorTest : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UConversationPreset_RelativeInteractionActorTest();
};

