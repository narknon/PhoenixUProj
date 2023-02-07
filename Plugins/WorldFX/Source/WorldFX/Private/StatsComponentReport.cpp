#include "StatsComponentReport.h"
#include "StatsComponentReportComponent.h"

AStatsComponentReport::AStatsComponentReport() {
    this->UpdateComponent = CreateDefaultSubobject<UStatsComponentReportComponent>(TEXT("ReportUpdate"));
}

