#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StatsComponentReport.generated.h"

class UStatsComponentReportComponent;

UCLASS(Blueprintable, Transient)
class WORLDFX_API AStatsComponentReport : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponentReportComponent* UpdateComponent;
    
    AStatsComponentReport();
};

