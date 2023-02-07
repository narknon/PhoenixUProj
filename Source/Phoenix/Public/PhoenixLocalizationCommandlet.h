#pragma once
#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "PhoenixLocalizationCommandlet.generated.h"

UCLASS(Blueprintable, NonTransient)
class UPhoenixLocalizationCommandlet : public UCommandlet {
    GENERATED_BODY()
public:
    UPhoenixLocalizationCommandlet();
};

