#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConversationPreset_InitialTransform.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UConversationPreset_InitialTransform : public UObject {
    GENERATED_BODY()
public:
    UConversationPreset_InitialTransform();
};

