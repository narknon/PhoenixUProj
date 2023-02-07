#pragma once
#include "CoreMinimal.h"
#include "QualifierTask.h"
#include "CentaurCopyCombatTargetsQualifierTask.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCentaurCopyCombatTargetsQualifierTask : public UQualifierTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeightThreshold;
    
    UCentaurCopyCombatTargetsQualifierTask();
};

