#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DayNightSkyStateOverrideInterface.h"
#include "SkyStateOverride.generated.h"

UCLASS(Abstract, Blueprintable, Const, EditInlineNew)
class DAYNIGHT_API USkyStateOverride : public UObject, public IDayNightSkyStateOverrideInterface {
    GENERATED_BODY()
public:
    USkyStateOverride();
    
    // Fix for true pure virtual functions not being implemented
};

