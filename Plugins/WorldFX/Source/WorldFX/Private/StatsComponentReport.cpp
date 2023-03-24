#include "StatsComponentReport.h"
#include "StatsComponentReportComponent.h"

AStatsComponentReport::AStatsComponentReport(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UpdateComponent = CreateDefaultSubobject<UStatsComponentReportComponent>(TEXT("ReportUpdate"));
}

