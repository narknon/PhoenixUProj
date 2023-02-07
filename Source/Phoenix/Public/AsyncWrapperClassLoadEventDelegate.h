#pragma once
#include "CoreMinimal.h"
#include "AsyncWrapperClassLoadEventDelegate.generated.h"

class UAsyncLoadWrapper;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAsyncWrapperClassLoadEvent, UAsyncLoadWrapper*, SelfReference);

