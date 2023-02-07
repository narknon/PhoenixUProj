#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsComponentReportSettings.h"
#include "StatsComponentReportComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WORLDFX_API UStatsComponentReportComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FStatsComponentReportSettings Report;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 OnReport;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 NextReport;
    
    UStatsComponentReportComponent();
};

