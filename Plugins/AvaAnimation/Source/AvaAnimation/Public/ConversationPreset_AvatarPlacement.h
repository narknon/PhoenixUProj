#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConversationPreset_AvatarPlacement.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UConversationPreset_AvatarPlacement : public UObject {
    GENERATED_BODY()
public:
    UConversationPreset_AvatarPlacement();
};

