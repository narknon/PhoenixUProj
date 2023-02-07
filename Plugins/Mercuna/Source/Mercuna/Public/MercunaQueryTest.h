#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "MercunaQueryTest.generated.h"

UCLASS(Abstract, Blueprintable)
class MERCUNA_API UMercunaQueryTest : public UEnvQueryTest {
    GENERATED_BODY()
public:
    UMercunaQueryTest();
};

