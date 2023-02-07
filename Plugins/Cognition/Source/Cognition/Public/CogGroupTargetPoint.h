#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CogGroupTargetPoint.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupTargetPoint : public UObject {
    GENERATED_BODY()
public:
    UCogGroupTargetPoint();
};

