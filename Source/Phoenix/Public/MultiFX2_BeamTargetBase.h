#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MultiFX2_BeamTargetBase.generated.h"

UCLASS(Abstract, Blueprintable, Const, EditInlineNew)
class UMultiFX2_BeamTargetBase : public UObject {
    GENERATED_BODY()
public:
    UMultiFX2_BeamTargetBase();
};

