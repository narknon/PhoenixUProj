#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EphemerisSubroutine.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutine : public UObject {
    GENERATED_BODY()
public:
    UEphemerisSubroutine();
};

