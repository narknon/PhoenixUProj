#pragma once
#include "CoreMinimal.h"
#include "ConversationPresetReference.h"
#include "NameProvider.h"
#include "Name_ConversationPreset.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UName_ConversationPreset : public UNameProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationPresetReference Reference;
    
    UName_ConversationPreset();
};

