#pragma once
#include "CoreMinimal.h"
#include "QualifierTask.h"
#include "ManageActionEnergyQualifierTask.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UManageActionEnergyQualifierTask : public UQualifierTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnergyBurnTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnergyResetTime;
    
    UManageActionEnergyQualifierTask();
};

