#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_Creature_CohesionWithActorsOfClass.generated.h"

UCLASS(Blueprintable)
class UEnvQueryTest_Creature_CohesionWithActorsOfClass : public UEnvQueryTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue DetectionRange;
    
    UEnvQueryTest_Creature_CohesionWithActorsOfClass();
};

