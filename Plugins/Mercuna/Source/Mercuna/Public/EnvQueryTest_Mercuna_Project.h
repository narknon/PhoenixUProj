#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "MercunaQueryTest.h"
#include "EnvQueryTest_Mercuna_Project.generated.h"

UCLASS(Blueprintable)
class MERCUNA_API UEnvQueryTest_Mercuna_Project : public UMercunaQueryTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MaxSearchRadius;
    
    UEnvQueryTest_Mercuna_Project();
};

