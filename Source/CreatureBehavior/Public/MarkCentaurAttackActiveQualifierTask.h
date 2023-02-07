#pragma once
#include "CoreMinimal.h"
#include "QualifierTask.h"
#include "MarkCentaurAttackActiveQualifierTask.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMarkCentaurAttackActiveQualifierTask : public UQualifierTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttackDescriptorName;
    
    UMarkCentaurAttackActiveQualifierTask();
};

