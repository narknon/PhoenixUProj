#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "VendorBroomPreviewClassLoadedDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FVendorBroomPreviewClassLoaded, FName, BroomID, TSubclassOf<AActor>, ActorClass);

