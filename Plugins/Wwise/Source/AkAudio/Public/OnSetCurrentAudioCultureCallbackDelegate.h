#pragma once
#include "CoreMinimal.h"
#include "OnSetCurrentAudioCultureCallbackDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSetCurrentAudioCultureCallback, bool, Succeeded);

