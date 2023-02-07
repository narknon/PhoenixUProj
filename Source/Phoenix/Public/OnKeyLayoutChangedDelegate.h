#pragma once
#include "CoreMinimal.h"
#include "EKeyLayout.h"
#include "OnKeyLayoutChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnKeyLayoutChanged, EKeyLayout, OldLayout, EKeyLayout, NewLayout);

