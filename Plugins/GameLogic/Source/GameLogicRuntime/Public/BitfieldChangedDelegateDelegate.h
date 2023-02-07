#pragma once
#include "CoreMinimal.h"
#include "Bitfield256.h"
#include "BitfieldChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBitfieldChangedDelegate, FBitfield256, CachedResult);

