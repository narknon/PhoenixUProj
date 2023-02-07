#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_OverlapWithIgnore.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable, MinimalAPI)
class UEnvQueryTest_OverlapWithIgnore : public UEnvQueryTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvOverlapData OverlapData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> IgnoreContext;
    
    UEnvQueryTest_OverlapWithIgnore();
};

