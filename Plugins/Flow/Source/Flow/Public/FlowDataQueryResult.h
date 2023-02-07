#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EWaterType.h"
#include "FlowDataQueryResult.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FFlowDataQueryResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWaterType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Normal;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> WaterBodyActor;
    
    FLOW_API FFlowDataQueryResult();
};

