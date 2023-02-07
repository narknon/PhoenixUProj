#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_Stations.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class UEnvQueryTest_Stations : public UEnvQueryTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScoreInOrder;
    
    UEnvQueryTest_Stations();
};

