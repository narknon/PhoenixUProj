#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblStartPositionGetter.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblStartPositionGetter : public UObject {
    GENERATED_BODY()
public:
    UAblStartPositionGetter();
};

