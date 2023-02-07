#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConversationPreset_FinalTransform.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UConversationPreset_FinalTransform : public UObject {
    GENERATED_BODY()
public:
    UConversationPreset_FinalTransform();
};

