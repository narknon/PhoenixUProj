#pragma once
#include "CoreMinimal.h"
#include "AvaDialogueTrackSectionData.h"
#include "AvaDialogueTrackTemplateData.generated.h"

USTRUCT(BlueprintType)
struct FAvaDialogueTrackTemplateData : public FAvaDialogueTrackSectionData {
    GENERATED_BODY()
public:
    PHOENIX_API FAvaDialogueTrackTemplateData();
};

