#pragma once
#include "CoreMinimal.h"
#include "AsyncLoadAssetListCompleteDelegate.generated.h"

class UObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAsyncLoadAssetListComplete, const TArray<TSoftObjectPtr<UObject>>&, StreamedAssets, int32, UniqueId);

