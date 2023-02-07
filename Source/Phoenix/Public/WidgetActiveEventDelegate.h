#pragma once
#include "CoreMinimal.h"
#include "WidgetActiveEventDelegate.generated.h"

class UUserWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWidgetActiveEvent, UUserWidget*, ActiveWidget);

