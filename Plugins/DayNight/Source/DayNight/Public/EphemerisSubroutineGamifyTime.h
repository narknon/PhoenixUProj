#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EphemerisSubroutineGamifyTime.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineGamifyTime : public UObject {
    GENERATED_BODY()
public:
    UEphemerisSubroutineGamifyTime();
};

