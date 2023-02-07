#pragma once
#include "CoreMinimal.h"
#include "SpecifcSenseCallOutTextChangedDelegate.generated.h"

class UAISenseSpecificDetails;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpecifcSenseCallOutTextChanged, UAISenseSpecificDetails*, AISenseSpecificDetails);

