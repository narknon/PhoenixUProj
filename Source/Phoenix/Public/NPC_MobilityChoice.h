#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NPC_MobilityChoice.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UNPC_MobilityChoice : public UObject {
    GENERATED_BODY()
public:
    UNPC_MobilityChoice();
};

