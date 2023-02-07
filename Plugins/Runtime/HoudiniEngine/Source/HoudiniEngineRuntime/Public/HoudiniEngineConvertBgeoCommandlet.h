#pragma once
#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "HoudiniEngineConvertBgeoCommandlet.generated.h"

UCLASS(Blueprintable, NonTransient)
class UHoudiniEngineConvertBgeoCommandlet : public UCommandlet {
    GENERATED_BODY()
public:
    UHoudiniEngineConvertBgeoCommandlet();
};

