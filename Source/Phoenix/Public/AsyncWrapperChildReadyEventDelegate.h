#pragma once
#include "CoreMinimal.h"
#include "AsyncWrapperChildReadyEventDelegate.generated.h"

class UUserWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAsyncWrapperChildReadyEvent, UUserWidget*, ChildObject);

