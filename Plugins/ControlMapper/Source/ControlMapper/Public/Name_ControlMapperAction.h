#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_ControlMapperAction.generated.h"

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FName_ControlMapperAction : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_ControlMapperAction();
};
FORCEINLINE uint32 GetTypeHash(const FName_ControlMapperAction) { return 0; }

