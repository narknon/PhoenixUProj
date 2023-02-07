#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "EStationSelectionMethod.h"
#include "EnvQueryGenerator_StationsManagedBy.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnvQueryGenerator_StationsManagedBy : public UEnvQueryGenerator {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAvailableStationsOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GenerateMaxCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EStationSelectionMethod> SelectionMethod;
    
    UEnvQueryGenerator_StationsManagedBy();
};

