#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "MercunaQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_Mercuna_Reachable.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable)
class MERCUNA_API UEnvQueryTest_Mercuna_Reachable : public UMercunaQueryTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MaxPathLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> Context;
    
    UEnvQueryTest_Mercuna_Reachable();
};

