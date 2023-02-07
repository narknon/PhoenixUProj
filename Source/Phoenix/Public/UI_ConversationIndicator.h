#pragma once
#include "CoreMinimal.h"
#include "UI_InGameIndicatorComponent.h"
#include "UI_ConversationIndicator.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UUI_ConversationIndicator : public UUI_InGameIndicatorComponent {
    GENERATED_BODY()
public:
    UUI_ConversationIndicator();
};

