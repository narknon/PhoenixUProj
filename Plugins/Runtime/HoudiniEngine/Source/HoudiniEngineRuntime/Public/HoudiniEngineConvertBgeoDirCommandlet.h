#pragma once
#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "HoudiniEngineConvertBgeoDirCommandlet.generated.h"

UCLASS(Blueprintable, NonTransient)
class UHoudiniEngineConvertBgeoDirCommandlet : public UCommandlet {
    GENERATED_BODY()
public:
    UHoudiniEngineConvertBgeoDirCommandlet();
};

