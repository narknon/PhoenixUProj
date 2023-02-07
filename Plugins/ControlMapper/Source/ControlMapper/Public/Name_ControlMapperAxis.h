#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_ControlMapperAxis.generated.h"

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FName_ControlMapperAxis : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_ControlMapperAxis();
};
FORCEINLINE uint32 GetTypeHash(const FName_ControlMapperAxis) { return 0; }

