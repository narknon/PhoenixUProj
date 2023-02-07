#pragma once
#include "CoreMinimal.h"
#include "DialogueLineAnimTablesFinishedLoadingDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialogueLineAnimTablesFinishedLoading, AActor*, Actor, FName, RegistryId);

