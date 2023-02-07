#pragma once
#include "CoreMinimal.h"
#include "CurriculumRequirements_Updated.h"
#include "VCSlot.h"
#include "Curriculum_YearData_Updated.generated.h"

USTRUCT(BlueprintType)
struct FCurriculum_YearData_Updated {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCurriculumRequirements_Updated> UncompletedTurnIns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCurriculumRequirements_Updated> CompletedTurnIns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVCSlot> YearRewards;
    
    PHOENIX_API FCurriculum_YearData_Updated();
};

