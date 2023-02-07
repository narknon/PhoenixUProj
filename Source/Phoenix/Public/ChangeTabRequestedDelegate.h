#pragma once
#include "CoreMinimal.h"
#include "EPauseMenuPage.h"
#include "ChangeTabRequestedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChangeTabRequested, EPauseMenuPage, NewPage, const TArray<FString>&, DestinationPath);

