#pragma once
#include "CoreMinimal.h"
#include "EFacialEmotion.h"
#include "DialogueLineEmotionChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueLineEmotionChanged, EFacialEmotion, FacialEmotion);

