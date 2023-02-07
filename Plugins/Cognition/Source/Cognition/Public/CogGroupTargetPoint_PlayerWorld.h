#pragma once
#include "CoreMinimal.h"
#include "CogGroupTargetPoint.h"
#include "CogGroupTargetPoint_PlayerWorld.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupTargetPoint_PlayerWorld : public UCogGroupTargetPoint {
    GENERATED_BODY()
public:
    UCogGroupTargetPoint_PlayerWorld();
};

